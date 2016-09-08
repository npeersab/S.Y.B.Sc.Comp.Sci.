#include <stdio.h>
#include <string.h>

struct contacts {
	char name[20], addrs[50], email[20];
	int number;
} cont[1000];

struct favourites {
	struct contacts favrt[20];
	int rear, size;
} fav;

int cnt_size = 0;

void readContact();
void readFavourites();
void findContact(char []);
void addContact();
void addtoFavourites();
void init(); 
void displayFavourites();
void displayContacts();
void findFavourite();

void init() {
	fav.rear = fav.size = 0;
}

void readContact() {
	FILE *file;
	file = fopen("cont.ct", "r");
	if(file == NULL)
		return;
	for(cnt_size = 0; !feof(file); cnt_size++)
		fscanf(file, "%s %s %s %d", cont[cnt_size].name, cont[cnt_size].addrs, cont[cnt_size].email, &cont[cnt_size].number);
	fclose(file);
	cnt_size--;
}

void findContact(char name[]) {
	int i, flag = 0;
	if(cnt_size == 0) {
		printf("No contacts found...\n");
		return;
	}
	for(i = 0; i < cnt_size; i++) {
		if(strcmp(cont[i].name, name)) {
			printf("Name : %s\nAddress : %s\nEmail id : %s\nPhone no. : %d\n", cont[i].name, cont[i].addrs, cont[i].email, cont[i].number);
			flag = 1;
		}
	}
	if(!flag) 
		printf("%s not found in the address book\n", name);
}

void addContact() {
	FILE *file;
	if(cnt_size == 999) {
		printf("Cannot add new contact address book is full...\n");
		return;
	}
	printf("Enter name : ");
	scanf(" %s" ,cont[cnt_size].name);
	printf("Enter address : ");
	scanf(" %s", cont[cnt_size].addrs);
	printf("Enter email id : ");
	scanf(" %s", cont[cnt_size].email);
	printf("Enter number : ");
	scanf("%d", &cont[cnt_size].number);
	file = fopen("cont.ct", "a");
	fprintf(file, "%s %s %s %d\n", cont[cnt_size].name, cont[cnt_size].addrs, cont[cnt_size].email, cont[cnt_size].number);
	fclose(file);
	cnt_size++;
}

void addtoFavourites() {
	int i;
	char temp_name[20];
	printf("Enter contact name : ");
	scanf(" %s", temp_name);
	if(cnt_size == 0) {
		printf("No contacts found...\n");
		return;
	}
	for(i = 0; i < cnt_size; i++) {
		if(!strcmp(cont[i].name, temp_name)) {
			strcpy(fav.favrt[fav.rear].name, cont[i].name);
			strcpy(fav.favrt[fav.rear].addrs, cont[i].addrs);
			strcpy(fav.favrt[fav.rear].email, cont[i].email);
			fav.favrt[fav.rear].number = cont[i].number;
			fav.rear = (fav.rear + 1) % 20;
			if(fav.size < 20)
				fav.size++;
			printf("%s added to favourites...\n", temp_name);
			return;
		}
	}
	printf("%s not found in the address book...\n");
}	

void findFavourite(char name[]) {
        int i, flag = 0;
        for(i = 0; i < 20; i++) {
                if(!strcmp(fav.favrt[i].name, name)) {
                        printf("Name : %s\nAddress : %s\nEmail id : %s\nPhone no. : %d\n", fav.favrt[i].name, fav.favrt[i].addrs, fav.favrt[i].email, fav.favrt[i].number);
                        flag = 1;
                }
        }
        if(!flag)
                printf("%s not found in the address book\n", name);
}

void displayContacts() {
	int i;
	if(cnt_size == 0) {
		printf("No contacts found...\n");
		return;
	}
	for(i = 0; i < cnt_size; i++)
		 printf("\nContact %d : \nName : %s\nAddress :%s\nEmail id : %s\nNumber : %d\n", i + 1, cont[i].name, cont[i].addrs, cont[i].email, cont[i].number);
}

void displayFavourites() {
        int i;
	if(fav.size == 0) {
		printf("No Favourites found...\n");
		return;
	}
        for(i = 0; i < fav.size; i++)
                 printf("\nFavourite %d : \nName : %s\nAddress : %s\nEmail id : %s\nNumber : %d\n", i + 1, fav.favrt[i].name, fav.favrt[i].addrs, fav.favrt[i].email, fav.favrt[i].number);
}


#include "head.h"
#include <stdlib.h>

main() {
	int choice;
	char temp_name[20];
	
	init();
	readContact();

	while(1) {
		printf("1.Add Contact\n2.Find Contact\n3.Find Favourites\n4.Add contact to favourites\n5.Display all Contacts\n6.Display all favourites\n7.Exit\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				addContact();
				break;
			case 2 :
				printf("Enter contact name : ");
				scanf(" %s", temp_name);
				findContact(temp_name);
				break;
			case 3 :
				printf("Enter contact name : ");
				scanf(" %s", temp_name);
				findFavourite(temp_name);
				break;
			case 4 :
				addtoFavourites();
				break;
			case 5 :
				displayContacts();
				break;
			case 6 :
				displayFavourites();
				break;
			case 7 :
				exit(0);
			default :
				printf("Please enter correct choice...\n");
		}
	}
}


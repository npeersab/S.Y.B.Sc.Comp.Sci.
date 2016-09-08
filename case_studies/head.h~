#include<stdio.h>
#include<stdlib.h>

FILE *file;
char data[20][1000];
char dic[20][100];
int size = 0, dicsize = 0;

void readFile();
void checkFile();
void binarySearch(char *);
void appendDic(char *);

void readFile() {
	char filename[20];
	printf("Enter filename: ");
	scanf("%s", filename);
	file = fopen(filename, "r");
	if(file == NULL) {
		printf("File not found ...\n");
		exit(1);
	}
	while(!feof(file))
		fscanf(file, "%s", data[size++]);
	fclose(file);
	size--;
}

void readDic() {
        file = fopen("mydic.dcc", "r");
        if(file == NULL) {
                printf("Error : Dictionary not found ...\nPlease Create or Check Dictionary File...\n");
                exit(1);
        }
        while(!feof(file))
                fscanf(file, "%s", dic[dicsize++]);
	fclose(file);
	dicsize--;
}

void checkFile() {
	int i;
	for(i = 0; i < size; i++) {
		binarySearch(data[i]);
	}
}

void binarySearch(char *word) {
	int i;
	char ch;
	for(i = 0; i < dicsize; i++) {
		if(!strcmp(dic[i], word))
			return;
	}
	printf("%s is miss spelled \n", word);
	printf("Do you want to add %s to dictionary ? (y/n) : ", word);
	scanf(" %c", &ch);
	if(ch == 'y' || ch == 'Y')
		appendDic(word);
	else
		exit(1); 
}

void appendDic(char *word) {
	FILE *file;
	file = fopen("mydic.dcc", "a");
	if(file == NULL) {
		printf("Error : Dictionary is Missing...\nPlease Check the Dictionary File");
		exit(1);
	}
	fprintf(file, "%s", word);
	fclose(file);
	dicsize++;
	printf("%s added to dictionary\n", word);
}

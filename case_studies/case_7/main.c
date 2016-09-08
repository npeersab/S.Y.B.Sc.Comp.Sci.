#include "head.h"

main() {

	int choice, time;	
	char name[20];	

	init();
	while(1) {
		printf("\n1.Add new user\n2.Return Machine\n3.Check status of machine\n4.Display all pending users\n5.Exit\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice) {
			case 1 :
				printf("Enter username : ");
				scanf("%s", name);
				printf("Enter amount : ");
				scanf("%d", &time);
				addUser(name, time);
				break;
			case 2 :
				removefromMachine();
				break;
			case 3 :
				getStatus();
				break;
			case 4 :
				displayUser();
				break;
			case 5 : 
				exit(0);
			default :
				printf("Wrong choice...\n");
		}
	}
}

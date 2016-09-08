#include "head.h"
#include <time.h>

main() {
	int size;
	unsigned long int start_time, stop_time;
	getPlayer:
	printf("\nHow many players : ");
	scanf("%d", &size);
	if(size < 2) {
		printf("There should be at least players for this game...\n");
		goto getPlayer;
	}
	createPlayer(size);
	printf("\nPress Enter to start the game...");
	getchar();
	getchar();
	while(1) {
		printf("Press Enter to start Passing Potato...");
		start_time = time(NULL);
		getchar();
		printf("Press Enter to stop Passing Potato...");
		getchar();
		stop_time = time(NULL);
		eliminatePlayer((stop_time - start_time) + 100);
	}
}
	


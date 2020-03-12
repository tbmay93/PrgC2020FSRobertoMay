#include<stdio.h>
#include<stdlib.h>

typedef enum{
	INVALID = 0,
	START,
	ROOM1,
	ROOM2,
	EXIT
} menuSelection;



menuSelection PrintUserMenu(void);


int main(int argc, char *argv[]){
	menuSelection switchCase = INVALID;
	int doAsLong = EXIT;
	while(doAsLong){
		switchCase = PrintUserMenu();
		switch(switchCase){
			case START:
				printf("\n\n\t\t\t\t\t\tStartpoint reached.\n\n");
				break;
			case ROOM1:
				printf("\n\n\t\t\t\t\t\tWelcome Room 1.\n\n");
				break;
			case ROOM2:
				printf("\n\n\t\t\t\t\t\tWelcome Room 2.\n\n");
				break;
			case EXIT:
				printf("\n\n\t\t\t\t\t\tGood choice, you will be logged out.\n\n");
				doAsLong = 0;
				break;
			default:
				printf("\n\n\t\t\t\t\t\tWhat the hell do you want!\n\n");
				break;
		}
	}

	return 1;
}

menuSelection PrintUserMenu( void ) {
	int selectedMenuItem = 0;
	printf("\n------------------------------------\n");
	printf("* * * * Welcome to CoolCode! * * * *\n");
	printf("------------------------------------\n");
	printf("Select from the following options:\n");
	printf("1: Start\n");
	printf("2: Room 1\n");
	printf("3: Room 2\n");
	printf("4: f*** this shit and exit\n");
	printf("-> ");
	scanf("%d", &selectedMenuItem );
	
	if(		selectedMenuItem != START
		&&	selectedMenuItem != ROOM1
		&&	selectedMenuItem != ROOM2
		&&	selectedMenuItem != EXIT){
		selectedMenuItem = INVALID;
	}
		
	return selectedMenuItem;
}

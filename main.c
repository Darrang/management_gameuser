#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record*[],int *pcount);
void display_menu();

// main function

int main(){
	int count=0;
	Record *records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "0") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records,&count);
	}
	
	return 0;
}

void input_handler(char input[], Record *records[], int *pcount){
		// TODO: Modify this function as you need
	if(!strcmp(input, "1"))
		*pcount=add_new_users(records,pcount);
	else if(!strcmp(input,"2"))
		add_user_file(records, pcount);
	else if(!strcmp(input, "3"))
		print_all_users(records,pcount);
	else if(!strcmp(input, "4"))
		load_datafile(records,pcount);
	else if(!strcmp(input, "5"))
		export_user_file(records,pcount);
	else if(!strcmp(input, "6"))
		save_file_users(records, pcount);
	else if(!strcmp(input, "7"))
		update_user_data(records,pcount);
	else if(!strcmp(input, "8"))
		*pcount=delete_user(records,pcount);
	else if(!strcmp(input, "9"))
		search_user(records, pcount);
	else if(!strcmp(input, "10"))
		sort_userlist(*records, pcount);
	else if(!strcmp(input, "11"))
		advanced_search_user(records, pcount);
	else if(!strcmp(input, "0"))
			printf("Terminating... bye!\n");// Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}

void display_menu(){

	// TODO: Modify this function as you need
	printf("******************************\n");
	printf(" Game User management system \n");
	printf("******************************\n");
	printf(" 1. Add a new user\n");
	printf(" 2. Add a new user to file\n"); 
	printf(" 3. Print all users\n"); 
	printf(" 4. load data file\n");
	printf(" 5. export data to file\n");
	printf(" 6. Save to all data to file\n");
	printf(" 7. Update User data\n");
	printf(" 8. Delete User\n");
	printf(" 9. Search(ID)\n"); 
	printf(" 10. Sort(ID/Age)\n");
	printf(" 11. Advanced Search\n"); 
	printf(" 0. Quit\n");
	
}

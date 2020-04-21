#include <stdio.h>
#include "base.h"
#include <string.h> 
//Added for searchuser function.

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - print all users data
void print_all_records(Record records[],int count){
	// TODO: Modify this function as you need
	printf("NO.     Name     Age  Gender     Id     Emailaddress\n");
	for(int i=0;i<count;i++){
		printf("%d. %s   %s   %s  %s  %s\n",i+1,records[i].name,records[i].age,records[i].gender,records[i].id,records[i].email);
	}
	return;
}

// Function: loadUsers()
// Input: record - array of Records
// Output: Number of users stored in the list
// Implementing a function that retrieves a list of users from the Userdata.txt file
int loadUsers(Record records[]){
  FILE *fp;
	fp=fopen("Userdata.txt","rt");
	int i=0;
	int count=0;
	while(!feof(fp))
	{
		fgets(records[i].name,sizeof(records[i].name),fp);
		fscanf(fp,"%s",records[i].age);
		fscanf(fp,"%s",records[i].gender);
		fscanf(fp,"%s",records[i].id);
		fscanf(fp,"%s",records[i].email);
		i++;
		count++;
	}
	fclose(fp);
	return count-1;
}

// Function: createUsers()
// Input: record - array of Records, count - number of user data
// Output: none
// add new user
void createUsers(Record records[], int count){
	char dummy;
 printf("=>Input User information: Name, Age, Gender, ID, Email address\n");
 printf("What is your name?\n");
 scanf("%[^\n]s",records[count].name);

 printf("How old are you?\n");
 scanf("%s",records[count].age);

 printf("What is your Gender? (M: Man F: Femail)\n");
 scanf("%s",records[count].gender);

 printf("What is your ID?\n");
 scanf("%s",records[count].id);
 printf("What is your Email address?\n");
 scanf("%s",records[count].email);
 printf("create new user!\n");
 scanf("%c",&dummy);

}

// Function: saveUsers()
// Input: record - array of Records, count - number of user data
// Output: none
//Save all currently registered users (Userdata.txt)
void saveUsers(Record records[], int count){
	FILE*fp;
	fp=fopen("Userdata.txt","wt");
	for(int i=0;i<count;i++)
	{
		fprintf(fp,"%s ",records[i].name);
		fprintf(fp,"%s ",records[i].age);
		fprintf(fp,"%s ",records[i].gender);
		fprintf(fp,"%s ",records[i].id);
		fprintf(fp,"%s\n",records[i].email);
	}
	fclose(fp);
	printf("Save User Data Successfully!!\n");
}

// Function: searchUser()
// Input: record - array of Records, count - number of user data
// Output: none
//Find and print desired user information
void searchUser(Record records[],int count){
	int i,j;
	char id[30];
	char age[10];
	char address[30];
	char dummy;
	int x=0;
	int n=0;
	
	printf("Search User");
	printf("ID > ");
	scanf("%s",id);
	
	printf("Age > ");
	scanf("%s",id);

	printf("Email address > ");
	scanf("%s",id);
	scanf("%c",&dummy);

	printf("********************\n");
	for(i=0;i<count;i++)
  {
		if(strcmp(records[i].id,id) == 0 || strcmp(records[i].age,age) == 0 ||strcmp(records[i].email,address) == 0)
		{
			printf("%d\t",n+1);
			printf("%s\t%s\t%s\t%s", records[i].id, records[i].age, records[i].email,records[i].gender);
			n++;
		}
	}
	printf("********************\n");
	printf("I found %d User!!\n",n);

}

void sortUserList(Record records[], int count){ 

}

void updateUserInfo(Record records[],int count){
	char find[100];
	char dummy;
	printf("Which user will you update? (Enter UserName)");
	scanf("%[^\n]s",find);
	for(int i=0; i<count;i++){
		if( strcmp(records[i].name, find) == 0){
			printf("=>Input User information: Name, Age, Gender, ID, Email address\n");
			printf("What is your name?\n");
			scanf("%[^\n]s",records[count].name);
			printf("How old are you?\n");
			scanf("%s",records[count].age);
			printf("What is your Gender? (M: Man F: Femail)\n");
			scanf("%s",records[count].gender);
			printf("What is your ID?\n");
			scanf("%s",records[count].id);
			printf("What is your Email address?\n");
			scanf("%s",records[count].email);
			printf("create new user!\n");
			scanf("%c",&dummy);
		}

	}
}


void deleteUser(Record records[],int count){
	char deleteUser[50];
	int dummy;
	printf("Which user will you delete?\n Enter user name: ");
	scanf("%[^\n]s",deleteUser);
	for(int i=0; i < count;i++){
		if(strcmp(records[i].name,deleteUser)==0){
			for(int j=i; j < count-1; j++){
				records[j] = records[j+1]; 
			}
		}
	}
}

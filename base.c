#include <stdio.h>
#include "base.h"
#include <string.h> 
#include <stdlib.h>
//Added for searchuser function.

//1. 데이터파일로부터 새로운 데이터를 생성
//2. standard 입력으로 새로운 데이터 생성
//3. 유저의 인풋 조건에 따라서 파일 프린트하기
//4. 파일에서 전체 데이터 읽어오기, 파일에 전체 데이터 쓰기
//5. 전체 데이터를 보고서 형식으로 .txt 파일로 내보내기
//

//display all records
//1: display current records
//2: display file records

//print a record, multiple or all records to the standard output
//현재 등록된 모든 유저 출력하기
void print_all_users(Record *records[],int *pcount){
	int choose=0;
	char dummy;
	int count=0;
	printf("1: display current records 2: display file records\n");
	scanf("%d",&choose);

	if(choose==1){
			display_records(records,pcount);
	}
	else if(choose==2){
		char dummy;
		int i;
		int count=0;
		FILE *fp;
	fp=fopen("Userdata.txt","rt");
	if(fp==NULL){
		printf("The file does not exist.");
		return;
	} 
	while(!feof(fp))
	{
		records[i]=(Record*)malloc(sizeof(Record));
		fgets(records[i]->name,sizeof(records[i]->name),fp);
		fscanf(fp,"%d",&records[i]->age);
		fscanf(fp,"%s",records[i]->gender);
		fscanf(fp,"%s",records[i]->id);
		fscanf(fp,"%s",records[i]->email);
	  count++;
	}
	fclose(fp);
	*pcount=count;

		display_records(records,pcount);
	}
}

//display current records
void display_records(Record *records[],int *pcount){
	int choose=0;
	char dummy;
	printf("There are %d users\n",*pcount);
	printf("Enter number of user to be printed(Enter 0 to print all):");
	scanf("%d",&choose);
	scanf("%c",&dummy);
	if(pcount == 0){
			printf("There are no users to display.\n");
			return;
	}
	else if(choose > 0 && choose <= *pcount){
		printf("==================================================================\n");
		printf("  NO. ||  Name  ||  Age  ||  Gender  ||   Id   ||  Email address\n");
		printf("==================================================================\n");
		for(int i=0; i<choose; i++){
			printf("%2d.  %10s   %5d   %5s %15s   %15s\n",i+1,records[i]->name,records[i]->age,records[i]->gender,records[i]->id,records[i]->email);
		}
		printf("===================================================================\n");

	}else if(*pcount < choose || choose == 0){
		printf("==================================================================\n");
		printf("  NO. ||  Name  ||  Age  ||  Gender  ||   Id   ||  Email address\n");
		printf("==================================================================\n");
		for(int i=0; i<*pcount; i++){
			printf("%2d.  %10s   %5d   %5s %15s  %15s\n",i+1,records[i]->name,records[i]->age,records[i]->gender,records[i]->id,records[i]->email);
		}
		printf("===================================================================\n");
	}

}

//load users from file and display file.
//전체 레코드 읽기
//Userdata.txt에서 유저정보 불러오기
void load_datafile(Record *records[], int*pcount){ 
	char dummy;
	int i;
	int count=0;
	FILE *fp;
	fp=fopen("Userdata.txt","rt");
	if(fp==NULL){
		printf("The file does not exist.");
		return;
	} 
	while(!feof(fp))
	{
		records[i]=(Record*)malloc(sizeof(Record));
		fgets(records[i]->name,sizeof(records[i]->name),fp);
		fscanf(fp,"%d",&records[i]->age);
		fscanf(fp,"%s",records[i]->gender);
		fscanf(fp,"%s",records[i]->id);
		fscanf(fp,"%s",records[i]->email);
	  count++;
	}
	*pcount=count;
	fclose(fp);
	display_records(records, pcount);
}

// Function: createUsers()
// Input: record - array of Records
// Output: none
// add new user and add current
// Create a new data record from the standard intput
int add_new_users(Record *records[],int *pcount){
 char dummy;
	records[*pcount]=(Record*)malloc(sizeof(Record));
	printf("=>Input User information\n(Name, Age, Gender, ID, Email address)\n");
	printf("What is your name?\n");
	scanf("%[^\n]s",records[*pcount]->name);
	printf("How old are you?\n");
	scanf("%d",&records[*pcount]->age);
	printf("What is your Gender? (M: Man F: Femail)\n");
	scanf("%s",records[*pcount]->gender);
	printf("What is your ID?\n");
	scanf("%s",records[*pcount]->id);
	printf("What is your Email address?\n");
	scanf("%s",records[*pcount]->email);
	printf("create new user!\n");
	scanf("%c",&dummy);

	return *pcount+1;
}

//파일에 직접 추가하기
//Create a new data records from a data file
void add_user_file(Record *records[],int *pcount){
	char filename[30];
	char dummy;
	int record=0;
	int count=0;
	FILE*fp;
	add_new_users(records, pcount);
	fp=fopen("Userdata.txt","at");
	fprintf(fp,"%s ",records[*pcount]->name);
	fprintf(fp,"%d ",records[*pcount]->age);
	fprintf(fp,"%s ",records[*pcount]->gender);
	fprintf(fp,"%s ",records[*pcount]->id);
	fprintf(fp,"%s\n",records[*pcount]->email);
	fclose(fp);
	*pcount=count+1;
}


// Function: saveUsers()
// Input: record - array of Records, count - number of user data
// Output: none
//Save all currently registered users to file.
//현재까지 메모리에 있는 데이터를 파일로 저장하기
void save_file_users(Record *records[], int *pcount){
	FILE*fp;
	fp=fopen("Userdata.txt","wt");
	if(fp==NULL){
		printf("The file does not exist.");
		return;
	}
	for(int i=0;i<*pcount;i++)
	{
		fprintf(fp,"%s ",records[i]->name);
		fprintf(fp,"%d ",records[i]->age);
		fprintf(fp,"%s ",records[i]->gender);
		fprintf(fp,"%s ",records[i]->id);
		fprintf(fp,"%s ",records[i]->email);
		fprintf(fp,"\n");
	}
	fclose(fp);
	printf("Save User Data Successfully!!\n");
}

//보고서 형식으로 저장하기
void export_user_file(Record *records[], int *pcount){
	FILE*fp;
	fp=fopen("report_user.txt","wt");
	if(fp==NULL){
		printf("The file does not exist.");
		return;
	}
	for(int i=0;i<*pcount;i++)
	{
		fprintf(fp,"===========================================\n");
		fprintf(fp,"  Name         :%s\n",records[i]->name);
		fprintf(fp,"  Age          :%d\n",records[i]->age);
		fprintf(fp,"  Gender       :%s\n",records[i]->gender);
		fprintf(fp,"  ID           :%s\n",records[i]->id);
		fprintf(fp,"  Email Address:%s\n",records[i]->email);
		fprintf(fp,"===========================================\n");
	}
	fclose(fp);
	printf("Save User Data Successfully!!\n");
}


// Function: searchUser()
// Input: record - array of Records, count - number of user data
// Output: none
//Find and print desired user information current
//현재 등록된 유저 정보 찾기
void search_user(Record *records[], int *pcount){
	char choose[1];
	char id[40];
	char dummy;
	int x=0;
	int i,j;
	int n=0;
		printf("Enter to search ID > ");
		scanf("%s",id);
		scanf("%c",&dummy);
		if(x==*pcount){
				printf("There are no users to search.");
				return;
		}
			printf("==================================================================\n");
			printf("  NO. ||  Name  ||  Age  ||  Gender  ||   Id   ||  Email address\n");
			printf("==================================================================\n");

	for(int i=0; i<*pcount; i++){
		 if(!strncmp(records[i]->id,id,strlen(id)))
		{
			printf("%2d ",n+1);
			printf("%s %s %d %s %s\n", records[i]->name, records[i]->id, records[i]->age,records[i]->gender,records[i]->email);
			n++;
		}
		else
		{
			x++;
		}
	}
	printf("====================================================================\n");

}



//update user
//유저 정보 업데이트 하기
void update_user_data(Record *records[],int *pcount){
	char user[50];
	int choose;
	char dummy;
	int flag=-1;
	int i;
	printf("Enter User name to update:"); //update
	scanf("%[^\n]s",user);
	for(i=0; i<*pcount;i++){
		if(!strcmp(records[i]->name, user)){
				flag=1;
				break;
			}
		}

if(flag==1){
	printf("1:Name 2: Age 3:Gender 4:ID 5:Email Address 0:quit\n");
			scanf("%c",&dummy);
			scanf("%d",&choose);
			if(choose==0) return;

			if(choose==1){
				printf("Name: ");
				scanf("%c",&dummy);
				scanf("%[^\n]s",records[i]->name);
			}
			if(choose==2){
				printf("Age: ");
				scanf("%d",&records[i]->age);
				scanf("%c",&dummy);
			}
			if(choose==3){
				printf("Gender: ");
				scanf("%s",records[i]->gender);
				scanf("%c",&dummy);
			}
			if(choose==4){
				printf("ID");
				scanf("%s",records[i]->id);
				scanf("%c",&dummy);
			}
			if(choose==5){
				printf("Email Address: ");
				scanf("%s",records[i]->email);
				scanf("%c",&dummy);
			}
}else{
	printf("error");
}
		
}

//유저정보 지우기
//특정 유저 또는 전체 유저 정보
int delete_user(Record *records[],int *pcount){
	char answer;
	char deleteUser[50];
	char dummy;
	int x=0;
	int count=0;
	printf("Do you want to delete all user? (y/n)");
	scanf("%c",&answer);
	scanf("%c",&dummy);

	if(answer=='y' || answer=='Y'){
		for(int i=0;i<*pcount;i++){
			free(records[i]);
			count--;
		}
	}

if(answer=='n'|| answer=='N'){
		printf("Enter user name want to delte: ");
		scanf("%[^\n]s",deleteUser);
		
		if(*pcount==x){
			printf("There are no users to delete.");
			return 0;
		}
		
		for(int i=0; i<*pcount; i++){
			if(!strcmp(records[i]->name,deleteUser))
			{
				free(records[i]);
				break;
			}
			else
				x++;
		}
		count--;
 }

	printf("Do you want to save current user data?(y/n)");  //save file
	scanf("%c",&answer);
	scanf("%c",&dummy);
	
	if(answer=='y'||answer=='Y') save_file_users(records,pcount);
	else if(answer=='n'||answer=='N') return 0;
	
	return *pcount = count;
}

//delete 수정하기
//sort 수정하기

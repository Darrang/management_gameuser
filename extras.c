#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "extras.h"

// Function: defragment()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: 1 if successful, otherwise 0
// - Leave a brief information about the function
int defragment(Record records[]){
	// TODO: Modify this function as you need
	printf("defragment(): this function needs to be implemented\n\n");
	return 0;	// TODO: return 1 if defragment succeed; return 0 otherwise 
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void display_stats(Record records[]){
	// TODO: Modify this function as you need
	printf("display_stats(): this function needs to be implemented\n\n"); // TODO: Remove this line
}


// TODO: Add more functions to fulfill the optional requirements

//typedef int (*compare)(const void*,const void*);

int CompareByID(const void *v1, const void *v2){
	const Record *records1 = (Record *)v1;
	const Record *records2 = (Record *)v2;
	return strcmp(records1->id, records2->id);
}

int CompareByage(const void *v1, const void *v2){
   int a = ((Record *)v1)->age;
   int b = ((Record *)v2)->age;
   return a-b;
}
 
//sort  current User list(gender, age, name, id)
//현재 유저리스트 정렬하기
void sort_userlist(Record records[], int *pcount){
	int select=0;
	char choose;
	char dummy;
	printf("Enter sorting criteria.(1:ID 2:Age)"); //sort
	scanf("%d",&select);
 //	scanf("%c",&dummy);
	if(select==1){
		qsort(records,*pcount,sizeof(Record),CompareByID);
	printf("==================================================================\n");
		printf("  NO. ||  Name  ||  Age  ||  Gender  ||   Id   ||  Email address\n");
		printf("==================================================================\n");
		for(int i=0; i<*pcount; i++){
			printf("%2d. %5s  %5d  %10s %15s %15s\n",i+1,records[i].name,records[i].age,records[i].gender,records[i].id,records[i].email);
		}
		printf("====================================================================\n");

	}
	else if(select==2){
		qsort(records,*pcount,sizeof(Record),CompareByage);
		printf("==================================================================\n");
		printf("  NO. ||  Name  ||  Age  ||  Gender  ||   Id   ||  Email address\n");
		printf("==================================================================\n");
		for(int i=0; i<*pcount; i++){
			printf("%2d. %5s  %5d  %10s %15s %15s\n",i+1,records[i].name,records[i].age,records[i].gender,records[i].id,records[i].email);
		}
		printf("====================================================================\n");
	}
	else return;
}

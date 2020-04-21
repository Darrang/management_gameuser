#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"
// function prototypes
void print_all_records(Record[],int count);
void add_a_record(Record[],int count);
int loadUsers(Record records[]);
void createUsers(Record records[], int count);
void saveUsers(Record records[], int count);
void searchUser(Record records[],int count);
void sortUserList(Record records[], int cout);
void deleteUser(Record records[],int usercount);
void updateUserInfo(Record records[],int count);

#endif

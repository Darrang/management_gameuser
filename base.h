#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"
// function prototypes
void print_all_users(Record *records[],int *pcount);
void display_records(Record *records[],int *pcount);
void load_datafile(Record *records[],int *pcount);
int add_new_users(Record *records[],int *pcount);
void add_user_file(Record *records[],int *pcount);
void save_file_users(Record *records[], int *pcount);
void export_user_file(Record *records[], int *pcount);
void search_user(Record *records[], int *pcount);
void update_user_data(Record *records[],int *pcount);
int delete_user(Record *records[],int *pcount);

#endif

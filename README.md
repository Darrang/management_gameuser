**#Management Game Users**
======================
I am making a program to manage the information of game users.


##management_gameuser
----------------------
###Usage
Load the information of the user stored in the file to add, delete, and update the user.
Information from existing files can be replaced with new files.

###Known Bugs
There are some bugs.
You can retrieve the file at the beginning of the program. 
However, an error occurs when a file is called up when the user's information is in memory.
When sorting information of users in memory or files, it is not sorted.
After deleting the user's information, the information in the file disappears, but a bug occurs that remains in memory.


**1)	void print_all_users(Record *records[],int *pcount);**. 
If you want to print data currently stored in memory, enter 1. If you want to print data stored in Userdata.txt, enter 2. Then this function prints out the data when you decide how many users to print. if you want to print all the data, enter 0. This function is associated with the display function and the load function. 

**2)	void display_records(Record *records[],int *pcount);**. 
If you want to print data stored in Userdata.txt, enter 2. Then this function prints out the data when you decide how many users to print. if you want to print all the data, enter 0.

**3)	void load_datafile(Record *records[],int *pcount);**. 
Read the data stored in Userdata.txt and print the user. Data is read and stored in the current memory.

**4)	int add_new_users(Record *records[],int *pcount);**. 
If the user input number1, the program will get user information and create new user in the current memory. The information is the name of user, the age of user, the gender of user, ID of user and the Email address of user. Following the picture is execution of add new user menu.

**5)	void add_user_file(Record *records[],int *pcount);**. 
This allows users to add data directly to the Userdate.txt file.

**6)	void save_file_users(Record *records[], int *pcount);**. 
This task is to save user’s data in file during whole user’s data in the memory as input. Open the Userdata.txt and write user’s data in the file.

**7)	void export_user_file(Record *records[], int *pcount);**. 
The data of the users present in the current memory can be stored in report_user.txt in a report format.

**8)	void search_user(Record *records[], int *pcount);**. 
You can search for the ID of the user you want to find. If you enter only the first letter of the user ID, you can find the user's ID that has the same word.

**9)	void update_user_data(Record *records[],int *pcount);**. 
Enter username as input that want to update user. compare Records structure saved username to username as input. If there is same user, get user’s information again like name, age, gender, Id and Email address. Update user information.

**10)	int delete_user(Record *records[],int *pcount);**. 
Enter username as input. You can delete only the user's data by removing all user data in memory or by entering the user's name. Compare Records saved username to username as input. If there is same username, delete user. 

**11)	void sort_userlist(Record records[], int *pcount);**. 
In this task, I want to sort user according to name and age from input. If user want to sort name, program will sort the name in order of dictionary. If user want to sort age, program will sort the age in order of the eldest user. But I don’t know algorithm and how I code the function yet. I need to think this algorithm.

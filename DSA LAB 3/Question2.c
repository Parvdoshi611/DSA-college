#include <stdio.h>
struct Student {
char name[50];
int roll_no;
char address[100]; 
};
int main() {
struct Student s1; 
struct Student *ptr; 
ptr = &s1;

printf("Enter Student Name: ");
fgets(ptr->name, sizeof(ptr->name), stdin);
printf("Enter Roll Number: ");
scanf("%d", &ptr->roll_no);
getchar(); 
printf("Enter Address: ");
fgets(ptr->address, sizeof(ptr->address), stdin);

printf("\nStudent Details:\n");
printf("Name : %s", ptr->name);
printf("Roll No : %d\n", ptr->roll_no);
printf("Address : %s", ptr->address);
return 0;
}

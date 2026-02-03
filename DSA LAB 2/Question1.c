#include <stdio.h>
struct Student {
char name[50]; 
int rollNumber;
char address[100];
};
int main() {
struct Student student1;
printf("Enter student name: ");
fgets(student1.name, sizeof(student1.name), stdin);
printf("Enter roll number: ");
scanf("%d", &student1.rollNumber);
getchar(); 
printf("Enter student address: ");
fgets(student1.address, sizeof(student1.address), stdin);

printf("\n--- Student Details ---\n");
printf("Name : %s", student1.name); 
printf("Roll Number : %d\n", student1.rollNumber);
printf("Address : %s", student1.address);
return 0;
}

#include <stdio.h>

struct Employee {
int empID;
float empSalary;
char empName[50];
};

struct Organization {
char orgName[50];
int orgID;
struct Employee emp[2]; 
};
int main() {
struct Organization org[2]; 
int i, j;
for (i = 0; i < 2; i++) {
printf("\nEnter details for Organization %d\n", i + 1);
printf("Organization Name: ");
scanf("%s", org[i].orgName);
printf("Organization ID: ");
scanf("%d", &org[i].orgID);
for (j = 0; j < 2; j++) {
printf("\n Enter details for Employee %d\n", j + 1);
printf("Employee Name: ");
scanf("%s", org[i].emp[j].empName);
printf("Employee ID: ");
scanf("%d", &org[i].emp[j].empID);
printf("Employee Salary: ");
scanf("%f", &org[i].emp[j].empSalary);
}
}

printf("\n--- Organization and Employee Details ---\n");
for (i = 0; i < 2; i++) {
printf("\nOrganization %d\n", i + 1);
printf("Name : %s\n", org[i].orgName);
printf("ID : %d\n", org[i].orgID);
for (j = 0; j < 2; j++) {
printf("\n Employee %d\n", j + 1);
printf(" Name : %s\n", org[i].emp[j].empName);
printf(" ID : %d\n", org[i].emp[j].empID);
printf(" Salary : %.2f\n", org[i].emp[j].empSalary);
}
}
return 0;
}

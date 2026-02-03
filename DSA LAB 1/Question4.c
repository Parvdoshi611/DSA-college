#include <stdio.h>
int main() {
int arr[100];
int n, i, choice, index, value;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d elements:\n", n);
for (i = 0; i < n; i++) {
scanf("%d", &arr[i]);
}
printf("\nChoose operation:\n");
printf("1. Insert (shift right)\n");
printf("2. Delete (shift left)\n");
scanf("%d", &choice);
if (choice == 1) {
printf("Enter element to insert: ");
scanf("%d", &value);
printf("Enter index to insert at (0 to %d): ", n - 1);
scanf("%d", &index);

if (index < 0 || index > n - 1) {
printf("Invalid index!\n");
return 0;
}

for (i = n - 1; i >= index; i--) {
arr[i + 1] = arr[i];
}
arr[index] = value;
n++;
printf("Array after insertion:\n");
for (i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
}
else if (choice == 2) {
printf("Enter index to delete from (0 to %d): ", n - 1);
scanf("%d", &index);
if (index < 0 || index > n - 1) {
printf("Invalid index!\n");
return 0;
}

for (i = index; i < n - 1; i++) {
arr[i] = arr[i + 1];
}
n--;
printf("Array after deletion:\n");
for (i = 0; i < n; i++) {
printf("%d ", arr[i]);
}
}
else {
printf("Invalid choice!\n");
}
return 0;
}

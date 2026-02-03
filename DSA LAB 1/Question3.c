#include <stdio.h>
int main() {
int arr[100], freq[100];
int n, i, j, count;
printf("Enter number of elements: ");
scanf("%d", &n);
printf("Enter %d integers:\n", n);
for (i = 0; i < n; i++) {
scanf("%d", &arr[i]); 
freq[i] = -1;
}

for (i = 0; i < n; i++) {
if (freq[i] != 0) {
count = 1;
for (j = i + 1; j < n; j++) {
if (arr[i] == arr[j]) {
count++;
freq[j] = 0;
}
}
freq[i] = count;
}
}
printf("\nElement Frequency\n");
for (i = 0; i < n; i++) {
if (freq[i] != 0) {
printf("%d\t\t%d\n", arr[i], freq[i]);
}
}
printf("\nUnique elements in the array:\n");
for (i = 0; i < n; i++) {
if (freq[i] == 1) {
printf("%d ", arr[i]);
}
}
return 0;
}

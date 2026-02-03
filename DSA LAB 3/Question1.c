#include <stdio.h>
int main() {
int i;
int a = 34, b = 45, c = 65;
int *ptrArray[3];
ptrArray[0] = &a;
ptrArray[1] = &b;
ptrArray[2] = &c;
printf("Array of Pointers:\n");
for(i = 0; i < 3; i++) {
printf("Value at ptrArray[%d] = %d\n", i,
*ptrArray[i]); 
}
int arr[3] = {42, 35, 67};
int (*ptrToArray)[3];
ptrToArray = &arr;
printf("\nPointer to Array:\n");
for(i = 0; i < 3; i++) {
printf("Value at arr[%d] = %d\n", i, (*ptrToArray)[i]);
}
return 0;
}

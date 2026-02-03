#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, i;
    printf("Enter number of students: ");
    scanf("%d", &n);
    getchar(); 

    char *names[n]; 
    for(i = 0; i < n; i++) {
        names[i] = (char *)malloc(50 * sizeof(char));

        printf("Enter name of student %d: ", i + 1);
        fgets(names[i], 50, stdin);
}

    printf("\nList of Students:\n");
    for(i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
    for(i = 0; i < n; i++) {
        free(names[i]);
    }
    return 0;
}

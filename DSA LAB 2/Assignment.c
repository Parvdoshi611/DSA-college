#include <stdio.h>
#include <string.h>

struct Book {
    int bookID;
    char title[50];
    char author[50];
    float price;
};

struct Library {
    char libraryName[50];
    int libraryID;
    struct Book books[3];
};

int main() {
    struct Library lib[2];
    int i, j;

    for(i = 0; i < 2; i++) {
        printf("\nEnter details for Library %d\n", i + 1);
        printf("Library Name: ");
        fgets(lib[i].libraryName, 50 ,stdin);
        printf("Library ID: ");
        scanf("%d", &lib[i].libraryID);
        getchar();
        for(j = 0; j < 3; j++) {
            printf("\nEnter details for Book %d in %s\n", j +
	        1, lib[i].libraryName);
            printf("Book ID: ");
            scanf("%d", &lib[i].books[j].bookID);
            getchar();
            printf("Title: ");
            fgets(lib[i].books[j].title, 50, stdin);
            printf("Author: ");
            fgets(lib[i].books[j].author,50, stdin);
            printf("Price: ");
            scanf("%f", &lib[i].books[j].price);
            getchar();  // clear buffer
        }
    }

printf("\n\n----- Library Details -----\n");
    for(i = 0; i < 2; i++) {
        printf("\nLibrary Name: %s\n", lib[i].libraryName);
        printf("Library ID: %d\n", lib[i].libraryID);

        for(j = 0; j < 3; j++) {
            printf("\nBook %d Details:\n", j + 1);
            printf("Book ID: %d\n", lib[i].books[j].bookID);
            printf("Title: %s\n", lib[i].books[j].title);
            printf("Author: %s\n", lib[i].books[j].author);
            printf("Price: %.2f\n", lib[i].books[j].price);
        }
    }

    int searchID, found = 0;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchID);
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 3; j++) {
            if(lib[i].books[j].bookID == searchID) {
                printf("\nBook Found in Library: %s\n",
			   lib[i].libraryName);
                printf("Title: %s\n", lib[i].books[j].title);
                printf("Author: %s\n", lib[i].books[j].author);
                printf("Price: %.2f\n", lib[i].books[j].price);
                found = 1;
            }
        }
    }
    if(!found) {
        printf("Book not found\n");
    }
  
    for(i = 0; i < 2; i++) {
        float total = 0;
        float maxPrice = lib[i].books[0].price;
        int maxIndex = 0;
        for(j = 0; j < 3; j++) {
            total += lib[i].books[j].price;
            if(lib[i].books[j].price > maxPrice) {
                maxPrice = lib[i].books[j].price;
                maxIndex = j;
            }
        }
        printf("\nLibrary: %s\n", lib[i].libraryName);
        printf("Total value of books: %.2f\n", total);
        printf("Most expensive book: %s (%.2f)\n",
               lib[i].books[maxIndex].title,
               lib[i].books[maxIndex].price);
    }
    return 0;
}

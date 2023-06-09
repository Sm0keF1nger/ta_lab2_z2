#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char author[50];
    char title[100];
    char publisher[50];
    int year;
} Book;

int compareAuthors(const void* a, const void* b) {
    const Book* bookA = (const Book*)a;
    const Book* bookB = (const Book*)b;
    return strcmp(bookA->author, bookB->author);
}

int getNumBooks() {
    char input[50];
    int numBooks;
    bool validInput = false;

    do {
        printf("Enter the number of books: ");
        fgets(input, sizeof(input), stdin);

        if (sscanf_s(input, "%d", &numBooks) == 1) {
            validInput = true;
        }
        else {
            printf("Invalid input. Please enter a valid number of books.\n");
        }
    } while (!validInput);

    return numBooks;
}

int main() {
    int numBooks = getNumBooks();

    Book* library = (Book*)malloc(numBooks * sizeof(Book));

    for (int i = 0; i < numBooks; i++) {
        printf("\nBook %d:\n", i + 1);
        while (getchar() != '\n'); // Очистка буфера вводу

        int validInput = 0;
        do {
            printf("Author's last name: ");
            if (scanf_s(" %[^0-9\n]s", library[i].author, sizeof(library[i].author)) == 1) {
                validInput = 1;
            }
            else {
                printf("Invalid input. Please enter a valid author's last name.\n");
            }
            while (getchar() != '\n'); // Очистка буфера вводу
        } while (!validInput);

        validInput = 0;
        do {
            printf("Title: ");
            if (scanf_s(" %[^\n]s", library[i].title, sizeof(library[i].title)) == 1) {
                validInput = 1;
            }
            else {
                printf("Invalid input. Please enter a valid title.\n");
            }
            while (getchar() != '\n'); // Очистка буфера вводу
        } while (!validInput);

        validInput = 0;
        do {
            printf("Publisher: ");
            if (scanf_s(" %[^\n]s", library[i].publisher, sizeof(library[i].publisher)) == 1) {
                validInput = 1;
            }
            else {
                printf("Invalid input. Please enter a valid publisher.\n");
            }
            while (getchar() != '\n'); // Очистка буфера вводу
        } while (!validInput);

        validInput = 0;
        do {
            printf("Year of publication: ");
            if (scanf_s("%d", &library[i].year) == 1) {
                if (library[i].year <= 2023) {
                    validInput = 1;
                }
                else {
                    printf("Invalid input. Please enter a valid year of publication (<= 2023).\n");
                }
            }
            else {
                printf("Invalid input. Please enter a valid year of publication.\n");
            }
            while (getchar() != '\n'); // Очистка буфера вводу
        } while (!validInput);
    }

    qsort(library, numBooks, sizeof(Book), compareAuthors);

    printf("\n%-20s %-30s %-20s %s\n", "Author", "Title", "Publisher", "Year of Publication");
    for (int i = 0; i < numBooks; i++) {
        printf("%-20s %-30s %-20s %d\n", library[i].author, library[i].title, library[i].publisher, library[i].year);
    }

    free(library);

    return 0;
}

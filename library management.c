
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Book books[MAX_BOOKS];
int count = 0;

void addBook() {
    if (count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &books[count].id);
    getchar();

    printf("Enter Book Title: ");
    fgets(books[count].title, 100, stdin);
    books[count].title[strcspn(books[count].title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(books[count].author, 100, stdin);
    books[count].author[strcspn(books[count].author, "\n")] = '\0';

    books[count].available = 1;
    count++;

    printf("Book added successfully!\n");
}

void displayBooks() {
    if (count == 0) {
        printf("No books available.\n");
        return;
    }

    printf("\n--- Library Books ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nBook ID: %d\n", books[i].id);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Status: %s\n",
               books[i].available ? "Available" : "Issued");
    }
}

void searchBook() {
    int id, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Book found: %s by %s\n",
                   books[i].title, books[i].author);
            printf("Status: %s\n",
                   books[i].available ? "Available" : "Issued");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void issueBook() {
    int id;

    printf("Enter Book ID to issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].available) {
                books[i].available = 0;
                printf("Book issued successfully!\n");
            } else {
                printf("Book is already issued.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

void returnBook() {
    int id;

    printf("Enter Book ID to return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (!books[i].available) {
                books[i].available = 1;
                printf("Book returned successfully!\n");
            } else {
                printf("Book is already available.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            return 1;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}

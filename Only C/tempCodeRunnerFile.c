#include <stdio.h>
#include <string.h>

// Define the structure for books
struct Book {
    int book_id;
    char title[100];
    char author[100];
};

// Global array to store books
struct Book library[100];
int book_count = 0;

// Function to add a book
void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[book_count].book_id);
    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[book_count].title);
    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[book_count].author);
    book_count++;
}

// Function to display all books.
void displayBooks() {
    for (int i = 0; i < book_count; i++) {
        printf("\nBook ID: %d\nTitle: %s\nAuthor: %s\n", library[i].book_id, library[i].title, library[i].author);
    }
}

// Function to list books by a given author
void listBooksByAuthor() {
    char author[100];
    printf("\nEnter Author Name: ");
    scanf(" %[^\n]s", author);
    for (int i = 0; i < book_count; i++) {
        if (strcmp(library[i].author, author) == 0) {
            printf("\nBook ID: %d\nTitle: %s\n", library[i].book_id, library[i].title);
        }
    }
}

// Main function
int main() {
    int choice;
    do {
        printf("\n1. Add Book\n2. Display Books\n3. List Books by Author\n4. Count Books\n5. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: listBooksByAuthor(); break;
            case 4: printf("\nTotal Books: %d\n", book_count); break;
            case 5: break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}

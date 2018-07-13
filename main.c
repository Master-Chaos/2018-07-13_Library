#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 50

typedef struct books
{
    char  title[MAXLENGTH];
    char  author[MAXLENGTH];
    int   isbn;
    struct books* next;
} book;

void init_books(book *books)
{
    bzero(books->title, MAXLENGTH);
    bzero(books->author, MAXLENGTH);
    books->isbn = 0;
    books->next = NULL;

}

void print_bookall(book *books)
{
    printf("Titel: %s\n", books->title);
    printf("Autor: %s\n",books->author);
    printf("ISBN: %s\n",books->isbn);
    printf("---------------\n");

}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], int isbn, struct books* next)
{
    strcpy(books->title, title);
    strcpy(books->author, author);
    books->isbn = isbn;
    books->next = books;

    return 0;
}

int main()
{
    book book1;
    book book2;
    init_books(&book1);
    init_books(&book2);
    add_book(&book1,"Am Ende steht Gott", "Jesus Christus", 123456, &book2);



    printf("Hello world!\n");
    print_bookall(&book1);
    return 0;
}

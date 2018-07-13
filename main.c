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
    printf("Buchtitel: %s\n", books->title);

}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], int isbn, struct books* next)
{

    return 0;
}

int main()
{
    book book1;
    init_books (&book1);




    printf("Hello world!\n");
    return 0;
}

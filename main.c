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
    int bookcount;
} book;

void init_books(book *books)
{
    bzero(books->title, MAXLENGTH);
    bzero(books->author, MAXLENGTH);
    books->isbn = 0;
    books->next = NULL;
    books->bookcount = 0;

}

void print_bookall(book *books)
{
    printf("Titel: %s\n", books->title);
    printf("Autor: %s\n",books->author);
    printf("ISBN: %i\n",books->isbn);
    printf("---------------\n");

}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], int isbn)
{
    book* last = books;
    book* new;
    new = malloc(sizeof(books));

    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
    strcpy(new->title, title);
    strcpy(new->author, author);
    new->isbn = isbn;
    new->next = NULL;
    books->bookcount++;

    return 0;
}

int main()
{
    book books;
    init_books(&books);
    add_book(&books,"Am Ende steht Gott", "Jesus Christus", 123456, &book2);



    printf("Hello world!\n");
    print_bookall(&books);
    return 0;
}

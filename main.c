#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 50

typedef struct bookdb
{
    char  title[MAXLENGTH];
    char  author[MAXLENGTH];
    int   isbn;
    struct bookdb* next;
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
    book* last = books->next;
    printf("Print out all Books of library:\n");
    printf("------------------------------------------------------------------\n");
    do
    {
        printf("Titel: %s\n", last->title);
        printf("Autor: %s\n", last->author);
        printf("ISBN: %i\n", last->isbn);
        printf("------------------------------------------------------------------\n");
        last = last->next;
    }while (last != NULL);


}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], int isbn)
{
    book* last = books;
    book* new;
    new = malloc(sizeof(book));

    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
    strncpy(new->title, title, MAXLENGTH-1);
    strncpy(new->author, author, MAXLENGTH-1);
    new->isbn = isbn;
    new->next = NULL;
    books->bookcount++;
    printf("New book was added! Current number of books: %i\n",books->bookcount);
    printf("------------------------------------------------------------------\n");
    return 0;
}

int main()
{
    book books;
    init_books(&books);

    printf("##################################################################\n");
    printf("########## Welcome in the national library of Austria! ###########\n");
    printf("##################################################################\n");

    add_book(&books,"Am Ende steht Gott", "Jesus Christus", 123456);
    //iprint_bookall(&bookdb, bookdb.bookcount);
    add_book(&books,"C-Tour with Mike", "Mike Carl Gringer", 79886065);
    //print_bookall(&bookdb, bookdb.bookcount);
    add_book(&books,"Fresh Meat", "James Miller", 45677663);

    print_bookall(&books);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 50

typedef struct bookdb
{
    char title[MAXLENGTH];
    char author[MAXLENGTH];
    char language[MAXLENGTH];
    long long isbn;
    int pages;
    int bookcount;
    struct bookdb* next;
} book;

void init_books(book *books)
{
    bzero(books->title, MAXLENGTH);
    bzero(books->author, MAXLENGTH);
    bzero(books->language, MAXLENGTH);
    books->isbn = 0;
    books->pages =0;
    books->next = NULL;
    books->bookcount = 0;
}

void print_allbooks(book *books)
{
    book* last = books->next;
    printf("Print out all Books of library:\n");
    printf("------------------------------------------------------------------\n");
    do
    {
        printf("TITLE: %s\n", last->title);
        printf("AUTHOR: %s\n", last->author);
        printf("LANGUAGE: %s", last->language);
        printf("ISBN %llu\n", last->isbn);
        printf("PAGES %i\n", last->pages);
        printf("------------------------------------------------------------------\n");
        last = last->next;
    }while (last != NULL);
}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], char  language[MAXLENGTH], long long isbn, int pages)
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
    strncpy(new->language, language, MAXLENGTH-1);
    new->isbn = isbn;
    new->pages = pages;
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

    add_book(&books,"Milk and Honey", "Rupi Kaur", "English", 144947425, 208);
    //iprint_bookall(&bookdb, bookdb.bookcount);
    add_book(&books,"Little Moments of Love", "Catana Chetwynd", "English", 1449492975, 160);
    //print_allbooks(&bookdb, bookdb.bookcount);
    add_book(&books,"Cien anos de soledad", "Gabriel Garcia Marquez", "Spanish", 8497592204, 494);

    add_book(&books, "Der Flüstermann", "Catherine Shepherd", "German", 3944676203 ,334);

    add_book(&books, "Sangue giusto", "Franesca Melandri", "Italian", 8817092150, 527);

    add_book(&books, "Mr. Fake", "Sophia Chase", "German", 1983311421,303);

    print_allbooks(&books);
    return 0;
}

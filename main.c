#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXLENGTH 50

typedef struct bookdb //STRUCT OF A BOOK
{
    char title[MAXLENGTH]; //VARIABLE FOR BOOKTITLE
    char author[MAXLENGTH];  //VARIABLE FOR AUTHOR
    char language[MAXLENGTH];  //VARIABLE FOR BOOK LANGUAGE
    long long isbn;  //VARIABLE FOR ISBN
    int pages;  //VARIABLE FOR BOOK PAGES
    struct bookdb* next;  //POINTER TO NEXT BOOK OF LIBRARY
    int bookcount;  //VARIABLE FOR AMOUNT OF ALL BOOKS
    bool isinlibrary; // 0 = is not vorrowed 1 is borrowed
} book;

void init_books(book *books) //INIT THE BOOK STRUCT
{
    bzero(books->title, MAXLENGTH); //FILL BOOK TITLE WITH ZEROS
    bzero(books->author, MAXLENGTH); //FILL BOOK AUTHOR WITH ZEROS
    bzero(books->language, MAXLENGTH); //FILL BOOK LANGUAGE WITH ZEROS
    books->isbn = 0; //SET ISBN TO ZERO
    books->pages = 0; //SET BOOK PAGES TO ZERO
    books->next = NULL; //SET POINTER OF THE NEXT BOOK TO NULL
    books->bookcount = 0; //SET BOOK COUNT TO ZERO
    books->isinlibrary = false; //SET
}

void print_allbooks(book *books) //PRINT ALL BOOKS OF THE LIBRARY
{
    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    printf("Print out all Books of library:\n"); //PRINT OUT A TEXT LINE
    printf("------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
    do
    {
        printf("TITLE: %s\n", last->title); //PRINT OUT THE BOOK TITLE OF THE CURRENT BOOK
        printf("AUTHOR: %s\n", last->author); //PRINT OUT THE AUTHOR OF THE CURRENT BOOK
        printf("LANGUAGE: %s", last->language); //PRINT OUT THE BOOK LANGUAGE OF THE CURRENT BOOK
        printf("ISBN %llu\n", last->isbn); //PRINT OUT THE ISBN OF THE CURRENT BOOK
        printf("PAGES %i\n", last->pages); //PRINT OUT THE BOOK PAGES OF THE CURRENT BOOK
        printf("------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST IS NULL
}

void print_allbooks_inlibrary(book *books)
{

}

void print_allborrowedbooks(book *books)
{

}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], char  language[MAXLENGTH], long long isbn, int pages) //ADD A NEW BOOK TO THE LIBRARY
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
    new->isinlibrary = true;
    books->bookcount++;
    printf("New book was added! Current number of books: %i\n",books->bookcount);
    printf("------------------------------------------------------------------\n");
    return 0;
}

int borrow_book(book *books, long long isbn)
{
    book* last = books;
    while(last->isbn != isbn)
    {
        last = last->next;
    }

    if (last->isinlibrary == false)
    {
        printf("The book \"%s\" is already borrowed!\n", last->title);
        printf("------------------------------------------------------------------\n");
    }
    else
    {
        last->isinlibrary = false;
        printf("The book \"%s\" is now borrowed!\n", last->title);
        printf("------------------------------------------------------------------\n");
    }

    return 0;
}

int return_book(book *books, long long isbn)
{
    book* last = books;
    while(last->isbn != isbn)
    {
        last = last->next;
    }

    if (last->isinlibrary == true)
    {
        printf("The book \"%s\" was never borrowed!\n", last->title);
        printf("------------------------------------------------------------------\n");
    }
    else
    {
        last->isinlibrary = true;
        printf("The book \"%s\" is now returned!\n", last->title);
        printf("------------------------------------------------------------------\n");
    }

    return 0;
}

int delete_book()
{

    return 0;
}


int main()
{
    book books; //CREATE A NEW STRUCT FOR FIRST BOOK
    init_books(&books); //INIT THE NEW STRUCT

    printf("##################################################################\n");
    printf("########## Welcome in the national library of Austria! ###########\n");
    printf("##################################################################\n");

    add_book(&books,"Milk and Honey", "Rupi Kaur", "English", 144947425, 208); //ADD A BOOK

    add_book(&books,"Little Moments of Love", "Catana Chetwynd", "English", 1449492975, 160); //ADD A BOOK

    add_book(&books,"Cien anos de soledad", "Gabriel Garcia Marquez", "Spanish", 8497592204, 494); //ADD A BOOK

    add_book(&books, "Der Flüstermann", "Catherine Shepherd", "German", 3944676203 ,334); //ADD A BOOK

    borrow_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    return_book(&books, 3944676203);
    return_book(&books, 3944676203);
    borrow_book(&books, 3944676203);

    add_book(&books, "Sangue giusto", "Franesca Melandri", "Italian", 8817092150, 527); //ADD A BOOK

    add_book(&books, "Mr. Fake", "Sophia Chase", "German", 1983311421, 303); //ADD A BOOK

    add_book(&books, "Lord of the Rings", "J.R.R. Tolkien", "English", 9780261102385, 1293); //ADD A BOOK

    add_book(&books, "Nachts an der Seine", "Jojo Moyes", "German", 3499290707, 144); //ADD A BOOK

   // print_allbooks(&books); //PRINT ALL BOOKS OF THE LIBRARY
    return 0;
}

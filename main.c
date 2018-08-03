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

void print_book(book *books)
{
    printf("TITLE: %s\n", books->title); //PRINT OUT THE BOOK TITLE OF THE CURRENT BOOK
    printf("AUTHOR: %s\n", books->author); //PRINT OUT THE AUTHOR OF THE CURRENT BOOK
    printf("LANGUAGE: %s\n", books->language); //PRINT OUT THE BOOK LANGUAGE OF THE CURRENT BOOK
    printf("ISBN: %llu\n", books->isbn); //PRINT OUT THE ISBN OF THE CURRENT BOOK
    printf("PAGES: %i\n", books->pages); //PRINT OUT THE BOOK PAGES OF THE CURRENT BOOK
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
}

int print_allbooks(book *books) //PRINT ALL BOOKS OF THE LIBRARY
{
    if (books == NULL)
    {

    }

    if (books->bookcount == 0)
    {
        printf("There are currently no books in the library.\n"); //PRINT OUT A TEXT LINE
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    printf("Print out all books of library:\n"); //PRINT OUT A TEXT LINE
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
    do
    {
        print_book(last);
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST IS NULL

    return 0;
}

int print_allbooks_inlibrary(book *books)
{
    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    int counter = 0;

    if (books->bookcount == 0)
    {
        printf("There are currently no books in the library.\n"); //PRINT OUT A TEXT LINE
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    printf("Print out all books in the library:\n"); //PRINT OUT A TEXT LINE
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    do
    {
        if(last->isinlibrary == true)
        {
            print_book(last);
            counter++;
        }
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST IS NULL

    if(counter == 0)
    {
        printf("INFO: All books are already borrowed.\n"); //PRINT OUT A TEXT LINE
    }

    return 0;
}

int print_allbooks_notinlibrary(book *books)
{
    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    int counter = 0;

    if (books->bookcount == 0)
    {
        printf("There are currently no books in the library.\n"); //PRINT OUT A TEXT LINE
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    printf("Print out all borrowed books of library:\n"); //PRINT OUT A TEXT LINE
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    do
    {
        if(last->isinlibrary == false)
        {
            print_book(last);
            counter++;
        }
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST IS NULL

    if(counter == 0)
    {
        printf("INFO: All books are in the library.\n"); //PRINT OUT A TEXT LINE
    }

    return 0;
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
    printf("New book \"%s\" was added!\nCurrent number of books: %i\n", new->title, books->bookcount);
    printf("------------------------------------------------------------------------------------\n");
    return 0;
}

int borrow_book(book *books, long long isbn)
{
    book* last = books;
    while(last->isbn != isbn)
    {
        last = last->next;
        if (last->next == NULL && last->isbn != isbn)
        {
            printf("The book with ISBN \"%llu\" is not in the library!\n", isbn);
            printf("------------------------------------------------------------------------------------\n");
            return 0;
        }
    }

    if (last->isinlibrary == false)
    {
        printf("The book \"%s\" is already borrowed!\n", last->title);
    }
    else
    {
        last->isinlibrary = false;
        printf("The book \"%s\" is now borrowed!\n", last->title);
    }
    printf("------------------------------------------------------------------------------------\n");
    return 0;
}

int return_book(book *books, long long isbn)
{
    book* last = books;
    while(last->isbn != isbn)
    {
        last = last->next;
        if (last->next == NULL && last->isbn != isbn)
        {
            printf("The book with ISBN \"%llu\" is not in the library!\n", isbn);
            printf("------------------------------------------------------------------------------------\n");
            return 0;
        }
    }

    if (last->isinlibrary == true)
    {
        printf("The book \"%s\" was never borrowed!\n", last->title);
    }
    else
    {
        last->isinlibrary = true;
        printf("The book \"%s\" is now returned!\n", last->title);

    }
    printf("------------------------------------------------------------------------------------\n");
    return 0;
}

int delete_book(book *books, long long isbn)
{
    book* pre = books; //
    book* current = books->next; //

    while(current->isbn != isbn)
    {
        pre = current;
        current = current->next;
        if (current->next == NULL && current->isbn != isbn)
        {
            printf("The book with ISBN \"%llu\" is not in the library!\n", isbn);
            printf("------------------------------------------------------------------------------------\n");
            return 0;
        }
    }

    if (current->next == NULL)
    {
        pre->next = NULL;
    }
    else
    {
        pre->next = current->next;
    }

    printf("The book \"%s\" was deleted!\nCurrent number of books: %i\n", current->title, books->bookcount);
    printf("------------------------------------------------------------------------------------\n");

    free(current);
    books->bookcount--;

    return 0;
}

int delete_allbooks(book *books)
{
    while (books->bookcount != 0)
    {
        delete_book(books, books->next->isbn);
    }

    printf("All books are deleted!\n"); //PRINT OUT A TEXT LINE
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
    return 0;
}

int main()
{
    book books; //CREATE A NEW STRUCT FOR FIRST BOOK
    init_books(&books); //INIT THE NEW STRUCT

    printf("####################################################################################\n");
    printf("################### Welcome in the national library of Austria! ####################\n");
    printf("####################################################################################\n");
    printf("------------------------------------------------------------------------------------\n");

    add_book(&books,"Milk and Honey", "Rupi Kaur", "English", 144947425, 208); //ADD A BOOK
    add_book(&books,"Little Moments of Love", "Catana Chetwynd", "English", 1449492975, 160); //ADD A BOOK
    add_book(&books,"Cien anos de soledad", "Gabriel Garcia Marquez", "Spanish", 8497592204, 494); //ADD A BOOK
    borrow_book(&books, 144947425);
    borrow_book(&books, 1449492975);
    borrow_book(&books, 8497592204);
    print_allbooks_notinlibrary(&books);
   /* add_book(&books, "Der Flüstermann", "Catherine Shepherd", "German", 3944676203 ,334); //ADD A BOOK
    borrow_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    return_book(&books, 3944676203);
    return_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    delete_book(&books, 3944676203);
    return_book(&books, 3944676203);
    borrow_book(&books, 3944676203);
    add_book(&books, "Sangue giusto", "Franesca Melandri", "Italian", 8817092150, 527); //ADD A BOOK
    add_book(&books, "Mr. Fake", "Sophia Chase", "German", 1983311421, 303); //ADD A BOOK
    add_book(&books, "Lord of the Rings", "J.R.R. Tolkien", "English", 9780261102385, 1293); //ADD A BOOK
    add_book(&books, "Nachts an der Seine", "Jojo Moyes", "German", 3499290707, 144); //ADD A BOOK
    delete_book(&books, 3499290707);
    return_book(&books, 9780261102385);
    borrow_book(&books, 9780261102385);
    return_book(&books, 9780261102385);
    print_allbooks(&books); //PRINT ALL BOOKS OF THE LIBRARY
    borrow_book(&books, 8497592204);
    borrow_book(&books, 3944676203);
    borrow_book(&books, 144947425);
    print_allbooks_notinlibrary(&books);
    delete_allbooks(&books);
    print_allbooks(&books);*/

    return 0;
}

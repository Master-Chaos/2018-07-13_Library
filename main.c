#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXLENGTH 50 //DEFINE MAXIMUM LENGTH

typedef struct bookdb //STRUCT OF A BOOK
{
    char title[MAXLENGTH]; //VARIABLE FOR TITLE OF A BOOK
    char author[MAXLENGTH];  //VARIABLE FOR AUTHOR
    char language[MAXLENGTH];  //VARIABLE FOR BOOK LANGUAGE
    long long isbn;  //VARIABLE FOR ISBN
    int pages;  //VARIABLE FOR BOOK PAGES
    struct bookdb* next;  //POINTER TO NEXT BOOK OF LIBRARY
    int bookCount;  //VARIABLE FOR AMOUNT OF ALL BOOKS
    bool isInLibrary; // BOOL FOR CHECK IF IS A BOOK IN THE LIBRARY OR IT IS BORROWED
} book;

int init_books(book *books) //INIT THE BOOK
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    bzero(books->title, MAXLENGTH); //FILL BOOK TITLE WITH ZEROS
    bzero(books->author, MAXLENGTH); //FILL BOOK AUTHOR WITH ZEROS
    bzero(books->language, MAXLENGTH); //FILL BOOK LANGUAGE WITH ZEROS
    books->isbn = 0; //SET ISBN TO ZERO
    books->pages = 0; //SET BOOK PAGES TO ZERO
    books->next = NULL; //SET POINTER OF THE NEXT BOOK TO NULL
    books->bookCount = 0; //SET BOOK COUNT TO ZERO
    books->isInLibrary = false; //SET BOOK IS IN THE LIBRARY

    return 0;
}

int print_book(book *books) //PRINT A BOOK OF THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    printf("TITLE: %s\n", books->title); //PRINT OUT THE BOOK TITLE OF THE CURRENT BOOK
    printf("AUTHOR: %s\n", books->author); //PRINT OUT THE AUTHOR OF THE CURRENT BOOK
    printf("LANGUAGE: %s\n", books->language); //PRINT OUT THE BOOK LANGUAGE OF THE CURRENT BOOK
    printf("ISBN: %llu\n", books->isbn); //PRINT OUT THE ISBN OF THE CURRENT BOOK
    printf("PAGES: %i\n", books->pages); //PRINT OUT THE BOOK PAGES OF THE CURRENT BOOK
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    return 0;
}

int print_all_books(book *books) //PRINT ALL BOOKS OF THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    if (books->bookCount == 0) //CHECK IF BOOKS ARE BE IN THE LIBRARY
    {
        printf("INFO: There are currently no books in the library.\n"); //PRINT OUT MESSAGE THAT NO BOOKS ARE IN THE LIBRARY
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    printf("Print out all books of library:\n"); //PRINT OUT MESSAGE THAT NOW ALL BOOKS WILL BE PRINT
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
    do
    {
        print_book(last); //CALL FUNCTION TO PRINT OUT ONE BOOK
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST BOOK IS PRINTED (LAST = NULL)

    return 0;
}

int print_all_books_InLibrary(book *books) //PRINT ALL BOOKS THAT ARE IN THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    int counter = 0; //VARIABLE FOR COUNT ALL BOOKS IN THE LIBRARY

    if (books->bookCount == 0) //CHECK IF BOOKS ARE IN THE LIBRARY
    {
        printf("INFO: There are currently no books in the library.\n"); //PRINT OUT MESSAGE THAT NO BOOKS ARE IN THE LIBRARY
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    printf("Print out all books in the library:\n"); //PRINT OUT MESSAGE THAT NOW ALL BOOKS WILL BE PRINT
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    do
    {
        if(last->isInLibrary == true) //CHECK IF A BOOK IS IN THE LIBRARY
        {
            print_book(last); //CALL FUNCTION TO PRINT OUT ONE BOOK
            counter++; //INCREASE COUNTER IF A BOOK IS IN THE LIBRARY
        }
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST BOOK IS PRINTED (LAST = NULL)

    if(counter == 0) //CHECK IF IS NO BOOK IN THE LIBRARY
    {
        printf("INFO: All books are already borrowed.\n"); //PRINT OUT MESSAGE THAT ALL BOOKS ARE BORROWED
    }

    return 0;
}

int print_all_books_NotInLibrary(book *books) //PRINT ALL BOOKS THAT ARE BORROWED
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* last = books->next; //SAVE THE FIRST BOOK IN STRUCT LAST
    int counter = 0; //VARIABLE FOR COUNT ALL BOOKS IN THE LIBRARY

    if (books->bookCount == 0) //CHECK IF BOOKS ARE IN THE LIBRARY
    {
        printf("INFO: There are currently no books in the library.\n"); //PRINT OUT MESSAGE THAT NO BOOKS ARE IN THE LIBRARY
        printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
        return 0;
    }

    printf("Print out all borrowed books of library:\n"); //PRINT OUT MESSAGE THAT NOW ALL BORROWED BOOKS WILL BE PRINT
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    do
    {
        if(last->isInLibrary == false) //CHECK IF A BOOK IS NOT IN THE LIBRARY
        {
            print_book(last);  //CALL FUNCTION TO PRINT OUT ONE BOOK
            counter++; //INCREASE COUNTER IF A BOOK IS NOT IN THE LIBRARY
        }
        last = last->next; //SAVE LAST->NEXT IN LAST TO GO TO THE NEXT BOOK
    }while (last != NULL); //END PRINTING IF LAST IS NULL

    if(counter == 0) //CHECK IF IS NO BOOK IN THE LIBRARY
    {
        printf("INFO: All books are in the library.\n"); //PRINT OUT MESSAGE THAT ALL BOOKS ARE BE IN THE LIBRARY
    }

    return 0;
}

int add_book(book *books, char title[MAXLENGTH], char  author[MAXLENGTH], char  language[MAXLENGTH], long long isbn, int pages) //ADD A NEW BOOK TO THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* last = books; //BOOK STRUCT FOR THE LAST BOOK
    book* new; //CREATE A NEW BOOK STRUCT
    new = malloc(sizeof(book)); //ALLOCATE MEMORY FOR THE NEW BOOK

    while(last->next != NULL) //LOOP TO GET THE LAST BOOK
    {
        last = last->next; //REPLACE CURRENT BOOK BY NEXT BOOK IF CURRENT BOOK IS NOT THE LAST BOOK
    }
    last->next = new; //BY LAST BOOK SET POINTER TO THE NEW BOOK
    strncpy(new->title, title, MAXLENGTH-1); //SET BOOK TITLE OF THE NEW BOOK
    strncpy(new->author, author, MAXLENGTH-1); //SET AUTHOR OF THE NEW BOOK
    strncpy(new->language, language, MAXLENGTH-1); //SET LANGUAGE OF THE NEW BOOK
    new->isbn = isbn; //SET ISBN OF THE NEW BOOK
    new->pages = pages; //SET PAGES TITLE OF THE NEW BOOK
    new->next = NULL; //NOW THE NEW BOOK IS THE LAST BOOK IN THE ROW
    new->isInLibrary = true; //THE BOOK IS AVAILABLE IN THE LIBRARY
    books->bookCount++; //INCREASE BOOK COUNT BECAUSE A NEW BOOK WAS ADDED
    printf("New book \"%s\" was added!\nCurrent number of books: %i\n", new->title, books->bookCount); //PRINT OUT MESSAGE WITH BOOK TITLE AND CURRENT NUMBER OF BOOKS THAT A NEW BOOK WAS ADDED
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    return 0;
}

int borrow_book(book *books, long long isbn) //BORROW A BOOK OF THE LIBRARY BY ISBN
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* last = books; //BOOK STRUCT FOR THE LAST BOOK
    while(last->isbn != isbn) //LOOP TO GET THE BOOK THAT WE WILL BORROW
    {
        last = last->next; //REPLACE CURRENT BOOK BY NEXT BOOK IF CURRENT BOOK IS NOT THE LAST BOOK
        if (last->next == NULL && last->isbn != isbn) //CHECK IF THE LOOP IS BY THE LAST BOOK AND THE ORDERED BOOK DOES NOT EXIST IN THE LIBRARY
        {
            printf("INFO: The book with ISBN \"%llu\" is not in the library!\n", isbn); //PRINT OUT MESSAGE THAT THE ORDERED BOOK IS NOT IN THE LIBRARY
            printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
            return 0;
        }
    }

    if (last->isInLibrary == false) //CHECK IF A BOOK IS ALREADY BORROWED
    {
        printf("The book \"%s\" is already borrowed!\n", last->title); //PRINT OUT MESSAGE THAT THE BOOK IS ALREADY BORROWED
    }
    else
    {
        last->isInLibrary = false; //BORROW THE BOOK BY SET A FLAG TO FALSE
        printf("The book \"%s\" is now borrowed!\n", last->title); //PRINT OUT MESSAGE THAT THE BOOK IS NOW BORROWED
    }
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    return 0;
}

int return_book(book *books, long long isbn) //RETURN A BOOK OF THE LIBRARY BY ISBN
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* last = books; //BOOK STRUCT FOR THE LAST BOOK
    while(last->isbn != isbn) //LOOP TO GET THE BOOK THAT WE WILL BE RETURN
    {
        last = last->next; //REPLACE CURRENT BOOK BY NEXT BOOK IF CURRENT BOOK IS NOT THE LAST BOOK
        if (last->next == NULL && last->isbn != isbn) //CHECK IF THE LOOP IS BY THE LAST BOOK AND THE ORDERED BOOK DOES NOT EXIST IN THE LIBRARY
        {
            printf("INFO: The book with ISBN \"%llu\" is not in the library!\n", isbn); //PRINT OUT MESSAGE THAT THE ORDERED BOOK IS NOT IN THE LIBRARY
            printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
            return 0;
        }
    }

    if (last->isInLibrary == true) //CHECK IF A BOOK WAS NEVER BORROWED
    {
        printf("The book \"%s\" was never borrowed!\n", last->title); //PRINT OUT MESSAGE THAT THE BOOK WAS NEVER BORROWED
    }
    else
    {
        last->isInLibrary = true; //RETURN THE BOOK BY SET A FLAG TO TRUE
        printf("The book \"%s\" is now returned!\n", last->title); //PRINT OUT MESSAGE THAT THE BOOK IS NOW RETURNED

    }
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    return 0;
}

int delete_book(book *books, long long isbn) //DELETE A BOOK FROM THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    book* previously = books; //BOOK STRUCT FOR THE PREVIOUSLY BOOK
    book* current = books->next; //BOOK STRUCT FOR THE CURRENT BOOK

    while(current->isbn != isbn) //LOOP TO GET THE BOOK THAT WE WILL BE DELETE
    {
        previously = current; //SAVE CURRENT BOOK AS THE PREVIOUSLY BOOK
        current = current->next; //SAVE NEXT BOOK AS THE CURRENT BOOK
        if (current->next == NULL && current->isbn != isbn) //CHECK IF THE LOOP IS BY THE LAST BOOK AND THE ORDERED BOOK DOES NOT EXIST IN THE LIBRARY
        {
            printf("INFO: The book with ISBN \"%llu\" is not in the library!\n", isbn); //PRINT OUT MESSAGE THAT THE ORDERED BOOK IS NOT IN THE LIBRARY
            printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE
            return 0;
        }
    }

    if (current->next == NULL) //CHECK IF THE CURRENT BOOK IS THE LAST BOOK
    {
        previously->next = NULL; //SET POINTER TO NEXT BOOK OF THE PREVIOUSLY BOOK AS THE LAST BOOK
    }
    else
    {
        previously->next = current->next; //SET POINTER TO NEXT BOOK OF THE PREVIOUSLY BOOK TO THE BOOK AFTER THE CURRENT BOOK
    }

    printf("The book \"%s\" was deleted!\nCurrent number of books: %i\n", current->title, books->bookCount); //PRINT OUT MESSAGE THAT THE BOOK IS NOW DELETED
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    free(current); //FREE MEMORY OF THE DELETED BOOK
    books->bookCount--; //DECREASE BOOK COUNTER BECAUSE A BOOK IS DELETED

    return 0;
}

int delete_all_books(book *books) //DELETE ALL BOOKS OF THE LIBRARY
{
    if (books == NULL) //CHECK IF FUNCTION GETS AN NULL-POINTER
    {
        printf("ERROR 1: NULL-POINTER.\n"); //PRINT A ERROR MESSAGE FOR NULL-POINTER
        return 1; //RETURN THE ERROR-CODE
    }

    while (books->bookCount != 0) //DELETE ALL BOOKS UNTIL BOOK COUNTER IS ZERO
    {
        delete_book(books, books->next->isbn); //CALL FUNCTION TO DELETE A BOOK
    }

    printf("All books are deleted!\n"); //PRINT OUT MESSAGE THAT ALL BOOKS ARE DELETED
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    return 0;
}

int main()
{
    book books; //CREATE A NEW STRUCT FOR FIRST BOOK
    init_books(&books); //INIT THE NEW STRUCT

    printf("####################################################################################\n"); //PRINT OUT A SEPARATIONS LINE
    printf("################### Welcome in the national library of Austria! ####################\n"); //PRINT OUT A SEPARATIONS LINE
    printf("####################################################################################\n"); //PRINT OUT A SEPARATIONS LINE
    printf("------------------------------------------------------------------------------------\n"); //PRINT OUT A SEPARATIONS LINE

    add_book(&books,"Milk and Honey", "Rupi Kaur", "English", 144947425, 208); //ADD A BOOK
    add_book(&books,"Little Moments of Love", "Catana Chetwynd", "English", 1449492975, 160); //ADD A BOOK
    add_book(&books,"Cien anos de soledad", "Gabriel Garcia Marquez", "Spanish", 8497592204, 494); //ADD A BOOK
    borrow_book(&books, 144947425); //BORROW A BOOK
    borrow_book(&books, 1449492975); //BORROW A BOOK
    borrow_book(&books, 8497592204); //BORROW A BOOK
    print_all_books_InLibrary(&books); //PRINT ALL BOOKS IN THE LIBRARY
    print_all_books_NotInLibrary(&books); //PRINT ALL BORROWED BOOKS
    add_book(&books, "Der Flüstermann", "Catherine Shepherd", "German", 3944676203 ,334); //ADD A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    return_book(&books, 3944676203); //RETURN A BOOK
    return_book(&books, 3944676203); //RETURN A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    delete_book(&books, 3944676203); //DELETE A BOOK
    return_book(&books, 3944676203); //RETURN A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    add_book(&books, "Sangue giusto", "Franesca Melandri", "Italian", 8817092150, 527); //ADD A BOOK
    add_book(&books, "Mr. Fake", "Sophia Chase", "German", 1983311421, 303); //ADD A BOOK
    add_book(&books, "Lord of the Rings", "J.R.R. Tolkien", "English", 9780261102385, 1293); //ADD A BOOK
    add_book(&books, "Nachts an der Seine", "Jojo Moyes", "German", 3499290707, 144); //ADD A BOOK
    delete_book(&books, 3499290707); //DELETE A BOOK
    return_book(&books, 9780261102385); //RETURN A BOOK
    borrow_book(&books, 9780261102385); //BORROW A BOOK
    return_book(&books, 9780261102385); //RETURN A BOOK
    print_all_books(&books); //PRINT ALL BOOKS OF THE LIBRARY
    borrow_book(&books, 8497592204); //BORROW A BOOK
    borrow_book(&books, 3944676203); //BORROW A BOOK
    borrow_book(&books, 144947425); //BORROW A BOOK
    print_all_books_NotInLibrary(&books); //PRINT ALL BORROWED BOOKS
    delete_all_books(&books); //DELETE ALL BOOKS
    print_all_books(&books); //PRINT ALL BOOK

    return 0;
}

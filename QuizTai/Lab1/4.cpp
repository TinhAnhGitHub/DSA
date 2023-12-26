#include <iostream>
#include <cstring>
using namespace std;


class Book
{
private:
    char* title; 
    char* authors; 
    int publishingYear; 
public: 
   // some method
};

class Book
{
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book()
    {
        /*
         * STUDENT ANSWER
         * TODO: set zero publishingYear and null pointer
         */
        this->publishingYear = 0;
        title = nullptr;
        authors = nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
        this->title = new char[strlen(title) + 1];
        strcpy( this->title , title);
        
        this->authors = new char[strlen(authors) + 1];
        strcpy( this->authors , authors);
        this->publishingYear = publishingYear;
    }

    Book(const Book &book)
    {
        /*
         * STUDENT ANSWER
         * TODO: deep copy constructor
         */
        this->title = new char [strlen(book.title) + 1];
        strcpy( this->title, book.title);
        this->authors = new char [strlen(book.authors) + 1];
        strcpy( this->authors, book.authors);
        this->publishingYear = book.publishingYear;
        
         
    }
    
    void setTitle(const char* title)
    {
        /*
         * STUDENT ANSWER
         */
         delete [] this->title;
         this->title = new char [strlen(title) + 1];
         strcpy( this->title, title);
         
    }

    void setAuthors(const char* authors)
    {
        /*
         * STUDENT ANSWER
         */
        delete [] this->authors;
         this->authors = new char [strlen(authors) + 1];
         strcpy( this->authors, authors);
    }

    void setPublishingYear(int publishingYear)
    {
        /*
         * STUDENT ANSWER
         */
         this->publishingYear = publishingYear;
    }

    char* getTitle() const
    {
        /*
         * STUDENT ANSWER
         */
         return this->title;
    }

    char* getAuthors() const
    {
        /*
         * STUDENT ANSWER
         */
         return this->authors;
    }

    int getPublishingYear() const
    {
        /*
         * STUDENT ANSWER
         */
        return  this->publishingYear;
    }

    ~Book()
    {
        /*
         * STUDENT ANSWER
         */
         delete [] title;
         delete [] authors;
    }

    void printBook(){
        printf("%s\n%s\n%d", this->title, this->authors, this->publishingYear);
    }
};
#ifndef _BOOK_HPP_
#define _BOOK_HPP_

#include <iostream>
#include <string>

class Invalid{};     // for throwing when isbn is invalid

class ISBN
{
    friend bool operator==(const ISBN &i1, const ISBN &i2);
public:    
    ISBN(std::string n1, std::string n2, std::string n3, char x);
    std::string ISBNString() const; 
private:
    std::string n1;
    std::string n2;
    std::string n3;
    char x;
};

bool is_isbn(std::string n1, std::string n2, std::string n3, char x);  // true for valid ISBN number

enum class Genre {fiction=0, nonfiction, periodical, biography, children, unknown};

class Book
{
    friend std::ostream &operator<<(std::ostream &os, const Book &bb);
    friend bool operator==(const Book &b1, const Book &b2);
    friend bool operator!=(const Book &b1, const Book &b2);

public:
    // access data
    ISBN GetIsbn() const {return isbn;};
    std::string GetTitle() const {return title;};
    std::string GetAuthor() const {return author;};
    std::string GetCopyright() const {return copyright;};
    Genre GetGenre() const {return genre;};
    bool GetcheckOutStatus() const {return checkOutStatus;};

    // check in and check out
    // TODO check current status before trying to make changes
    void CheckIn();
    void CheckOut();
    
    // verify isbn validity (m n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string)
    // bool VerifyIsbn(std::string isbnCandidate);

    // constructor
    Book();
    Book(ISBN isbn, std::string title, std::string author, std::string copyright, Genre genre, bool checkOutStatus);

private:
    ISBN isbn;
    std::string title;
    std::string author;
    std::string copyright;
    Genre genre;
    bool checkOutStatus;
};

#endif
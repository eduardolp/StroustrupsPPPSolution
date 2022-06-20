#include <iostream>
#include <string>

class Invalid{};     // for throwing when isbn is invalid

class ISBN
{
    friend bool operator==(const ISBN &i1, const ISBN &i2);
public:    
    ISBN(std::string n1, std::string n2, std::string n3, char x);
    std::string ISBNString(); 
private:
    std::string n1;
    std::string n2;
    std::string n3;
    char x;
};

bool is_isbn(std::string n1, std::string n2, std::string n3, char x);  // true for valid ISBN number

class Book
{
public:
    // access data
    ISBN GetIsbn() const {return isbn;};
    std::string GetTitle() const {return title;};
    std::string GetAuthor() const {return author;};
    std::string GetCopyright() const {return copyright;};
    bool GetcheckOutStatus() const {return checkOutStatus;};

    // check in and check out
    // TODO check current status before trying to make changes
    void CheckIn() {checkOutStatus = false;};
    void CheckOut() {checkOutStatus = true;};
    
    // verify isbn validity (m n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string)
    // bool VerifyIsbn(std::string isbnCandidate);

    // constructor
    Book();
    Book(ISBN isbn, std::string title, std::string author, std::string copyright, bool checkOutStatus);

private:
    ISBN isbn;
    std::string title;
    std::string author;
    std::string copyright;
    bool checkOutStatus;
};
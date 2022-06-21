#include "Book.hpp"
#include <cctype>
#include <algorithm>

// true for valid ISBN number
bool VerifyIsbn(std::string n1, std::string n2, std::string n3, char x)
{
    if(std::all_of(n1.begin(), n1.end(), ::isdigit) && 
        std::all_of(n2.begin(), n2.end(), ::isdigit) && 
        std::all_of(n3.begin(), n3.end(), ::isdigit) && std::isalnum(x))
        {
            return true;
        }
    else
        return false;
}

ISBN::ISBN(std::string n1, std::string n2, std::string n3, char x) 
    : n1{n1}, n2{n2}, n3{n3}, x{x}
{
    if(!VerifyIsbn(n1, n2, n3, x))
        throw Invalid{};
}

std::string ISBN::ISBNString() const
{
    return n1 + "-" + n2 + "-" + n3 + "-" + x; 
}

bool operator==(const ISBN &i1, const ISBN &i2)
{
    if(i1.n1 == i2.n1 || i1.n2 == i2.n2 || i1.n3 == i2.n3 || i1.x == i2.x)
        return true;
    else
        return false;
}

Book::Book(ISBN isbn, 
            std::string title, 
            std::string author, 
            std::string copyright, 
            Genre genre,
            bool checkOutStatus)
    : isbn{isbn}, title{title}, author{author}, copyright{copyright}, genre{genre}, checkOutStatus{checkOutStatus}{}

const Book& defaultBook()
{
    static Book bb{ {"0","0","0",'a'}, "", "", "",Genre::unknown, false};
    return bb;
}

Book::Book()
    : isbn{defaultBook().GetIsbn()},
        title{defaultBook().GetTitle()},
        author{defaultBook().GetAuthor()},
        copyright{defaultBook().GetCopyright()},
        genre{defaultBook().GetGenre()},
        checkOutStatus{defaultBook().GetcheckOutStatus()}
{
}

void Book::CheckIn()
{
    if(!checkOutStatus)
        std::cout << "Book \"" << title << "\" is already in the library. Can't check it in." << std::endl;
    else
    {
        std::cout << "Checking \"" << title << "\" in." << std::endl;
        checkOutStatus = false;
    }
};

void Book::CheckOut()
{
    if(checkOutStatus)
        std::cout << "Book \"" << title << "\" not in the library. Can't check it out." << std::endl;
    else
    {
        std::cout << "Checking \"" << title << "\" out." << std::endl;
        checkOutStatus = true;
    }
};


bool operator==(const Book &b1, const Book &b2)
{
    if((b1.isbn == b2.isbn))
        return true;
    else return false;
}

bool operator!=(const Book &b1, const Book &b2)
{
    if(!(b1.isbn == b2.isbn))
        return true;
    else return false;
}

std::ostream &operator<<(std::ostream &os, const Book &bb)
{
    return os << "Book: " << bb.title << "\n" << "Author: " << bb.author << "\n" << "ISBN: " << bb.isbn.ISBNString();
}
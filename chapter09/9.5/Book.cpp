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

std::string ISBN::ISBNString()
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

Book::Book(ISBN isbn, std::string title, std::string author, std::string copyright, bool checkOutStatus)
    : isbn{isbn}, title{title}, author{author}, copyright{copyright}, checkOutStatus{checkOutStatus}{}

const Book& defaultBook()
{
    static Book bb{ {"0","0","0",'a'}, "", "", "", false};
    return bb;
}

Book::Book()
    : isbn{defaultBook().GetIsbn()},
        title{defaultBook().GetTitle()},
        author{defaultBook().GetAuthor()},
        copyright{defaultBook().GetCopyright()},
        checkOutStatus{defaultBook().GetcheckOutStatus()}
{
}
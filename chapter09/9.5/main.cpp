#include "Book.hpp"
#include "Patron.hpp"

void testBook()
{
    Book bb1{{"85","01","06170",'0'}, "O Arqueiro", "Bernard Cornwell", "Record", Genre::fiction, false};
    Book bb2{{"14", "05", "08730", '8'}, "Romeo and Juliet", "William Shakespeare", "Macmillan Education", Genre::fiction, false};
    Book bb3 = bb1;

    std::cout << bb1 <<std::endl;
    bb1.CheckOut();
    bb1.CheckOut();


    // std::cout << bb1 << std::endl;

    // std::cout << std::boolalpha << (bb1==bb2) << std::endl;
    // std::cout << std::boolalpha << (bb1==bb3) << std::endl;
}

void testPatron()
{
    Patron p1{"Eduardo", "12345", 15};
    Patron p2{"Carlos", "54356", 0};
    std::cout << p1 << std::endl;
    PatronOwes(p1);
    PatronOwes(p2);
}

int main()
{
    // testBook();
    testPatron();
    return 0;
}
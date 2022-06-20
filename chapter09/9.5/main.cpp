#include "Book.hpp"

int main()
{
    Book arqueiro{{"85","01","06170",'0'}, "O Arqueiro", "Bernard Cornwell", "Record", false};

    std::cout << "Book: " << arqueiro.GetTitle() << std::endl;
    std::cout << "ISBN: " << arqueiro.GetIsbn().ISBNString() << std::endl;
    std::cout<< "Checked out: " << std::boolalpha << arqueiro.GetcheckOutStatus() << std::endl;
    
    std::cout << "Checking book out" << std::endl;
    arqueiro.CheckOut();

    std::cout<< "Checked out: " << std::boolalpha << arqueiro.GetcheckOutStatus() << std::endl;


    return 0;
}
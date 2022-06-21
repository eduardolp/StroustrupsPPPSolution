#include "Patron.hpp"
#include <iostream>
#include <algorithm>

bool Patron::setFeeOwed(double amount)
{
    if (amount==0)
    {
        feeOwed = amount;
        return true;
    }

    else if (feeOwed + amount < 0)
    {
        std::cerr << "Fee owed can't be less than 0." << std::endl;
        return false;
    }

    feeOwed += amount;
    return true;
}

bool isValidCardNumber(std::string cardNumber)
{
    if(std::all_of(cardNumber.begin(), cardNumber.end(), ::isdigit)
        && cardNumber.size() == 5)
    {    
        return true;
    }
    else
    {
        std::cerr << "Invalid card number" << std::endl;
        return false;
    }
}

Patron::Patron(std::string name, std::string cardNumber, double feeOwed)
    : name{name}, cardNumber{cardNumber}, feeOwed{feeOwed}
{
    if(!isValidCardNumber(cardNumber))
    {
        throw InvalidCardNumber{};
    }
}

const Patron& defaultPatron()
{
    static Patron p{"", "", 0};
    return p;
}

Patron::Patron()
    : name{defaultPatron().name}, 
      cardNumber{defaultPatron().cardNumber}, 
      feeOwed{defaultPatron().feeOwed} 
{
}

std::ostream &operator<<(std::ostream &os, const Patron &p)
{
    return os << "Name: " << p.name << "\n"
              << "Card Number: " << p.cardNumber << "\n"
              << "Fee Owed: " << p.feeOwed;
}

bool PatronOwes(const Patron &p)
{
    if(p.getFeeOwed() == 0)
    {
        std::cout << "Patron \"" << p.GetName() << "\" owes nothing." << std::endl;
        return false;
    }
    else
    {
        std::cout << "Patron \"" << p.GetName() << "\" owes $" << p.getFeeOwed() << std::endl;
        return true;
    }
}
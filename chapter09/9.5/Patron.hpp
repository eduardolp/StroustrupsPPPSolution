#ifndef _PATRON_HPP_
#define _PATRON_HPP_

#include <string>
#include <iostream>

class InvalidCardNumber{};     // for throwing when cardNumber is invalid

bool isValidCardNumber(std::string cardNumber);

class Patron
{
    friend std::ostream &operator<<(std::ostream &os, const Patron & p);

public:
    std::string GetName() const {return name;} ;
    std::string GetCardNumber() const {return cardNumber;};
    double getFeeOwed() const {return feeOwed;};
    bool setFeeOwed(double amount);

    Patron();
    Patron(std::string name, std::string cardNumber, double feeOwed);
    
private:
    std::string name;
    std::string cardNumber;
    double feeOwed;
};

bool PatronOwes(const Patron &p);

#endif
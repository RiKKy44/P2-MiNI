#pragma once
#include <string>
#include <iostream>
using namespace std;

class CreditCard{
private:
    string number;
    int month;
    int year;
    int balance;
    string item;
public:
    CreditCard(string number, string date, int balance = 100);

    CreditCard(string number, const CreditCard& card, int balance =100);

    friend ostream& operator<<(ostream& out, const CreditCard& card);

    friend istream& operator>>(istream& in, CreditCard& card);

    bool operator<(const CreditCard& other) const;

    bool operator>=(const CreditCard& other) const;
};
string clean_number(string& number);

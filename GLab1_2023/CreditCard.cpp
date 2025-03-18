#include "CreditCard.hpp"
#include <string>
#include <iostream>
using namespace std;

CreditCard::CreditCard(string number,string date,int balance):item(""),balance(balance){
    month = stoi(date.substr(0,2));
    year = stoi(date.substr(3,4));
    this->number = clean_number(number);
}

CreditCard:: CreditCard(string number, const CreditCard& card, int balance):balance(balance){
    this->number = clean_number(number);
    month = card.month;
    year = card.year;
    item = card.item;
}

string clean_number(string& number){ // helper function to clean credit card number
    string temp = "";
    for (char c:number){
        if(isdigit(c)){
            temp+=c;
        }
    }
    return temp;
} 
ostream& operator<<(ostream& out, const CreditCard& card){ // cout operator
    cout<<card.number<<" - "<<card.month<<"/"<<card.year<<'\n';
    cout<<"Balance: "<<card.balance<<'\n';
    cout<<"Last bought item: "<<card.item<<'\n';
    return out;
}
istream& operator>>(istream& in, CreditCard& card){ // cin operator
    string month,year,item;
    int balance;
    cout<<"New expiration date (month): ";
    in>>card.month;
    cout<<"New expiration date (year): ";
    in>>card.year;
    std::cout << "Enter last bought item: ";
    in.ignore();
    getline(in, card.item); 
    cout<<'\n';
    return in;
}

bool CreditCard::operator<(const CreditCard& other) const{ // both < and >= operators compare two CreditCard objects by expiration date
    if (this->year<other.year) return true;
    if (this->year==other.year && this->month<other.month) return true;
    return false;
}

bool CreditCard::operator>=(const CreditCard& other) const{
    return !(*this<other);
}

void CreditCard::BuyItem(string item){
    int price = item.size();
    this->balance-=price;
    this->item = item;
}

void CreditCard::BuyItem(int n){
    for (int i=0;i<n;i++){
        BuyItem(item);
    }
}
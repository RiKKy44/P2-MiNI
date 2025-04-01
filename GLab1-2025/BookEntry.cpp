#include <iostream>
#include <string>
#include "BookEntry.h"
#include "Library.h"
using namespace std;

BookEntry::BookEntry(string title, string author, int year, int quantity, int max_quantity) : title(title), author(author), year(year), quantity(1), max_quantity(1) {}


ostream& operator<<(ostream& out, const BookEntry& book) {
	if (!book.IsAvailable()) {
		cout << "UNAVAILABLE" << endl;
	}

	cout << "Title :" << book.title << endl;
	cout << "Author: " << book.author << endl;
	cout << "Year: " << book.year << endl;
	cout << "Quantity: " << book.max_quantity << "(Available: " << book.quantity << ")" << endl;
	return out;

}

istream& operator>>(istream& in, BookEntry& book) {
	cout << "Title: ";
	in >>book.title;
	cout << endl;
	cout << "Author: ";
	in >> book.author;
	cout << endl;
	cout << "Year: ";
	in >> book.year;
	return in;
}

string BookEntry::GetAuthor() const{
	string temp = this->author;
	return temp;
}

string BookEntry::GetTitle() const {
	string temp = this->title;
	return temp;
}

bool BookEntry::IsAvailable() const{
	return quantity > 0;
}

void BookEntry::BorrowBook() {
	if (IsAvailable()) {
		quantity--;
	}
}

void BookEntry::ReturnBook(){
	if (quantity < max_quantity) {
		quantity++;
	}
}

void BookEntry::ChangeBookMaxQuantity(int q) {
	int temp = max_quantity;
	max_quantity = q;
	quantity = max_quantity - temp;
}

//float BookEntry::GetRating()const {
//	return rating;
//	
//	
//}


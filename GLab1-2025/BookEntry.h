#pragma once
#include <string>
#include <iostream>
using namespace std;
class BookEntry{
private:
	string title;
	string author;
	int year;
	int quantity;
	int max_quantity;
	float rating;
public:
	BookEntry(string title = "NOT AVAILABLE", string author = "John Doe", int year = -1,int quantity =1,int max_quantity = 1);


	friend ostream& operator<<(ostream& out, const BookEntry& book);

	friend istream& operator>>(istream& in, BookEntry& book);

	friend void GetBookTitleAndAuthor(const BookEntry& book);

	string GetTitle() const;

	string GetAuthor() const;

	bool IsAvailable() const;

	void BorrowBook();

	void ReturnBook();

	void ChangeBookMaxQuantity(int q);

	//float GetRating() const;
	//void ChangeBookRating(float newRating, int maxRating);

};
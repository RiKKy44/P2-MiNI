#include <string>
#include <iostream>
#include "BookEntry.h"
#include "Library.h"
using namespace std;

Library::Library(string name, BookEntry* bookEntries, int number): name(name), number(0){}

void Library::AddBook(BookEntry* book) {
	this->number++;
	this->bookEntries[number - 1] = book;
}

void Library::PrintCollection() const{
	for (int i = 0;i < number;i++) {
		cout<< *bookEntries[i]<<endl;
	}
}


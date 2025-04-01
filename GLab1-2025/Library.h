#pragma once
#include <string>
#include <iostream>
#include "BookEntry.h"
#define MAX_LIBRARY_CAPACITY 10
using namespace std;
class Library {
private:
	BookEntry* bookEntries[MAX_LIBRARY_CAPACITY];
	int number;
	string name;

public:
	Library(string name, BookEntry* bookEntries = {}, int number = 0);
	void AddBook(BookEntry* book);
	void PrintCollection() const;
};
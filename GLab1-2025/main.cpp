#include <iostream>
#include <iomanip>
#include <string>
#include "BookEntry.h"
#include "Library.h"
#define STAGE_1 1
#define STAGE_2 0
#define STAGE_3 1
#define STAGE_4 1
#define STAGE_5 0

#if STAGE_2
void GetBookTitleAndAuthor(const BookEntry& book)
{
	std::cout << "Acquiring book data: " << std::endl;
	std::cout << "\tTitle: " << book.GetTitle() << std::endl;
	std::cout << "\tAuthor: " << book.GetAuthor() << std::endl;
}
#endif

#if STAGE_5
void CompareBooks(const BookEntry& book1, const BookEntry& book2)
{
	std::cout << "-----------------------------------------------------BOOK COMPARER-----------------------------------------------------" << std::endl;
	std::cout << "Comparing book " << book1.GetTitle() << " written by " << book1.GetAuthor() << " to \n" <<
		book2.GetTitle() << " written by " << book2.GetAuthor() << ":" << std::endl << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << std::setw(18) << std::left << "Title" << "|";
	std::cout << std::setw(48) << std::right << book1.GetTitle()
		<< " vs. "
		<< std::setw(48) << std::left << book2.GetTitle() << std::endl;
	std::cout << std::setw(18) << std::left << "Rating (out of 5)" << "|";
	std::cout << std::setw(48) << std::right << book1.GetRating()
		<< (book1 < book2 ? "  <  " : "  >  ")
		<< std::setw(48) << std::left << book2.GetRating() << std::endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}
#endif

int main()
{
	std::cout << "--------------------------------- PART 1 ---------------------------------" << std::endl;
#if STAGE_1
	BookEntry bookAlgebra = BookEntry("Introduction to Linear Algebra",
		"Gilber Strang",
		2023);
	BookEntry bookLinearOptimization = BookEntry("Linear Programming: Foundations and Extensions",
		"Robert Vanderbei",
		2020);
	BookEntry bookCoding = BookEntry("Clean Code",
		"Robert Martin",
		2009);

	std::cout << "--PRINTING BOOK--" << std::endl;
	std::cout << bookAlgebra;
	std::cout << bookLinearOptimization;
	std::cout << bookCoding;
#endif // STAGE_1
	std::cout << "--------------------------------- PART 2 ---------------------------------" << std::endl;
#if STAGE_2
	BookEntry newBookEntry;
	std::cout << "--PRINTING OBJECT CONSTRUCTED WITH PARAMETERLESS CONSTRUCTOR--" << std::endl;
	std::cout << newBookEntry;
	std::cout << "--NEW BOOK CLI INPUT--" << std::endl;
	std::cin >> newBookEntry;
	std::cout << newBookEntry;
	std::cout << "--ACQUIRING BOOK DATA (TITLE AND AUTHOR)--" << std::endl;
	GetBookTitleAndAuthor(newBookEntry);
#endif // STAGE_2
	std::cout << "--------------------------------- PART 3 ---------------------------------" << std::endl;
#if STAGE_3
	Library library_WUT("Main Library of Warsaw University of Technology");

	// TODO: 
	 library_WUT.AddBook(&bookAlgebra);
	 library_WUT.AddBook(&bookLinearOptimization);
	 library_WUT.AddBook(&bookCoding);
	 //library_WUT.AddBook();

	std::cout << "--PRINTING COLLECTION--" << std::endl;
	library_WUT.PrintCollection();
#endif // STAGE_3
	std::cout << "--------------------------------- PART 4 ---------------------------------" << std::endl;
#if STAGE_4
	for (int i = 0;i < 4;i++) {
		bookLinearOptimization.BorrowBook();
	}
	std::cout << "--BORROWING BOOKS--" << std::endl;
	bookCoding.BorrowBook();
	bookLinearOptimization.BorrowBook();
	library_WUT.PrintCollection();

	std::cout << "--RETURNING BOOKS--" << std::endl;
	bookLinearOptimization.ReturnBook();
	library_WUT.PrintCollection();

	std::cout << "--ADDING COPIES TO THE LIBRARY AND BORROWING THEM IN LOOP--" << std::endl;
	bookCoding.ChangeBookMaxQuantity(5);
	library_WUT.PrintCollection();

	// TODO: Borrow books 4 times and print the library's collection content

	std::cout << "--FAILING TO BORROW UNAVAILABLE BOOK--" << std::endl;
	bookCoding.BorrowBook();
	// Here you can decide to return the book :)

	std::cout << "----Few days later----" << std::endl;
	std::cout << "You decide that before looking for a book for a long time, you will ask the lady at the library " <<
		"front desk if the book is available:" << std::endl;
	std::cout << "You: Is the book " << bookCoding.GetTitle() << " by " << bookCoding.GetAuthor() << " available for borrowing?" << std::endl;
	if (bookCoding.IsAvailable())
	{
		std::cout << "Librarian: Yes, of course. Here you go." << std::endl;
		bookCoding.BorrowBook();
	}
	else
		std::cout << "Librarian: No, unfortunately not yet. Please come again in a few days." << std::endl;
#endif // STAGE_4
	std::cout << "--------------------------------- PART 5 ---------------------------------" << std::endl;
#if STAGE_5
	std::cout << "--RATING CHANGE SHOULD FAIL - MAX RATING IS 5--" << std::endl;
	bookLinearOptimization.ChangeBookRating(7.0f);
	std::cout << "--CORRECT RATING CHANGES--" << std::endl;
	bookLinearOptimization.ChangeBookRating(4.8f);
	bookAlgebra.ChangeBookRating(3.4f);
	bookCoding.ChangeBookRating(8.2f, 10);
	library_WUT.PrintCollection();

	std::cout << "--COMPARING BOOKS--" << std::endl;
	CompareBooks(bookAlgebra, bookLinearOptimization);
	CompareBooks(bookLinearOptimization, bookCoding);
#endif // STAGE_5
}
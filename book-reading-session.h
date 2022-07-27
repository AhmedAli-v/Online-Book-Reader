#ifndef BOOK-READING-SESSION_H_INCLUDED
#define BOOK-READING-SESSION_H_INCLUDED
#include "book.h"
namespace BookReader {

class BookReadingSession {

private:
	// Using a pointer is a bad design chioce here: what if the original book removed now by admin? We access garbage!
	// A more proper way: use book isbn, and later use book manager to find the book
	Book* book;	// Note, we did not create this pointer. Someone else should destory
	int current_page;
	string last_access_date;

public:
	BookReadingSession() ;
	BookReadingSession(Book* book) ;
	string ToString();

	string GetCurrentPageContent() ;

	const Book* GetBook() const;

	const string& GetLastAccessDate() const;

	void ResetLastAccessDate();

	int GetCurrentPage() const ;

	string PageIdxStr();

	void NextPage();
	void PreviousPage();

};


}


#endif // BOOK-READING-SESSION_H_INCLUDED

#ifndef BOOKS-MANAGER_H_INCLUDED
#define BOOKS-MANAGER_H_INCLUDED
#include "book.h"
#include <map>
#include <iostream>
using std::map;
using std::string;
namespace BookReader {
class BooksManager {
private:
	map<string, Book*> isbn_to_book_map;

	void FreeLoadedData() ;

public:
	BooksManager();

	void LoadDatabase() ;

	BooksManager(const BooksManager&) = delete;
	void operator=(const BooksManager&) = delete;

	~BooksManager() ;

	// CRUD operations
	void AddBook(Book* book) ;

	void UpdateBook(string isbn, Book* book);

	void DeleteBook(string isbn) ;

	Book* GetBook(string isbn) ;

	const map<string, Book*>& GetIsbnToBookMap() const ;

	void SetIsbnToBookMap(const map<string, Book*>& isbnToBookMap);

};


}


#endif // BOOKS-MANAGER_H_INCLUDED

#include "books-manager.h"
using std::cout;
using std::cin;

namespace BookReader {


	void BooksManager::FreeLoadedData() {
		for (auto pair : isbn_to_book_map) {
			delete pair.second;
		}
		isbn_to_book_map.clear();
	}


	BooksManager::BooksManager() {
	}

	void BooksManager::LoadDatabase() {
		FreeLoadedData();

		Book* book1 = new Book();
		book1->SetIsbn("00001");
		book1->SetAuthor("Mostafa");
		book1->SetTitle("C++ how to program");
		vector<string> pages1 = { "A C++", "B C++", "C C++", "D C++", "E C++" };
		book1->SetPages(pages1);
		AddBook(book1);

		Book* book2 = new Book();
		book2->SetIsbn("00002");
		book2->SetAuthor("Morad");
		book2->SetTitle("Intro to algo");
		vector<string> pages2 = { "A Algo", "B Algo", "C Algo", "D Algo", "E " };
		book2->SetPages(pages2);
		AddBook(book2);

		Book* book3 = new Book();
		book3->SetIsbn("00003");
		book3->SetAuthor("Morad");
		book3->SetTitle("Data Structures in C++");
		vector<string> pages3 = { "A Data", "B Data", "C Data", "D Data", "E Data" };
		book3->SetPages(pages3);
		AddBook(book3);
	}



	BooksManager::~BooksManager() {
		cout << "Destuctor: BooksManager\n";
		FreeLoadedData();
	}

	// CRUD operations
	void BooksManager::AddBook(Book* book) {
		isbn_to_book_map[book->GetIsbn()] = book;
	}

	void BooksManager::UpdateBook(string isbn, Book* book) {
	}

	void BooksManager::DeleteBook(string isbn) {
	}

	Book* BooksManager::GetBook(string isbn) {
		return nullptr;
	}

	const map<string, Book*>& BooksManager::GetIsbnToBookMap() const {
		return isbn_to_book_map;
	}

	void BooksManager::SetIsbnToBookMap(const map<string, Book*>& isbnToBookMap) {
		isbn_to_book_map = isbnToBookMap;
	}


}

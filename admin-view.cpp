#include "admin-view.h"
#include "helper.h"
#include <vector>
#include <iostream>
#include "book.h"

using std::cout;
using std::string;
using std::vector;

namespace BookReader {


AdminView::AdminView(UsersManager &users_manager, BooksManager &books_manager) :
			users_manager(users_manager), books_manager(books_manager) {

	}

	void AdminView::Display() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n\nHello " << user->GetName() << " | Admin View\n";
		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("Add Book");
		menu.push_back("Logout");

		while (true) {
			int choice = Helper::ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				AddBook();
			else
				break;
		}
	}

	void AdminView::ViewProfile() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n" << user->ToString() << "\n";
	}

	void AdminView::AddBook() {
		Book *book = new Book();
		book->Read();
		books_manager.AddBook(book);
	}

}



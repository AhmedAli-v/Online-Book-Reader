

#include "user-view.h"
#include <vector>
#include <iostream>
#include "helper.h"
#include <map>
#include <utility>
using std::map;
using std::pair;
using std::vector;
using std::cout;

namespace BookReader {



	UserView::UserView(UsersManager & users_manager, BooksManager &books_manager) :
			users_manager(users_manager), books_manager(books_manager) {

	}

	void UserView::Display() {
		const User* user = users_manager.GetCurrentUser();
		cout << "\n\nHello " << user->GetName() << " | User View\n";

		vector<string> menu;
		menu.push_back("View Profile");
		menu.push_back("List & Select from My Reading History");
		menu.push_back("List & Select from Available Books");
		menu.push_back("Logout");

		while (true) {
			int choice = Helper::ShowReadMenu(menu);
			if (choice == 1)
				ViewProfile();
			else if (choice == 2)
				ListReadingHistory();
			else if (choice == 3)
				ListAvailableBooks();
			else
				break;
		}
	}

	void UserView::ViewProfile() {
		const User* user = users_manager.GetCurrentUser();

		cout << "\n" << user->ToString() << "\n";
	}

	void UserView::DisplaySession(BookReadingSession* session) {
		vector<string> menu;
		menu.push_back("Next Page");
		menu.push_back("Previous Page");
		menu.push_back("Stop Reading");

		while (true) {
			cout << "Current Page: " << session->PageIdxStr() << "\n";
			cout << session->GetCurrentPageContent() << "\n";

			int choice = Helper::ShowReadMenu(menu);
			if (choice == 1)
				session->NextPage();
			else if (choice == 2)
				session->PreviousPage();
			else
				break;
		}
		session->ResetLastAccessDate();
	}

	void UserView::ListReadingHistory() {
		int idx = 0;
		const auto& sessions = users_manager.GetCurrentUser()->GetReadingSessions();
		for (auto& session : sessions) {
			cout << ++idx << ": " << session->ToString() << "\n";
		}

		if (idx == 0)
			cout << "\nNo history. List books and start having fun\n";
		else {
			cout << "\nWhich session to open?: ";
			int choice = Helper::ReadInt(1, idx);
			DisplaySession(sessions[choice - 1]);
		}
	}

	void UserView::ListAvailableBooks() {
		const map<string, Book*>& mp = books_manager.GetIsbnToBookMap();

		cout << "\nOur current book collection:\n";
		int idx = 0;
		for (const auto &pair : mp) {
			// As we call ToString: we don't need to worry about book data members future changes
			cout << "\t" << ++idx << " " << pair.second->ToString() << "\n";
		}

		cout << "\nWhich book to read?: ";
		int choice = Helper::ReadInt(1, idx);	// For simplicity, assume a new book is selected

		idx = 0;
		for (const auto &pair : mp) {
			if (++idx == choice) {
				BookReadingSession* session = users_manager.AddReadingSession(pair.second);
				DisplaySession(session);
				break;
			}
		}

	}


}

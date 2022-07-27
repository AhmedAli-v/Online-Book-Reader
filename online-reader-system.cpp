#include "online-reader-system.h"
#include <iostream>
#include "admin-view.h"
#include "user-view.h"
using std::cout;


namespace BookReader {

void OnlineReaderSystem::LoadDatabase() {
		users_manager->LoadDatabase();
		books_manager->LoadDatabase();
	}


	OnlineReaderSystem::OnlineReaderSystem() :
			books_manager(new BooksManager()), users_manager(new UsersManager()) {
	}

	OnlineReaderSystem::~OnlineReaderSystem() {
		cout << "Destuctor: OnlineReaderSystem\n";

		if (books_manager != nullptr) {
			delete books_manager;
			books_manager = nullptr;
		}
		if (users_manager != nullptr) {
			delete users_manager;
			users_manager = nullptr;
		}
	}

	void OnlineReaderSystem::Run() {	// only public one
		LoadDatabase();

		while (true) {
			users_manager->AccessSystem();	// login/signup

			// Let's make for every user, its own viewer class: Remember: Single responsibility principle
			if (users_manager->GetCurrentUser()->IsLibraryAdmin()) {
				AdminView view(*users_manager, *books_manager);
				view.Display();
			} else {
				UserView view(*users_manager, *books_manager);
				view.Display();
			}
		}
	}


}

#ifndef ADMIN-VIEW_H_INCLUDED
#define ADMIN-VIEW_H_INCLUDED
#include "users-manager.h"
#include "books-manager.h"


namespace BookReader {

class AdminView {
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
public:

	AdminView(UsersManager &users_manager, BooksManager &books_manager);

	void Display();

	void ViewProfile() ;

	void AddBook() ;

};

}


#endif // ADMIN-VIEW_H_INCLUDED

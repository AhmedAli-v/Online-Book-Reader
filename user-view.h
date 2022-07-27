#ifndef USER-VIEW_H_INCLUDED
#define USER-VIEW_H_INCLUDED
#include "books-manager.h"
#include "users-manager.h"
#include "book-reading-session.h"

namespace BookReader {

class UserView {
private:
	UsersManager &users_manager;
	BooksManager &books_manager;
public:

	UserView(UsersManager & users_manager, BooksManager &books_manager) ;

	void Display() ;
	void ViewProfile() ;

	void DisplaySession(BookReadingSession* session) ;
	void ListReadingHistory();

	void ListAvailableBooks();
};

}


#endif // USER-VIEW_H_INCLUDED

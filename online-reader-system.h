#ifndef ONLINE-READER-SYSTEM_H_INCLUDED
#define ONLINE-READER-SYSTEM_H_INCLUDED
#include "books-manager.h"
#include "users-manager.h"



namespace BookReader {
class OnlineReaderSystem {
private:
	BooksManager *books_manager;
	UsersManager *users_manager;

	void LoadDatabase();

public:
	OnlineReaderSystem();

	~OnlineReaderSystem();

	void Run();
};


}


#endif // ONLINE-READER-SYSTEM_H_INCLUDED

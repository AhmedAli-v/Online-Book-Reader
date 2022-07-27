#ifndef USERS-MANAGER_H_INCLUDED
#define USERS-MANAGER_H_INCLUDED
#include "user.h"
#include <utility>
#include <map>
#include <iostream>
using std::string;
using std::map;
using std::pair;
namespace BookReader {

class UsersManager {
private:
	User* current_user = nullptr;
	map<string, User*> userame_userobject_map;

	void FreeLoadedData();
public:
	UsersManager();

	~UsersManager();

	// No sense for such a class (manager of objects) to be copyable!
	// This is a C++ 11 feature that prevents Copy constructor and Assignment Operator (=)from being called. It delete then from the class
	// https://ariya.io/2015/01/c-class-and-preventing-object-copy#:~:text=There%20are%20three%20ways%20to,have%20its%20instance%20copied%20around.
	UsersManager(const UsersManager&) = delete;
	void operator=(const UsersManager&) = delete;

	void LoadDatabase() ;
	void AccessSystem() ;

	void DoLogin() ;

	void DoSignUp() ;

	BookReadingSession* AddReadingSession(Book* book) ;

	const User* GetCurrentUser() const ;
};

}


#endif // USERS-MANAGER_H_INCLUDED

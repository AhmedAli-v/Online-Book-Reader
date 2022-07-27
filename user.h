#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include "book-reading-session.h"

#include <vector>
#include <iostream>
using std::vector;
using std::string;
namespace BookReader {
class User{
private:
	string user_name;
	string password;
	string name;
	string email;
	bool is_library_admin;

	vector<BookReadingSession*> reading_sessions;
public:

	// If you have pointers internally: start with canceling copy constructor, so that you discover any bugs due to misuse
	// Provide it based on logic & needs
	User(const User&) = delete;
	void operator=(const User&) = delete;

	User();

	~User() ;

	string ToString() const ;

	void Read(const string &user_name);

	const string& GetEmail() const ;

	void SetEmail(const string& email) ;

	const string& GetName() const ;

	void SetName(const string& name) ;

	const string& GetPassword() const ;

	void SetPassword(const string& password) ;

	const string& GetUserName() const ;

	void SetUserName(const string& userName) ;

	bool IsLibraryAdmin() const ;

	void SetIsLibraryAdmin(bool isLibraryAdmin);

	const vector<BookReadingSession*>& GetReadingSessions() const ;

	BookReadingSession* AddReadingSession(Book* book) ;


};


}


#endif // USER_H_INCLUDED

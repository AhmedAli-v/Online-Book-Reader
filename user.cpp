#include "user.h"
#include <vector>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::string;
using std::vector;
using std::cin;
using std::cout;

namespace BookReader {
	User::User() {
		is_library_admin = false;
	}

	User::~User() {
		for (auto &session : reading_sessions)
			delete session;

		reading_sessions.clear();
	}

	string User::ToString() const {
		ostringstream oss;
		oss << "Name: " << user_name;
		if (IsLibraryAdmin())
			oss << " | Admin";
		oss << "\n";
		oss << "Email: " << email << "\n";
		oss << "User name: " << user_name << "\n";
		return oss.str();
	}

	void User::Read(const string &user_name) {
		SetUserName(user_name);

		string str;

		cout << "Enter password: ";
		cin >> str;
		SetPassword(str);

		cout << "Enter name: ";
		cin >> str;
		SetName(str);

		cout << "Enter email: ";
		cin >> str;
		SetEmail(str);
	}

	const string& User::GetEmail() const {
		return email;
	}

	void User::SetEmail(const string& email) {
		this->email = email;
	}

	const string& User::GetName() const {
		return name;
	}

	void User::SetName(const string& name) {
		this->name = name;
	}

	const string& User::GetPassword() const {
		return password;
	}

	void User::SetPassword(const string& password) {
		this->password = password;
	}

	const string& User::GetUserName() const {
		return user_name;
	}

	void User::SetUserName(const string& userName) {
		user_name = userName;
	}

	bool User::IsLibraryAdmin() const {
		return is_library_admin;
	}

	void User::SetIsLibraryAdmin(bool isLibraryAdmin) {
		is_library_admin = isLibraryAdmin;
	}

	const vector<BookReadingSession*>& User::GetReadingSessions() const {
		// Note: Although the return is const vector, but the pointer is not const, so someone can cause problems using setters on pointer
		return reading_sessions;	// No set
	}

	BookReadingSession* User::AddReadingSession(Book* book) {
		// We create pointer & later delete it
		BookReadingSession* session = new BookReadingSession(book);
		reading_sessions.push_back(session);
		return session;
	}
	}

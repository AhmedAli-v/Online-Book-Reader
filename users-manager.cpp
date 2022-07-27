#include "users-manager.h"
#include "helper.h"
using std::cout;
using std::cin;


namespace BookReader {


    void UsersManager::FreeLoadedData() {
		for (auto pair : userame_userobject_map) {
			delete pair.second;
		}
		userame_userobject_map.clear();
		current_user = nullptr;
	}

	UsersManager::UsersManager() {
	}

	UsersManager::~UsersManager() {
		FreeLoadedData();
	}

	// No sense for such a class (manager of objects) to be copyable!
	// This is a C++ 11 feature that prevents Copy constructor and Assignment Operator (=)from being called. It delete then from the class
	// https://ariya.io/2015/01/c-class-and-preventing-object-copy#:~:text=There%20are%20three%20ways%20to,have%20its%20instance%20copied%20around.

	void UsersManager::LoadDatabase() {

		FreeLoadedData();
		// Some "Dummy Data" for simplicity
		User* user1 = new User();
		user1->SetUserName("mostafa");
		user1->SetPassword("111");
		user1->SetEmail("most@gmail.com");
		user1->SetIsLibraryAdmin(true);
		user1->SetName("Mostafa Saad Ibrahim");
		userame_userobject_map[user1->GetUserName()] = user1;

		User* user2 = new User();
		user2->SetUserName("asmaa");
		user2->SetPassword("222");
		user2->SetEmail("asmaa@gmail.com");
		user2->SetIsLibraryAdmin(false);
		user2->SetName("Asmaa Saad Ibrahim");
		userame_userobject_map[user2->GetUserName()] = user2;
	}

	void UsersManager::AccessSystem() {
		int choice = Helper::ShowReadMenu( { "Login", "Sign Up" });
		if (choice == 1)
			DoLogin();
		else if (choice ==2)
			DoSignUp();
        else AccessSystem();
	}

	void UsersManager::DoLogin() {
		LoadDatabase();

		while (true) {
			string user_name, pass;
			cout << "Enter Username: ";
			cin >> user_name;
			cout <<"\n Password: ";
			cin >>pass;

			if (!userame_userobject_map.count(user_name)) {
				cout << "\nInvalid user user_name or password. Try again\n\n";
				continue;
			}
			User* user_exist = userame_userobject_map.find(user_name)->second;

			if (pass != user_exist->GetPassword()) {
				cout << "\nInvalid user user_name or password. Try again\n\n";
				continue;
			}
			current_user = user_exist;
			break;
		}
	}

	void UsersManager::DoSignUp() {
		string user_name;
		while (true) {
			cout << "Enter user name. (No spaces): ";
			cin >> user_name;

			if (userame_userobject_map.count(user_name))
				cout << "Already used. Try again\n";
			else
				break;
		}

		current_user->Read(user_name);
		userame_userobject_map[current_user->GetUserName()] = current_user;
	}

	BookReadingSession* UsersManager::AddReadingSession(Book* book) {
		return current_user->AddReadingSession(book);
	}

	const User* UsersManager::GetCurrentUser() const {
		return current_user;
	}


}

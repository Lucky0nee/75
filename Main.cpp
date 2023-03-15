#include <iostream>
#include <vector>

class User {
public:
	User() {
		id = g_id; g_id++;
		this->login = "login";
		this->password = "password";
	}

	User(std::string login, std::string password) {
		id = g_id; g_id++;
		this->login = login;
		this->password = password;
	}

	void addUserInFriends(User* user) {
		if (this->id != user->id) {
			friends.push_back(user);
			std::cout << "Success";
		}
		else {
			std::cout << "Error";
		}
	}
	void followers(std::vector<User*> f) {
		int counter = 0, temp = 0;
		for (int i = 0; i < f.size(); i++) {
			for (int j = 0; j < f[i]->getFriends().size(); j++) {
				if (f[i]->getFriends()[j] == this) {
					temp++;
				}
			}
		}
		if (temp == 0) { return; }

		std::cout << "Mutual Followers: ";
		for (int i = 0; i < f.size(); i++) {
			for (int j = 0; j < f[i]->getFriends().size(); j++) {
				if (f[i]->getFriends()[j] == this) {
					std::cout << f[i]->getLogin() << (counter == temp - 1 ? "" : ", ");
					counter++;
				}
			}
		}
	}

	void printInfo() {
		std::cout << "Id: " << id;
		std::cout << "\nLogin: " << login;
		std::cout << "\nPassword: " << password;

		printFriends();
		followers(friends);

		std::cout << "\n";
	}

	void printFriends() {
		if (friends.size() == 0) { return; }

		std::cout << "\nFollowing: ";
		for (int i = 0; i < friends.size(); i++) {
			std::cout << friends[i]->getLogin() << (friends.size() - 1 == i ? "" : ", ");
		}

		std::cout << "\n";
	}

	std::vector<User*> getFriends() {
		return friends;
	}

	std::string getLogin() {
		return login;
	}
	int getId() {
		return id;
	}
protected:
	int id;
	static int g_id;
	std::string login;
	std::string password;
	std::vector<User*> friends;
};
int User::g_id = 0;

void printUsers(std::vector<User*> users) {
	for (int i = 0; i < users.size(); i++) {
		users[i]->printInfo();
		std::cout << "\n";
	}
}		

int main() {
	system("color f & chcp 1251>nul");
	std::vector<User*> users;

	User* user0 = new User("Vadim", "1234");
	User* user1 = new User("Bryachislav", "4321");
	User* user2 = new User("Alipiy", "1111");
	User* user3 = new User("Auxentius", "9999");
	User* user4 = new User("???", "????");

	users.push_back(user0); users.push_back(user1);
	users.push_back(user2); users.push_back(user3);
	users.push_back(user4);

	users[0]->addUserInFriends(users[1]);
	users[0]->addUserInFriends(users[2]);
	users[2]->addUserInFriends(users[0]);
	users[3]->addUserInFriends(users[2]);
	users[2]->addUserInFriends(users[3]);
	users[0]->addUserInFriends(users[4]);

	users[1]->addUserInFriends(users[1]); // Test
	system("cls");
	printUsers(users);

	return 0;
}

/*
Створіть класи об’єктів, потрібних у соціальних мережах.
1) Почніть із зареєстрованих користувачів (ідентифікатор, логін, пароль, тощо).
2) Кожен користувач має доданих друзів.
3) Є ті, хто додав користувача у друзі.
4) Клас взаємні друзі

В головній програмі створіть список зареєстрованих
користувачів із 5-9 об’єктів.
*/

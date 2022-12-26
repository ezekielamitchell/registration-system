#include <iostream>
#include<string>
#include<userstor>
#include<algorithm>

using namespace std;

int menu() {
    int input;

    cout << "*----- Menu -----*" << endl;
    cout << "1) Register" << endl;
    cout << "2) Log In" << endl;
    cout << "3) exit" << endl;
    cout << "enter option: ";
    cin >> input;

    // invalid user input
    if (std::cin.fail() || !(input == 1 || input == 2 || input == 3)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input; please enter 1, 2, or 0" <<endl;
    }

    return input;
}

struct User {
    string accountNumber;
    string fName;
    string lName;
    string userName;
    string password;
};

userstor<User> users;

User registerUser() {
    User user;

    cout << "First Name: ";
    cin >> user.fName;
    cout << "Last Name: ";
    cin >> user.lName;
    cout << "Username: ";

    bool usernameExists = true;
    while (usernameExists) {
        cin >> user.userName;
        usernameExists = false;
        for (User& i : users) {
            if (user.userName == i.userName) {
                usernameExists = true;
                cout << "Username already exists. Enter a new username: ";
                break;
            }
        }
    }

    cout << "Password (min 8 characters):  ";
    cin >> user.password;
    while (user.password.length() < 8) {
        cout << "Password must be at least 6 characters. Try again." << endl;
        cin >> user.password;
    }

    user.accountNumber = to_string(users.size() + 1000);
    return user;
}

void accountInfo(User& user) {
    // print user info
    cout << "Account Number: " << user.accountNumber << endl;
    cout << "First Name: " << user.fName << endl;
    cout << "Last Name: " << user.lName << endl;
    cout << "Username: " << user.userName << endl;
    cout << "Password: " << user.password << endl;
}

void login() {
    string username;
    string password;

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for (User& user : users) {
        if (user.userName == username && user.password == password) {
            accountInfo(user);
        }
    }

    if (find(users.begin(), users.end(), ) != users.end()) {

    }


}

int main() {
    bool active = true;
    while (active) {
        switch (menu()) {
            case 1:
                users.push_back(registerUser());
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "exiting systems...";
                active = false;
        }

    }
    return 0;
}


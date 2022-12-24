#include <iostream>
#include<string>

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

User registerUser() {
    User user;

    return user;
}


int main() {
    bool active = true;
    while (active) {
        switch (menu()) {
            case 1:
                cout << 1 << endl;
                break;
            case 2:
                cout << 2 << endl;
                break;
            case 3:
                cout << "exiting systems...";
                active = false;
        }

    }
    return 0;
}


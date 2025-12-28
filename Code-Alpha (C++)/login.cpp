#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(username + ":") != string::npos) {
            cout << "Username already exists!\n";
            return;
        }
    }
    file.close();

    ofstream outFile("users.txt", ios::app);
    outFile << username << ":" << password << endl;
    outFile.close();
    cout << "Registration successful!\n";
}

bool loginUser() {
    string username, password, line;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (getline(file, line)) {
        size_t pos = line.find(":");
        if (line.substr(0, pos) == username && line.substr(pos + 1) == password) {
            file.close();
            cout << "Login successful!\n";
            return true;
        }
    }
    file.close();
    cout << "Invalid username or password!\n";
    return false;
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice!\n";

    return 0;
}
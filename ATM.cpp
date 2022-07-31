#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include "Account.h"

using namespace std;

void show_balance(Account user){
    string line;
    cout << "Main Window-->Show Balance\n";
    cout << "==========================================\n";
    char * output = (char *)malloc(100); //WRONG
    sprintf(output, "Your current balance is: %0.2f\n", user.get_balance());
    cout << output;
    cout << "Press enter to go back to the Main Window";
    getline(cin, line);
    cout << "\n";
    free(output);
}

void deposit(Account *user){
    string line;
    cout << "Main Window-->Deposit(Enter the following information)\n";
    cout << "======================================================\n";
    bool valid = false;
    while (!valid){
        cout << "The amount you want to deposit:";
        getline(cin, line);
        valid = true;
        bool decimal_found = false;
        for (int i = 0; i < line.length(); i++){
            if (line.at(i) == '.' && !decimal_found){
                decimal_found = true;
                continue;
            }
            if (!isdigit(line.at(i)) || ((line.at(i) == '.') && decimal_found)){
                valid = false;
                break;
            }
        }
        if (line.length() == 0 || stod(line) < 0){
            valid = false;
        }
    }
    (*user).deposit(stod(line));
    cout << "-------------------------------------------------------\n";
    cout << "Added to your balance successfully. Press enter to go back to Main Window";
    getline(cin, line);
    cout << "\n";
}

void withdraw(Account *user){
    string line;
    cout << "Main Window-->Withdraw(Enter the following information)\n";
    cout << "=======================================================\n";
    bool valid = false;
    while (!valid){
        cout << "The amount you want to withdraw:";
        getline(cin, line);
        valid = true;
        bool decimal_found = false;
        for (int i = 0; i < line.length(); i++){
            if (line.at(i) == '.' && !decimal_found){
                decimal_found = true;
                continue;
            }
            if (!isdigit(line.at(i)) || ((line.at(i) == '.') && decimal_found)){
                valid = false;
                break;
            }
        }
        if (line.length() == 0 || stod(line) < 0 || (*user).get_balance() < stod(line)){
            valid = false;
        }
    }
    (*user).withdraw(stod(line));
    cout << "--------------------------------------------------------\n";
    cout << "Please take your money then...Press enter to go back to the Main Window";
    getline(cin, line);
    cout << "\n";
}

void show_transaction(Account *user){
    string line;
    cout << "Main Window-->Show All Transactions\n";
    cout << "===========================================\n";
    cout << "Account no:";
    cout << (*user).get_no();
    cout << "\n";
    cout << "-------------------------------------------------\n";
    cout << "Date                        | Type      | Amount\n";
    cout << "-------------------------------------------------\n";
    (*user).print_transactions();
    cout << "-------------------------------------------------\n";
    cout << "Press enter to go back to the Main Window";
    getline(cin, line);
    cout << "\n";
}

int main(){
    vector<Account> users;
    int available_id = 1;
    for (int i = 0; i < 10; i++){
        users.push_back(Account(available_id, "123", 5000.0));
        available_id++;
    }
    cout << "Login Window:\n";
    cout << "==============\n";
    string line;
    bool valid = false;
    int id = 0;
    while (!valid){
        cout << "Enter Your Account no:";
        getline(cin, line);
        valid = true;
        for (int i = 0; i < line.length(); i++){
            if (!isdigit(line.at(i))){
                valid = false;
                break;
            }
        }
        if (valid && (line.length() < 1 || stoi(line) < 1 || stoi(line) >= available_id)){
            valid = false;
        }
        if (valid){
            id = stoi(line);
        }
    }
    cout << "Enter your password:";
    getline(cin, line);
    while (line.compare(users.at(id - 1).get_password()) != 0){
        cout << "Enter your password:";
        getline(cin, line);
    }
    Account current_user = users.at(id - 1);
    cout << "\n";
    int CurrentOption = 0;
    while (CurrentOption != 5){
        cout << "Main Window\n";
        cout << "====================================\n";
        cout << "Choose one of the following options:\n";
        cout << "(1) Show balance\n";
        cout << "(2) Deposit\n";
        cout << "(3) Withdraw\n";
        cout << "(4) Show All Transactions\n";
        cout << "(5) Exit\n";
        cout << "Enter your choice:";
        getline(cin, line);
        while (line.length() != 1 || stoi(line) > 5 || stoi(line) < 0){
            getline(cin, line);
        }
        cout << "\n";
        CurrentOption = stoi(line);
        switch (CurrentOption){
			case 1: show_balance(current_user);
				break;
			case 2: deposit(&current_user);
				break;
			case 3: withdraw(&current_user);
				break;
            case 4: show_transaction(&current_user);
                break;
		}
    }
}

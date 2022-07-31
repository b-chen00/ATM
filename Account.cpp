#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <ctime>

#include "Account.h"

using namespace std;

Account::Account(int no, string p, double b){
    account_no = no;
    password = p;
    balance = b;
}

Account::~Account(){
    transactions.clear();
    transactions.shrink_to_fit();
}

void Account::deposit(double amount){
    balance += amount;
    time_t current_time;
	tm * current_tm;
	time(&current_time);
	current_tm = localtime(&current_time);
    char buffer[100];
    strftime(buffer, 100, "%a %b %e %T %Y", current_tm);
    char *output = (char *)malloc(100);
    sprintf(output, "%-28s| %-10s| %.2f\n", buffer, "deposit", amount);
    transactions.push_back(output);
}

void Account::withdraw(double amount){
    balance -= amount;
    time_t current_time;
	tm * current_tm;
	time(&current_time);
	current_tm = localtime(&current_time);
    char buffer[100];
    strftime(buffer, 100, "%a %b %e %T %Y", current_tm);
    char *output = (char *)malloc(100);
    sprintf(output, "%-28s| %-10s| %.2f\n", buffer, "withdraw", amount);
    transactions.push_back(output);
}

int Account::get_no(){
    return account_no;
}

string Account::get_password(){
    return password;
}

double Account::get_balance(){
    return balance;
}

void Account::print_transactions(){
    for (char * c : transactions){
        cout << c;
    }
}

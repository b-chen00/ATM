#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account{
    private:
        int account_no;
        string password;
        double balance;
        vector<char *> transactions;
    public:
        Account();
        ~Account();
        Account(int no, string p, double b);
        void deposit(double amount);
        void withdraw(double amount);
        int get_no();
        string get_password();
        double get_balance();
        void print_transactions();
};

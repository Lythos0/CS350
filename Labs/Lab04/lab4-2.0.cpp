#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#ifndef LAB4_2_0_H 
#define LAB4_2_0_H
class Account{
private:
double balance;
long accountnumber;
static long acc_number_gen;
public:
Account(){
    balance = 0;
    accountnumber = acc_number_gen++;
}
Account(float starting_balance){
balance = starting_balance;
starting_balance = acc_number_gen++;
if (starting_balance < 0){
    balance = 0;
}
}

bool Deposit(float money_deposited){
if(money_deposited >= 0){
    balance += money_deposited;
}
else
return false;
}

 bool Withdraw(float money_withdrawn){
if (money_withdrawn >= 0 && balance - money_withdrawn >= 0) {
balance -= money_withdrawn;
    return true;
 }
    return false;
}
double GetBalance(){
return balance;}

long GetAccount(){
    return accountnumber;
}
string toString() const {
ostringstream oss;
oss << accountnumber << " :\n$ " << balance;
return oss.str();
    }
};

long Account::acc_number_gen = 162410010000;

#endif
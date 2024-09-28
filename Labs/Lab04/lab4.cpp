#include <iostream>
using namespace std;

   class Account{

 protected:

int balance;
int accountnumber;
static int acc_num_gen;

public:
Account(){
balance = 0;
accountnumber = acc_num_gen++;
}

Account(float InitialBalance){
    if(InitialBalance < 0){
        balance = 0;
    }
    else{
      balance = InitialBalance;
    }
           accountnumber = acc_num_gen++;

}

virtual bool Deposit(float deposited){
    if(deposited >=0){
        balance += deposited;
        return true;
    }
    return false;


}

virtual float Withdraw(float withdrawal) {
    if (withdrawal >= 0 && balance - withdrawal >= 0) {
        balance -= withdrawal;  
     return withdrawal;      
    }
    return 0; 
}
float Balance()const{
    return balance;
}

int GetAccountNumber()const{
    return accountnumber;
}


void Process(){

}

    string toString() const {
 return to_string(accountnumber) + " :\n$ " + to_string(balance);
    }



   };

int Account::acc_num_gen = 162410010000;

class Checking:public Account{

private:
float fee;

public:

Checking(){
    fee = 0;
    balance = 0;
}

Checking(float InitialBalance): Account(InitialBalance){
    if(balance < 0){
        balance = 0;
    }
    fee = 0;
}

 bool Deposit(float amount) override {
        if (amount >= 0 && (amount - fee) >= 0) { 
            balance += (amount - fee);
            fee = 0;
            return true;
        } else if (amount >= 0) {
            fee -= static_cast<int>(amount); 
            return false;
        }
        return false;
    }
float Withdraw(float amount) override {
        if (amount >= 0 && balance - amount >= 0) {
            balance -= amount;  
            return amount; 
        } else if (amount >= 0) { 
            fee += 5 + static_cast<int>(amount - balance); 
            float previousBalance = balance;
            balance = 0; 
            return previousBalance; 
        }
        return 0;  
    }

    int GetFee()const{
        return fee;
    }

    string toString() const override {
    return to_string(accountnumber) + " :\n$ " + to_string(balance - fee);
    }




};

class Savings: public Account{
  private:  
 float fee;

  public:
  Savings():Account(){
  balance = 0;
  fee = 0;

  }

Savings(float initialBalance) : Account(initialBalance) {
        if (initialBalance < 0) {
            balance = 0;
        }
        fee = 0;
    }

bool Deposit(float amount) override {
        if (amount >= 0 && (amount - fee) >= 0) {
            balance += (amount - fee);  
            fee = 0; 
        return true;
        } else if (amount >= 0) {
        fee -= static_cast<int>(amount);
        return false;
        }
        return false;
    }

    int GetFee()const{
        return fee;
    }

    void Process()override{
        if(balance < 500){
      fee += 3.50;
        }
        balance *= 1.00426;
    }
    string toString() const override {
        return to_string(accountnumber) + " :\n$ " + to_string(balance - fee);
    }

};

const int MAX_ACCOUNTS = 100;  
Account* accounts[MAX_ACCOUNTS];  
int accountCount = 0;  

void app() {
    int option = 0;

    while (option != 3) {
        cout << "1. Start an account\n";
        cout << "2. Perform a transaction\n";
        cout << "3. Quit\n";
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1) { 
            if (accountCount >= MAX_ACCOUNTS) { 
                cout << "Cannot create more accounts. Limit reached.\n";
                continue;
            }
              int accountType;
            float initialBalance;
            cout << "1. Checking 2. Savings: ";
            cin >> accountType;
            cout << "Enter initial balance: ";
            cin >> initialBalance;

            if (accountType == 1) {
                accounts[accountCount] = new Checking(initialBalance); 
                cout << "Checking account created.\n";
            } else if (accountType == 2) {
                accounts[accountCount] = new Savings(initialBalance);  
                cout << "Savings account created.\n";
            }
            accountCount++;
        }
        else if (option == 2) {
            int accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;

            Account* foundAccount = nullptr;
            for (int i = 0; i < accountCount; i++) {
                if (accounts[i]->GetAccountNumber() == accountNumber) {
                    foundAccount = accounts[i];
                    break;
                }
            }

            if (foundAccount) {
                int transactionType;
                float amount;
                cout << "1. Deposit 2. Withdraw: ";
                cin >> transactionType;
                cout << "Enter amount: ";
                cin >> amount;

                if (transactionType == 1) {
              if (foundAccount->Deposit(amount)) {
                        cout << "Deposit successful. New balance: " << foundAccount->Balance() << endl;
                    } else {
                        cout << "Deposit failed.\n";
                    }
                } else if (transactionType == 2) {  
                    float withdrawn = foundAccount->Withdraw(amount);
                    if (withdrawn > 0) {
                        cout << "Withdrawal successful. New balance: " << foundAccount->Balance() << endl;
                    } else {
                        cout << "Withdrawal failed. Please try again..\n";
                    }
                }
            } else {
                cout << "Your account not found.\n";
            }
        }

        else if (option == 3) {
            cout << "Exiting the program...\n";
        }

        else {
            cout << "This option is not valid. Please try again.\n";
        }
    }
}


   int main(){
    app();


    return 0;


   }




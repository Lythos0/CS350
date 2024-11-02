#using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "lab4-2.0.cpp"
class Checking : public Account {
private:
    double fee; 

public:
    Checking() : fee(0.0) {
        balance = 0.0;
        accountnumber = acc_num_gen++;
    }

    Checking(double initFee) : fee(initFee >= 0 ? initFee : 0.0) {
        balance = 0.0;
        accountnumber = acc_num_gen++;
    }

    bool deposit(double amount) override {
        if (amount < 0) return false; 

        double netAmount = amount - fee;
        if (netAmount >= 0) {
            balance += netAmount;
            fee = 0; 
            return true;
        } else {
            fee -= amount; 
            return false;
        }
    }

    bool withdraw(double amount) override {
        if (amount < 0) return false; 

        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            fee += 5 + (amount - balance);
            balance = 0;
            return false;
        }
    }
    double Fee() const {
        return fee;
    }
    std::string toString() const {
        return std::to_string(accountnumber) + " :\n$ " + std::to_string(balance - fee);
    }
};


class Savings : public Account {
private:
    float interest;

public:
    Savings() : interest(0.0f) {
        balance = 0.0;
        accountnumber = acc_num_gen++;
    }

    Savings(float initInterest) : interest(initInterest >= 0 ? initInterest : 0.0f) {
        balance = 0.0;
        accountnumber = acc_num_gen++;
    }

    float getInterest() const {
        return interest;
    }
    void accumulate() {
        interest += (1.00426 * (balance + interest));
    }
    std::string toString() const {
        return std::to_string(accountnumber) + " :\n$ " + std::to_string(balance + interest);
    }

    friend std::ostream& operator<<(std::ostream &out, const Savings &account) {
        out << account.accountnumber << " :\n$ " << (account.balance + account.interest);
        return out;
    }
};

void app() {
    std::vector<Account*> accounts;
    int accountCount = 0;

    while (true) {
        std::cout << "Accounts created: " << accountCount << "\n";
        std::cout << "Menu:\n";
        std::cout << "1. Start an account\n";
        std::cout << "2. Perform a transaction\n";
        std::cout << "3. Quit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        if (choice == 3) break;

        if (choice == 1) {
            std::cout << "Choose account type (1 for Checking, 2 for Savings): ";
            int type;
            std::cin >> type;

            std::cout << "Enter initial balance: ";
            double balance;
            std::cin >> balance;

            if (type == 1) {
                Checking *newChecking = new Checking();
                newChecking->deposit(balance);
                accounts.push_back(newChecking);
                std::cout << "You have successfully created a new checking account!:\n" << *newChecking << "\n";
            } else if (type == 2) {
                std::cout << "Please enter initial interest rate: ";
                float interest;
                std::cin >> interest;
                Savings *newSavings = new Savings(interest);
                newSavings->deposit(balance);
                accounts.push_back(newSavings);
                std::cout << "Created Savings account:\n" << *newSavings << "\n";
            }
     accountCount++;

        } else if (choice == 2) {
            std::cout << "Enter account number: ";
            int accNum;
            std::cin >> accNum;

            Account *account = nullptr;
            for (auto *acc : accounts) {
                if (acc->getAccountNumber() == accNum) {
                    account = acc;
                    break;
                }
            }
            if (account) {
                std::cout << "Select a transaction! Type (1 for deposit, 2 for withdraw): ";
                int transactionType;
                std::cin >> transactionType;

                std::cout << "Please enter amount: ";
                double amount;
                std::cin >> amount;

                bool success = false;
                if (transactionType == 1) {
                    success = account->deposit(amount);
                } else if (transactionType == 2) {
                    success = account->withdraw(amount);
                }
                if (success) {
                    std::cout << "Transaction successful. New balance:\n" << *account << "\n";
                } else {
                    std::cout << "Transaction failed.\n";
                }
            } else {
                std::cout << "Account not found.\n";
            }
        }
        for (auto *acc : accounts) {
            Savings *savingsAccount = dynamic_cast<Savings*>(acc);
            if (savingsAccount) {
                savingsAccount->accumulate();
            }
        }
    }
    for (auto *acc : accounts) {
        delete acc;
    }
}

int main(){
    app();
}
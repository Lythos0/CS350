#include "Utils.h"
//Define Classes Below Here
class BalanceManager: public Object{

private:
float _amount;
int _count = 0;
public:
BalanceManager(){
	_amount = 0;
	_count++;}

BalanceManager(float _newamount){
	_amount = _newamount;
	_count++;
	if(_amount < 0){
		_amount =0;}
}
virtual bool possible_deposit(float money){
	return True
}

virtual bool poosible_withdraw(float money){
	return True
		}

virtual bool deposit(float money){
	_amount +=money;
	if(money ! < 0 && money != possible_deposit){
		return true;
			
	else {
		return false;
	}
}
}

virtual bool withdraw(float money){
	_amount -= money;
	if(money ! < 0 && money != possible_withdraw){
		return true; 
}
	else {
		return false;
	}
}
	
int balance(){
	return _amount;
}
int total_accounts(){
	return _count;
}
std::string to_str() {
        std::ostringstream oss;
        oss << "Balance: " << std::fixed << std::setprecision(2) << _amount << " USD";
        return oss.str();
    }
}

};

class BalanceManagerWithDailyTurnOver : public BalanceManager
private:
float _current;
float _maximum;
public:
BalanceManagerWithDailyTurnOver(){
_amount = 0;
_current = 0;
_maximum = 5000;
}

bool possible_transaction(float transaction){
if(_current + transaction <= _maximum){
return true; }

else {
return false;
}
}

bool possible_deposit(float transaction) override {
         return possible_transaction(transaction);  
    }
}

bool possible_withdraw(float transaction) override {
return possible_transaction(transaction);
	}
}


bool deposit(float transaction) override {
        if (BalanceManager::deposit(transaction)) {
            if (possible_transaction(transaction)) {
                _current += transaction;  
                return true;  
            }
        }
        return false;  
    }

   
    bool withdraw(float transaction) override {
        
        if (BalanceManager::withdraw(transaction)) {
           
            if (possible_transaction(-transaction)) {
                _current -= transaction;  
                return true; 
            }
        }
        return false; 
    }
};

float turnover(){
return _current;
}

void adjustment(float new_maximum) {
        if (new_maximum >= _current) {
            _maximum = new_maximum;
        }
    }

    void reset() {
        _current = 0;
    }

    std::string to_str() override {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2);
        oss << "Balance: " << _amount << " USD\n";
        oss << "Turnover: " << _current << " USD\n";
        oss << "Limit: " << _maximum << " USD";
        return oss.str();
    }
};

//Define Classes Above Here 

void transactions(BalanceManager& acct, int num)
{
	double amount;

	std::cout << "Account Number: " << num << "\n";

	std::cout << "Current " << acct << "\n"; 
	std::cout << "Enter amount to deposit: ";
	std::cin >> amount;
	acct.deposit(amount);
	std::cout << "New " << acct << "\n";
	std::cout << "\nCurrent " << acct << "\n";
	std::cout << "\Enter amount to withdraw: ";
	std::cin >> amount;
	acct.withdraw(amount);
	std::cout << "New " << acct << "\n\n";
}

void adjust(BalanceManagerWithDailyTurnOver& acct, int num)
{
	double amount;

	std::cout << "Account Number: " << num << "\n";
	std::cout << "Current Stats:\n" << acct << "\n";
	std::cout << "\nEnter new limit: ";
	std::cin >> amount;
	acct.adjustment(amount);

	std::cout << "New Stats:\n" << acct << "\n";
	acct.reset();
	std::cout << "\nDaily Reset\nNew Stats:\n" << acct << "\n\n";
}

int main()
{
	BalanceManager b[2] = {BalanceManager(), BalanceManager(1000)};
	std::cout << "Number of Accounts: " << BalanceManager::total_accounts() << "\n";

	for(int i = 0;i < 2;i += 1)
	{
		transactions(b[i], 1000 + i);
	}


	BalanceManagerWithDailyTurnOver c[3] = {BalanceManagerWithDailyTurnOver(), BalanceManagerWithDailyTurnOver(1000), BalanceManagerWithDailyTurnOver(100,2000)};


	std::cout << "Number of Accounts: " << BalanceManager::total_accounts() << "\n";

	for(int i = 0;i < 3;i += 1)
	{
		transactions(c[i], 3000 + i);
		adjust(c[i], 3000 + i);
	}

	return 0;
}

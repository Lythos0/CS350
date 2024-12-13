#include "Utils.h"

//Define Classes Below Here

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

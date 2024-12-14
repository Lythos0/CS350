#Define Classes Below Here
class BalanceManager:
    _count = 0
    def __init__(self, amount=0.0):
        if amount < 0:
            self._amount = 0.0
        else:
            self._amount = float(amount)
        BalanceManager._count += 1
        
    @staticmethod
    def total_accounts():
        return BalanceManager._count

    def possible_deposit(self, amount):
        return True

    def possible_withdraw(self, amount):
        return True

    def deposit(self, amount):
        if amount >= 0 and self.possible_deposit(amount):
            self._amount += amount
            return True
        return False

    def withdraw(self, amount):
        if amount >= 0 and self.possible_withdraw(amount):
            self._amount -= amount
            return True
        return False

    def balance(self):
        return self._amount

    def __str__(self):
        return f"Balance: {self._amount:.2f} USD"

class BalanceManagerWithDailyTurnOver(BalanceManager):
    def __init__(self, amount=0.0, maximum=5000.0):
        super().__init__(amount)
        self._current = 0.0
        if maximum < 0:
            self._maximum = 5000.0
        else:
            self._maximum = float(maximum)

    def possible_transaction(self, amount):
        return self._current + amount <= self._maximum

    def possible_deposit(self, amount):
        return self.possible_transaction(amount)

    def possible_withdraw(self, amount):
        return self.possible_transaction(amount)

    def deposit(self, amount):
        if super().deposit(amount):
            self._current += amount
            return True
        return False

    def withdraw(self, amount):
        if super().withdraw(amount):
            self._current += amount
            return True
        return False

    def turnover(self):
        return self._current

    def adjustment(self, maximum):
        if maximum >= self._current:
            self._maximum = maximum
             def reset(self):
        self._current = 0.0

    def __str__(self):
        return (f"Balance: {self._amount:.2f} USD\n"
                f"Turnover: {self._current:.2f} USD\n"
                f"Limit: {self._maximum:.2f} USD")



#Define Classes Above Here

def transactions(acct, num):
    print("Account Number:", num)

    print("Current", acct)
    amount = float(input("Enter amount to deposit: "))
    acct.deposit(amount)
    print("New", acct)
    print("\nCurrent", acct)
    amount = float(input("Enter amount to withdraw: "))
    acct.withdraw(amount)
    print("New",acct, "\n")

def adjust(acct, num):
    print("Account Number:", num)
    print("Current Stats:\n", acct, sep ="")
    amount = float(input("\nEnter new limit: "))
    acct.adjustment(amount)

    print("New Stats:\n",acct, sep = "")
    acct.reset()
    print("\nDaily Reset\nNew Stats:\n",acct, "\n", sep="")

if __name__ == "__main__":
    b = [BalanceManager(), BalanceManager(1000)]
    print("Number of Accounts:", BalanceManager.total_accounts())

    for i in range(len(b)):
        transactions(b[i], 1000 + i)

    c = [BalanceManagerWithDailyTurnOver(), BalanceManagerWithDailyTurnOver(1000), BalanceManagerWithDailyTurnOver(100,2000)]

    print("Number of Accounts:", BalanceManager.total_accounts())

    for i in range(len(c)):
        transactions(c[i], 3000 + i)
        adjust(c[i], 3000 + i)

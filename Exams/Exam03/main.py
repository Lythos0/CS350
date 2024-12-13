#Define Classes Below Here

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

#Define Classes Below Here

#Define Classes Above Here

def transactions(acct, num)
    print("Account Number: ", num, "\n")

    print("Current ", acct, "\n")
    print("Enter amount to deposit: ")
    amount = gets.chomp.to_f
    acct.deposit(amount)

    print("New ", acct, "\n")
    print("\nCurrent ", acct, "\n")
    print("Enter amount to withdraw: ")
    amount = gets.chomp.to_f
    acct.withdraw(amount)
    print("New ",acct, "\n\n")
end

def adjust(acct, num)
    print("Account Number: ", num, "\n")
    print("Current Stats:\n", acct, "\n")
    print("\nEnter new limit: ")
    amount = gets.chomp.to_f
    acct.adjustment(amount)

    print("New Stats:\n",acct, "\n")
    acct.reset()
    puts("\nDaily Reset", "New Stats:", acct, "\n")
end

def main()
  b = [BalanceManager.new(), BalanceManager.new(1000)]
    print("Number of Accounts: ", BalanceManager.total_accounts(), "\n")

    for i in 0...b.length
        transactions(b[i], 1000 + i)
    end

    c = [BalanceManagerWithDailyTurnOver.new(), BalanceManagerWithDailyTurnOver.new(1000), BalanceManagerWithDailyTurnOver.new(100,2000)]

    print("Number of Accounts: ", BalanceManager.total_accounts(), "\n")

    for i in 0...c.length
        transactions(c[i], 3000 + i)
        adjust(c[i], 3000 + i)
    end
end

main
  

require_relative 'lab4-2.0'
class Savings < Account
  attr_accessor :interest
  def initialize(init_interest = 0.0)
    super()
    @interest = init_interest >= 0 ? init_interest : 0.0
  end

  def get_interest
    @interest
  end

  def accumulate
    @interest += (1.00426 * (balance + interest))
  end

  def to_string
    "#{@account_number} :\n$ #{balance + interest}"
  end
end

def app
  accounts = []
  account_count = 0

  loop do
    puts "Accounts created: #{account_count}"
    puts "Menu:"
    puts "1. Start an account"
    puts "2. Perform a transaction"
    puts "3. Quit"
    print "Choose an option: "
    choice = gets.chomp.to_i

    break if choice == 3

    if choice == 1
      print "Choose account type (1 for Checking, 2 for Savings): "
      type = gets.chomp.to_i

      print "Enter initial balance: "
      balance = gets.chomp.to_f

      if type == 1
        print "Enter initial fee: "
        init_fee = gets.chomp.to_f
        new_checking = Checking.new(init_fee)
        new_checking.deposit(balance)
        accounts << new_checking
        puts "You have successfully created a new checking account!:\n#{new_checking.to_string}\n"
      elsif type == 2
        print "Please enter initial interest rate: "
        interest = gets.chomp.to_f
        new_savings = Savings.new(interest)
        new_savings.deposit(balance)
        accounts << new_savings
        puts "Created Savings account:\n#{new_savings.to_string}\n"
      end
      account_count += 1
    elsif choice == 2
      print "Enter account number: "
      acc_num = gets.chomp.to_i

      account = accounts.find { |acc| acc.get_account_number == acc_num }
      if account
        print "Select a transaction! Type (1 for deposit, 2 for withdraw): "
        transaction_type = gets.chomp.to_i

        print "Please enter amount: "
        amount = gets.chomp.to_f

        success = false
        if transaction_type == 1
          success = account.deposit(amount)
        elsif transaction_type == 2
          success = account.withdraw(amount)
        end
        if success
          puts "Transaction successful. New balance:\n#{account.to_string}\n"
        else
          puts "Transaction failed.\n"
        end
      else
        puts "Account not found.\n"
      end
    end

    accounts.each do |acc|
      if acc.is_a?(Savings)
        acc.accumulate
      end
    end
  end

  accounts.each(&:delete)
end

app
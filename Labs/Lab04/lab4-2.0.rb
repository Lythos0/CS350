class Account
  attr_accessor :balance, :account_number
  @@acc_num_gen = 162410010000

  def initialize(b = 0)
    if b >= 0
      @balance = b
    else
      @balance = 0
    end
    @account_number = @@acc_num_gen
    @@acc_num_gen += 1
  end

def deposit(amount)
  return false if amount < 0
  @balance += amount
    true
  end

  def withdraw(amount)
    return false if amount < 0 || @balance - amount < 0
    @balance -= amount
    true
  end

  def to_string
    "Account Number: #{@accountnumber}, Balance: #{@balance}"
  end

  def account
    @account_number
  end

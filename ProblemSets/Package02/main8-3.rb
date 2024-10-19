def prime?(n)
  end
  
  def get_prime
    puts "Please enter an integer:"
    input = gets.chomp.to_i
    if prime?(input)
      puts "You entered a prime number: #{input}"
    else
      puts "That's not a prime number. Please try again."
      get_prime_ 
    end
  end
  
  get_prime_
  
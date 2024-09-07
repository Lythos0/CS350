rando = rand(1..100)

max_attempts = 10

puts "Greetings guest! If you can correctly guess the number from 1-100, You will receieve a fabulous prize!"

1.upto(max_attempts) do |attempt|
  print "Attempt #{attempt} of #{max_attempts}: "
  guess = gets.to_i

  if guess == rando
    puts "Ayyyy nice job! You earned a prize!"
    break
  elsif (guess - rando).abs > 20
    puts "OhNAH you are FREEZING!"
  elsif (guess - rando).abs > 10
    puts "Feelin a bit cold there buddy..."
  elsif (guess - rando).abs > 5
    puts "Now we're warming up!"
  else
    puts "Ooooh you are so so warm. ALMOST THERE!"
  end

  if attempt == max_attempts
    puts "Darn.. You're out of attempts. The correct number was #{rando}."
  end
end

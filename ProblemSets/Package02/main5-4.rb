num1 = rand(-100..100)

case

when num1 > 0
    puts "It seems that the number #{num1} is positive"
when num1 < 0 
    puts "Ooh looks like the number #{num1} is negative."
else
    puts "Oh. Well the number #{num1} is zero"
end
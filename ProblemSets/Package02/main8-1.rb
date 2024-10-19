def calculating_quadratic(a,b,c,x)
    results = a * x**2 + b * x + c
    return results
end
puts "What is the value of a?"
a = gets.chomp.to_i
puts "What is the value of b?"
b = gets.chomp.to_i
puts "What is the value of c?"
c = gets.chomp.to_i
puts "What's the value of x?"
x = gets.chomp.to_i

results = calculating_quadratic(a,b,c,x)
puts "Here is the results of the quadratic equation: #{results}"

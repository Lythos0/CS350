target_value = 5
inputs = []
valid_input = false
while !valid_input
  puts "Enter an integer between 1 and 20:"
  input = gets.chomp.to_i
  inputs << input
  if input == target_value
    valid_input = true
end
end
puts "Values entered: #{inputs.join(' ')}"

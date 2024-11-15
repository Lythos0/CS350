require_relative "CharHash.rb"

for i in 'A'..'Z' do
  print Coder.value(i), " "
end
puts 

for i in 0..25 do
  print Coder.key(i), " "
end
puts

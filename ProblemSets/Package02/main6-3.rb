arr = [3, 8, 12, 5, 20, 15]
max_value = arr[0]
i = 1
while i < arr.length
  if arr[i] > max_value
    max_value = arr[i]
  end
  i += 1
end
i = 0
sum = 0

while i < arr.length
  if arr[i] != max_value
    sum += arr[i]
  end
  i += 1
end
puts "Here is the sum without the max value: #{sum}"

letters = ['a', 'b', 'c']
i = 0
while i < letters.length
  j = 0
  while j < letters.length
    k = 0
    while k < letters.length
      if i != j && j != k && i != k
        puts "#{letters[i]}#{letters[j]}#{letters[k]}"
      end
      k += 1
    end
    j += 1
  end
  i += 1
end

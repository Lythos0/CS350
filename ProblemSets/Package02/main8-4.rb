def concatenate_strings(words)
    result = ""
    words.each do |word|
      result += word
    end
    result
  end
  
  word_array = ["corgi", "demon", "sauce", "kitty", "berry", "toast", "melon", "flame"]
  concatenated_result = concatenate_strings(word_array)
  puts "Concatenated String: #{concatenated_result}"
  
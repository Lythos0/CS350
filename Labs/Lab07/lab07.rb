def char_to_num(c)
    if c =~ /[A-Za-z]/
      c.downcase.ord - 'a'.ord
    else
      -1
    end
  end
  
  def num_to_char(n, is_upper)
    is_upper ? ('A'.ord + n).chr : ('a'.ord + n).chr
  end
  
  def encrypt_line(line, key)
    result = ""
    key_index = 0
  
    line.each_char do |char|
      if char =~ /[A-Za-z]/
        text_value = char_to_num(char)
        key_value = char_to_num(key[key_index % key.length])
  
        encrypted_char = num_to_char((text_value + key_value) % 26, char == char.upcase)
        result += encrypted_char
        key_index += 1
      else
        result += char 
      end
    end
  
    result
  end
  
  puts "Please enter a key (letters only): "
  key = gets.chomp
  
  unless key =~ /^[A-Za-z]+$/
    puts "We're sorry, your key is not valid. Only letters are allowed."
    exit
  end
  
  puts "Please enter the filename to encrypt: "
  filename = gets.chomp
  
 
  begin
    input_file = File.open(filename, 'r')
    output_file = File.open("ECopy.txt", 'w')
  
    input_file.each_line do |line|
      encrypted_line = encrypt_line(line, key)
      output_file.puts encrypted_line
    end
  
    puts "The encryption is complete! Saved to 'ECopy.txt'."
  rescue Errno::ENOENT
    puts "Sorry.. It seems your file cannot be opened."
  end
  
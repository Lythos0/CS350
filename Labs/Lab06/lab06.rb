class Cipher

  
  def initialize(alphabet)
    @alphabet = alphabet
    @multiplicative_inverses = {
      5 => 29, 7 => 31, 11 => 23, 13 => 25, 17 => 17,
      19 => 19, 23 => 11, 25 => 13, 29 => 5, 31 => 7, 35 => 35
    }
  end

  def caesar_cipher(text, shift)
    text.chars.map do |char|
      if @alphabet.include?(char.upcase)
        index = (@alphabet.index(char.upcase) + shift) % @alphabet.size
        @alphabet[index]
      else
        char
      end
    end.join
  end

  def affine_cipher(text, a, b)
    mod = @alphabet.size
    mod_inv = @multiplicative_inverses[a] || raise(ArgumentError, "a and mod must be coprime")

    text.chars.map do |char|
      if @alphabet.include?(char.upcase)
        index = (mod_inv * (@alphabet.index(char.upcase) - b)) % mod
        @alphabet[index]
      else
        char
      end
    end.join
  end
end

cipher = Cipher.new('ABCDEFGHIJKLMNOPQRSTUVWXYZ')

plaintext = "HELLO WORLD"
encrypted_caesar = cipher.caesar_cipher(plaintext, 3)
decrypted_caesar = cipher.caesar_cipher(encrypted_caesar, -3)

encrypted_affine = cipher.affine_cipher(plaintext, 5, 8)
decrypted_affine = cipher.affine_cipher(encrypted_affine, 5, 8)

puts "Caesar Cipher:"
puts "  Encrypted: #{encrypted_caesar}"
puts "  Decrypted: #{decrypted_caesar}"

puts "Affine Cipher:"
puts "  Encrypted: #{encrypted_affine}"
puts "  Decrypted: #{decrypted_affine}"

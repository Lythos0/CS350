module Coder
  ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

  def self.value(ch) 
    if (ch.is_a? String) && !ch.match(/[^A-Za-z]/) then
      for i in 0...ALPHA.length do
        return i if ALPHA[i] == ch.upcase
      end
    else
      nil
    end
  end

  def self.key(ch)
    if (ch.is_a? Integer) && ch >= 0 && ch <=25 then
      ALPHA[ch]
    else
      nil
    end  
  end
end

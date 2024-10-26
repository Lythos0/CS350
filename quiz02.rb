class Name
  attr_reader :name
  def initialize(name = "Doe")
    @name = isword?(name) ? name : "Doe"
  end
  def name=(new_name)
    @name = isword?(new_name) ? new_name : @name
  end
  def isword?(s)
    for i in 0...s.size
      return false if !isletter(s[i])
    end
    true
  end
  def isletter(ch)
    ('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')
  end
  def to_s
    @name.capitalize
  end
end

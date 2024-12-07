class V
  att_accessor :x
  def intialize
    @x = 1

  end
end

class U < V
  def initialize
    super()
    @x = 2
  end 
end

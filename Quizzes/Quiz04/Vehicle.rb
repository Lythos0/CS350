class Vehicle
  attr_reader :wheels, :doors

  def initialize(wheels,doors)
    @wheels = wheels >= 1 ? wheels : 1
    @doors = doors > 0 ? doors : 0
  end

  def to_s
    "#{@wheels} wheels and #{@doors} doors vechile"
  end
end
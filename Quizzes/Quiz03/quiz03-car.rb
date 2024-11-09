class Car
  attr_accessor :doors, :wheels
  def initialize(doors)
    @wheels = 4
    @doors = (doors >= 2 && doors <= 4) ? doors : 4
  end

  def doors=(value)
    @doors = (value >= 2 && value <= 4) ? value : @doors
  end

  def to_s
    "4 wheel drive car with #{@doors} doors"
  end
end



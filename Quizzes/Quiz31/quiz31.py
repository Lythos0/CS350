class Shape:
def __init__(self, sides=3):
self.sides = sides 
return sides

@ sides setter
def set.sides(self,value)
if value => 3
sides = value

sides = property(get.sides,set.sides)

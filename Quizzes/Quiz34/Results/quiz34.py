class Shape:
  count = 0
  
def _innit_(self):
  Shape.count+=1

def shapes():
return Shape.count

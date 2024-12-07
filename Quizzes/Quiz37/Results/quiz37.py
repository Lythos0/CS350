class V:
  def __innit__(self):
  self.x = 1

class U(V):
def __innit__(self):
  super()__innit()
  self.x = 2

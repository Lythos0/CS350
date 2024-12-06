#include <iostream>
class Shape{
private:
int sides = 3;
public:
void SetSides(int value){
  if(value >= 3){
  sides = value;
  }
}

int GetSides(){
return sides;
}

};

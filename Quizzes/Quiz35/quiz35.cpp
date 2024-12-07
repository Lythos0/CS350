class Shape{
public:
static int count;

Shape(){
count ++; }


static int shapes(){
  return count;
}
};

int Shape::count = 0;

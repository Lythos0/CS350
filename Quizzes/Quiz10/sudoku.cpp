#include <vector>
#include <stack>
#include <string>

class Sudoku
{
	private:
	std::vector<int> board;
	std::stack<std::string> records;
	std::vector<bool> permanent;
	int digit;

	public:
	Sudoku()
	{
		board = std::vector<int>(81,0);
		permanent = std::vector<bool>(81,false);
		digit = 1;
	}

};

int main()
{
	Sudoku s;
	return 0;
}

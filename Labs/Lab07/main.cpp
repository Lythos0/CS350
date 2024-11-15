#include <iostream>
#include "CharHash.h"

int main() 
{
	for(int i = 0;i < 26;i += 1)
	{
		std::cout << Coder::value('a' + i) << " ";
	}
	std::cout << "\n";
	for(int i = 0;i < 26;i += 1)
	{
		std::cout << Coder::key(i) << " ";
	}
	std::cout << "\n";
	return 0;
}

#include <iostream>
#include <string>

class HangManGame
{
	public:
	virtual void MakeGuess(char) = 0;
       	virtual bool HasSolved() const = 0;
	virtual unsigned int Chances() const = 0;
	virtual bool CanPlay() const = 0;
	virtual std::string ToString() const = 0;
	virtual void Reset() = 0;

	friend std::ostream& operator<<(std::ostream& out,const HangManGame& obj)
	{
		out << obj.ToString();
		return out;
	}
}	

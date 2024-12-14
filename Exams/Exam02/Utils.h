#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Object
{
	virtual std::string to_str() const = 0;

	friend std::ostream& operator<<(std::ostream& out,const Object& obj)
	{
		out << obj.to_str();
		return out;
	}
};

#endif

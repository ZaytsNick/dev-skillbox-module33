#include <iostream>
#include <map>
#include <string>
#include <exception>


void remove(std::map<std::string, int>& product)
{
	std::string tempS;
	int  tempI;
	bool tmp = true;
	while (tmp)
	{
		try {
			std::cout << "Enter vendor code and quantity: ";
			std::cin >> tempS >> tempI;
			if (product.count(tempS) < 1)
				throw std::runtime_error("this product not found");
			if (tempI > product.find(tempS)->second || tempI < 1)
				throw std::runtime_error(tempI<1?"incorrect argument":"value too high");
			if (tempI == product.find(tempS)->second)
				product.erase({ tempS,(const unsigned _int64)tempI });
			else
				product.find(tempS)->second-= tempI;
			tmp = false;
		}
		catch (const std::exception& x) {
			std::cerr << "ERROR: " << x.what() << std::endl;
		}
	}
}

std::pair<std::string, int> add(std::map<std::string, int>& product)
{	
	std::pair<std::string, int> temp;
	bool tmp = true;
	while (tmp)
	{
		try {
			std::cout << "Enter vendor code and quantity: ";
			std::cin >> temp.first >> temp.second;
			if (product.count(temp.first)>0&& (temp.first[0] < 'A' || temp.first[0] > 'Z') && temp.first.size()!=3) {
				throw std::invalid_argument("invalid argument");
			}
			if (temp.second < 1 || temp.second >100) {
				throw std::invalid_argument("invalid argument");
			}
			tmp = false;
		}
		catch (const std::exception& x) {
			std::cerr << "ERROR: " << x.what()  << std::endl;
		}
	}
	return temp;
}

int main()
{
	std::map<std::string, int> product;
	product["A05"] = 10;
	product["G34"] = 15;
	product["F12"] = 5;
	std::string comand="";
	while (comand != "exit")
	{
		std::cout << "Enter command: ";
		std::cin >> comand;
		
		if (comand == "add")
			product.insert(add(product));
		else if (comand == "remove")
			remove(product);
	}
}
#include <iostream>
#include <map>
#include <string>
#include <exception>

class Fish
{
public:
	std::string getName()
	{
		return name;
	}
private:
	std::string name = "fish";
};
class Boot
{
public:
	std::string getName()
	{
		return name;
	}
private:
	std::string name = "boot";
};
struct SectorWater
{
	Fish* fish = nullptr;
	Boot* boot= nullptr;
	~SectorWater()
	{
		delete fish;
		delete boot;
	}
}; 

void setWater(SectorWater water[3][3])
{
	water[std::rand() % 3][std::rand() % 3].fish = new Fish();
	std::srand(std::time_t(0));
	for (int i = 3; i != 0;)
	{
		int j(rand() % 3), k(rand() % 3);
		water[j][k].boot == nullptr ? (water[j][k].fish == nullptr ? (water[j][k].boot = new Boot(), i--) : 0) : 0;
	}
}
class YouLose :public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "You LOSE!";
	}
};
class YouWon:public std::exception
{
public:
	const char* what() const noexcept override
	{
		return "You WON!";
	}
};
void getWater(SectorWater water[3][3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << (water[i][j].fish == nullptr ? (water[i][j].boot == nullptr ? " " : "B") : "F");
		}
		std::cout << std::endl;
	};
}

int main()
{
	SectorWater water[3][3];
	setWater(water);
	//getWater(water);
		while (true)
		{
			try
			{
				std::cout << "Enter where to cast your fishing rod: ";
				int i, j;
				std::cin >> i>>j;
				if (i < 0 || i>2 || j < 0 || j>2)
				{
					throw std::invalid_argument("invalid argument");
				}
				if (water[i][j].boot != nullptr)
				{
					throw YouLose();
				}
				else if (water[i][j].fish != nullptr)
				{
					throw YouWon();
				}
			}
			catch (const YouLose& x)
			{
				std::cerr<<x.what();
				break;
			}
			catch (const YouWon& x)
			{
				std::cerr << x.what();
				break;
			}
			catch (const std::exception& x)
			{
				std::cerr << x.what()<<std::endl;
			}
		
	}
}
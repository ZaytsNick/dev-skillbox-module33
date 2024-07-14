#include <iostream>
#include <string>
#include <vector>

#define KEY int
#define VALUE std::string

template<typename T1,typename T2>

class Registry
{
public:
    Registry()
    {
        std::cout << "Enter key and value: ";
        std::cin >> key >> value;
    }
    Registry(T1 _key, T2 _value) :key(_key), value(_value){}
    T1 getKey() const
    {
        return key;
    }
    T2 getValue() const
    {
        return value;
    }
private:
    T1 key;
    T2 value;    
};


int main()
{

    std::vector <Registry<KEY, VALUE>> registry;
    std::string command;
    while (command != "exit") {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "add")
        {
            registry.push_back(Registry<KEY, VALUE>());
        }
        if (command == "remove")
        {
            std::cout << "Enter key: ";
            KEY tempKey;
            std::cin >> tempKey;
            registry.erase(
                std::remove_if(registry.begin(), registry.end(),
                    [&tempKey](const Registry<KEY,VALUE>& item) { return item.getKey() == tempKey; }),
                registry.end());
        }
        if (command == "print")
        {
            for (auto i(0); i < registry.size(); ++i)
            {
                std::cout << "Key:\t" << registry[i].getKey() << "\tValue:\t" << registry[i].getValue() << std::endl;
            }
        }
        if (command == "find")
        {
            std::cout << "Enter key: ";
            KEY tempKey;
            std::cin >> tempKey;
            std::cout << std::endl;
            for (auto i(0); i < registry.size(); i++)
            {
                if (registry[i].getKey() == tempKey)
                    std::cout << registry[i].getValue() << ",";
            }
            std::cout << std::endl;
        }
    }
}
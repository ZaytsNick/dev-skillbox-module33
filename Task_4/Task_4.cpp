#include <iostream>
#include <numeric>
//#define TYPE double;
template < typename T >
void input(T array[8])
{
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}
template < typename T >
T average(T array[8])
{
    T sum(0);
    for (int i = 0; i < 8; ++i)
    {
        sum+= array[i];
    }
    return sum / 8;
}

int main()
{
    double arr[8];
    input(arr);
    std::cout<<"Answer: "<<average(arr);
}
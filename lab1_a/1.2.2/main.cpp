#include <iostream>
  
int main()
{
    std::string num;
    std::cin >> num;
    auto point_pos = num.find('.');
    std::cout << num[point_pos+4];

    return 0;
}

#include <iostream>

int main()
{
  size_t t = 0;
  double sum = 0;
  while(std::cin >> t){
    sum += t*t;
  }
  if(std::cin.eof()){
    std::cout << sum << '\n';
    return 0;
  }else if (std::cin.fail()) {
    std::cout << "Sudar, vse ploho\n";
    return 1;
  }
}


#include <iostream>

int main()
{
  size_t count = 0;
  int t = 0;
  while(true){
    std::cin >> t;
    if(std::cin.eof()){
      std::cout << count << '\n';
      return 0;
    }else if (std::cin.fail()) {
      std::cout << "Sudar, vse ploho\n";
      return 1;
    }
    count++;
  }

}

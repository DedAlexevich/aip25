#include <iostream>

int main()
{
  double sum = 0;
  size_t count = 0;
  int t = 0;
  while(true){
    std::cin >> t;
    if(std::cin.eof){
      if(count == 0) return 0; 
      std::cout << sum/count << '\n'; 
      return 0;
    }else if (std::cin.fail) {
      std::cout << "Sudar, vse ploho\n";
      return 1;
    }
    sum += t;
    count++;
  }

}

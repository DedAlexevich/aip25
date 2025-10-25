#include <iostream>

bool isPth(int a, int b, int c);

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}


int main()
{
  int a = 0, b = 0, c = 0;
  size_t count = 0;
  std::cin >> c >> b;
    
  if (b <= 0 || c <= 0){
      std::cerr << "The side lengths are always positive\n";
      return 1;
  }
  while (std::cin >> a) {
    count += isPth(a,b,c);
    c = b;
    b = a;
  }
    
  if (std::cin.eof()){
    std::cout << count << '\n';
    return 0;
  } else if (std::cin.fail()) {
    std::cerr << "Сouldn't count the sequence\n";
    return 1;
  }
}


bool isPth(int a, int b, int c)
{
  int greate = max(a,max(b,c));
  int lower = min(a,min(b,c));
  int median = a - greate + b - lower + c;
  return greate * greate == (lower * lower + median * median);
}


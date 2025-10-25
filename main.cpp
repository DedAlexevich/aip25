
#include <iostream>

bool isPth(size_t a, size_t b, size_t c);

int main()
{
  size_t a = 0, b = 0, c = 0;
  size_t count = 0;
  std::cin >> c >> b;
  while (std::cin >> a) {
    count += isPth(a,b,c);
    c = b;
    b = a;
  }
  if (std::cin.eof()){
    std::cout << count << '\n';
    return 0;
  }else if (std::cin.fail()) {
    std::cout << "Man, u are mistake\n";
    return 1;
  }
}


bool isPth(size_t a, size_t b, size_t c)
{
  bool d = a*a == (b*b + c*c);
  d = d || (b*b == (a*a + c*c));
  d = d || (c*c == (a*a + b*b));
  return d;
}

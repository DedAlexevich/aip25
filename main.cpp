#include <iostream>

bool isPth(size_t a, size_t b, size_t c);

size_t max(size_t a, size_t b)
{
  return a > b ? a : b;
}

size_t min(size_t a, size_t b)
{
  return a < b ? a : b;
}

bool canSquare(size_t a)
{
  size_t MAX = std::numeric_limits<size_t>::max();
  if (MAX / a < a) return false;
  return true;
}

bool canSumSquared(size_t a, size_t b)
{
  size_t MAX = std::numeric_limits<size_t>::max();
  if (MAX - a < b) {
      return false;
  }
  return true;
}

int main()
{
  size_t a = 0, b = 0, c = 0;
  size_t count = 0;
  std::cin >> c >> b;
    
  if (std::cin.eof()){
    std::cerr << "Need 3 number";
    return 1;
  }

    
  while (std::cin >> a) {
    try {
      count += isPth(a,b,c);
    } catch (const std::overflow_error& e) {
        std::cerr << e.what();
        return 2;
    }
    c = b;
    b = a;
  }

  if (std::cin.eof()) {
    std::cout << count << '\n';
    return 0;
  } else if (std::cin.fail()) {
    std::cerr << "Couldn't count the number\n";
    return 1;
  }
}


bool isPth(size_t a, size_t b, size_t c)
{
  size_t great = max(a,max(b,c));
  size_t lower = min(a,min(b,c));
  size_t median = a - great + b - lower + c;
  if (!canSquare(great)) {
    throw std::overflow_error("cant great multiply by great\n");
  }
  if (!canSumSquared(lower * lower, median * median)) {
    throw std::overflow_error("cant sum lower^2 and median^2");
  }
  return great * great == (lower * lower + median * median);
}


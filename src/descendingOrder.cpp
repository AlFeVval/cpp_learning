#include <stack/stack.h>

uint64_t descendingOrder(uint64_t n)
{
  Stack digits;
  Stack sorted;
  uint64_t temp = n;
  uint64_t result = 0;

  if(n == 0) 
    return 0;

  while(temp > 0)
  {
    digits.push(temp % 10);
    temp /= 10;
  }

  while(!digits.isEmpty())
  {
    uint64_t current = digits.pop();
    while(!sorted.isEmpty() && sorted.peek() > current)
    {
      digits.push(sorted.pop());
    }
    sorted.push(current);
  }

  while(!sorted.isEmpty())
  {
    result = result * 10 + sorted.pop();
  }

  return result;
}

int main() {
    // Test cases
    std::cout << "Using custom stack implementation:" << std::endl;
    std::cout << "descendingOrder(123456789) = " << descendingOrder(123456789) << std::endl;
    std::cout << "descendingOrder(0) = " << descendingOrder(0) << std::endl;
    std::cout << "descendingOrder(1024) = " << descendingOrder(1024) << std::endl;
    std::cout << "descendingOrder(987654321) = " << descendingOrder(987654321) << std::endl;
    
    return 0;
}

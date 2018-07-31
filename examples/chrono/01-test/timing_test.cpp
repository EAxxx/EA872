#include <iostream>
#include <chrono>
#include <thread>

int main ()
{
  std::cout << "Count!\n";
  for (int i=10; i>0; --i) {
    std::cout << i << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
  }
  std::cout << "The End\n";
  return 0;
}

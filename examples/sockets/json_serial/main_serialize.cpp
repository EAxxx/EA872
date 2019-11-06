
#include <iostream>
#include <string>
#include "serializable.hpp"

int main() {
  RelevantData D1(50, 80);
  RelevantData D2(100, 90);
  std::string buffer;

  std::cout << "Originais:\n";
  D1.dump();
  D2.dump();

  buffer = D1.serialize();

  std::cout << "Recuperado:\n";
  D2.unserialize(buffer);

  D2.dump();

  return 0;
}

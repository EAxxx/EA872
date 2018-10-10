
#include <iostream>
#include <string>
#include "serializable.hpp"

int main() {
  RelevantData D1(50, 'a');
  RelevantData D2(100, 'b');

  std::string buffer(sizeof(DataContainer), ' ');

  std::cout << "Originais:\n";
  D1.dump();
  D2.dump();

  D1.serialize(buffer);

  std::cout << "Recuperado:\n";
  D2.unserialize(buffer);

  D2.dump();

  return 0;
}

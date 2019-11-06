#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <fstream>
#include <iostream>
#include <string>

struct DataContainer {
  int a;
  int b;
};

class RelevantData {
  private:
    DataContainer data;

  public:
    RelevantData();
    RelevantData(int a, char b);
    RelevantData(std::string buffer_in);
    std::string serialize();
    void unserialize(std::string buffer_in);
    void dump();
};

#endif

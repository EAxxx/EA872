#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include <fstream>
#include <iostream>
#include <string>

struct DataContainer {
  int a;
  char b;
};

class RelevantData {
  private:
    DataContainer data;

  public:
    RelevantData();
    RelevantData(int a, char b);
    RelevantData(std::string buffer_in);
    void serialize(std::string &buffer_out);
    void unserialize(std::string buffer_in);
    void dump();
};

#endif

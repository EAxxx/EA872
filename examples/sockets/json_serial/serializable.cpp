
#include "serializable.hpp"

#include <string>
#include <cstring>

// JSON library
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/*
class RelevantData {
  private:
    int a;
    char b;

  public:
    RelevantData(int a, char b);
    RelevantData(std::string serial_data);
    std::string serialize();
};
*/

RelevantData::RelevantData() {
};

RelevantData::RelevantData(int a, char b) {
  this->data.a = a;
  this->data.b = b;
}

RelevantData::RelevantData(std::string buffer_in) {
  this->unserialize(buffer_in);
}

std::string RelevantData::serialize() {
  json j;
  j["a"] = this->data.a;
  j["b"] = this->data.b;
  return j.dump();
}

void RelevantData::unserialize(std::string buffer_in) {
  json j;
  j = json::parse(buffer_in);
  this->data.a = j.at("a");
  this->data.b = j.at("b");
}

void RelevantData::dump() {
  std::cout << this->data.a << '\n' << this->data.b << std::endl;
}

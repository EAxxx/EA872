
#include <iostream>

#include "sinesynth.h"

int main() {
  SineSynth *s = new SineSynth();
  s->init(8, 16);
  s->setFreq(4);
  for (int i=0; i<16; i++) {
    std::cout << s->getSample() << "\n";
  }
  return 0;
}

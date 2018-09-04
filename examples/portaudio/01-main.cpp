
#include "01-playback.hpp"

#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main() {

  uint64_t t0, t1;

  Audio::Sample *asample;
  asample = new Audio::Sample();
  asample->load("assets/blip.dat");

  Audio::Player *player;
  player = new Audio::Player();
  player->init();

  // Espera
  while (1) {
    std::this_thread::sleep_for (std::chrono::milliseconds(1));
    t1 = get_now_ms();
    if (t1-t0 > 500) break;
  }

  std::cout << "Audio initialized!\n";

  player->play(asample);

  t0 = get_now_ms();
  while (1) {
    std::this_thread::sleep_for (std::chrono::milliseconds(1));
    t1 = get_now_ms();

    if (t1-t0 > 500) break;
  }

  asample->set_position(0);

  t0 = get_now_ms();
  while (1) {
    std::this_thread::sleep_for (std::chrono::milliseconds(1));
    t1 = get_now_ms();

    if (t1-t0 > 500) break;
  }


  player->stop();

  return 0;
}

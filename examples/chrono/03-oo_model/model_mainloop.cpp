#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

#include "oo_model.hpp"

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main ()
{
  Corpo *c = new Corpo(10, 0, 10);
  ListaDeCorpos *l = new ListaDeCorpos();
  l->add_corpo(c);

  Fisica *f = new Fisica(l);

  std::cout << "Iniciando simulacao\n";
  std::cout << "Simulando por 3 segundos\n";

  uint64_t t0;
  uint64_t t1;
  uint64_t deltaT;
  uint64_t T;

  int i = 0;

  T = get_now_ms();
  t1 = T;
  while (1) {
    // Atualiza timers
    t0 = t1;
    t1 = get_now_ms();
    deltaT = t1-t0;

    // Atualiza modelo
    f->update(deltaT);

    std::vector<Corpo *> *corpos = l->get_corpos();

    for (int j=0; j<corpos->size(); j++)
    {
      std::cout << i << " t=" << (t1-T)/1000. << " - Altura = ";
      std::cout << (*corpos)[j]->get_posicao() << " - Velocidade = ";
      std::cout << (*corpos)[j]->get_velocidade() << std::endl;
    }

    // Condicao de parada
    if ( (t1-T) > 3000 ) break;

    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    i++;
  }
  std::cout << "The End\n";
  return 0;
}

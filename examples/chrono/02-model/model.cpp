#include <iostream>
#include <chrono>
#include <thread>

// Definicoes do modelo fisico
// Situacao: objeto caindo de grande altura
float altura = 10; // Altura inicial, metros
float velocidade = 0; // Velocidade inicial, m/s

float gravidade = -10.0; // m/s^2


// Encontrar tempo de sistema em ms

using namespace std::chrono;
uint64_t get_now_ms() {
  return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

int main ()
{
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
    velocidade = velocidade + gravidade * (float)deltaT/1000;
    altura = altura + velocidade * (float)deltaT/1000;

    // Imprime situacao do modelo na tela
    std::cout << i << " t=" << (t1-T)/1000. << " - Altura = " << altura << " - Velocidade = " << velocidade << std::endl;
    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    i++;

    // Condicao de parada
    if ( (t1-T) > 3000 ) break;
  }
  std::cout << "The End\n";
  return 0;
}

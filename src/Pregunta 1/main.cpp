#include <iostream>

using namespace std;

class Piedra
{
  private:
    int tipo; // 0: pequeña ; 1: grande
    bool hunde;
    int distancia;

  public:
    Piedra();
    Piedra(int tipo, int distancia);
    ~Piedra();
    int getDistancia();
    bool estaHundida();
    void seHundio();
};

Piedra::Piedra()
{
    this->tipo = 0;
    this->distancia = 0;
    this->hunde = false;
}

Piedra::Piedra(int tipo, int distancia)
{
    this->tipo = tipo;
    this->distancia = distancia;
    this->hunde = false;
}

int Piedra::getDistancia()
{
    return this->distancia;
}

bool Piedra::estaHundida()
{
    return this->hunde;
}

void Piedra::seHundio()
{
    this->hunde = true;
}

main(int argc, char const *argv[])
{
    cout << "Hola Mundo" << endl;

    return 0;
}

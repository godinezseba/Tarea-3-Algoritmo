#include <iostream>

using namespace std;

class Piedra
{
  private:
    int tipo;
    bool hunde;
    int distancia;

  public:
    Piedra(int tipo, int distancia);
    int getDistancia();
    bool estaHundida();
    void seHundio();
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

#include <iostream>

using namespace std;

class Piedra
{
  private:
    char tipo; // P: pequeña ; G: grande
    bool hunde;
    int distancia;

  public:
    Piedra();
    Piedra(char tipo, int distancia);
    ~Piedra();
    int getDistancia();
    char getTipo();
    bool estaHundida();
    void seHundio();
};

Piedra::Piedra()
{
    this->tipo = ' ';
    this->distancia = 0;
    this->hunde = false;
}

Piedra::Piedra(char tipo, int distancia)
{
    this->tipo = tipo;
    this->distancia = distancia;
    this->hunde = false;
}

int Piedra::getDistancia()
{
    return this->distancia;
}

char Piedra::getTipo()
{
    return this->tipo;
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

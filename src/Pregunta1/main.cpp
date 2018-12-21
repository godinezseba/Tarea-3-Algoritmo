#include <iostream>
#include <string>

using namespace std;

class Piedra{
  private:
    string tipo; // P: pequeña ; G: grande
    bool hunde;
    int distancia;

  public:
    Piedra();
    Piedra(string tipo, int distancia);
    ~Piedra();
    int getDistancia();
    string getTipo();
    bool estaHundida();
    void seHundio();
};

Piedra::Piedra(){
    this->tipo = ' ';
    this->distancia = 0;
    this->hunde = false;
}

Piedra::Piedra(string tipo, int distancia){
    this->tipo = tipo;
    this->distancia = distancia;
    this->hunde = false;
}

Piedra::~Piedra(){

}

int Piedra::getDistancia(){
    return this->distancia;
}

string Piedra::getTipo(){
    return this->tipo;
}

bool Piedra::estaHundida(){
    return this->hunde;
}

void Piedra::seHundio(){
    this->hunde = true;
}

int main(int argc, char const *argv[]){
    int cantidad, distanciatotal;
    string cadena;
    string temptipo;
    int tempdist;
    Piedra camino[cantidad];

    // solicito datos:
    cin >> cantidad >> distanciatotal;
    for(int i = 0; i < cantidad; i++){
        cin >> cadena;
        temptipo = cadena.at(0);
        tempdist = stoi(cadena.substr(2), nullptr);
        camino[i] = Piedra(temptipo, tempdist);
    }

    cout << cantidad << " " << distanciatotal << endl;
    
    // for(int i = 0; i < cantidad; i++){
    //     cout << camino[i].getDistancia() << " " << camino[i].getTipo() << endl;
    // }
    
    int recorrido = 0;
    // CALCULO DE IDA:
    int i = 0; // posicion piedra actual
    while( i + 2 < cantidad ){ // mientras pueda revisar 2 piedras mas adelante:
        // planteamos la condicion del Dani:
        if(camino[i+1].getTipo() == "P" && camino[i+2].getTipo() == "P"){
            camino[i+2].seHundio(); // me muevo 2 posiciones
            i = i + 2;
        } else{ // sino me muevo 1
            if(camino[i+1].getTipo() == "P"){
                camino[i+1].seHundio();
            }
            i++;
        }
        recorrido ++;
    }
    // ultimas piedras sin analizar
    if(cantidad - i == 3){ // me quedan 2 piedras
        if(camino[i+1].getTipo() == "P" && camino[i+2].getTipo() == "P"){
            camino[i+2].seHundio(); // me muevo 2 posiciones
            i = i + 2;
            recorrido ++;
        } else{ // sino me muevo 1
            if(camino[i+1].getTipo() == "P"){
                camino[i+1].seHundio();
            }
            i++;
        }
    }else{
        if(camino[i+1].getTipo() == "P"){
            camino[i+1].seHundio();
        }
    }
    // CALCULO DE VUELTA:
    
    for(int i = cantidad-1; i >= 0 ; i++){
        // si la piedra no esta hundida, la recorro
        if (not(camino[i].estaHundida())) {
            recorrido ++;
        }
    }
    // imprimo el resultado
    cout << recorrido << endl;

    return 0;
}

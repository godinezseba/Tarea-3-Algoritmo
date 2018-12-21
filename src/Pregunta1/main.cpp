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

int mayor(int distancia, Piedra A, Piedra B){
    int distPiedras;
    distPiedras = abs(A.getDistancia() - B.getDistancia());
    if(distancia > distPiedras){
        return distancia;
    }
    else{
        return distPiedras;
    }
}

void printRuteo(int a, int b,Piedra camino[]){
    cout << camino[a].getTipo() << " " << a << " ";
    cout << camino[b].getTipo() << " " << b << " ";
    cout << "distancia: " << abs(camino[b].getDistancia() - camino[a].getDistancia()) << endl;
            
}

int main(int argc, char const *argv[]){
    int cantidad, distanciatotal;
    string cadena;
    string temptipo;
    int tempdist;
    // solicito datos:
    cin >> cantidad >> distanciatotal;
    Piedra camino[cantidad + 2];

    for(int i = 1; i <= cantidad; i++){
        cin >> cadena;
        temptipo = cadena.at(0);
        tempdist = stoi(cadena.substr(2), nullptr);
        camino[i] = Piedra(temptipo, tempdist);
    }
    // agrego los extremos
    camino[0] = Piedra("I", 0);
    camino[cantidad + 1] = Piedra("D", distanciatotal);
    // for(int i = 0; i < cantidad+2; i++){
    //     cout << camino[i].getDistancia() << " " << camino[i].getTipo();
    //     cout << " pos: " << i << endl;
    // }
    
    int distancia = abs(camino[1].getDistancia() - camino[0].getDistancia());
    // CALCULO DE IDA:
    int i = 0; // posicion piedra actual
    while( i + 1 < cantidad + 2 ){ // mientras no este en la ultima piedra
        if(camino[i + 1].getTipo() == "D"){ // si me quedan 2 piedras y entremedio tengo una chica, termino
            // printRuteo(i, i+1, camino);
            distancia = mayor(distancia, camino[i], camino[i + 1]);
            i ++;
        }
        // planteamos las condiciones del Dani:
        else if(camino[i + 1].getTipo() == "P" && camino[i + 2].getTipo() == "P"){ // dos siguientes chicos
            camino[i + 2].seHundio(); // me muevo 2 posiciones
            // printRuteo(i, i+2, camino);
            distancia = mayor(distancia, camino[i], camino[i+2]);
            i = i + 2;
        } 
        else if(camino[i + 1].getTipo() == "P"){ // si el siguiente es pequeño, entonces me muevo a la subsiguiente
            // printRuteo(i, i+2, camino);
            distancia = mayor(distancia, camino[i], camino[i+2]);
            i = i + 2;
        }
        else{ // sino me muevo 1
            // printRuteo(i, i+1, camino);
            distancia = mayor(distancia, camino[i], camino[i+1]);
            i++;
        }
    }
    // cout << "de vuelta" << endl;
    // CALCULO DE VUELTA:
    i = cantidad; // analizo desde el extremo derecho
    int otro; // posicion de la otra piedra
    while(i-1 >= 0){ // mientras este en una piedra y no en el extremo izquierdo
        // si la piedra no esta hundida, la recorro
        otro = i-1;
        while(otro - 1 >= 0 && camino[otro].estaHundida()) otro --; // busco hasta obtener una piedra que no este hundida
        
        // printRuteo(i, i+1, camino);
        distancia = mayor(distancia, camino[i], camino[otro]);
        i = otro;
    }
    // imprimo el resultado
    cout << distancia << endl;

    return 0;
}

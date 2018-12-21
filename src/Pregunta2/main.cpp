#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int s;
    int i;
    int var;

    while(cin >> s){
        int *data = new int[s];
        for(i=0;i<s;i++){
            cin >> var;
            data[i] = var;


        }
        delete [] data;

    }

    return 0;
}

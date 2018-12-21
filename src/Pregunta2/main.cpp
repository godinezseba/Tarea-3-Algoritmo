#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

// Encuentra la subsecuencia creciente mas grande 
int helper(int *array,int var){

    int i;
    int j;
    int max;
    int maxGlobal;

    maxGlobal = 0;

    int *data = new int[var];
    data[0] = 1;

    for (i = 1; i<var; i++){
        max = 0;
        for(j =0;j<i;j++){
            if(array[i]>array[j] && data[j] > max){
                max = data[j];
            }
        }
        
        data [i] = max + 1;
        if (data[i] > maxGlobal) maxGlobal =data[i];
    }


    delete [] data;
    return maxGlobal;
}

int main(int argc, char const *argv[])
{
    int s;
    int i;
    int var;
    int resp;

    while(cin >> s){
        int *data = new int[s];
        for(i=0;i<s;i++){
            cin >> var;
            data[i] = var;


        }

        resp = helper(data,s);

        cout << s - resp << endl;
        delete [] data;

    }

    return 0;
}

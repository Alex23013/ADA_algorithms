#include <iostream>
#include <algorithm>
#include <thread>
#include "Selection.h"

using namespace std;



int main(){

    srand(time(NULL));

    vector<int> array;
    vector<int> result;

    int n;
    double x;

    int n_threads = 4;

        n = 100;

        for (int i = 0; i < n; i++){
            array.push_back(rand() % n);
        }
	print(array);
        cout<<"--------------------\n";

        clock_t start = clock();

        //Selection_Sort(&array);

Selection_sortP(&array);
        x = (clock() - start) / (double)(CLOCKS_PER_SEC);

        orden(&array);

        if(flag){
            cout<<"Ordenado";
        

        cout<<endl<<"Tiempo: "<<x<<"\nHilos: "<<n_threads<<"\nCantidad Elementos: "<<n<<endl<<"--------------------\n";
        print(array);       
    }


}


#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

template <typename T>
void Insertion_Sort(vector<T>* _array){
    int n = _array->size(),
        j = 0,
        x = 0;

    for (int i = 1; i < n; i++){
        x = _array->at(i);
        j = i;
        while(j > 0 &&  ( _array->at(j-1) > x ) ){
            _array->at(j) = _array->at(j-1);
            j--;
        }
        _array->at(j) = x;
    }
}

int Pivot_Sort(vector<int>* _array, int _start, int _end){
    int x = _array->at(_end);
    int i = (_start - 1);
    for (int j = _start; j <= _end - 1; j++){

        if (_array->at(j) <= x){                            ///Solo considera menores pues al hacer swap los mayores
            i++;
            swap(*(_array->begin()+i), *(_array->begin()+j));
        }
    }

    swap(*(_array->begin()+i+1), *(_array->begin()+_end));
    return (i + 1);                                         ///Siguiente a ordenar
}

void QuickSort(vector<int>* _array){
    vector<int> pila;
    pila.push_back(0);
    pila.push_back(_array->size()-1);

    while ( !pila.empty() ) {

        int fin = pila.back();
        pila.pop_back();                        ///Elimina de la pila
        int ini = pila.back();                  ///Copia a la pila
        pila.pop_back();

        int tmp = Pivot_Sort(_array, ini, fin);     ///Ordena el vector[ini;fin] respecto al pivote

        if(tmp-1 > ini){
            pila.push_back(ini);                    ///Agrega lado izquierdo
            pila.push_back(tmp-1);
        }
        if(tmp+1 < fin){
            pila.push_back(tmp+1);                    ///Agrega lado derecho
            pila.push_back(fin);
        }
    }
}


template <typename T>
void print(vector<T> _array){
    int n = _array.size();
    for (int i = 0; i < n; i++){
        cout<<_array[i]<<"-";
    }
    cout<<endl;
}




int main() {

    vector<int> array;
    int n;
    srand(time(NULL));

    int elementos[4] = {1000,3000,5000,7000};
    int opcion = 7;
    while(opcion != 0){
        cout<<"Desea ver: \n 1) Mejor caso \n 2) Caso medio \n 3) Peor caso\n 0) salir\n";
        cin>>opcion;

        for(int i = 0; i < 4; i++){

            n = elementos[i];

            double time = 0;
             int tests = 10;

             for (int i = 0; i < tests ; i++) {

                 if(opcion < 3 && opcion != 0){

                    for (int i = 0; i < n; i++){array.push_back(i);}
                    if (opcion == 2){
                        auto randomFun =[] (int i) { return rand()%i;};
                        random_shuffle(array.begin(), array.end(), randomFun);
                    }
                 }
                 if(opcion ==3){
                    for (int i = 0; i < n; i++){array.push_back(n-i);}
                 }


                 high_resolution_clock::time_point t1 = high_resolution_clock::now();
                 Insertion_Sort(&array);
                 // QuickSort(&array);// intercambiar con la linea de arriba para ver los tiempos del otro sort
                 high_resolution_clock::time_point t2 = high_resolution_clock::now();
                 auto res = duration_cast<microseconds>( t2 - t1 ).count();
                 time += res;
                 array.clear();
            }

            long long  ttime = time/tests;
            if(opcion != 0){
                cout << "tiempo:" << ttime/1000.0<< " milliseconds con " <<elementos[i]<< endl ;
            }

        }
    }


}


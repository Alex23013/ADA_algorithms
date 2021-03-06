#include <iostream>
#include <chrono>
#include <utility>
#include <vector>
#include <string>
#include<sstream>
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



template <typename T>
void print(vector<T> _array){
    int n = _array.size();
    for (int i = 0; i < n; i++){
        cout<<_array[i]<<"-";
    }
    cout<<endl;
}
void heapify(vector<int> *arr , int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr->at(l) > arr->at(largest))
        largest = l;
    if (r < n && arr->at(r) > arr->at(largest))
        largest = r;
    if (largest != i)
    {
        swap(arr->at(i), arr->at(largest));
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>* arr)
{
    int n = arr->size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr->at(0), arr->at(i));
        heapify(arr, i, 0);
    }
}


template <typename T>
int digitos_num ( T Number )
{
    string number;
    stringstream ss;
    ss << Number;
    number = ss.str();
    return number.size();
}

template <typename T>
int max_digitos(vector<T>* a){
    int n = a->size();
    int max=0;
    for(int i =0;i< n;i++){
        if(max < a->at(i)){
            max=a->at(i);
        }
    }
    return max;
}

template <typename T>
void radix_sort(vector<T> *a){
int n = a->size();
int temp[10];
int res[n];
int div =10;
int digito;
int num_digitos = digitos_num(max_digitos(a));
for(int j =0;j<num_digitos;j++){
    for(int i=0;i<10;i++){temp[i]= 0;}

    for(int i =0;i<n;i++){
        //cout<<(a[i]%div)/(div/10)<<" / ";//para ver que digito se esta analizando
        digito =(a->at(i)%div)/(div/10);
        temp[digito]+=1;
    }
    for(int i=0;i<10;i++){;
        temp[i+1]=temp[i]+temp[i+1];}

    for(int i=n-1;i>=0;i--){
        digito =(a->at(i)%div)/(div/10);
        temp[digito]-=1;
        res[temp[digito]]=a->at(i);
    }
    for(int i =0;i <n ;i++){
        a->at(i)= res[i];
    }
    div=div*10;
    //cout<<"\n------------------------\n";//para asegurarse la cantidad de loops
    }
}

int main() {

    vector<int> array;
    int n;
    srand(time(NULL));

    int elementos[4] = {100,3000,5000,7000};
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
                 // intercambiar las linea comentadas para ver los tiempos de los 3 sorts

                 Insertion_Sort(&array);
                // heapSort(&array);
                 //radix_sort(&array);

                 //print(array); //para verificar que los array estan ordenados
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

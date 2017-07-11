#include <iostream>
#include <vector>
#include <mutex>
#include <thread>

using namespace std;

mutex F;
bool Sorted_flag = false;
vector<thread*> threads;
int n_cores = thread::hardware_concurrency();

void Stupid_Sorting(vector<int>);

bool Sorted(vector<int>*);

void print(vector<int>);

void Stupid_PSort(vector<int>*);

void Stupid_Sort(vector<int>*);

int main(){

    vector<int> array;

	int siz=10;
	srand((unsigned)time(NULL));
 
	int arreglo[siz];
	for (int i = 0; i < siz; i++) {
		array.push_back(rand() % 100);
	}
     	print(array);   

	//clock_int start = clock();


        //Stupid_PSort(&array);
	 Stupid_Sort(&array);
	print(array); 

   	//cout <<"---"<<  (clock() - start) / (double)(CLOCKS_PER_SEC *10)<<"---\n";
}

void Stupid_Sort(vector<int>* _array){

    srand(time(NULL));
    int n = _array->size();

    while(!Sorted(_array)){
        for (int i = 0; i < n; i++){
            swap(_array->at(rand()%n), _array->at(rand()%n));
        }
    }
}


void Stupid_PSort(vector<int>* _array){

    srand(time(NULL));

    while(!Sorted_flag){
        threads.push_back(new thread(Stupid_Sorting, *_array));
    }
    for(int i = 0; i < threads.size(); i++){
        threads[i]->join();
    }
}

void Stupid_Sorting(vector<int> _array){
    int n = _array.size();
    for (int i = 0; i < n; i++){
        swap(_array.at(rand()%n), _array.at(rand()%n));
    }
    if(Sorted(&_array)){
        Sorted_flag = true;
        print(_array);
    }
}

bool Sorted(vector<int>* _array){
    int n = _array->size();
    for (int i = 1; i < n; i++){
        if(_array->at(i-1) > _array->at(i)){
            return false;
        }
    }
    return true;
}

void print(vector<int> a){

    int n = a.size();

    for (int i = 0; i < n; i++){
        cout << a[i] << "-";
    }
    cout<<endl;

}



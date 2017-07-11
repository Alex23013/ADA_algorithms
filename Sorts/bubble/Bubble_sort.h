#include <vector>
#include <mutex>

using namespace std;

mutex F;

void print(vector<int> a){

    int siz = a.size();
    for (int i = 0; i < siz; i++){
        cout << a[i] << "-";
    }
    cout<<endl;  

}



int NT =4;
vector<thread*> threads;
bool cambio = true;

void Bubble_PSort(vector<int>* _array){

    int siz = _array->size();

    while (cambio){

        cambio = false;

        for (int j = 1; j < siz; j++){

            F.lock();

            if (_array->at(j-1) > _array->at(j)){
                swap(_array->at(j-1), _array->at(j));
                cambio = true;
            }


            if (j == siz/2  && threads.size() < NT){
                threads.push_back(new thread(Bubble_PSort, _array));
            }

            F.unlock();
        }

    }

}


bool flag = false;

void verify(vector<int>* _array){

    int siz = _array->size();

    for (int i = 1; i < siz; i++){

        if(_array->at(i-1) > _array->at(i)){
            flag = false;
            return;
        }
    }
    flag = true;
}


void orden(vector<int>* _array){

    int siz = _array->size();
    int cores =4;

    vector<int> _array1(_array->begin(), _array->begin() + (siz/4));
    vector<int> _array2(_array->begin() + ((siz/4)), _array->begin() + siz/2);
    vector<int> _array3(_array->begin() + ((siz/2)), _array->begin() + 3*(siz/4));
    vector<int> _array4(_array->begin() + (3*(siz/4)), _array->end());

vector <vector<int>> vectors(cores);
vectors.push_back(_array1);
vectors.push_back(_array2);
vectors.push_back(_array3);
vectors.push_back(_array4);

 vector <thread> ths(cores);
    for(int i=0;i<cores;i++){
        ths[i]=thread(verify,&vectors[i]);
    }
    for(int i=0;i<cores;i++){
        ths[i].join();
    }

}



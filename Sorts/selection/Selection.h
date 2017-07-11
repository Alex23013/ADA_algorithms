#include <vector>
using namespace std;

void print(vector<int> _array){
    int siz = _array.size();
    for (int i = 0; i < siz; i++){
        cout<<_array[i]<<"-";
    }
    cout<<endl;
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
int cores=4;

    vector<int> _array1(_array->begin(), _array->begin() + (siz/4));
    vector<int> _array2(_array->begin() + ((siz/4)+1), _array->begin() + siz/2);
    vector<int> _array3(_array->begin() + ((siz/2)+1), _array->begin() + 3*(siz/4));
    vector<int> _array4(_array->begin() + (3*(siz/4)+1), _array->end());


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


void Selection_Sort(vector<int>* _array){

    int     siz = _array->size(), aux;
    int     tmp;

    for (int j = 0; j < siz; j++){

	tmp = *(_array->begin() + j);               ///Hace swaps entre el elemento [j] con [i] donde [i] es el menor siguiente
        aux = 0;
        for (int i = j; i < siz; i++){

            if ( *(_array->begin()+i) < tmp ){
                tmp = *(_array->begin()+i);
                aux = i;
            }

        }
        if (aux != 0){
            swap( *(_array->begin() + j), *(_array->begin()+aux) );
        }
    }

}



void min(vector<int>* _array,int start,int* pos,int*minimo_parcial){
	int     siz = _array->size();
	int pos_min,cont;
	int min = 1000;
	for(cont=start;cont<siz;cont++){
		if(*(_array->begin()+cont)<min){
			min =*(_array->begin()+cont);
			pos_min=cont;
		}
	//cout<< cont <<": "<<min<<endl;
	}
	//cout<<"pos_min"<<pos_min<<endl;
}


void Selection_sortP(vector<int>* _array){

	int siz = _array->size();
	int start =0;
	int cores=4;
	for(int conta =0; conta<siz;conta++){
	    vector<int> _array1(_array->begin()+start, _array->begin() + (siz/4));
	    vector<int> _array2(_array->begin() + ((siz/4)+1), _array->begin() + siz/2);
	    vector<int> _array3(_array->begin() + ((siz/2)+1), _array->begin() + 3*(siz/4));
	    vector<int> _array4(_array->begin() + (3*(siz/4)+1), _array->end());


	vector <vector<int>> vectors(cores);
	vectors.push_back(_array1);
	vectors.push_back(_array2);
	vectors.push_back(_array3);
	vectors.push_back(_array4);

	vector<int> minimos_parciales(4);
	vector<int> pos_minimos_parciales(4);
	int min_total;
	int pos_total;
	 vector <thread> ths(cores);
	    for(int i=0;i<cores;i++){
		ths[i]=thread(min,&vectors[i],0,&minimos_parciales,&pos_minimos_parciales);
	    }
	    for(int i=0;i<cores;i++){
		ths[i].join();
	    }

	min_total =minimos_parciales[0];
	pos_total =0;
	    for(int i=1;i<cores;i++){
		if(min_total>*(minimos_parciales+i)){
			min_total=*(minimos_parciales+i);
			pos_total=i;
		}	
	    }
	
	swap(_array->begin()+start,_array->begin()+pos_total);
	start++;


	}
	
}




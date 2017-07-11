#include <iostream>
#include <algorithm>
#include <chrono>
#include <utility>

using namespace std::chrono;
using namespace std;

void print_arr(	int **pm,int n){
	for (int i = 0; i < n-1; i++){
		for(int j =0; j< n-1 ; j++){
			cout << *(*(pm + i) + j) << " ";
		}
		cout <<endl;	
	}
}

void swap( int * e1, int *  e2 ){
	int temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void orden( int **matriz,  int n ){
	for ( int i = 0; i < (n)*(n); i++){
		for ( int j = 0; j < n ; j++ ){
			for(int z =0; z < n; z++){
				if(z == n-1){
					if ( matriz[j][ z ] > matriz[j+1][0 ] ){
						swap( &matriz[j][ z ], &matriz[j+1][ 0 ] );
					}	
				}else{
					if ( matriz[j][ z ] > matriz[j][ z + 1 ] ){
						swap( &matriz[j][ z ], &matriz[j][ z + 1 ] );
					}						
				}
			}
			
		}
	}
} 

int main()
{
	
	int **pm;
	int n =1000 ;
	int tests =1;
	srand(time(NULL));
	double rtime = 0;
	pm = new int* [n]; 
	for(int i = 0; i < n; i++) {
		pm[i] = new int[n];
	}
	for(int i =0;i< n;i++){
		for (int j = 0; j < n; j++) {
			*(*(pm + i) + j)  = rand() % 100;
		}
	}
	
	//print_arr(pm,n);
	for (int i = 0; i < tests ; i++) {
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	orden(pm,n-1);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
		 auto res = duration_cast<microseconds>( t2 - t1 ).count();
		 rtime += res;
	}
	long long  ttime = rtime/tests;
	cout << "tiempo:" << ttime/1000.0<< " milliseconds con " << n<<" elementos " << endl ;
	cout << "Sorted Array: " << endl;
	//print_arr(pm,n);
	return 0;
}

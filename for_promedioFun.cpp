#include <iostream>
#include <chrono>
#include <utility>
#include <algorithm>
using namespace std;
using namespace std::chrono;

int elementos[4] = {100,3000,5000,7000};
int tests = 10;

for(int i = 0; i < 4; i++){
    n = elementos[i];
    double time = 0;
    for (int i = 0; i < tests ; i++) {

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
				///
				codigo que quieras tomar tiempo xD
				///

		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto res = duration_cast<microseconds>( t2 - t1 ).count();
        time += res;
    }

    long long  ttime = time/tests;
    cout << "tiempo:" << ttime/1000.0<< " milliseconds con " <<elementos[i]<< endl ;          
}

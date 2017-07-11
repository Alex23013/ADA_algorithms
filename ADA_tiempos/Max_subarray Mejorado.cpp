#include <iostream>
using namespace std;
#include <chrono>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std::chrono;


void Find_Max_cross (/*int**/vector<int> A,int low ,int mid ,int high,int& max_left,int& max_right,int& sumrl){
    int left_sum = -10000;
    int sum =0;
    for (int i = mid;i >low; i--){
        sum = sum + A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left =i;
        }
    }
    int right_sum = -10000;
    sum =0;
    for (int j = mid+1;j <high; j++){
        sum = sum + A[j];
        if (sum > right_sum){
            right_sum = sum;
            max_right =j;
        }
    }
    sumrl = left_sum+right_sum;
}

void find_max(/*int **/vector<int> A, int low,int high,int&rlow,int&rhigh,int& rsum){
    int left_low = 0;	int left_high = 0; 	int left_sum = 0;
    int right_low = 0;  int right_high = 0;	int right_sum = 0;
    int cross_low = 0;  int cross_high = 0;     int cross_sum = 0;

    if (high == low){
        rlow=low;
        rhigh =high;
        rsum = A[low];
        return;
    }
    else{
        int mid = (low+high)/2;
        find_max(A,low,mid,left_low,left_high,left_sum);
        find_max(A,mid+1,high,right_low,right_high,right_sum);
        Find_Max_cross(A,low ,mid ,high,cross_low,cross_high,cross_sum);}

    if(left_sum >= right_sum && left_sum >= cross_sum){
		rlow=left_low;
		rhigh = left_high;
		rsum=left_sum;}

    else if (right_sum >= left_sum && right_sum >= cross_sum){
		rlow=right_low;		
		rhigh = right_high;
		rsum=right_sum;}
    else{
	rlow=cross_low;
	rhigh = cross_high;
	rsum=cross_sum;}
}


void cuadratico (/*int **/ vector<int> A,int n, int& rlow,int&rhigh,int&rsum){
    int index =0;
    int actual =0;
    int sum_max = -10000;
    for(int i =0;i <n;i++){
        for (int j=0;j<n;j++){
                actual =0;
            for(int k =i;k<=j;k++){
                actual+= A[k];
                 if (actual > sum_max){
                sum_max = actual;
                rlow =i;
                rhigh =j;
                rsum = sum_max;
                }

            }
        }
    }
}
int main()
{
	cout<<"Starting ...\n";
	//int ventas[16]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};//array de prueba
	int n = 17;
	int tests =1;
	//int ventas[16];
	vector<int> ventas;
	int elementos[4]= {10,100,1000,10000};
	srand(time(NULL));
	double rtime = 0;
for(int k =0;k<4;k++){
	n=elementos[k];
	for (int i = 0; i < tests ; i++) {

		for(int j =-n/2;j<n;j++){ventas.push_back(j);}
		//for(int j =0;j<n;j++){cout<<ventas[j]<<" . ";}
		auto randomFun =[] (int i) { return rand()%i;};
		random_shuffle(ventas.begin(), ventas.end(), randomFun);
		cout<<"\n";
		//for(int j =0;j<n;j++){cout<<ventas[j]<<" . ";}
		 cout<<"\n";

		int max_left=0;
		int max_right=0;
		int sumrl=0;

		 high_resolution_clock::time_point t1 = high_resolution_clock::now();

		 //find_max(ventas,0,n-1,max_left,max_right,sumrl);//metodo divide y venceras
		  cuadratico(ventas,n,max_left,max_right,sumrl); //metodo fuerza bruta

		  cout<<"la respuesta del max_subarray:\n\n";
		  cout<<"low: "<<max_left<<" high:"<<max_right<<" sum:"<<sumrl<<endl;

		 high_resolution_clock::time_point t2 = high_resolution_clock::now();
		 auto res = duration_cast<microseconds>( t2 - t1 ).count();
		 rtime += res;
	}

	long long  ttime = rtime/tests;
	cout << "tiempo:" << ttime/1000.0<< " milliseconds con " << n<<" elementos " << endl ;
}	
return 0;
}


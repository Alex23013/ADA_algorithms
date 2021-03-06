#include <iostream>
#include <string>
#include<sstream>
using namespace std;

void llenar_array(int * a, int n){
int tmp;
	for(int i =0;i<n;i++){
	cout<<"\nelemento "<<i<<" --> ";
	cin>>tmp;
	a[i]=tmp;
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
void print_array(int * a, int n, string nombre){
cout<<"\n"<<nombre<<"; \n\t";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" . "; }
}

int max_digitos(int* a,int n){
	int max=0;
	for(int i =0;i< n;i++){
		if(max < a[i]){
			max=a[i];
		}
	}
	return max;
}

void radix_sort(int *a, int n){
int temp[10];
int res[n];
int div =10;
int digito;
int num_digitos = digitos_num(max_digitos(a,n));
for(int j =0;j<num_digitos;j++){
	for(int i=0;i<10;i++){temp[i]= 0;}

	for(int i =0;i<n;i++){
		//cout<<(a[i]%div)/(div/10)<<" / ";
		digito =(a[i]%div)/(div/10);
		temp[digito]+=1;
	}
	for(int i=0;i<10;i++){;
		temp[i+1]=temp[i]+temp[i+1];}

	for(int i=n-1;i>=0;i--){
		digito =(a[i]%div)/(div/10);
		temp[digito]-=1;
		res[temp[digito]]=a[i];
	}
	for(int i =0;i <n ;i++){
        a[i]= res[i];
	}
	div=div*10;
	//cout<<"\n------------------------\n";
	}
}

int main (){
cout<<"Starting ...\n";

int n=6;

//cout<<"Numero de elementos: \n";
//cin>>n;


int a[6]={183,2915,892,1283,585,0};
int ans[n];
//llenar_array(a,n);
print_array(a,n,"original");
cout<<endl<<endl;
radix_sort(a,n);
print_array(a,n,"ordenado");

return 0;
}

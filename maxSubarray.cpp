#include <QCoreApplication>
#include <iostream>
using namespace std;

void Find_Max_cross (int* A,int low ,int mid ,int high,int& max_left,int& max_right,int& sumrl){
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

void find_max(int * A, int low,int high,int&rlow,int&rhigh,int& rsum){
    int left_low = 0;
    int left_high = 0;
    int left_sum = 0;
    int right_low = 0;
    int right_high = 0;
    int right_sum = 0;
    int cross_low = 0;
    int cross_high = 0;
    int cross_sum = 0;

    if (high == low){
        rlow=low;
        rhigh =high;
        rsum = A[low];
        return;
    }
    else{
        int mid = (low+high)/2;
        find_max(A,low,mid,left_low,left_high;left_sum);
        find_max(A,mid+1,high,right_low,right_high;right_sum);
        Find_Max_cross(A,low ,mid ,high,cross_low,cross_high,cross_sum);
    }

    if(left_sum > right_sum && left_sum > cross_sum){

    }

}

int main()
{
   cout<<"Starting ...\n";
   int n = 16;
  int ventas[16];
  for (auto i =0;i< n;i++){
      ventas[i]=i;
  }
  for (auto i =0;i< n;i++){
      cout<<ventas[i]<<" - ";
  }
  cout<<"\n";
  int max_left=0;
  int max_right=0;
  int sumrl=0;
  Find_Max_cross (ventas,0,7 ,16,max_left,max_right,sumrl);
  cout<<max_left<<"  "<<max_right<<" "<<sumrl<<endl;
  return 0;
}

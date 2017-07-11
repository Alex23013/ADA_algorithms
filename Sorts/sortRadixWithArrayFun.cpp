void radix_sort(int *a, int n, int * res){
int temp[10];
int div =10;
int digito;
string len;
len=to_string(max_digitos(a,n));
for(int j =0;j<len.size();j++){
	for(int i=0;i<10;i++){temp[i]= 0;}
	
	for(int i =0;i<n;i++){
		cout<<(a[i]%div)/(div/10)<<" / ";
		digito =(a[i]%div)/(div/10);
		temp[digito]+=1;}

	for(int i=0;i<10;i++){temp[i+1]=temp[i]+temp[i+1];}

	for(int i=n-1;i>=0;i--){
		digito =(a[i]%div)/(div/10);
		temp[digito]-=1;
		res[temp[digito]]=a[i];}
	div=div*10;
	}
}



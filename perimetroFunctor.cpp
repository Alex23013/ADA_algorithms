#include <iostream>
using namespace std;

int suma (int a, int b){
    return a+b;
}

int resta (int a, int b){
    return a-b;
}

double tabla(int(*p)(int,int), int a, int b){
    return p(a,b);
}


class perimetro{
public:
    perimetro(string nombre):name(nombre){}

    int operator()(int l, int n_l){
        cout<<"\nel area de las figura: "<<name<<endl;
        return l*n_l;
    }
private:
    string name;
};

int main(){
    perimetro t("cuadrado");
    cout<<t(4,4);
    perimetro y("triangulo");
    cout<<y(3,8);

}



/*class padre{
public:
int suma (int a, int b){
        return a+b;
    }
};
class hijo1 : public padre{
public:
 int suma (int a, int b){
        return a+b+1;
    }
};
class hijo2 : public padre{
public:
int suma (int a, int b){
        return a+b+2;
    }
};

int sumar(padre* r,int a , int b){
    return r->suma(a,b);
}

int main()
{
    hijo1 uno;
    hijo2 dos;
    cout<<sumar(&uno,1,4);
    cout<<sumar(&dos,1,4);
}
*/




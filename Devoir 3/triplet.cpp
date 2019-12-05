#include <iostream>
using namespace std;
template <typename T>

class Triplet {
 
    int courant;
    T *t;
 
  public:
 
    Triplet() {
       
        t= new T[3];
        t[0]= t[1]= t[2]= 0;
    }

    Triplet(int num) : courant(0)
    {

        t = new T[3];
        t[0] = static_cast<T>(((num / 10) / 10) % 10);
        t[1] = static_cast<T>((num / 10) % 10);
        t[2] = static_cast<T>(num % 10);
    }

    Triplet(T a, T b, T c) : courant(0) {
       
        t= new T[3];
        t[0]= a;
        t[1]= b;
        t[2]= c;
       
    }

    Triplet(const Triplet &triplet){
        courant = triplet.courant;
        t = triplet.t;
    }

    T get() {
       
        T r = t[courant];
        courant= (courant+1)%3;
       
        return r;
    }

    ~Triplet(){
        delete[] t;
    }

};

template <typename T>
void fct(Triplet<T> t3)
{ // pour vos tests, convertir cette fonction
    // en fonction template
    cout << "t3:" << endl;
    cout << t3.get() << ",";
    cout << t3.get() << ",";
    cout << t3.get() << ",";
    cout << t3.get() << endl;
}

int main() {


    Triplet<int> t1(2,4,6);
   
    cout << "t1a:" << endl;     
    cout << t1.get() << ",";
    cout << t1.get() << ",";    
    cout << t1.get() << ",";
    cout << t1.get() << endl;
   
    Triplet<int> t2(t1);   
   
    cout << "t2:" << endl;
    cout << t2.get() << ",";    cout << t2.get() << endl;
   
    cout << "t1b:" << endl;   
    cout << t1.get() << ",";    cout << t1.get() << endl;
   
    fct<double>(1234);   
 
    return 0;
}   
#include<iostream>
using namespace std;

class Complex{
    int real;
    int complex;
    public:
    Complex()
    {
        
    }
    Complex(int real,int complex){
this->real=real;
this->complex=complex;
    }
Complex operator+(const Complex& c1){
    Complex c2;
c2.real=real+c1.real;
c2.complex=complex+c1.complex;
return c2;
}
Complex operator*(const Complex& c1){
    Complex c3;
c3.real=real*c1.real-complex*c1.complex;
c3.complex=real*c1.complex+complex*c1.real;
return c3;
}
void display(){
    cout<<real<<" + "<<complex<<"i"<<endl;
}
};

int main(){
    int r1,r2,c11,c22;
cout<<"enter real";
cin>>r1;
cout<<"enter complex";
cin>>c11;
cout<<"enter real";
cin>>r2;
cout<<"enter complex";
cin>>c22;
Complex c5(r1,c11);
Complex c6(r2,c22);
Complex c3,c4;
c3=c5+c6;
c4=c5*c6;
c3.display();
c4.display();
}

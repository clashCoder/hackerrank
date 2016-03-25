//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};
//--------------- code written only between the hyphens (rest given)-----------------------------------
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

//type operator sign (parameters) { /*... body ...*/ }

Complex operator+(const Complex &A, const Complex &B) {
    Complex c;
    c.a = A.a + B.a;
    c.b = A.b + B.b;
    return c;
}

ostream& operator<<(ostream &os, const Complex &A) {
    os << A.a << "+i" << A.b;
    return os;
}

//friend Complex operator<<(const Complex &A, const Complex &B) {
  //  Co
//}
//-----------------------------------------------------------------------------------------------------

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
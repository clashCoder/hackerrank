#include<iostream>

using namespace std;

int callA=0;
int callB=0;
int callC=0;
class A
{
protected:
   
   void func(int  & a)
   {
      a=a*2;
      callA++;
   }
};

class B
{
protected:
   void func(int & a)
   {
      a=a*3;
      callB++;
   }
};

class C
{
protected:
   void func(int & a)
   {
      a=a*5;
      callC++;
   }
};

//--------------- code written only between the hyphens (rest given)-----------------------------------

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val=1;
		 }


		 //Implement this function
		 void update_val(int new_val)
		 {
            //Note that one number has to divide evenly (2,3,5)
             int checker = new_val;
             int tempVal = val;
             int rightChild;
             int leftChild;
             //A put;
             
             while (true) { 
                 
                 if( (checker % 2) == 0) {
                     rightChild = 2;
                     leftChild = checker / 2;
                     checker = leftChild;   
                     A::func(val);
                 }
                 else if( (checker % 3) == 0) {
                     rightChild = 3;
                     leftChild = checker / 3;
                     checker = leftChild;
                     B::func(val);

                 }
                 else { //must be divisible by 5 {
                    rightChild = 5;
                    leftChild = checker / 5;
                    checker = leftChild; 
                    C::func(val);
                     
                 }
             
                if (checker == tempVal) {
                    break;
                }   
                     
             }
             
			
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
    
    private:
        A a;            // *2
        B b;            // *3
        C c;            // *5
};
//-------------------------------------------------------------------------------------------------------

void D::check(int new_val)
{
       update_val(new_val);
       cout<<"Value = "<<val<<endl<<"A's func called "<<callA<<" times "<<endl<<"B's func called "<<callB<<" times "<<endl<<"C's func called "<<callC<<" times"<<endl;
}


int main()
{
   D d;
   int new_val;
   cin>>new_val;
   d.check(new_val);

}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;



//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);

// Destructor
// ~Box()
// {

// }

// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//--------------- code written only between the hyphens (rest given)-----------------------------------

class Box {
    public:
	
	//default Box constructor
        Box() {
            l = b = h = 0;
            BoxesCreated++;
        }
        
    //constructor that passes in the length, breadth, and height of the Box
        Box(long int length, long int breadth, long int height) {
            l = length;
            b = breadth;
            h = height;
            BoxesCreated++;
        }

    //copy constructor    
        Box (const Box &src) {
            l = src.l;
            b = src.b;
            h = src.h;
            BoxesCreated++;
        }
        
        ~Box() {
            BoxesDestroyed++;
        }
    
        long int getLength() const{
            return l;
        }
    
        long int getBreadth() const {
            return b;
        }
        
        long int getHeight() const{
            return h;
        }
    
        long long CalculateVolume() {
            return l * b * h;
        }

     // overload '<' operator
     // made fix of Box &b to const Box &b
       bool operator<(const Box &b){
            
           if ( this->l < b.l) {
               return true;
           }
           
           if ( (this->b < b.b) && (this->l == b.l) ) {
               return true;
           }
           
           if ( (this->h < b.h) && (this->b == b.b) && (this->l == b.l) ) {
               return true;
           }
           
           return false;
     }

/*bool operator<(const Box &left, const Box &right) {
    
    //Box left = l;
    //Box right = r;
    
    long int leftLength = left.getLength();
    long int leftBreadth = left.getBreadth();
    long int leftHeight = left.getHeight();
    
    long int rightLength = right.getLength();
    long int rightBreadth = right.getBreadth();
    long int rightHeight = right.getHeight();
    
    if (leftLength < rightLength) {
        return true;
    }
    
    if ( (leftBreadth < rightBreadth) && (leftLength == rightLength) ) {
        return true;
    }
    
    if ( (leftHeight < rightHeight) && (leftBreadth < rightBreadth) && (leftLength < rightLength) ) {
        return true;
    }
    
    return false;
}*/
    
    private:
        long int l;      //length
        long int b;      //breadth
        long int h;      //height
};

//Overload operator < as specified
//bool operator<(Box &b)


//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)

// made fix from Box B to const Box &B and modified Box functions of Box used below to const

ostream& operator<<(ostream& os, const Box &B) {
    os << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return os;
}

//--------------------------------------------------------------------------------------------

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}

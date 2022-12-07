#include <iostream>
using namespace std;
// Reference: https://husking-studio.com/cpp-template-01/
// Template make datatype as kind of parameter

// Template Function
template<class T>
T MaxTest(T x, T y)
{
	if(x > y)
		return x;
    else
	    return y;
}

// Template Class
template<class T>
class CObj{
    public:
        CObj(T x);
        void Showdata();
        T val;
};

template<class T>
CObj<T>::CObj(T x) // Constructor
    {val = x;}

template<class T>
void CObj<T>::Showdata()
    {cout << "val = " << val << endl;}

int main()
{
    // Template Function - allow all type pass in the function
	cout << "MaxTest(3, 4) = " << MaxTest(3, 4) << endl;
	cout << "MaxTest(6.3, 8.7) = " << MaxTest(6.3, 8.7) << endl;
	cout << "MaxTest('O', 'A') = " << MaxTest('O', 'A') << endl;
	
    // Template Class, send in datatype as a parameter
	CObj<int> X(10);
    CObj<float> Y(3.14);
	CObj<char> Z('A');
	X.Showdata();
	Y.Showdata();
    Z.Showdata();
    return 0;
}
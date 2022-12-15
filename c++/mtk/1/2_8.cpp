
# include <iostream>
using namespace std;

union MyUnion{
    int  a[2];
    char b[8];
};

int main (){
    MyUnion tmp;
    tmp.a[0] = 3406;
    cout << tmp.b[0] << endl; // "N" // 78 in ASCII code
}
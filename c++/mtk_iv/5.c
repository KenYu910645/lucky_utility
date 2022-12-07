
# include <iostream>
using namespace std;

union Myu
{
    int a[2];
    char b[8];
};

int main (){
    Myu tmp;
    tmp.a[0] = 3406;
    cout << tmp.b[0];
}
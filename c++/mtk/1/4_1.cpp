# include <stdio.h>
# include <vector>
using namespace std;
// Use an interator to traverse all element in vector<int> ivec:for(1)



int main(){
    vector<int> ivec(10, 1);

    // My answer:
    vector<int>::iterator iter;
    for (iter=ivec.begin(); iter != ivec.end(); iter++){
        printf("%d\n", *iter);
    }
}
# include <stdio.h>

using namespace std;

//Function Overriding
class Human {
    public:
        void makeLove(){
            cout << "Human making love" << endl; 
        }
};
class Girl: public Human {
    public:
        void makeLove(){
            cout << "Girl making love" << endl; 
        }
};

int main(){
    Human human

    return 0;
}

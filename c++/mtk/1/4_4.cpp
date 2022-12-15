# include <iostream>
using namespace std;

class CData{
    public: 
        CData(){}
        CData(int y, int m, int d){
            year  = y;
            month = m;
            day = d;
        }
        void show(){
            cout << year << '-' << month << '-' << day << endl;
        }
        int getYear(){
            return year; // Ask you to fill the line
        }
        void setYear(int y){
            year = y; // Ask you to fill the line
        }
    private: 
        int year, month, day;
};

int main(){
    CData c = CData(2008, 8, 8);// Ask you to fill the line to creat the object with 2008, 8, 8
    int y = 2022;
    c.setYear(y); // Ask you to fill the line to set years to y's value
    return 0;
}
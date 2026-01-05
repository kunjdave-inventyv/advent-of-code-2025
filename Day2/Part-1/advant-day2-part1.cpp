#include <iostream>
#include <fstream>
#include <string>
using namespace std;

long long solve( long long  first , long long  second ){
    long long  sum = 0;

    long long  firstNum = first;
    long long  secondNum = second;
    for (long long  num = firstNum ; num <= secondNum ; num++ ){
        string str = to_string(num);
        int size = str.size();
        if( size % 2 != 0 ){
            continue;
        }

        int j = size / 2 ;
        int i = 0;
        bool flag = true;
        while( j != size ){
            if( str[i++] != str[j++] ){
                flag = false;
            }
        }
        if( flag ){
            sum += num;
        }
    }
    return sum;
}
int main() {
    ifstream file("example1.txt");

    string move;
    int i = 0 ; 
    long long  ans = 0 ;
    while (file >> move) {
     
        while( i != move.size()  ){
            string first = "";
            string second = "";
            while( move[i] != '-' ){
                first += move[i++];
            }
            i++;
            while( move[i] != ','  && i != move.size() ){
                second += move[i++];
            }
            if( move[i] == ',' ){
                i++;
            }
            ans += solve( stoll(first) , stoll(second) );
        }
    }
    cout<< ans;
    return 0;
}

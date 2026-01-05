#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("example.txt");

    int curr = 50;
    int cnt = 0;
    string temp;

    while (file >> temp) {
        int num = stoi(temp.substr(1));

        if (temp[0] == 'L'){
            curr = (curr - num + 100) % 100;
        }
        else{
            curr = (curr + num) % 100;
        }
        if (curr == 0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

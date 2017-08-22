#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    string input1, input2;
    map<string, int> entry;
    int N;
    cin >> N;
    while(N--){
        cin >> input1 >> input2;
        if(input1 == "entry"){
            if(entry.count(input2) == 0 || entry[input2] == 0){
                cout << input2 << " entered\n";
                entry[input2] = 1;
            } else {
                cout << input2 << " entered (ANOMALY)\n";
            }
        } else {
            if(entry[input2] == 1){
                cout << input2 << " exited\n";
                entry[input2] = 0;
            } else {
                cout << input2 << " exited (ANOMALY)\n";
            }
        }
    }
}

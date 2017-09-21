#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int N, i;
    string input;
    while(cin >> N){
        map<string, int> dict;
        while(N--){
            cin >> input;
            int len = input.size();
            cout << dict[input] << "\n";
            for(i = 1; i <= len; ++i){
                dict[input.substr(0,i)] += 1;
            }
        }
    }
}

#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input;
    double total = 0, white = 0, lower = 0, upper = 0, symbols = 0;
    cin >> input;
    int len = input.size();
    for(int i = 0; i < len; ++i){
        if(input[i] == '_'){++white; continue;}
        if(islower(input[i])){++lower; continue;}
        if(isupper(input[i])){++upper; continue;}
        ++symbols;
    }
    double wRatio = white / len;
    double lRatio = lower / len;
    double uRatio = upper / len;
    double sRatio = symbols / len;
    cout << wRatio << "\n" << lRatio << "\n" << uRatio << "\n" << sRatio << "\n";
}

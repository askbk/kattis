#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    map<char,int> alphabet;
    alphabet['a']=2; 
    alphabet['b']=22;
    alphabet['c']=222;
    alphabet['d']=3;
    alphabet['e']=33;
    alphabet['f']=333;
    alphabet['g']=4;
    alphabet['h']=44;
    alphabet['i']=444;
    alphabet['j']=5;
    alphabet['k']=55;
    alphabet['l']=555;
    alphabet['m']=6;
    alphabet['n']=66;
    alphabet['o']=666;
    alphabet['p']=7;
    alphabet['q']=77;
    alphabet['r']=777;
    alphabet['s']=7777;
    alphabet['t']=8;
    alphabet['u']=88;
    alphabet['v']=888;
    alphabet['w']=9;
    alphabet['x']=99;
    alphabet['y']=999;
    alphabet['z']=9999;
    alphabet[' ']=0;
    string input;
    int N;
    cin >> N;
    for(int i = 0; i <= N ; ++i){
        getline(cin, input);
        if(i == 0) continue;
        cout << "Case #" << i << ": ";
        int length = input.size();
        for(int j = 0; j < length; ++j){
            if((alphabet[input[j-1]] % 10) == (alphabet[input[j]] % 10)){
                cout << " ";
            }
            cout << alphabet[input[j]];
        }
        cout << "\n";
    }
}

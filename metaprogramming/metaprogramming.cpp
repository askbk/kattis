#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    map<string, int> definition;
    string command, def1, def2;
    char op;
    int number;
    while(cin >> command){
        if(command == "define"){
            cin >> number >> def1;
            definition[def1] = number;
        }else if(command == "eval"){
            cin >> def1 >> op >> def2;
            if(definition.count(def1) != 1 || definition.count(def2) != 1){
                cout << "undefined\n";
                continue;
            }
            if(op == '<'){
                if(definition[def1] < definition[def2]){
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            }else if(op == '>'){
                if(definition[def1] > definition[def2]){
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            }else{
                if(definition[def1] == definition[def2]){
                    cout << "true\n";
                } else {
                    cout << "false\n";
                }
            }
        }
    }
}

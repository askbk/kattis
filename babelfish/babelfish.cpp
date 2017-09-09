#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string input;
    map<string, string> dictionary;
    while (getline(cin, input)) {
        if(!input.empty()){
            size_t found = input.find(" ");
            if(found != string::npos){
                dictionary[input.substr(found+1)] = input.substr(0, found);
            } else {
                if(dictionary.count(input) == 0){
                    cout << "eh\n";
                }else{
                    cout << dictionary[input] << "\n";
                }
            }
        }
    }
}

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    multiset<string> candidate;
    vector<string> names;
    string win;
    bool runoff = false;
    int max = 0;
    while (getline(cin, input)) {
        if(input == "***"){
        int n = names.size();
        for(int i = 0; i < n; ++i){
            int count = candidate.count(names[i]);
            if(count == max){
                runoff = true;
            }else if(count > max){
                runoff = false;
                win = names[i];
                max = count;
            }
        }
        if(runoff){
            cout << "Runoff!\n";
        }else{
            cout << win << "\n";
        }
        return 0;
        }else{
            if(candidate.count(input) == 0){
                names.push_back(input);
            }
            candidate.insert(input);
        }
    }
}

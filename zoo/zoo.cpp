#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main(){
    int list = 1;
    for(;;){
        int n;
        cin >> n;
        if(n == 0) break;

        cout << "List " << list << ":\n";
        ++list;
        
        multiset<string> animals;
        vector<string> alphSort; 

        for(int i = 0; i <= n; ++i){
            string input;
            getline(cin, input);
            size_t last = input.rfind(" ");
            if(last != string::npos){
                input = input.substr(last+1, input.size() - last);
            }
            for(int j = 0; j < input.length(); ++j){
               input[j] = tolower(input[j]);
           }
            animals.insert(input);
            if(animals.count(input) == 1){
                alphSort.push_back(input);
            }
        }
        
        sort(alphSort.begin(), alphSort.end());

        int vLength = alphSort.size();

        for(int i = 1; i < vLength; ++i){
            cout << alphSort[i] << " | " << animals.count(alphSort[i]) << "\n";
        }
        //cout << alphSort[0] << " | " << animals.count(alphSort[0]) << "\n";
        //cout << alphSort[0] << alphSort[1] << "\n";
        //cout << animals.count(alphSort[5]) << "\n";

    }
}

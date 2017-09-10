#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    string input;
    string prev, cur, maxname;
    priority_queue<string> candidate;
    bool runoff = true;
    int max = -1, count = 0;
    while (getline(cin, input)) {
        if(input == "***"){
            prev = candidate.top();
            while(!candidate.empty()){
                cur = candidate.top();
                candidate.pop();
                if(prev == cur){
                    ++count;
                    if(count > max){
                        max = count;
                        maxname = prev;
                        runoff = false;
                    }else if(count == max){
                        runoff = true;
                    }
                }else{
                    count = 1;
                    if(count == max) runoff = true;
                }
                prev = cur;
            }
            if(runoff){
                cout << "Runoff!\n";
            }else{
                cout << maxname << "\n";
            }
            return 0;
        }else{
            candidate.push(input);
        }
    }
}

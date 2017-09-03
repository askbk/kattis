#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
    string input;
    while(cin >> input){
        vector<int> Nletters;
        Nletters.push_back(-1);
        map<char, int> alphanum;
        int len = input.length();

        for(int i = 0; i < len; ++i){
            if(alphanum[input[i]] == 0){
                Nletters.push_back(1);
                alphanum[input[i]] = Nletters.size();
            } else {
                Nletters[alphanum[input[i]]]++;
            }
        }

        /*for(int i = 1; i < Nletters.size(); ++i){
            cout << Nletters[i] << "\n";
        }*/

        int top = Nletters.size() - 1, botS = Nletters.size();
        //long long ans = 1;
        double ans = 1;

        for(int i = 1; i < botS; ++i){
            while(Nletters[i] > 1 || top > 1){
                if(top > 1){
                    ans *= top;
                    --top;
                    ans *= top;
                    --top;
                }
                if(Nletters[i] > 1){
                    ans /= Nletters[i], --Nletters[i];
                    ans /= Nletters[i], --Nletters[i];
                }
            }
        }

        cout << ans << "\n";
    }
}

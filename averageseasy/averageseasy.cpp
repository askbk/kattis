#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T, CS, E;
    double csavg, eavg;


    cin >> T;

    while(T--){
        long long cssum = 0, esum = 0, input, total = 0;
        cin >> CS >> E;
        vector<long long> csiq;

        for(int i = 0; i < CS; ++i){
            cin >> input;
            cssum += input;
            csiq.push_back(input);
        }
        
        csavg = double(cssum) / double(CS);

        for(int i = 0; i < E; ++i){
            cin >>  input;
            esum += input;
        }

        if(E != 0){
            eavg = double(esum) / double(E);
        } else {
            eavg = 0;
        }
        //cout << "eavg: " << eavg << " csavg: " << csavg << "\n";
        for(int i = 0; i < CS; ++i){
            if(csiq[i] < csavg && csiq[i] > eavg){
                ++total;
                //cout << eavg << "<" << csiq[i] << "<" << csavg << "\n";
            } else {
                //cout << eavg << " " << csiq[i] << " " << csavg << "\n";
            }
        }

        cout << total << "\n";
    }
}

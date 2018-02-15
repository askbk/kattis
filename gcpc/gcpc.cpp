#include <iostream>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

int main(){
    int n, m, t, p;
    set< pair<int, int> > ahead; //score, penalty
    set< pair<int, int> >::iterator it;

    cin >> n >> m;
    
    vector< vector < int > > team (n, {0, 0}); //score, penalty
 
    while(m--){
        cin >> t >> p;
        --t;

        if(t == 0){ //if team 1 solves a problem, increase score and remove everyone whose score is lower from the set
            ++team[t][0];
            team[t][1] += p;

            for(it = ahead.begin(); it != ahead.end();){
                pair<int, int> curr = *it;

                if(curr.first < team[0][0] || (curr.first == team[0][0] && curr.second <= team[0][1])){
                    ahead.erase(it++);
                } else {
                    ++it;
                }
            }
        } else { //if someone else solves a problem, first check if they are already ahead. if they are, simply increase their score. else, check if the score increase puts them ahead. if so, add them to the set and increase their score.
            int currS = team[t][0], currP = team[t][1];

            if(currS > team[0][0] || (currS == team[0][0] && currP < team[0][1])){
                ++team[t][0];
                team[t][1] += p;
            } else {
                if(currS + 1 > team[0][0] || (currS + 1 == team[0][0] && currP + p < team[0][1])){
                    ++team[t][0];
                    team[t][1] += p;
                    ahead.insert(make_pair(team[t][0], team[t][1]));
                }
            }
        }

        cout << ahead.size() + 1 << "\n";
    }
}

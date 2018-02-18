#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class State{
    public:
        vector<int> visited;
        State(int);
        State(vector<int>, int);
};

State::State(int start){
    visited.push_back(start);
}

State::State(vector<int> _v, int n){
    visited.assign(_v.begin(), _v.end());
    visited.push_back(n);
}

int main(){
    int N, shortestCycle = -1, temp;
    vector< vector<int> > node; //contains all nodes
    vector< vector<int> > cycle;//contains some cycles
    map<int, string> nodeName;  //contains filenames
    map<string, int> nodeValue; //contains filenumbers
    string input;

    cin >> N;

    node.resize(N);
    
    for(int i = 0; i < N; ++i){
        cin >> input;
        nodeName[i] = input;
        nodeValue[input] = i;
    }

    for(int i = 0; i < N; ++i){
        cin >> input >> temp;

        while(temp){
            cin >> input;

            if(input == "import"){
                continue;
            } else {
                --temp;
                int size = input.size();

                if(input[size - 1] == ','){
                    --size;
                }
                node[i].push_back(nodeValue[input.substr(0, size)]);
            }
        }
    }

    cout << "finished input\n";

    for(int i = 0; i < N; ++i){
        queue<State> que;

        que.push(State(i));

        while(!que.empty()){
            State currentState = que.front();
            que.pop();

            int size = currentState.visited.size() - 1;
            int currentNode = currentState.visited[size];
            
            if(currentNode == currentState.visited[0]){
                if(size < cycle[shortestCycle].size()){
                    cycle.push_back(currentState.visited);
                    ++shortestCycle;
                    cout << size << "\n";
                }
                continue;
            }

            int neighbours = node[currentNode].size();

            for(int j = 0; j < neighbours; ++j){
                int next = node[currentNode][j];
                if(find(currentState.visited.begin(), currentState.visited.end(), next) == currentState.visited.end()){
                    que.push(State(currentState.visited, next));
                }
            }
        }
    }

    if(shortestCycle == -1){
        cout << "SHIP IT\n";
    } else {
        for(int i = 0; i < cycle[shortestCycle].size(); ++i){
            cout << cycle[shortestCycle][i] << " ";
        }
        cout << "\n";
    }
}

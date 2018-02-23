#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
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

bool IsTrash(string c){
    return c == ",";
}

int main(){
    int N, shortestCycle = -1, temp;
    vector< vector<int> > node; //contains all nodes (relations)
    vector< vector<int> > cycle;//contains some cycles. last one is always the shortest cycle.
    map<int, string> nodeName;  //contains filenames (names of the nodes)
    map<string, int> nodeValue; //contains maps each nodename to its respective number
    string input;

    cin >> N;

    node.resize(N);
    
    for(int i = 0; i < N; ++i){
        cin >> input;
        nodeName[i] = input;
        nodeValue[input] = i;
    }

    for(int i = 0; i < N; ++i){
        cin >> input >> temp;   //nodename is discarded; they are inputted in correct order anyway

        while(temp--){  //inputs each import line
            cin >> input;   //ignore "import"
            getline(cin, input);

            size_t last = 0;
            size_t next = 0; 
            
            while ((next = input.find(", ", last)) != string::npos) { 
                node[i].push_back(nodeValue[input.substr(last + 1, next - last - 1)]);
                last = next + 1; 
            }
            
            node[i].push_back(nodeValue[input.substr(last+ 1, next - last)]);
        }
    }

    for(int startNode = 0; startNode < N; ++startNode){
        queue<State> que;   //queue for BFS starting from each node. startNode is the current starting node.

        que.push(State(startNode));

        while(!que.empty()){
            State currentState = que.front();

            que.pop();

            int size = currentState.visited.size() - 1;
            int currentNode = currentState.visited[size];
            
            if(currentNode == currentState.visited[0]){
                if(shortestCycle == -1 || size < cycle[shortestCycle].size()){
                    vector<int> newCycle;
                    for(int i = 0; i < currentState.visited.size() - 1; ++i){
                        newCycle.push_back(currentState.visited[i]);
                    }

                    cycle.push_back(newCycle);
                    ++shortestCycle;
                    //cout << size << "\n";
                }
                continue;
            }

            int neighbours = node[currentNode].size();  //number of neighbours the current node has

            for(int i = 0; i < neighbours; ++i){    //loop through all the neightbours.
                int next = node[currentNode][i];    //if unvisited (except startNode)
                if(find(currentState.visited.begin() + 1, currentState.visited.end(), next) == currentState.visited.end()){
                    que.push(State(currentState.visited, next));
                    for(int j = 0; j < currentState.visited.size(); ++j){
                        cout << currentState.visited[j];
                    }
                }
            }
        }
    }

    if(shortestCycle == -1){
        cout << "SHIP IT\n";
    } else {
        for(int i = 0; i < cycle.size(); ++i){
            //cout << nodeName[cycle[shortestCycle-1][i]] << " ";
            for(int j = 0; j < cycle[i].size(); ++j){
                cout << nodeName[cycle[i][j]];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

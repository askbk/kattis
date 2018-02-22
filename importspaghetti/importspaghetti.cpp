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
        //cout << "temp" <<  temp << "\n";

        while(temp--){  //inputs each import line
            cin >> input;   //ignore "import"
            getline(cin, input);

            size_t last = 0;
            size_t next = 0; 
            
            while ((next = input.find(", ", last)) != string::npos) { 
                node[i].push_back(nodeValue[input.substr(last + 1, next - last - 1)]);
                cout << input.substr(last + 1, next - last - 1) << "\n";;
                last = next + 1; 
            }
            
            cout << input.substr(last + 1, next - last) << "\n";
            node[i].push_back(nodeValue[input.substr(last)]);
        }
    }

    cout << "finished input\n";
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < node[i].size(); ++j){
            cout << nodeName[node[i][j]];
        }
    };

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < node[i].size(); ++j){
            cout << "node " << nodeName[i] << " imports: " << nodeName[node[i][j]] << " " << node[i][j] << "\n";
        }
    }

    for(int startNode = 0; startNode < N; ++startNode){
        queue<State> que;

        que.push(State(startNode));

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

            for(int i = 0; i < neighbours; ++i){
                int next = node[currentNode][i];
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

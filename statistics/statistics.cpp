#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N, n = 1;
    while(cin >> N){
        vector<int> list;
        list.resize(N);
        for(int i = 0; i < N; ++i){
            cin >> list[i];
        }
        auto result = minmax_element(list.begin(), list.end());
        cout << "Case " << n << ": "  << *result.first << " " << *result.second << " " << *result.second - *result.first<< "\n";
        ++n;
    }
}

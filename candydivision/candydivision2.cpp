#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    long long N, i, ceiling;
    cin >> N;
    ceiling = floor(sqrt(N));
    vector<long long> factors;
    for(i = 1; i <= ceiling; ++i){
        if(N % i == 0){
            if(i != N/i){
                factors.push_back(i - 1);
                factors.push_back(N / i - 1);
            }else{
                factors.push_back(i - 1);
            }
        }
    }
    
    sort(factors.begin(), factors.end());
    for(i = 0; i < factors.size(); ++i){
        cout << factors[i] << " ";
    }

}

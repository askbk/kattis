#include <iostream>

using namespace std;

int main(){
	int N, P, inp,  max = 0, current = 0;
	cin >> N >> P;
	while(N--){
		cin >> inp;
		inp -= P;
		if(current + inp > 0){
			current += inp;
			if(current > max){
				max = current;
			}
		} else {
			current = 0;	
		}
	
	}

	cout << max << "\n";
}

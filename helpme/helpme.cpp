#include <iostream>
#include <map>
#include <cctype>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple <char, char, int> tcci;

map<char, int> order;

bool sort_white(const tcci a, const tcci b){
	if(order[get<0>(a)] < order[get<0>(b)]){
		return true;
	} else if(order[get<0>(a)] > order[get<0>(b)])	{
		return false;
	} else {
		if(get<2>(a) < get<2>(b)){
			return true;
		} else if(get<2>(a) > get<2>(b)){
			return false;
		} else {
			char ca = get<1>(a), cb = get<1>(b);
			return ca < cb;
		}
	}
}

bool sort_black(){}

int main(){
	order['K'] = 0, order['Q'] = 1, order['R'] = 2, order['B'] = 3, order['N'] = 4 order['W'] = 5;
	char input;
	vector< tcci > white;
	vector< tcci > black; 
	char column [] = {'a','b','c','d','e','f','g','h'};
	int col = 0, row = 8;
	while(row > 0){
		while(col < 7){
			cin >> input;
			if(isalpha(input)){
				if(isupper(input)){
					if(input=='P') input = 'W';
					white.push_back(make_tuple(input, row, column[col]));
					cout << "white piece found\n";
				} else {
					if(input=='p') input = 'w';
					black.push_back(make_tuple(input, row, column[col]));
					cout << "black piece found\n";
				}
				++col;
			}
		}
		--row;
	}

	sort(white.begin(),white.end(),sort_white);
	cout << "White: ";
	for(auto i : white){
		tcci current = i;
		cout << get<0>(current) << get<1>(current) << get<2>(current) << ",";
		cout << "hy";
	}
	cout << "\n";
}

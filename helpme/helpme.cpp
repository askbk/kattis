#include <iostream>
#include <map>
#include <cctype>
#include <string>

using namespace std;

int main(){
	char input;
	map<char, string> white;
	map<char, string> black;
	//char column = ['a','b','c','d','e','f','g','h'];
	char column [] = {'a','b','c','d','e','f','g','h'};
	char order [] = {'K', 'Q', 'R','R','B','B','N'}
	int col = 0, row = 1;
	while(row < 9){
		while(col < 7){
			cin >> input;
			if(isalpha(input)){
				if(islower(input)){
					white[input] = column[col] + to_string(row);

				} else {
					black[input] = column[col] + to_string(row);

				}
				++col;
			}
		}
		++row;
	}
}

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    string password, msg;
    cin >> password >> msg;
    int plen = password.size(), last = -1;
    map<char,int> pos;
    for(int i = 0; i < plen; ++i){
        string::iterator it;
        int sBegin = 0;
        if(pos.count(password[i]) == 1){
            sBegin = pos[password[i]] + 1;
        }
        it = find(msg.begin()+sBegin, msg.end(), password[i]);
        if(it == msg.end() || last > (it-msg.begin())){
            cout << "FAIL\n";
            return 0;
        }
        last = it-msg.begin();
	pos[password[i]] = last;
    }
    cout << "PASS\n";
}

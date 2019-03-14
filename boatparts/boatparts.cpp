#include <iostream>
#include <set>
#include <string>

int main(int argc, char const *argv[]) {
    using namespace std;
    set<string> replacedParts;
    int N, P;
    string input;
    cin >> P >> N;

    for (size_t day = 1; day <= N; day++) {
        cin >> input;
        replacedParts.insert(input);
        if (replacedParts.size() == P) {
            cout << day << "\n";
            return 0;
        }
    }

    cout << "paradox avoided" << "\n";

    return 0;
}

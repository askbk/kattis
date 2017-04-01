#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, M, m, input = 0, d = 0;
  cin >> N;
  while (N--) {
    cin >> M;
    m = M;
    vector<int> seq;
    while (m--) {
      cin >> input;
      seq.push_back(input);
    }

    d = seq[1] - seq[0];
    for (size_t i = 2; i < M; i++) {
      if ((seq[i] - seq[i-1]) != d) {
        goto next;
      }
    }
    cout << "arithmetic\n";
    goto end;
    next:

    sort(seq.begin(), seq.end());
    d = seq[1] - seq[0];
    for (size_t i = 2; i < M; i++) {
      if (seq[i] - seq[i-1] != d) {
        cout << "non-arithmetic\n";
        goto end;
      }
      if (i==M-1) {
        cout << "permuted arithmetic\n";
        goto end;
      }
    }
    end:
    cout << "";
  }
}

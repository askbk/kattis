#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N, M, m, input, d = 0;
  bool done;
  cin >> N;
  while (N--) {
    done = false;
    cin >> M;
    m = M;
    vector<int> seq;
    seq.resize(M);
    while (m--) {
      cin >> input;
      seq.push_back(input);
    }

    d = seq[1] - seq[0];
    for (size_t i = 2; i < M; i++) {
      if (seq[i] - seq[i-1] != d) {
        break;
      }
      if (i==M-1) {
        cout << "arithmetic\n";
        done = true;
      }
    }
    if (done) {
      continue;
    }
    sort(seq.begin(), seq.end());
    d = seq[1] - seq[0];
    for (size_t i = 2; i < M; i++) {
      if (seq[i] - seq[i-1] != d) {
        cout << "non-arithmetic\n";
        break;
      }
      if (i==M-1) {
        cout << "permuted arithmetic\n";
        done = true;
      }
    }
  }
}

#include <iostream>
#include <vector>

using namespace std;

int main(){
  int N, H;
  vector<int> arrow;
  bool found = false;
  cin >> N;
  while (N--) {
    cin >> H;
    if (!arrow.empty()) {
      int size = arrow.size();
      for (size_t i = 0; i < size; i++) {
        if (H==arrow[i]) {
          arrow[i] -= 1;
          found = true;
          break;
        }
      }
      if (!found) {
        arrow.push_back(H-1);
      }
      found = false;
    } else {
      arrow.push_back(H-1);
    }
  }
  cout << arrow.size() << "\n";
}

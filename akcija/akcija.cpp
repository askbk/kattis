#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool wayToSort(int a, int b) { return a > b; }

int main() {
  int N, n, p;
  long long price = 0;
  vector<int> item;
  cin >> N;
  n = N;
  item.push_back(1000000);
  while (n--) {
    cin >> p;
    item.push_back(p);
  }
  sort(item.begin(), item.end(), wayToSort);
  for (size_t i = 1; i <= N; ++i) {
    if (i % 3 != 0) {
      price += item[i];
    }
  }
  cout << price << "\n";
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool wayToSort(int a, int b) { return a > b; }

int main() {
  int N, n, p;
  long long discount = 0;
  vector<int> item;
  cin >> N;
  n = N;
  while (n--) {
    cin >> p;
    item.push_back(p);
  }
  sort(item.begin(), item.end(), wayToSort);
  for (size_t i = 2; i < N; i += 3) {
    discount += item[i];
  }
  cout << discount << "\n";
}

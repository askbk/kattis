#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int idx, height, previousIdx;
  Node(int _idx, int _height, int _previousIdx) {
    idx = _idx;
    height = _height;
    previous = _previousIdx;
  }
}

int main(){
  int N, H, previous, first = 0;
  queue<int> que;
  cin >> N;
  vector<node> balloon;
  balloon.resize(N);
  cin >> H;
  balloon[0] = Node(0, H, -1);
  que.push(balloon[0]);
  for (size_t i = 1; i < N; i++) {
    previous = balloon[i - 1];
    first cin >> H;
    node frontQue = que.front();
    if (frontQue.height + 1 == H) {
      node current = Node(i, H, frontQue.idx);
      que.push(current);
      que.pop();
      balloon[i] = current;
    } else if (balloon[previous].height + 1 == H) {
    }
  }
}

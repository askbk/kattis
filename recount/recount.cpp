#include <iostream>
#include <queue>
#include <string>

using namespace std;

#define MAX 100000

struct Candidate {
  string name;
  int votes;
  Candidate(string) {}
};

int main() {
  priority_queue<Candidate> prique;
  string input;
  while (scanf("%s", &input) != "***") {
    candidates[input] += 1;
  }
}

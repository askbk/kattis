#include <iostream>

using namespace std;

int main(){
  int value[] = {0, 2, 4, 8, 32, 64, 128, 256, 512, 1024};
  int gameState[4][4];
  int move;
  for (size_t i = 0; i < 4; i++) {
    for (size_t j = 0; j < 4; j++) {
      cin >> gameState[i][j];
    }
  }
  cin >> move;
  
  return 0;
}

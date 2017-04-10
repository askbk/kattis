#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
  string input;
  string output = "";
  map<char, string> alphabet;
  alphabet['a'] = "@";
  alphabet['b'] = "8";
  alphabet['c'] = "(";
  alphabet['d'] = "|)";
  alphabet['e'] = "3";
  alphabet['f'] = "#";
  alphabet['g'] = "6";
  alphabet['h'] = "[-]";
  alphabet['i'] = "|";
  alphabet['j'] = "_|";
  alphabet['k'] = "|<";
  alphabet['l'] = "1";
  alphabet['m'] = "[]\\/[]";
  alphabet['n'] = "[]\\[]";
  alphabet['o'] = "0";
  alphabet['p'] = "|D";
  alphabet['q'] = "(,)";
  alphabet['r'] = "|Z";
  alphabet['s'] = "$";
  alphabet['t'] = "']['";
  alphabet['u'] = "|_|";
  alphabet['v'] = "\\/";
  alphabet['w'] = "\\/\\/";
  alphabet['x'] = "}{";
  alphabet['y'] = "`/";
  alphabet['z'] = "2";
  getline(cin, input);

  for (char c : input) {
    if ((isalpha(c))) {
      output.append(alphabet[tolower(c)]);
    } else {
      output.push_back(c);
    }
  }

  std::cout << output << '\n';
  return 0;
}

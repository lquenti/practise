#include<iostream>

std::string s;


int main() {
  std::cin >> s;
  for (int i=0; i<s.size(); ++i) {
    if (s[i] == '.') {
      std::cout << '0';
      continue;
    }
    i++;
    std::cout << (s[i] == '.' ? '1' : '2');
  }
  std::cout << std::endl;
}

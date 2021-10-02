#include<iostream>

unsigned long long ull;
int c,i;
int main(){
  std::cin >> ull;
  while (ull != 0) {
    c = ull%10;
    if (c == 7 || c == 4) i++;
    ull/=10;
  }
  std::cout << (i == 7 || i == 4 ? "YES" : "NO") << std::endl;
}

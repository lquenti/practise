#include<iostream>
#include<cctype>
std::string s;
int main(){
  std::cin >> s;
  s[0] = (char)std::toupper(s[0]);
  std::cout << s << std::endl;
}

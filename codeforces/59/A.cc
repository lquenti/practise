#include<iostream>
#include<cctype>
std::string s;
size_t l=0,u=0;
int main(){
  std::cin >> s;
  for (auto c:s){
    (std::isupper(c)?u:l)+=1;
  }
  if (u>l) {
    for (auto c:s) {
      std::cout << (char)std::toupper(c);
    }
  } else {
    for (auto c:s) {
      std::cout << (char)std::tolower(c);
    }
  }
  std::cout << std::endl;
}

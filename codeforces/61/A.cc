#include<iostream>
std::string s1,s2;
int main(){
  std::cin >> s1 >> s2;
  for (size_t i=0; i<s1.size();++i){
    std::cout << (s1[i]+s2[i]==1+48+48) ? '1' : '0';
  }
  std::cout << std::endl;
}

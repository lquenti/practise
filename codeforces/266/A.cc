#include<iostream>

int n;
std::string s;
int sum=0,tmp=0;
int main(){
  std::cin >> n >> s;
  for (int i=0; i<n;++i) {
    if (s[i] == s[i+1]) sum++;
  }
  std::cout << sum << std::endl;
}

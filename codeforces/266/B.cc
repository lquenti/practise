#include<iostream>
#include<algorithm>
std::string s;
int n,t;

int main() {
  std::cin >> n >> t;
  std::cin >> s;
  for (;t>0;--t) {
    for (int i=0; i<n-1; ++i) {
      if (s[i] == 'B' && s[i+1] == 'G') {
	std::swap(s[i], s[i+1]);
	i++;
      }
    }
  }
  std::cout << s << std::endl;
}

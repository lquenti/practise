#include<iostream>
int n,m;

int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47, -1};

int main(){
  std::cin >> n >> m;
  
  for (int i=0; i<15; ++i) {
    if (n==primes[i]) std::cout << (m == primes[i+1] ? "YES" : "NO") << std::endl;
  }
}

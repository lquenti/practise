#include<vector>
#include<iostream>
#define N 100

int n,x,y,z;
int sumx = 0, sumy=0, sumz=0;
int main() {
  std::cin >> n;
  for (int i=0;i<n;++i) {
    std::cin >> x >> y >> z;
    sumx += x; sumy += y; sumz += z;
  }
  if (sumx == 0 && sumy == 0 && sumz == 0) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  
}

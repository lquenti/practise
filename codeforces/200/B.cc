#include<iostream>
#include<vector>

// I know there are rolling means but lets try whether this is
// within space limits
int n, sum=0,tmp;
int main() {
  std::cout.precision(17);
  std::cin >> n;
  for (int i=0; i<n; ++i) {
    std::cin >> tmp;
    sum += tmp;
  }
  std::cout << (double)(sum)/(double)(n) << std::endl;
}

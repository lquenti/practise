#include<iostream>
int n;
int main(){
  std::cin >> n;
  if (n%2) {
    std::cout << "-1" << std::endl;
    return 0;
  }
  for (int i=1; i<=n;++i) {
    if (i%2){
      std::cout << i+1 << " ";
    } else {
      std::cout << i-1 << " ";
    }
  }
  std::cout << std::endl;
}

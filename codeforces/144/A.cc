#include<iostream>

int n,min=110,max=-1,idmin,idmax,tmp;
int main() {
  std::cin >> n;
  for (int i=0;i<n;++i) {
    std::cin >> tmp;
    if (tmp > max) {
      max=tmp; idmax=i;
    }
    if (tmp <= min) {
      min=tmp; idmin=i;
    }
  }
  //std::cout << "min " << min << std::endl;
  //std::cout << "idmin " << idmin << std::endl;
  //std::cout << "max " << max << std::endl;
  //std::cout << "idmax " << idmax << std::endl;
  tmp = idmax + (n-1)-idmin;
  if (idmax > idmin) tmp--;
  std::cout << tmp << std::endl;
}

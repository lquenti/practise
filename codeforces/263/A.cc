#include<iostream>
#include<cstdlib>
int x,y,tmp;

int main() {
  for (x=1; x<=5;++x) {
    for (y=1;y<=5;++y) {
      std::cin >> tmp;
      if (tmp) {
	std::cout << abs(x-3) + abs(y-3) << std::endl;
      }
    }
  }
  
}

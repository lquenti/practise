#include<iostream>

bool xss[3][3] = {1,1,1,1,1,1,1,1,1};
int x,y,tmp;


int main() {
  for (x=0;x<3;++x) {
    for (y=0;y<3;++y) {
      std::cin >> tmp;
      if (tmp%2) {
	xss[x][y] = !xss[x][y];
        if (x+1 < 3) xss[x+1][y] = !xss[x+1][y];
        if (y+1 < 3) xss[x][y+1] = !xss[x][y+1];
        if (x-1 >= 0) xss[x-1][y] = !xss[x-1][y];
        if (y-1 >= 0) xss[x][y-1] = !xss[x][y-1];
      }
    }
  }
  for (x=0;x<3;++x){
    for(y=0;y<3;++y){
      std::cout << xss[x][y];
    }
    std::cout << std::endl;
  }
}

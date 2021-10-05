#include<iostream>

int k,l,m,n,d;
int idk=0,idl=0,idm=0,idn=0,sum=0;
bool b=false;
int main() {
  std::cin >> k >> l >> m >> n >> d;
  for (int i=0;i<d;++i) {
    idk++;idl++;idm++;idn++;
    if (idk == k) {b=true;idk=0;}
    if (idl == l) {b=true;idl=0;}
    if (idm == m) {b=true;idm=0;}
    if (idn == n) {b=true;idn=0;}
    if (b) sum+=1;
    b=false;
  }
  std::cout << sum << std::endl;
}

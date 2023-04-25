#include<bits/stdc++.h>

using namespace std;
#define ll long long

// http://www.usaco.org/index.php?page=viewproblem2&cpid=855
int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    ll cs[3];
    ll ms[3];
    cin >> cs[0] >> ms[0] >> cs[1] >> ms[1] >> cs[2] >> ms[2];
    //cout << "Initial State:" << ms[0] << " " << ms[1] << " " << ms[2] << endl;
    for (int i=0; i<100; ++i) {
        int from = i%3;
        int to = (i+1)%3;
        int amount = min(cs[to]-ms[to], ms[from]);
        ms[to]+=amount;
        ms[from]-=amount;
//        cout << i << " Pour " << from << " -> " << to << ": " << ms[0] << " " << ms[1] << " " << ms[2] << endl;
    }
    cout << ms[0] << endl << ms[1] << endl << ms[2] << endl;
}
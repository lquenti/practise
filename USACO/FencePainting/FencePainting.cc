#include<bits/stdc++.h>

using namespace std;

// http://www.usaco.org/index.php?page=viewproblem2&cpid=567
void fence_painting() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if (b < c || d < a) {
        cout << b-a + (d-c);
    } else {
        cout << max(d, b) - min(a, c);
    }
}

int main() {
  fence_painting();
}

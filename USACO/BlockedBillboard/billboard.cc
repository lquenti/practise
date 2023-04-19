#include<bits/stdc++.h>

using namespace std;

int rect_size(array<int, 4> a) {
    return (a[3]-a[1])*(a[2]-a[0]);
}

int overlap_line(int a,int b,int c,int d) {
    return max(min(b, d) - max(a, c), 0);
}

int overlap_rect(array<int,4> a, array<int,4> b) {
    return overlap_line(a[0], a[2], b[0], b[2]) *
    overlap_line(a[1], a[3], b[1], b[3]);
}

// http://www.usaco.org/index.php?page=viewproblem2&cpid=759
void blocked_billboard() {
    // 1: first billboard
    // 2: second billboard
    // t: truck
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int l1x, l1y, u1x, u1y, l2x, l2y, u2x, u2y, ltx, lty, utx, uty;
    cin >> l1x >> l1y >> u1x >> u1y >> l2x >> l2y >> u2x >> u2y >> ltx >> lty >> utx >> uty;
    int size = rect_size({l1x, l1y, u1x, u1y}) + rect_size({l2x, l2y, u2x, u2y});
    int overlap = overlap_rect({l1x,l1y,u1x,u1y}, {ltx, lty, utx, uty})
            + overlap_rect({l2x,l2y,u2x,u2y}, {ltx, lty, utx, uty});
    cout << size - overlap << endl;
}

int main() {
  blocked_billboard();
}

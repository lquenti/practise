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

////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////

struct Line {
    long l,r;
};

struct Rect {
    long lx, ly, ux, uy;
};

bool intersect_line(Line a, Line b) {
    // if a left of b then (no intersect <=> a.r < b.l)
    // if b left of a then (no intersect <=> b.r < a.l)
    return !(a.r < b.l || b.r < a.l);
}

bool intersect_rect(Rect a, Rect b) {
    return intersect_line({a.lx, a.ux}, {b.lx, b.ux})
        && intersect_line({a.ly, a.uy}, {b.ly, b.uy});
}

// int(w,b1) + int(w, b2) - int(b1, b2, w) >= w.size() dann completely covered
long inter_area(Rect a, Rect b) {
    if (!intersect_rect(a,b)) return 0;
    return (min(a.ux, b.ux) - max(a.lx, b.lx))
        * (min(a.uy, b.uy) - max(a.ly, b.ly));
}
long inter_area3(Rect a, Rect b, Rect c) {
    if (!intersect_rect(a,b)) return 0;
    if (!intersect_rect(a,c)) return 0;
    if (!intersect_rect(b,c)) return 0;
    return (min(min(a.ux, b.ux),c.ux) - max(max(a.lx, b.lx), c.lx))
        * (min(min(a.uy, b.uy),c.uy) - max(max(a.ly, b.ly),c.ly));
}

// https://codeforces.com/contest/1216/problem/C
void white_sheet() {
    Rect w{}, b1{}, b2{};
    cin >> w.lx >> w.ly >> w.ux >> w.uy
        >> b1.lx >> b1.ly >> b1.ux >> b1.uy
        >> b2.lx >> b2.ly >> b2.ux >> b2.uy;
    if (inter_area(w, b1) + inter_area(w, b2) - inter_area3(w, b1, b2)
        >= rect_size({w.lx, w.ly, w.ux, w.uy})) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    white_sheet();
//    blocked_billboard();
    //fence_painting();
    return 0;
}

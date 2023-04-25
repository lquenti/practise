#include<bits/stdc++.h>
using namespace std;
#define ll long long

// https://codeforces.com/problemset/problem/1555/B
int main() {
    int t;
    long W, H, x_1, y_1, x_2, y_2, w, h;
    cin >> t;
    while (t--) {
        cin >> W >> H >> x_1 >> y_1 >> x_2 >> y_2 >> w >> h;
        long dx = x_2 - x_1, dy = y_2-y_1;

        // move to top
        long top_shift = max(h - y_1, 0l);

        // move to bottom
        long bottom_shift = max(y_2 - H + h, 0l);

        // move left
        // W - w +rs = x_2
        long left_shift = max(x_2 - W + w, 0l);

        // move right
        // w = x_1 + right_shift
        // right_shift = w - x_1
        long right_shift = max(w-x_1, 0l);

        /*
        cout << "left " << left_shift << endl
        << "right " << right_shift << endl
        << "top " << top_shift << endl
        << "bottom " << bottom_shift << endl;
        */

        // dann min finden von allem was valide
        long res = LONG_MAX;
        // left and right-shift valid
        if (w + dx <= W) {
            res = min(right_shift, left_shift);
        }
        // top and bottom shift valid
        if (h + dy <= H) {
            res = min(res, min(top_shift, bottom_shift));
        }

        if (res == LONG_MAX) {
            res = -1;
        }
        cout << res << endl;
    }
}
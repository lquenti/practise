#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

auto f(vi &xs, int a, int b, int c) -> int {
    return xs[a]+xs[b]+xs[c]-(c-a);
}

void solve_single() {
    int n;
    cin >> n;
    vi signs;
    // 2 2 2 1  1 1 1 1 1 1 1 1 3 3 3
    // 3 1 1 6 5 3
    for (int i=0; i<n; i++) {
        int s;
        cin >> s;
        signs.pb(s);
    }

    /* by def, leftmost and rightmost are in the top 3 */
    int leftmost {0};
    int rightmost {2};
    int innermax {1};
    int i {rightmost};
    while (i < n-1) {
        /* early prune if it is not better than our current best */
        int j = i + 1;
        i++;
        if (signs[j] <= signs[leftmost] &&  signs[j] <= signs[innermax] && signs[j] <= signs[rightmost]) {
            continue;
        }

        /* can we throw out leftmost */
        int yeet_left = f(signs, innermax, rightmost, j);
        int yeet_inner = f(signs, leftmost, rightmost, j);
        int yeet_right = f(signs, leftmost, innermax, j);
        //int yeet_j = f(signs, leftmost, innermax, rightmost);

        if (yeet_left >= yeet_inner && yeet_left >= yeet_right) {
            /* best case is without left, so throw it out */
            leftmost = innermax;
            innermax = rightmost;
            rightmost = j;
            continue;
        } else if (yeet_inner >= yeet_left && yeet_inner >= yeet_right) {
            /* best case is without inner */
            innermax = rightmost;
            rightmost = j;
            continue;
        } else {
            /* best case is we do not use right */
            rightmost = j;
            continue;
        }

    }

    cout << f(signs, leftmost, innermax, rightmost) << endl;
}

void solve() {
    // DO THE SOLVING HERE
    int T;
    cin >> T;
    while (T--) {
        solve_single();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

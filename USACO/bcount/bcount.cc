#include<bits/stdc++.h>

using namespace std;

#define PROBLEM "bcount"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; " << endl;
#define NL cerr << endl << endl

void solve() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    // DO THE SOLVING HERE
    vector<int> ones{}; ones.push_back(0);
    vector<int> twos{}; twos.push_back(0);
    vector<int> threes{}; threes.push_back(0);
    int N, Q, tmp;
    cin >> N >> Q;
    while (N--) {
        cin >> tmp;
        ones.push_back(ones.back() + (tmp == 1));
        twos.push_back(twos.back() + (tmp == 2));
        threes.push_back(threes.back() + (tmp == 3));
    }

    int l,r;
    while (Q--) {
        cin >> l >> r;
        // r - (l-1)
        // 1 2 3 4 5
        // (2 bis 5) 5 - 1
//        ones[5] - ones[2-1]
        cout << ones[r] - ones[l-1] << " ";
        cout << twos[r] - twos[l-1] << " ";
        cout << threes[r] - threes[l-1] << endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
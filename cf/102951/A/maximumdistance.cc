#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

#define SQR(X) ((X)*(X))

ll square_dist(ll x1, ll y1, ll x2, ll y2) {
    return SQR(x2-x1) + SQR(y2-y1);
}

void solve() {
    // DO THE SOLVING HERE
    ll N;
    cin >> N;
    vll xs, ys;
    for (ll i=0; i<N; i++){
        ll x;
        cin >> x;
        xs.push_back(x);
    }
    for (ll i=0; i<N; i++) {
        ll y;
        cin >> y;
        ys.push_back(y);
    }
    ll mdist = 0.0;
    for (ll i=0; i<N; ++i) {
        for (ll j=i+1; j<N; ++j) {
            mdist = max(mdist, square_dist(xs[i], ys[i], xs[j], ys[j]));
        }
    }
    cout << mdist;
}

/// https://codeforces.com/gym/102951/problem/A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

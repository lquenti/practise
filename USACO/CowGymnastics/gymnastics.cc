#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "gymnastics"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

void solve() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    // DO THE SOLVING HERE

    ll K, N, ret=0;
    cin >> K >> N;
    vector<vector<ll>> xs;
    for (ll k=0; k<K; k++) {
        vll curr;
        for (ll i=0; i<N; ++i) {
            ll tmp;
            cin >> tmp;
            curr.push_back(tmp);
        }
        xs.push_back(curr);
    }

    for (int a=1; a<=N; ++a) {
        for (int b=1; b<=N; ++b) {
            // try to "prove" a is better than b
            if (a==b) goto FAILURE;
            for (auto row: xs) {
                for (auto elem:row) {
                    if (elem == a) {
                        // die line ist gut
                        goto SUCCESS;
                    }
                    if (elem == b) {
                        // nicht consistent
                        goto FAILURE;
                    }
                }
                SUCCESS:
                ;
            }
            ret+=1;
            FAILURE:
            ;
        }
    }
    cout << ret << endl;
}

// http://www.usaco.org/index.php?page=viewproblem2&cpid=963
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

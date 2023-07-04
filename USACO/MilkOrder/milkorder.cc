#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "milkorder"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl
// http://www.usaco.org/index.php?page=viewproblem2&cpid=832
void solve() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    int N,M,K,tmp;
    cin >> N >> M >> K;
    vi xs = vi(N, -1);
    vi ms = vi();
    auto ks = unordered_map<int, int>();
    // Vec<(i32, i32)>
    for (int m=0; m<M; m++){
        cin >> tmp;
        ms.push_back(tmp);
    }
    for (int k=0; k<K; k++) {
        int ci, pi;
        cin >> ci >> pi;
        ks[ci] = pi;

        if (ci == 1) {
            cout << pi << endl;
            return;
        }
    }
    for (int i=0; i<N; i++) {
        fill(xs.begin(), xs.end(), -1);
        xs[i] = 1;
        // fill the ks
        for (auto k: ks) {
            int ci = k.first;
            int pi = k.second;
            if (xs[pi-1] != -1) {
                // cow 1 takes the place of a fixed cow
                goto next_i;
            }
            xs[pi-1] = ci; // 1-based indexing
        }

        for (int j=0,mi=0; j<N; j++) {
            if (xs[j] != -1) {
                if (ms[mi] == xs[j]) {
                    mi++;
                }
            }
            // Wenn ms[mi] nicht in ks, dann setze ms[mi]
            else if (ks.find(ms[mi]) == ks.end()) {
                xs[j] = ms[mi];
                mi++;
            }
            // if the cow was ALREADY set b4, cow 1 is set too greedy
            else if (ks[ms[mi]] < j+1) {
                goto next_i;
            }


            if (ms[mi] == 1) {
                for (int k=0; k<j; k++) {
                    if (xs[k] == 1) {
                        goto next_i;
                    }
                }
            }

            if (mi == M) {
                cout << i+1 << endl;
                return;
            }
        }
        next_i:
        ;
    }


    cout << "n" << endl;
    int *x = nullptr;
    *x = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

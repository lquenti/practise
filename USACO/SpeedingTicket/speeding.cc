#include<bits/stdc++.h>

using namespace std;
#define ll int


// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    ll N = 0, M = 0, ls, ss;
    cin >> N >> M;
    vector<ll> nls, nss, mls, mss;



    // .back() fix
    cin >> ls >> ss;nls.push_back(ls);nss.push_back(ss);N--;
    while (N--) {
        cin >> ls >> ss;
        nls.push_back(ls);
        nss.push_back(ss);
    }
    N = (ll) nls.size();

    ll bessie_ind = 0;

    ll max_speed = 0;
    while (M--) {
        cin >> ls >> ss;
        while (ls > 0) {
            max_speed = max(max_speed, ss - nss[bessie_ind]);
            if (ls >= nls[bessie_ind]) {
                ls -= nls[bessie_ind];
                bessie_ind++;
                if (bessie_ind == N) {
                    goto fin;
                }
            } else {
                nls[bessie_ind] -= ls;
                ls = 0;
            }
        }
    }

    fin:
    cout << max_speed << endl;
}
#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "blocks"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

// http://www.usaco.org/index.php?page=viewproblem2&cpid=664
void solve() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    // DO THE SOLVING HERE
    ll N;
    cin >> N;
    array<int, 26> xs = {0};
    string f,b;
    while (N--) {
        array<int, 26> front = {0};
        array<int, 26> back = {0};
        cin >> f >> b;
        for (char c: f) {
           front[c-'a']++;
        }
        for (char c: b) {
            back[c-'a']++;
        }
        for (size_t i=0; i<26; ++i) {
            xs[i] += max(front[i], back[i]);
        }
    }

    for (size_t i=0; i< 26; ++i) {
        cout << xs[i] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

#include<bits/stdc++.h>

using namespace std;
#define ll long long

// http://www.usaco.org/index.php?page=viewproblem2&cpid=891
int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    ll N;
    cin >> N;
    ll scores[3 + 1] = {-1, 0, 0, 0}; // score[1] == score, wenn der pebble am Anfang in 1 war
    ll loc[3 + 1] = {-1, 1, 2, 3}; // loc[1] == location, wenn der pebble am Anfang in 1 war
    while (N--) {
        ll s1, s2, guess;
        cin >> s1 >> s2 >> guess;
        swap(loc[s1], loc[s2]);


        //cout << loc[1] << ", " << loc[2] << ", " << loc[3] << endl;

        for (ll i = 1; i<3+1; i++) {
            scores[i] += loc[guess] == i;
        }
    }
    /*
    cout << "1: " << scores[1] << endl
    << "2: " << scores[2] << endl
    << "3: " << scores[3] << endl;
     */
    cout << max(scores[1], max(scores[2], scores[3])) << endl;
}
#include<bits/stdc++.h>

using namespace std;

#define PROBLEM "evolution"

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
    int N;
    cin >> N;

    unordered_set<string> props{};
    vector<unordered_set<string>> sub_pops{};
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;

        sub_pops.push_back({});
        for (int k = 0; k < K; k++) {
            string s;
            cin >> s;
            sub_pops.back().insert(s);
            props.insert(s);
        }
    }

    // FIND UNIQUE
    int unique_one = -1;
    string unique_prop = nullptr;
    for (auto p: props) {
        int occ = -1; // not in
        for (int i = 0; i < N; i++) {
            if (sub_pops[i].find(p) != sub_pops[i].end()) {
                if (occ != -1) {
                    // found it second time
                    goto not_unique;
                } else {
                    occ = i;
                    unique_prop = p;
                }
            }
        }
        if (occ != -1) {
            unique_one = occ;
        }
        not_unique:
        ;
    }

    // if no unique found, then it is invalid
    if (unique_one == -1) {
        cout << "no" << endl;
        return;
    }

    // remove prop from unique subpop

    props.erase()
    // merge if possible (okay if not)
}


}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
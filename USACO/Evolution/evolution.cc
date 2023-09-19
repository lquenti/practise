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

    set<string> props{}; /* All props that exist at all */
    vector<set<string>> sub_pops{}; /* each population and their props */
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

    while (true) {
        // FIND UNIQUE
        int unique_one = -1;
        string_view unique_prop{};
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
                break;
            }
            not_unique:;
        }

        for (int i = 0; i < N; ++i) {
            if (sub_pops[i].size() > 0) {
                goto not_all_clear;
            }
        }
        cout << "yes" << endl;
        return;
        not_all_clear:

        // if no unique found, then it is invalid
        if (unique_one == -1) {
            cout << "no" << endl;
            return;
        }

        // Dont get a dangling ref if bad delete
        string unique{unique_prop};

        // remove prop from unique subpop
        sub_pops[unique_one].erase(unique);

        // merge if possible (okay if not)
        for (int i = 0; i < N; ++i) {
            if (i == unique_one) {
                continue;
            }
            if (sub_pops[i] == sub_pops[unique_one]) {
                sub_pops[i].clear();
            }
        }
    }
}

// B C
// B C
// D C X


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
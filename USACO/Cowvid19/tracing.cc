#include<bits/stdc++.h>
#include <functional>
#include <array>
using namespace std;

#define PROBLEM "tracing"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

struct row {
    int time;
    int cow_a;
    int cow_b;
};

void print_row(row r) {
    cerr << r.time << " " << r.cow_a << " " << r.cow_b << endl;
}

vector<int> convert(string bits) {
    vector<int> ret;
    ret.push_back(0);
    for (char c : bits)
        ret.push_back(c == '1');
    return ret;
}

void solve() {
    freopen(PROBLEM ".in", "r", stdin);
    freopen(PROBLEM ".out", "w", stdout);
    int N,T, tmp_time, tmp_a, tmp_b;
    string bits;
    vector<row> rows;

    cin >> N >> T;
    cin >> bits;
    vector<int> post_cond = convert(bits);


    for (int i=0; i<T; ++i) {
        cin >> tmp_time >> tmp_a >> tmp_b;
        rows.push_back(row{tmp_time,tmp_a, tmp_b});
    }

    sort(begin(rows), end(rows),
         [](auto a, auto b) {return a.time < b.time;});



    int min_k=1000000, max_k=-1;
    set<int> possible_K;
    set<int> possible_pat0;
    for (int k_cand = 0; k_cand <= T; k_cand++) {
        for (int pat0 = 1; pat0 <= N; pat0++) {
            // simulate disease spread
            vector<int> state(N+1);
            // state[1] == 1
            state[pat0] = k_cand+1;
            for (auto r : rows) {

                // interesting case 1 : cow a infectious and cow b healthy
                if (state[r.cow_a] > 1) {
                    if (state[r.cow_b] == 0) {
                        state[r.cow_b] = k_cand + 2;
                    }
                }

                // interesting case 2 : cow b infectious and cow a healthy
                else if (state[r.cow_b] > 1) {
                    if (state[r.cow_a] == 0) {
                        state[r.cow_a] = k_cand + 2; // +2 because of decrement down below
                    }
                }

                // decrement infectiousness-counter
                if (state[r.cow_a] > 1) {
                    state[r.cow_a]--;
                }
                if (state[r.cow_b] > 1) {
                    state[r.cow_b]--;
                }
            }

            for (int i = 1; i<=N; i++ ) {
                if ((state[i] > 0) != post_cond[i]) {
                    // not a candidate
                    goto FAILURE;
                }
            }

            // if consistent with results, pat0 is a possible patient 0 and k_cand is a possible bound for K
            possible_pat0.insert(pat0);
            //possible_K.insert(k_cand);
            min_k = min(min_k, k_cand);
            max_k = max(max_k, k_cand);

            FAILURE:
            ;
        }

    }

    //int min_K = *possible_K.begin();
    //int max_K = *possible_K.rbegin();
    int n_possible_pat0 = possible_pat0.size();

    cout << n_possible_pat0 << " ";
    cout << min_k << " ";
    if (max_k == T) {
        cout << "Infinity";
    } else {
        cout << max_k;
    }
    cout << endl;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl
#define R(X) X.begin(),X.end() // range

int calculate_diff_sum(vi xs, size_t skip1, size_t skip2) {
//    int res = 0;
//
//    int prev = -1;
//    for (size_t i=0; i<xs.size()-1; i++) {
//        if (i != skip1 && i != skip2) {
//            int val = xs[i];
//            if (prev != -1) {
//                res += val-prev;
//            }
//            prev = val;
//        }
//    }
//    return res;


    ///////////////////
    int a,b; // a<b
    if (skip1 < skip2) {a=skip1;b=skip2;} else {a=skip2;b=skip1;}
    vi ys(xs);
    ys.erase(ys.begin()+b);ys.erase(ys.begin()+a);
    int res2=0;
    for (size_t i=0; i<ys.size()-1; i+=2) {
        res2+=ys[i+1] - ys[i];
    }
    return res2;
}

void solve() {
    int n, tmp;
    vi xs;
    cin >> n;
    n *= 2;
    while (n--) {
        cin >> tmp;
        xs.push_back(tmp);
    }
    sort(xs.begin(), xs.end());

    int res = 1000000;
    for (size_t i=0; i<xs.size(); i++) {
        for (size_t j=i+1; j<xs.size(); j++) {
            tmp = calculate_diff_sum(xs,i,j);
            if (tmp < res) res=tmp;
        }
    }



    cout << res << endl;
}

// 50 55 56 660
// 50 55 60 65 1000 2000
//   5  5  5  1000-65 1000

// 50 55 1000       2000     3060 3065
//   5  45    1000-65     1060    5


// https://codeforces.com/contest/863/problem/B
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

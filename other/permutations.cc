#include<bits/stdc++.h>

#define graph vector<vector<double>>
#define path vector<int>
#define N 5

using namespace std;

graph G = {
        { 0.0, 18.73245842, 13.82772511, 19.87692121, 18.19886162 },
        { 18.73245842, 0.0, 0.87246248, 2.43232237, 12.52686046 },
        { 13.82772511, 0.87246248, 0.0, 8.37226594, 17.60489811 },
        { 19.87692121, 2.43232237, 8.37226594, 0.0, 10.55886287 },
        { 18.19886162, 12.52686046, 17.60489811, 10.55886287, 0.0 }
};

double eval_path(const path &p) {
    double acc = 0.0;
    for (int i=0; i<p.size()-1; ++i) {
        acc += G[i][i+1];
    }
    acc += G[p.size()-1][0]; // cycle
    return acc;
}

pair<double, path> solve_internal(double cost, path p_initial);
// Next steps:
// 1. prefix sum mitbringen
// 2. prune: wenn bereits schlechter als bisheriges min gib auf
// 3. (mach ich alleine): bound mit MST
// 4. n * NN, danach pr
pair<double, path> solve() {
    path p_initial = {};
    double best_cost = numeric_limits<double>::max();
    path best_path;
    for (int i=0; i<N; i++) {
        p_initial.push_back(i);
        auto best = solve_internal(0.0, p_initial);
        if (best.first < best_cost) {
            best_cost = best.first;
            best_path = best.second;
        }
        p_initial.pop_back();
    }
    return {best_cost, best_path};
}

pair<double, path> solve_internal(double cost, path p_initial) {
    if (p_initial.size() == N) {
        cost += G[p_initial.back()][p_initial[0]];
        return {cost, p_initial};
    }
    double best_cost = numeric_limits<double>::max();
    path best_path;
    for (int i=0; i<N; i++) {
        if (find(p_initial.begin(), p_initial.end(), i) != p_initial.end()) continue;
        double new_edge = G[p_initial.back()][i];
        cost += new_edge;
        p_initial.push_back(i);
        pair<double, path> best = solve_internal(cost, p_initial);
        if (best.first < best_cost) {
            best_cost = best.first;
            best_path = best.second;
        }
        cost -= new_edge;
        p_initial.pop_back();
    }
    return {best_cost, best_path};
}

int main() {
    // TODO: fixed allocated length vec
    auto res = solve();
    cout << res.first << " ";
    for (auto x : res.second) cout << x << " ";
    cout << endl;
}
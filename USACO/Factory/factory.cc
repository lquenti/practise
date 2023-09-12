#include<bits/stdc++.h>
using namespace std;

#define PROBLEM "factory"

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>

#define P(X) cerr << #X << "=" << X << "; ";
#define NL cerr << endl << endl

void solve() {
  freopen(PROBLEM ".in", "r", stdin);
  freopen(PROBLEM ".out", "w", stdout);
  int N;
  cin >> N;
  vector<vector<int>> xs;
  for (int i=0; i<=N; i++) {
      xs.push_back({});
  }
  for (int i=1; i<N; i++) {
      int from, to;
      cin >> from >> to;
      xs[to].push_back(from);
  }

  for (int i=1; i<=N; ++i) {
      vector<int> visited(N+1,0);
      int n_visited = 0;
      vector<int> stack{};
      stack.push_back(i);
      while (!stack.empty()) {
          int current = stack.back();
          stack.pop_back();
          if (visited[current]) {
              continue;
          }
          n_visited++;
          if (n_visited == N) {
              cout << i << endl;
              return;
          }
          visited[current] = 1;

          for (int neighbour : xs[current]) {
              if (!visited[neighbour]) {
                  stack.push_back(neighbour);
              }
          }
      }
  }
  cout << "-1" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, K; cin >> n >> K;
  int tot = 0, m = 0;
  vector<string> a(n);
  for (auto &x : a) cin >> x, tot += x.size();
  vector<array<int, 26>> tr(tot+1);
  vector<int> cnt(tot+1);
  
  auto insert = [&] (string& s) {
    int u = 0;
    for (auto c : s) {
      if (!tr[u][c-'A']) tr[u][c-'A'] = ++m;
      u = tr[u][c-'A']; 
      cnt[u]++;
    }
  };
  for (auto& x : a) insert(x);
  int ans = 0;
  for (int i = 1; i <= m; ++i) ans += cnt[i] / K;
  cout<< ans <<"\n";

}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
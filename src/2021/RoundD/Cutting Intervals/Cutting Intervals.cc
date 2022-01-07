#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t n, C; cin >> n >> C;
  vector<array<int64_t, 2>> a(n);
  for (auto &[x, y] : a) cin >> x >> y;
  vector<int64_t> alls;
  for (auto [x, y] : a) {
    alls.push_back(x + 1);
    alls.push_back(y);
  }
  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());
  int m = alls.size();
  unordered_map<int64_t, int> mp;
  for (int i = 0; i < m; ++i) mp[alls[i]] = i;
  vector<int64_t> b(m);
  for (auto &[x, y] : a) {
    b[mp[x + 1]]++;
    b[mp[y]]--;
  }
  partial_sum(b.begin(), b.end(), b.begin());

  priority_queue<array<int64_t, 2>> pq;
  for (int i = 0; i < m - 1; ++i) {
    pq.push({b[i], alls[i + 1] - alls[i]});
  } 
  int64_t ans = 0;
  while (pq.size() && C) {
    auto [x, y] = pq.top(); pq.pop();
    int64_t cur = min(C, y);
    ans += cur * x;
    C -= cur;
  }
  cout << ans + n << endl;
}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";  
    solve();
  }
  return 0;
}

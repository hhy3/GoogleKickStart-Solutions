#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, K; cin >> n >> K;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
      int x = a[i] - a[i-1];
      cnt += (x + mid - 1) / mid - 1;
    }
    if (cnt <= K) hi = mid;
    else lo = mid + 1;
  }
  cout << lo << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
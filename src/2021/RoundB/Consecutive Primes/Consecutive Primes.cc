#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t Z; cin >> Z;
  int64_t x = sqrt(Z);
  auto is_prime = [] (int x) {
    for (int i = 2; i <= x / i; ++i) {
      if (x % i == 0) return false;
    }
    return true;
  };
  vector<int64_t> before, after;
  for (int i = x; before.size() < 2; --i)
    if (is_prime(i)) before.push_back(i);
  for (int i = x + 1; after.size() < 1; ++i) 
    if (is_prime(i)) after.push_back(i);
  int64_t ans = before[0] * before[1];
  if (int64_t y = before[0] * after[0]; y <= Z) ans = max(ans, y);
  cout << ans << endl;
}

int main() {
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

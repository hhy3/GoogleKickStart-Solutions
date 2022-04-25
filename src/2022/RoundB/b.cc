#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t X; cin >> X;
  int ans = 0;

  auto palindrome = [&] (int64_t x) {
    string s = to_string(x);
    if (s == string(s.rbegin(), s.rend())) return true;
    return false;
  };

  for (int64_t i = 1; i * i <= X; ++i) {
    if (X % i == 0) {
      if (palindrome(i)) ans++;
      if (i * i != X && palindrome(X / i)) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
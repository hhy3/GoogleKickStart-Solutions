#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;
int n;
int64_t a[N], b[N], c[N];
int f[N];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = b[i-1] + a[i], c[i] = c[i-1] + b[i];
  b[n+1] = -1e18;
  stack<int> stk;
  stk.push(n+1);
  for (int i = n; i >= 0; --i) {
    while (b[stk.top()] >= b[i]) {
     stk.pop(); 
    }
    f[i+1] = stk.top() - 1;
    stk.push(i);
  }
  int64_t ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (c[f[i]] - c[i-1]) - (f[i] - i + 1) * b[i-1];

  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

#include <bits/stdc++.h>
using namespace std;

const int MAXM = 2e5, MAXN = 5e4, MAXQ = 1e5;
int64_t tr[MAXM + 10 << 2];
vector<array<int64_t, 3>> G[MAXN + 10];
vector<array<int, 2>> queries[MAXN + 10];
int64_t ans[MAXQ + 10];

void update(int i, int64_t val, int x, int xl, int xr) {
  if (xl == xr) {
    tr[x] = val;
    return;
  }
  int mid = xl + xr >> 1;
  if (i <= mid) update(i, val, x << 1, xl, mid);
  else update(i, val, x << 1 | 1, mid + 1, xr);
  tr[x] = gcd(tr[x << 1], tr[x << 1 | 1]);
}

int64_t sum(int l, int r, int x, int xl, int xr) {
  if (xl >= l && xr <= r) return tr[x];
  if (xl > r || xr < l) return 0;
  int mid = xl + xr >> 1;
  int64_t L = sum(l, r, x << 1, xl, mid);
  int64_t R = sum(l, r, x << 1 | 1, mid + 1, xr);
  return gcd(L, R);
}

void dfs(int u, int p) {
  for (auto [w, idx] : queries[u]) {
    ans[idx] = sum(1, w, 1, 1, MAXM);
  }
  for (auto [v, l, a] : G[u]) if (v != p) {
    update(l, a, 1, 1, MAXM);
    dfs(v, u);
    update(l, 0, 1, 1, MAXM);
  }
}

void solve() {
  memset(tr, 0, sizeof tr);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; ++i) G[i].clear(), queries[i].clear();
  for (int i = 0; i < n - 1; ++i) {
    int64_t u, v, l, a; cin >> u >> v >> l >> a;
    G[u].push_back({v, l, a});
    G[v].push_back({u, l, a});
  }
  for (int i = 0; i < q; ++i) {
    int u, w; cin >> u >> w;
    queries[u].push_back({w, i});
  }
  dfs(1, 0);
  for (int i = 0; i < q; ++i) cout << ans[i] << ' ';
  cout << endl;

}

int main() {
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";  
    solve();
  }
  return 0;
}

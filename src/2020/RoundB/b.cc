#include <bits/stdc++.h>
using namespace std;

void solve() {
  int64_t n,D;cin>>n>>D;
  vector<int64_t>a(n);
  for(auto&x:a)cin>>x;
  for(int i=n-1;i>=0;--i)D=D/a[i]*a[i];
  cout<<D<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
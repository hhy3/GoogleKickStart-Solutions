#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (auto&x:a)cin>>x;
  int ans=0;
  for(int i=1;i<n-1;++i)if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
  cout<<ans<<"\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}
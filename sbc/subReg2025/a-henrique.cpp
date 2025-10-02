#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

vi freq;
int mx[512345];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int ans = 0;
   int n,m; cin >> n >> m;
   for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        int a;
        cin >> a;
        mx[j] = max(mx[j], a);
    }
   }
   for(int i = 0; i < m; i++) {
    ans += mx[i];
   }
    cout << ans << '\n';
    return 0;
}
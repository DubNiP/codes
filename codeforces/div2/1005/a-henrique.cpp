#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define ii pair<int,int>
#define iii pair<int,ii>

#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define vvii vector<vii>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++){
        if (s[i] != s[i-1]) ans++;
    }
    ans += s[0] == '1';
    cout << ans << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
    return 0;
}
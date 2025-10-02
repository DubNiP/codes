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
    vi a(n);
    for (auto &x : a) cin >> x;

    vi freq(n+1);
    for (auto x : a) freq[x]++;

    int l = 0, r = 0;
    int ans = 0, cur = 0;
    for (int i = 0; i < n; i++){
        if (freq[a[i]] == 1) cur++;
        else {
            cur = 0;
        }
        if (cur > ans){
            ans = cur;
            l = i-cur+2;
            r = i+1;
            // atualizo o l,r e o ans
        }
    }

    if (ans == 0) cout << 0 << '\n';
    else cout << l << ' ' << r << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
    return 0;
}
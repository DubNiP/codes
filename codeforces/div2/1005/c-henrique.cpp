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

    vi prefPosSum(n);
    vi sufNegSum(n);
    for (int i = 0; i < n; i++){
        prefPosSum[i] = max(a[i],0LL);
        if (i > 0) prefPosSum[i] += prefPosSum[i-1];
    }
    for (int i = n-1; i >= 0; i--){
        sufNegSum[i] = max(-a[i],0LL);
        if (i < n-1) sufNegSum[i] += sufNegSum[i+1];
    }

    int ans = sufNegSum[0];
    for (int i = 0; i < n; i++){
        int op = prefPosSum[i];
        if (i < n-1) op += sufNegSum[i+1];
        ans = max(ans, op);
    }

    cout << ans << '\n';
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t = 1; 
    cin >> t;
    while(t--) solve();
    return 0;
}
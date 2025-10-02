#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define LOGN 20
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>


void buildSparseTable(vvii &st, vi &v){
    int m = v.size();
    st.assign(LOGN, vii(m));

    for (int i = 0; i < m; i++){
        st[0][i] = {v[i],i};
    }

    for (int i = 1; (1ll<<i) <= m; i++){
        int len = 1ll<<i;
        for (int time = 0; time + len <= m; time++){
            ii ans1 = st[i-1][time];
            ii ans2 = st[i-1][time+len/2];
            st[i][time] = min(ans1,ans2);
        }
    }
}

vi a, b;
vvii st1, st2;

ii rmq(vvii &st, int l, int r){
    // cout << "params " << l << ' ' << r << endl;
    int k = __bit_width(r-l+1) - 1;



    ii ans1 = st[k][l];
    ii ans2 = st[k][r-(1<<k)+1];

    return min(ans1,ans2);
}

void solve(){
    int n, k; cin >> n >> k;
    a = b = vi(n);
    for (auto &x : a) cin >> x;

    for (int i = 0; i < n; i++){
        b[i] = a[i]+i+1;
    }

    buildSparseTable(st1,a);
    buildSparseTable(st2,b);

    int ans = 0;

    const int INF = 1e18;

    for (int i = 0; i < n; i++){
        int idop1 = rmq(st2, max(i-k+1, 0ll), i).second; // opcao do meio (aplicar a escada)
        int op1 = a[idop1] + k-i+idop1;
        int idop2 = i < n-1 ? rmq(st1, i+1,n-1).second : -1;
        int op2 = idop2 != -1 ? a[idop2] : INF;
        int idop3 = i >= k ? rmq(st1,0,i-k).second : -1;
        int op3 = idop3 != -1 ? a[idop3] : INF;
        // int idop1 = i+k < n ? rmq(st1, i+k,n-1).second : -1;
        // int idop2 = rmq(st2,i,i+k-1).second;
        // int idop3 = i > 0 ? rmq(st1, 0, i-1).second : -1;
        // int op1 = idop1 != -1 ? a[idop1] : INF;
        // int op2 = a[idop2] + idop2-i+1;
        // int op3 = idop3 != -1 ? a[idop3] : INF;
        // cout << idop1 << ' ' << idop2 << ' ' << idop3 << endl;
        // cout << endl;
        ans = max(ans, min(op3,min(op1, op2))); 
    }

    cout << ans << endl;

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}


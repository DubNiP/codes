#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>

vvi bit(6, vi(6));
vector<ii> fromBit(21);

struct DSU {
    vi p, sz;

    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    int find(int i) {
        if (p[i] == i) return i;
        return p[i] = find(p[i]);
    }

    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) swap(u, v);
        
        p[v] = u;
        sz[u] += sz[v];
    }
};

int hasSolution(int mask){
    if (mask == 0) return 0;

    DSU dsu(6);
    vi freq(6);
    int cnt = 0;

    vi appears(6);

    while (mask > 0){
        int lsb = mask&-mask;
        int id = __builtin_ctz(lsb);
        auto [a,b] = fromBit[id];
        dsu.unite(a,b);
        freq[a]++;
        freq[b]++;
        // if (log) cout << a << ' ' << b << endl;
        appears[a] = appears[b] = 1;
        mask -= lsb;
    }

    for (auto a : appears) cnt += a;

    // check connectivity
    for (int i = 0; i < 6; i++){
        if (!appears[i]) continue;
        int sz = dsu.sz[dsu.find(i)];
        if (sz != cnt) return 0;
    }

    int cntOdd = 0;
    for (auto f : freq) 
        if (f&1) cntOdd++;
    
    return cntOdd <= 2;
}

void solve(){
    int t; cin >> t;
    int cnt = 0;
    for (int a = 0; a < 6; a++) {
        for (int b = a; b < 6; b++) {
            bit[a][b] = cnt++;
            fromBit[bit[a][b]] = ii(a,b);
        }
    }

    const int MAX = 1<<21;
    vi sos(MAX);
    for (int mask = 0; mask < MAX; mask++){
        sos[mask] = hasSolution(mask);
    }

    for (int i = 0; i < 21; i++){
        for (int mask = 0; mask < MAX; mask++){
            if (mask & (1<<i)) sos[mask] += sos[mask ^ (1<<i)];
        }
    }

    while(t--){
        int n; cin >> n;
        int mask = 0;
        while(n--){
            int a, b; cin >> a >> b; a--,b--;
            mask |= (1 << bit[a][b]);
        }
        cout << sos[mask] << '\n';
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
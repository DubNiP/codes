#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int MOD = 1e9+7;
struct mint {
    ll v;

    mint() : v(0) {}
    mint(ll _v) {
        v = _v % MOD;
        if (v < 0) v += MOD;
    }

    static mint power(mint base, ll exp) {
        mint res = 1;
        base.v %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res *= base;
            base *= base;
            exp /= 2;
        }
        return res;
    }

    mint inv() const {
        return power(*this, MOD - 2);
    }

    mint& operator+=(const mint& other) {
        v += other.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }

    mint& operator-=(const mint& other) {
        v -= other.v;
        if (v < 0) v += MOD;
        return *this;
    }

    mint& operator*=(const mint& other) {
        v = (v * other.v) % MOD;
        return *this;
    }


    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }

    // Unary minus
    mint operator-() const {
        return mint(-v);
    }

    // Increment and decrement operators
    mint& operator++() {
        v++;
        if (v == MOD) v = 0;
        return *this;
    }

    mint operator++(int) {
        mint temp = *this;
        ++*this;
        return temp;
    }

    mint& operator--() {
        if (v == 0) v = MOD;
        v--;
        return *this;
    }

    mint operator--(int) {
        mint temp = *this;
        --*this;
        return temp;
    }

    // Comparison operators
    bool operator==(const mint& other) const {
        return v == other.v;
    }
    bool operator!=(const mint& other) const {
        return v != other.v;
    }

    friend ostream& operator<<(ostream& os, mint &m) {
        os << m.v;
        return os;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    vector<mint> queries(q+1);
    vector<vector<int>> pos(n+1);
    vector<mint> pot2(q+1), pot2inv(q+1), presum(q+1);

    pot2[0] = pot2inv[0] = 1;
    mint inv2 = mint(2).inv();


    for (int i = 1; i <= q; i++){
        int x; cin >> x;
        queries[i] = mint(x);
        pot2[i] = pot2[i-1]*2;
        pot2inv[i] = pot2inv[i-1]*inv2;
        presum[i] = pot2inv[i]*x + presum[i-1];
        pos[x].push_back(i);
    }

    for (int i = 1; i <= n; i++){
        mint ans = 0;
        mint prob = mint(i==1?1:0);
        int start = 1;
        for (auto x : pos[i]){
            if (x > start){
                ans += prob*(presum[x-1] - presum[start-1]) * pot2[start-1];
                prob *= pot2inv[x-start];
            }
            ans += prob*inv2*queries[x];
            prob = inv2*(prob+1);
            start = x+1;
        }

        if (start <= q){
            ans += prob*(presum[q]-presum[start-1])*pot2[start-1];
        }

        cout << ans.v << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
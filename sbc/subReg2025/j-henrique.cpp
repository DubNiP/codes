#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;

vi freq;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freq = vi(4);
    for(int i = 0; i < 10; i++){
        int a;
        cin >> a; a--;
        freq[a] += 1;
    }
    int ans = 0;
    for(int i = 0; i < 4; i++){
        if(freq[i] == 0) ans++;
    }
    cout << ans << '\n';
    return 0;
}
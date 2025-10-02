#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int> vi;
typedef pair<int, int> ii;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int x, y, xa, ya;
    cin >> xa >> ya;
    vi pts(n + 10);
    pts[0] = 0;
    vi sent(n + 10);
   // cout << pts[0] << " ";
    for(int i = 1; i < n; i++) {
        cin >> x >> y;
        int dist;
        if(x == xa) {
            dist = abs(y - ya);
        }
        else {
            dist = abs(x - xa);
        }
        pts[i] = pts[i - 1] + dist;
       // cout << pts[i] << " ";
        xa = x; ya = y;
    }
   // for(int i = 0; i < n; i++) cout << pts[i] << " ";
    //cout << '\n';
    int l = 1, r = 1e12; int best = 0;
    while(l < r) {
        int mid = (l + r)/2;
         int radius = mid; 
         int p = -radius;  
        int last = -1;
        for(int i = 0; i < n; i++) {
            p += 2 * radius;
            if(i < n - 1 && p >= pts[i + 1]) {
                last = i; break;
            }
            if(i < n - 1) radius = pts[i + 1] - p;
        }
        if(last == -1) {
            best = max(best, mid);
            l = mid + 1;
        }
        else {
            int dim = (last % 2) == 0;
            if(dim) r = mid;
            else l = mid + 1;
        }
    }
    cout << ((best == 0)?(-1):(best)) << '\n';
    return 0;
}
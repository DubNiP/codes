#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> ii;
const int inf = 1e18;

int n, t, q, k, f, m;
map<string, int> strToIndex;
map<int, string> indexToStr;
map<int, ii> vec;
vector<int> dict, base;

string s;
int u, v;

int dot(ii a, ii b){
    return a.first*b.first + a.second*b.second;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s >> u >> v;
        strToIndex[s] = t;
        indexToStr[t] = s;
        vec[t] = ii(u, v);
        dict.push_back(t);
        t++;
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> s;
        if(strToIndex.count(s) == 0){
            strToIndex[s] = t;
            indexToStr[t] = s;
            vec[t] = ii(0, 0);
            t++;
        }
        base.push_back(strToIndex[s]);
    }
    cin >> q >> k;
    for(int i = 0; i < q; i++){
        cin >> f;
        vector<int> query;
        for(int j = 0; j < f; j++){
            cin >> s;
            if(strToIndex.count(s) == 0){
                strToIndex[s] = t;
                indexToStr[t] = s;
                vec[t] = ii(0, 0);
                t++;
            }
            query.push_back(strToIndex[s]);
        }
        int found = 0;
        vector<int> indexes;
        for(int j = k; j > 0 && !found; j--){
            for(int l = 0; l < m; l++){
                int ok = 1;
                for(int o = 0; o < j; o++){
                    if(base[l+o] != query[f-j+o]) ok = 0;
                }
                if(ok && l+j < m) indexes.push_back(l+j);
            }
            if(indexes.size() > 0) found = 1;
        }
        int mx = -inf, mxi = -1;
        for(int d = 0; d < (int)dict.size(); d++){
            int sum = 0;
            for(auto ind: indexes) sum += dot(vec[dict[d]], vec[base[ind]]);
            if(sum > mx){
                mx = sum;
                mxi = d;
            }
        }
        for(auto q: query) cout << indexToStr[q] << " ";
        if(found) cout << indexToStr[mxi] << '\n';
        else cout << "*\n";
    }
    return 0;
}

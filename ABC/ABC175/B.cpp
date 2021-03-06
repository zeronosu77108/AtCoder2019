#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}

using int64 = long long;

int main() {
    int n;
    cin >> n;
    vector l(n,0);
    for (int i=0; i<n; i++) cin >> l[i];

    int ans = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (l[i] == l[j])continue;
            for (int k=j+1; k<n; k++) {
                if (l[i]==l[k] || l[j]==l[k]) continue;
                if (l[i]+l[j]<=l[k] || l[i]+l[k]<=l[j] || l[j]+l[k]<=l[i]) continue;
                ans++;
            }
        }
    }

    cout << ans << endl;
}
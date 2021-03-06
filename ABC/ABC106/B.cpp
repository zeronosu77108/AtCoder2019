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

int diviser(int n) {
    int res = 0;
    for (int i=1; i*i<=n; i++) {
        if (n%i == 0) {
            res++;
            if (n/i != i) res++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i=1; i<=n; i+=2) {
        if (diviser(i) == 8) ans++;
    }

    cout << ans << endl;
}
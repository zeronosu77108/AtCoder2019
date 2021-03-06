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
    int n, k;
    cin >> n >> k;
    vector pre(n+1, 0LL);
    for (int i = 0; i < n; i++) cin >> pre[i];


    for (int i=0; i<k; i++) {
        vector c(n+1, 0LL);
        for (int j = 0; j < n; j++) {
            c[max(0LL, j-pre[j])]++;
            c[min(n-1LL, j+pre[j])+1]--;
        }
        for (int j=0; j<n; j++) c[j+1] += c[j];

        pre = c;
        if (all_of(pre.begin(), pre.end()-1, [&](const int& x){return x==n;})) {
            break;
        }
    }


    for (int j = 0; j < n; j++) {
        cout << pre[j] << " ";
    }
    cout << endl;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cout<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<v<<endl;}


typedef long long int64;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin>>a[i];

    int ans = INT_MAX;
    for (int i=-100; i<=100; i++) {
        int tmp = 0;
        for (int j=0; j<n; j++) {
            tmp += (i-a[j])*(i-a[j]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
}
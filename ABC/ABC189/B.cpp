//
// Created by zeronosu77108 on Jan 23, 2021.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <set>
#include <complex>
#include <optional>

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;

int main() {
    int n;
    int x;
    cin >> n >> x;
    x *= 100;

    int sum = 0;
    for (int i=0; i<n; i++) {
        int v, p;
        cin >> v >> p;
        sum += v * p;
        if (x < sum) {
            cout << i+1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
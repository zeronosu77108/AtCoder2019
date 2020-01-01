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

typedef long long int64;


int main() {
    int n, a, b, k;
    bool ans = true;
    map<int, int> mp;
    cin >> n >> a >> b;
    cin >> k;
    mp[a]++;
    mp[b]++;
    for (int i = 0; i < k; i++) {
        int p;
        cin >> p;
        if (mp[p]++) ans = false;
    }

    cout << (ans? "YES" : "NO") << endl;
}
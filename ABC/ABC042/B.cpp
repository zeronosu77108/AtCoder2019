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
    int n,l;
    cin >> n >> l;
    vector<string> s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    sort(s.begin(), s.end());

    for (auto as : s) cout << as;
    cout << endl;
}
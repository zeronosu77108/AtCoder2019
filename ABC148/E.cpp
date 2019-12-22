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
    int64 n;
    int64 ans = 0;
    cin >> n;
    if (n%2) {
        cout << 0 << endl;
        return 0;
    }

    ans += n /= 10;
    while(n != 0) {
        ans += n /= 5;
    }

    cout << ans << endl;
    return 0;
}
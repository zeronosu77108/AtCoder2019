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
    int n;
    cin >> n;
    int h = n / 3600;
    n %= 3600;
    int m = n / 60;
    n %= 60;
    int s = n;

    printf("%02d:%02d:%02d\n",h,m,s);
}
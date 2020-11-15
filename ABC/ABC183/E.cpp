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

using namespace std;
struct aaa{aaa(){cin.tie(nullptr); ios::sync_with_stdio(false); cout<<fixed<<setprecision(20);};}aaa;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
#define debug(v) {cerr<<"\033[1;36m[debug]\033[m "<<#v<<" : "<<(v)<<endl;}

using int64 = long long;
using P = pair<int, int>;

const int MOD = 1'000'000'007;
class mint {
    using int64 = long long;
private:
    int64 x;
public:
    mint(const int64 x1=0) { x = x1%MOD; };

    mint& operator++(int n) { x+=1; return *this; };
    mint& operator--(int n) { x-=1; return *this; };
    mint& operator=(int64 n) { x=n%MOD; return *this; };
    mint& operator--() {x-=1; return *this; };
    mint& operator+=(const mint a) { if ( (x+=a.x) >= MOD) x-=MOD; return *this; }
    mint& operator-=(const mint a) { if ( (x+= MOD-a.x) >= MOD) x-= MOD; return *this; }
    mint& operator*=(const mint a) { (x*=a.x) %= MOD; return *this; }
    mint& operator/=(const mint a) { return (*this) *= a.inv();}
    mint operator+(const mint a) const { mint res(*this); return res+=a; }
    mint operator-(const mint a) const { mint res(*this); return res-=a; }
    mint operator*(const mint a) const { mint res(*this); return res*=a; }
    mint operator/(const mint a) const { mint res(*this); return res/=a; }
    mint inv() const { return pow(MOD-2);}
    friend ostream& operator<<(ostream &os, const mint a) noexcept { return os << a.x; }
    constexpr bool operator == (const mint& r) const noexcept { return this->x == r.x; }
    constexpr bool operator != (const mint& r) const noexcept { return this->x != r.x; }
    mint pow(long long t) const {
        if (!t) return mint(1);
        mint a = pow(t>>1);
        a*=a;
        if(t&1) a*= *this;
        return a;
    }
};


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i=0; i<h; i++) cin >> s[i];

    vector dp(4, vector(h, vector(w, mint(0))));
    dp[0][0][0] = 1;

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') continue;

            if (j>0) {
                dp[0][i][j] += dp[0][i][j-1] + dp[1][i][j-1];
                dp[1][i][j] = dp[0][i][j-1] + dp[1][i][j-1];
            }

            if (i>0) {
                dp[0][i][j] += dp[0][i-1][j] + dp[2][i-1][j];
                dp[2][i][j] = dp[0][i-1][j] + dp[2][i-1][j];
            }

            if (i>0 && j>0) {
                dp[0][i][j] += dp[0][i-1][j-1] + dp[3][i-1][j-1];
                dp[3][i][j] = dp[0][i-1][j-1] + dp[3][i-1][j-1];
            }
        }
    }

    cout << dp[0][h-1][w-1] << endl;
}
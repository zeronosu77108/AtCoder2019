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

const int MOD = 1000000007;
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

    int k = 0;
    for (int i=0; i<h; i++) k += count(s[i].begin(), s[i].end(), '.');

    vector up(h, vector(w, 0LL));
    vector down(h, vector(w, 0LL));
    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            if (s[j][i] != '#') {
                up[j][i]++;
                if (j>0) up[j][i] += up[j-1][i];
            }
            if (s[h-j-1][i] != '#') {
                down[h-j-1][i]++;
                if (j>0) down[h-j-1][i] += down[h-j][i];
            }
        }
    }


    vector left(h, vector(w, 0LL));
    vector right(h, vector(w, 0LL));
    for (int j=0; j<h; j++) {
        for (int i=0; i<w; i++) {
            if (s[j][i] != '#') {
                left[j][i]++;
                if (i>0) left[j][i] += left[j][i-1];
            }
            if (s[j][w-i-1] != '#') {
                right[j][w-i-1]++;
                if (i>0) right[j][w-i-1] += right[j][w-i];
            }
        }
    }

//    debug(up);
//    debug(down);
//    debug(right);
//    debug(left);


    mint ans = mint(2).pow(k) * k;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (s[i][j] == '#') continue;
            int t = up[i][j] + down[i][j] + right[i][j] + left[i][j] - 3;
            ans -= mint(2).pow(k-t);
        }
    }
    cout << ans << endl;
}
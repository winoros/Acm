#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 1010

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int64 ll;
typedef unsigned __int64 ull;

#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 1010

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int64 ll;
typedef unsigned __int64 ull;

ll exgcd(ll a, ll b, ll &x, ll &y);

int main() {
    ll a, b, x1, x2, y1, y2, c;
    scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d", &a, &b, &c, &x1, &x2, &y1, &y2);
    c = -c;
    if(a == 0 && b == 0) {
        if(c == 0) printf("%I64d\n", (x2-x1+1) * (y2-y1+1));
        else puts("0");
        exit(0);
    }
    if(a == 0) {
        if(c%b == 0 && y1 <= c/b && y2 >= c/b) printf("%I64d\n", x2 - x1 + 1);
        else puts("0");
        exit(0);
    }
    if(b == 0) {
        if(c%a == 0 && x1 <= c/a && x2 >= c/a) printf("%I64d\n", y2 - y1 + 1);
        else puts("0");
        exit(0);
    }
    ll tx = 0, ty = 0, d = exgcd(a, b, tx, ty);
    if(c%d) { puts("0"); exit(0); }
    tx = tx * (c/d), ty = ty * (c/d);
    ll i_lx = (x1 <= tx || (x1-tx) * d % b == 0 ? (x1-tx) * d / b : (x1-tx) * d / b + 1),
        i_rx = (x2 >= tx || (x2-tx) * d % b == 0 ? (x2-tx) * d / b : (x2-tx) * d / b - 1),
        i_ly = (y1 <= ty || (y1-ty) * d % a == 0 ? (ty-y1) * d / a : (ty-y1) * d / a - 1),
        i_ry = (y2 >= ty || (y2-ty) * d % a == 0 ? (ty-y2) * d / a : (ty-y2) * d / a + 1);
    if(i_lx > i_rx) swap(i_lx, i_rx);
    if(i_ly > i_ry) swap(i_ly, i_ry);
    ll ansl = max(i_lx, i_ly), ansr = min(i_rx, i_ry);
    if(ansl <= ansr) printf("%I64d\n", ansr - ansl + 1);
    else puts("0");
    return 0;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        ll r = exgcd(b, a%b, y, x);
        y -= x*(a/b);
        return r;
    }
}


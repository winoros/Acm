/*
 * =====================================================================================
 *
 *       Filename:  24D.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014/11/28 21:27:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

using namespace std;

void solve(int n, double a[], double b[], double c[], double d[]) {
    for(int i=1; i<n; i++) {
        double m = a[i]/b[i - 1];
        b[i] -= m*c[i-1];
        d[i] -= m*d[i-1];
    }
    d[n-1] /= b[n-1];
    for(int i=n-2; i>=0; i--)
        d[i] = (d[i]-c[i]*d[i+1])/b[i];
}

double a[1010], b[1010], c[1010], d[1010];

int main() {
    int n, m, x, y;
    ios::sync_with_stdio(0);

    cin>>n>>m>>x>>y;
    fill(d, d+m, 0);
    for(int i=n-1; i>=x; i--) {
        fill(a, a+m, -1);
        fill(b, b+m, 3);
        fill(c, c+m, -1);
        a[0] = c[m-1] = 0;
        b[0] -= 1;  b[m-1] -= 1;
        for(int j=0; j<m; j++)
            d[j] += b[j]+1;
        solve(m, a, b, c, d);
    }
    printf("%.10lf\n", d[y-1]);

    return 0;
}

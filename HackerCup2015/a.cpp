/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/8 15:20:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

int cnt[10000010];
bool not_prime[10000010];

void init() {
    for(int i = 2; i <= 10000000; ++i)
        if(!not_prime[i]) {
            for(int j = i; j <= 10000000; j+=i)
                not_prime[j] = true, ++cnt[j];
        }
}

void MAIN() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int ans = 0;
    for(int i = n; i <= m; ++i)
        if(cnt[i] == k)
            ++ans;
    printf("%d\n", ans);
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        printf("Case #%d: ", i);
        MAIN();
    }
    return 0;
}

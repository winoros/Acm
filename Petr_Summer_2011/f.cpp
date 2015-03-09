/*
 * =====================================================================================
 *
 *       Filename:  f.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/26 14:14:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

void MAIN() {
	int n, m;
	std::cin >> n >> m;
	std::cout << (n%m == 0 ? 1 : 3) << std::endl;
	if(n >= m)
		for(int i = n-m; i >= 0; --i)
			std::cout << ((n-i)%m == 0 ? 1 : 0);
	else
		std::cout << 0;
	std::cout << " ";
	n %= m;
	if(n > 0) {
		for(int i = m-n; i > 0; --i)
			std::cout << 9;
		std::cout << " 1 ";
		for(int i = 0; i < n; ++i)
			std::cout << 9;
	} else
		for(int i = 0; i < m; ++i)
			std::cout << 9;
	std::cout << std::endl;
}

int main() {
	freopen("continued.in", "r", stdin);
	freopen("continued.out", "w", stdout);
	MAIN();
	return 0;
}

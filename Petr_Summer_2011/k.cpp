/*===============================================================
*   
*   FILE NAME:  k.cpp
*   AUTHOR:     winoros
*   SHOOL:      BUPT
*   DATE:       02/26/2015 12:38:24
*   EMAIL:      winoros@gmail.com
*   Description:  
*
*
================================================================*/
#include <bits/stdc++.h>

int p;

struct matrix {
	int m[3][3];
	matrix() {
		memset(m, 0, sizeof m);
	}
	void set() {
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j)
				m[i][j] = i == j;
	}
	matrix operator * (matrix rhs) {
		matrix ans;
		for(int i = 0; i < 3; ++i)
			for(int j = 0; j < 3; ++j) {
				long long tmp = 0;
				for(int k = 0; k < 3; ++k)
					tmp += (long long)m[i][k]*rhs.m[k][j];
				ans.m[i][j] = tmp %p;
			}
		return ans;
	}
};

matrix fast_pow(matrix base, long long exp) {
	matrix ret;
	ret.set();
	while(exp) {
		if(exp&1)
			ret = ret * base;
		base = base * base;
		exp >>= 1;
	}
	return ret;
}

void MAIN() {
	long long k;
	std::cin >> k >> p;
	if(k == 1)
		puts("1");
	else {
		matrix tmp;
		tmp.m[0][0] = tmp.m[1][1] = tmp.m[2][0] = 10;
		tmp.m[0][1] = tmp.m[2][1] = 9;
		tmp.m[2][2] = 1;
		tmp = fast_pow(tmp, k-2);
		std::cout << (9LL*tmp.m[2][0] + 10LL*tmp.m[2][1] + 10LL*tmp.m[2][2] + k-1) %p << std::endl;
	}
}

int main() {
	freopen("zeroes.in", "r", stdin);
	freopen("zeroes.out", "w", stdout);
	MAIN();
	return 0;
}

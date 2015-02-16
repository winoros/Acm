/*
 * =====================================================================================
 *
 *       Filename:  514.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/2/15 15:34:44
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

struct Trie {
	int ch[600010][3], tot, root;
	bool flag[600010];
	void init() {
		tot = root = 1;
		flag[0] = flag[1] = false;
		memset(ch[1], 0, sizeof ch[1]);
	}
	void insert(char *s) {
		int *now = &root;
		for(char *p = s; *p; ++p) {
			now = &ch[*now][*p-'a'];
			if(*now == 0) {
				*now = ++tot;
				memset(ch[tot], 0, sizeof ch[tot]);
				flag[tot] = false;
			}
		}
		flag[*now] = true;
	}
	bool _query(char *s, int pos, bool err) {
		if(*s == 0 || pos == 0)
			return flag[pos] && err;
		else {
			bool ret = _query(s+1, ch[pos][*s-'a'], err);
			if(!err)
				for(int i = 0; i < 3; ++i)
					if(*s != 'a'+i)
						ret |= _query(s+1, ch[pos][i], true);
			return ret;
		}
	}
	bool query(char *s) {
		return _query(s, root, false);
	}
};

Trie t;
char str[600010];

void MAIN() {
	t.init();
	int n, m;
	scanf("%d%d", &n, &m);
	while(n--) {
		scanf("%s", str);
		t.insert(str);
	}
	while(m--) {
		scanf("%s", str);
		puts(t.query(str) ? "YES" : "NO");
	}
}

int main() {
	MAIN();
	return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  100624c.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2015/3/7 13:47:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  winoros (Ding), winoros@gmail.com
 *   Organization:  BUPT
 *
 * =====================================================================================
 */
#include <bits/stdc++.h>

std::string e[114] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};

bool reach[50010];

void MAIN() {
	std::string str;
	std::cin >> str;
	reach[0] = true;
	int len = str.length();
	for(int i = 1; i <= len; ++i) {
		reach[i] = false;
		for(int j = 0; j < 114; ++j) {
			int lenn = e[j].length();
			if(i >= lenn && reach[i-lenn] && str.substr(i-lenn, lenn) == e[j])
				reach[i] = true;
		}
	}
	std::cout << (reach[len] == true ? "YES" : "NO") << std::endl;
}

int main() {
	for(int i = 0; i < 114; ++i)
		transform(e[i].begin(), e[i].end(), e[i].begin(), ::tolower);
	int n;
	std::cin >> n;
	while(n--)
		MAIN();
	return 0;
}

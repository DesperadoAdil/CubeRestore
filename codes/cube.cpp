#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;
#include "cube.h"
cube A;
int F[7][4][4], Sum;
string Command[13];
struct dicar {
	int ii, jj, kk;
}temp_dicar, temp1, temp2;
struct Clockwise_rotation {
	int J, K;
}Cwr[4][4];
struct Counterclockwise_rotation {
	int J, K;
}Ccwr[4][4];
struct node {
	int x, y, z, next;
}data[50];
void add (int x1, int y1, int z1, int x2, int y2, int z2) {
	data[++Sum].x = x2;
	data[Sum].y = y2;
	data[Sum].z = z2;
	data[Sum].next = F[x1][y1][z1];
	F[x1][y1][z1] = Sum;
}
void initialization () {
	Command[1] = "R";Command[2] = "Ri";
	Command[3] = "L";Command[4] = "Li";
	Command[5] = "B";Command[6] = "Bi";
	Command[7] = "D";Command[8] = "Di";
	Command[9] = "F";Command[10] = "Fi";
	Command[11] = "U";Command[12] = "Ui";
	Cwr[1][1].J = 1;Cwr[1][1].K = 3;
	Cwr[1][3].J = 3;Cwr[1][3].K = 3;
	Cwr[3][3].J = 3;Cwr[3][3].K = 1;
	Cwr[3][1].J = 1;Cwr[3][1].K = 1;
	Cwr[1][2].J = 2;Cwr[1][2].K = 3;
	Cwr[2][3].J = 3;Cwr[2][3].K = 2;
	Cwr[3][2].J = 2;Cwr[3][2].K = 1;
	Cwr[2][1].J = 1;Cwr[2][1].K = 2;
	Ccwr[1][1].J = 3;Ccwr[1][1].K = 1;
	Ccwr[3][1].J = 3;Ccwr[3][1].K = 3;
	Ccwr[3][3].J = 1;Ccwr[3][3].K = 3;
	Ccwr[1][3].J = 1;Ccwr[1][3].K = 1;
	Ccwr[1][2].J = 2;Ccwr[1][2].K = 1;
	Ccwr[2][1].J = 3;Ccwr[2][1].K = 2;
	Ccwr[3][2].J = 2;Ccwr[3][2].K = 3;
	Ccwr[2][3].J = 1;Ccwr[2][3].K = 2;
	add(1,1,1,5,3,1);add(1,1,1,4,1,3);
	add(1,1,3,5,3,3);add(1,1,3,3,1,1);
	add(1,3,1,6,1,1);add(1,3,1,4,3,3);
	add(1,3,3,6,1,3);add(1,3,3,3,3,1);
	add(2,1,1,5,1,3);add(2,1,1,3,1,3);
	add(2,1,3,5,1,1);add(2,1,3,4,1,1);
	add(2,3,1,6,3,3);add(2,3,1,3,3,3);
	add(2,3,3,6,3,1);add(2,3,3,4,3,1);
	add(3,1,1,5,3,3);add(3,1,1,1,1,3);
	add(3,1,3,5,1,3);add(3,1,3,2,1,1);
	add(3,3,1,6,1,3);add(3,3,1,1,3,3);
	add(3,3,3,6,3,3);add(3,3,3,2,3,1);
	add(4,1,1,5,1,1);add(4,1,1,2,1,3);
	add(4,1,3,5,3,1);add(4,1,3,1,1,1);
	add(4,3,1,6,3,1);add(4,3,1,2,3,3);
	add(4,3,3,6,1,1);add(4,3,3,1,3,1);	
	add(5,3,1,1,1,1);add(5,3,1,4,1,3);
	add(5,3,3,1,1,3);add(5,3,3,3,1,1);
	add(5,1,1,2,1,3);add(5,1,1,4,1,1);
	add(5,1,3,2,1,1);add(5,1,3,3,1,3);
	add(6,1,1,1,3,1);add(6,1,1,4,3,3);
	add(6,1,3,1,3,3);add(6,1,3,3,3,1);
	add(6,3,1,2,3,3);add(6,3,1,4,3,1);
	add(6,3,3,2,3,1);add(6,3,3,3,3,3);
	add(1,1,2,5,3,2);
	add(1,2,1,4,2,3);
	add(1,2,3,3,2,1);
	add(1,3,2,6,1,2);
	add(2,1,2,5,1,2);
	add(2,2,1,3,2,3);
	add(2,2,3,4,2,1);
	add(2,3,2,6,3,2);
	add(3,1,2,5,2,3);
	add(3,2,1,1,2,3);
	add(3,2,3,2,2,1);
	add(3,3,2,6,2,3);
	add(4,1,2,5,2,1);
	add(4,2,1,2,2,3);
	add(4,2,3,1,2,1);
	add(4,3,2,6,2,1);
	add(5,1,2,2,1,2);
	add(5,2,1,4,1,2);
	add(5,2,3,3,1,2);
	add(5,3,2,1,1,2);
	add(6,1,2,1,3,2);
	add(6,2,1,4,3,2);
	add(6,2,3,3,3,2);
	add(6,3,2,2,3,2);
}
void get_ (dicar &x) {
	int j = F[x.ii][x.jj][x.kk];
	temp1.ii = data[j].x;
	temp1.jj = data[j].y;
	temp1.kk = data[j].z;
	if (data[j].next) {
		j = data[j].next;
		temp2.ii = data[j].x;
		temp2.jj = data[j].y;
		temp2.kk = data[j].z;
	}
}
void get_temp_dicar (int x1, int y1, int z1) {
	temp_dicar.ii = x1;
	temp_dicar.jj = y1;
	temp_dicar.kk = z1;
}
bool Is_cross () {
	for ( int j = 1, k = 2, t = 1; t <= 4; t++) {
		if (A.a[d][j][k] != A.a[d][2][2]) return false;
		temp = Cwr[j][k].J;
		k = Cwr[j][k].K;
		j = temp;
	}
	for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++)
		if (A.a[j][3][2] != A.a[j][2][2]) return false;
	return true;
}
int judge_down (int co) {
	for ( int j = 1, k = 2, t = 1; t <= 4; t++) {
		if (A.a[u][j][k] == co) {
			get_temp_dicar (u, j, k);
			return 0;
		}
		temp = Cwr[j][k].J;
		k = Cwr[j][k].K;
		j = temp;
	}
	for ( int i = f, t = 1; t <= 4; i = Cwr_edge[i], t++)
		for ( int j = 1, k = 2, t = 1; t <= 4; t++) {
			if (A.a[i][j][k] == co) {
				get_temp_dicar (i, j, k);
				return t;
			}
			temp = Cwr[j][k].J;
			k = Cwr[j][k].K;
			j = temp;
		}
	return -1;
}
void work_formula_down_case_1_Ccwr (dicar &x) {
	if (x.ii == f) A.F(),A.Ri(),A.Fi();
	if (x.ii == b) A.B(),A.Li(),A.Bi();
	if (x.ii == r) A.R(),A.Bi(),A.Ri();
	if (x.ii == l) A.L(),A.Fi(),A.Li();
}
void work_formula_down_case_1_Cwr (dicar &x) {
	if (x.ii == f) A.Fi(),A.L(),A.F();
	if (x.ii == b) A.Bi(),A.R(),A.B();
	if (x.ii == r) A.Ri(),A.F(),A.R();
	if (x.ii == l) A.Li(),A.B(),A.L();
}
void work_formula_down_case_2_Ccwr (dicar &x) {
	if (x.ii == f) A.Fi();
	if (x.ii == b) A.Bi();
	if (x.ii == r) A.Ri();
	if (x.ii == l) A.Li();
}
void work_formula_down_case_2_Cwr (dicar &x) {
	if (x.ii == f) A.F();
	if (x.ii == b) A.B();
	if (x.ii == r) A.R();
	if (x.ii == l) A.L();
}
bool Is_down () {
	for ( int j = 1; j <= 3; j++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[d][j][k] != A.a[d][2][2]) return false;
	for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[j][3][k] != A.a[j][2][2]) return false;
	return true;
}
int judge_d_corner (int co) {
	for ( int j = 1; j <= 3; j++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[u][j][k] == co) {
				get_temp_dicar (u, j, k);
				return 0;
			}
	for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[j][1][k] == co) {
				get_temp_dicar (j, 1, k);
				return 1;
			}
	return -1;
}
void work_formula_d_corner_from_ceiling (dicar &x) {
	if (x.jj == 3 && x.kk == 3) A.R(),A.U(),A.U(),A.Ri(),A.Ui(),A.R(),A.U(),A.Ri();
	if (x.jj == 3 && x.kk == 1) A.F(),A.U(),A.U(),A.Fi(),A.Ui(),A.F(),A.U(),A.Fi();
	if (x.jj == 1 && x.kk == 3) A.B(),A.U(),A.U(),A.Bi(),A.Ui(),A.B(),A.U(),A.Bi();
	if (x.jj == 1 && x.kk == 1) A.L(),A.U(),A.U(),A.Li(),A.Ui(),A.L(),A.U(),A.Li();
	return;
}
void work_formula_d_corner_from_edge (dicar &x) {
	if (x.ii == f && x.jj == 1 && x.kk == 1) A.F(),A.U(),A.Fi();
	if (x.ii == f && x.jj == 1 && x.kk == 3) A.Fi(),A.Ui(),A.F();
	if (x.ii == b && x.jj == 1 && x.kk == 1) A.B(),A.U(),A.Bi();
	if (x.ii == b && x.jj == 1 && x.kk == 3) A.Bi(),A.Ui(),A.B();
	if (x.ii == r && x.jj == 1 && x.kk == 1) A.R(),A.U(),A.Ri();
	if (x.ii == r && x.jj == 1 && x.kk == 3) A.Ri(),A.Ui(),A.R();
	if (x.ii == l && x.jj == 1 && x.kk == 1) A.L(),A.U(),A.Li();
	if (x.ii == l && x.jj == 1 && x.kk == 3) A.Li(),A.Ui(),A.L();
	return;
}
bool Is_mid () {
	for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[j][2][k] != A.a[j][2][2]) return false;
	return true;
}
int judge_mid (int co) {
	for ( int j = 1; j <= 3; j++)
		for ( int k = 1; k <= 3; k++) {
			if ((j*k)%2) continue;
			get_temp_dicar (u, j, k);
			get_ (temp_dicar);
			int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
			if (A.a[u][j][k] != co && color1 != co) return 0;
		}
	return -1;
}
void work_formula1_mid (dicar &x) {
	if (x.ii == f) A.U(),A.R(),A.Ui(),A.Ri(),A.Ui(),A.Fi(),A.U(),A.F();
	if (x.ii == b) A.U(),A.L(),A.Ui(),A.Li(),A.Ui(),A.Bi(),A.U(),A.B();
	if (x.ii == r) A.U(),A.B(),A.Ui(),A.Bi(),A.Ui(),A.Ri(),A.U(),A.R();
	if (x.ii == l) A.U(),A.F(),A.Ui(),A.Fi(),A.Ui(),A.Li(),A.U(),A.L();
	return;
}
void work_formula2_mid (dicar &x) {
	if (x.ii == f) A.Ui(),A.Li(),A.U(),A.L(),A.U(),A.F(),A.Ui(),A.Fi();
	if (x.ii == b) A.Ui(),A.Ri(),A.U(),A.R(),A.U(),A.B(),A.Ui(),A.Bi();
	if (x.ii == r) A.Ui(),A.Fi(),A.U(),A.F(),A.U(),A.R(),A.Ui(),A.Ri();
	if (x.ii == l) A.Ui(),A.Bi(),A.U(),A.B(),A.U(),A.L(),A.Ui(),A.Li();
	return;
}
bool Is_up () {
	for ( int j = 1, k = 2, t = 1; t <= 4; t++) {
		if (A.a[u][j][k] != A.a[u][2][2]) return false;
		temp = Cwr[j][k].J;
		k = Cwr[j][k].K;
		j = temp;
	}
	return true;
}
void work_formula_up () {
	A.F();A.R();A.U();A.Ri();A.Ui();A.Fi();
	return;
}
bool Is_ceiling () {
	for ( int j = 1; j <= 3; j++)
		for ( int k = 1; k <= 3; k++)
			if (A.a[u][j][k] != A.a[u][2][2]) return false;
	return true;
}
void work_formula_ceiling () {
	A.R();A.U();A.Ri();A.U();A.R();A.U();A.U();A.Ri();
	return;
}
bool Is_top_corner (int x) {
	if (x == 1) {
		for ( int t = 1; t <= 4; t++)
			if (A.a[t][1][1] != A.a[t][1][3]) return false;
		return true;
	}
	else {
		for ( int t = 1; t <= 4; t++)
			if (A.a[t][1][1] != A.a[t][2][2] || A.a[t][1][3] != A.a[t][2][2]) return false;
		return true;
	}
}
void work_formula_top_corner () {
	A.R();A.Bi();A.R();A.F();A.F();A.Ri();A.B();A.R();A.F();A.F();A.R();A.R();
	return;
}
void work_formula_top (int x) {
	if (x == 1) A.L(),A.Ui(),A.L(),A.U(),A.L(),A.U(),A.L(),A.Ui(),A.Li(),A.Ui(),A.L(),A.L();
	if (x == 2) A.R(),A.Ui(),A.R(),A.U(),A.R(),A.U(),A.R(),A.Ui(),A.Ri(),A.Ui(),A.R(),A.R();
	if (x == 3) A.F(),A.Ui(),A.F(),A.U(),A.F(),A.U(),A.F(),A.Ui(),A.Fi(),A.Ui(),A.F(),A.F();
	if (x == 4) A.B(),A.Ui(),A.B(),A.U(),A.B(),A.U(),A.B(),A.Ui(),A.Bi(),A.Ui(),A.B(),A.B();
}
void work () {
	initialization ();
	while (!Is_cross ()) {
		switch (judge_down(A.a[d][2][2])) {
			case 0 : {
				do {
					get_ (temp_dicar);
					int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
					if (color1 == A.a[temp1.ii][2][2]) {
						work_formula_down_case_2_Cwr (temp1);
						work_formula_down_case_2_Cwr (temp1);
						break;
					}
					temp = Cwr[temp_dicar.jj][temp_dicar.kk].J;
					temp_dicar.kk = Cwr[temp_dicar.jj][temp_dicar.kk].K;
					temp_dicar.jj = temp;
					A.U();
				}while (true);
				break;
			}
			case 1 : {
				do {
					get_ (temp_dicar);
					int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
					if (color1 == A.a[Ccwr_edge[temp_dicar.ii]][2][2]) {
						work_formula_down_case_1_Ccwr (temp_dicar);
						break;
					}
					if (color1 == A.a[Cwr_edge[temp_dicar.ii]][2][2]) {
						work_formula_down_case_1_Cwr (temp_dicar);
						break;
					}
					temp_dicar.ii = Cwr_edge[temp_dicar.ii];
					A.U();
				}while (true);
				break;
			}
			case 2 : {
				get_ (temp_dicar);
				int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
				if (color1 == A.a[temp1.ii][2][2]) work_formula_down_case_2_Ccwr (temp1);
				else work_formula_down_case_2_Cwr (temp1);
				break;
			}
			case 3 : {
				work_formula_down_case_2_Ccwr (temp_dicar);
				break;
			}
			case 4 : {
				get_ (temp_dicar);
				int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
				if (color1 == A.a[temp1.ii][2][2]) work_formula_down_case_2_Cwr (temp1);
				else work_formula_down_case_2_Ccwr (temp1);
				break;
			}
			case -1 : {
				for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++) {
					if (A.a[j][3][2] != A.a[j][2][2]) {
						temp_dicar.ii = j;
						work_formula_down_case_2_Ccwr (temp_dicar);
						break;
					}
				}
				break;
			}
		}
	}
	while (!Is_down ()) {
		switch (judge_d_corner (A.a[d][2][2])) {
			case 0 : {
				do {
					get_ (temp_dicar);
					int color1 = A.a[temp1.ii][temp1.jj][temp1.kk], color2 = A.a[temp2.ii][temp2.jj][temp2.kk];
					if (color1 == A.a[temp2.ii][2][2] && color2 == A.a[temp1.ii][2][2]) {
						work_formula_d_corner_from_ceiling (temp_dicar);
						break;
					}
					temp = Cwr[temp_dicar.jj][temp_dicar.kk].J;
					temp_dicar.kk = Cwr[temp_dicar.jj][temp_dicar.kk].K;
					temp_dicar.jj = temp;
					A.U();
				}while (true);
				break;
			}
			case 1 : {
				do {
					get_ (temp_dicar);
					int color1 = A.a[temp1.ii][temp1.jj][temp1.kk], color2 = A.a[temp2.ii][temp2.jj][temp2.kk];
					if (color1 == A.a[temp_dicar.ii][2][2] && color2 == A.a[temp2.ii][2][2] ||
						color1 == A.a[temp1.ii][2][2] && color2 == A.a[temp_dicar.ii][2][2]) {
						work_formula_d_corner_from_edge (temp_dicar);
						break;
					}
					temp_dicar.ii = Cwr_edge[temp_dicar.ii];
					A.U();
				}while (true);
				break;
			}
			case -1 : {
				for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++) {
					if (A.a[j][3][3] != A.a[j][2][2]) {
						get_temp_dicar (j, 1, 3);
						work_formula_d_corner_from_edge (temp_dicar);
						break;
					}
					if (A.a[j][3][1] != A.a[j][2][2]) {
						get_temp_dicar (j, 1, 1);
						work_formula_d_corner_from_edge (temp_dicar);
						break;
					}
				}
				break;
			}
		}
	}
	while (!Is_mid ()) {
		switch (judge_mid (A.a[u][2][2])) {
			case 0 : {
				do {
					get_ (temp_dicar);
					int color1 = A.a[temp1.ii][temp1.jj][temp1.kk];
					int tempcolor = A.a[temp_dicar.ii][temp_dicar.jj][temp_dicar.kk];
					if (color1 == A.a[temp1.ii][2][2] && tempcolor == A.a[Ccwr_edge[temp1.ii]][2][2]) {
						work_formula1_mid (temp1);
						break;
					}
					if (color1 == A.a[temp1.ii][2][2] && tempcolor == A.a[Cwr_edge[temp1.ii]][2][2]) {
						work_formula2_mid (temp1);
						break;
					}
					temp = Cwr[temp_dicar.jj][temp_dicar.kk].J;
					temp_dicar.kk = Cwr[temp_dicar.jj][temp_dicar.kk].K;
					temp_dicar.jj = temp;
					A.U();
				}while (true);
				break;
			}
			case -1 : {
				for ( int j = f, t = 1; t <= 4; j = Cwr_edge[j], t++) {
					if (A.a[j][2][3] != A.a[j][2][2]) {
						get_temp_dicar (j, 2, 3);
						get_ (temp_dicar);
						work_formula1_mid (temp_dicar);
						break;
					}
					if (A.a[j][2][1] != A.a[j][2][2]) {
						get_temp_dicar (j, 2, 1);
						get_ (temp_dicar);
						work_formula2_mid (temp_dicar);
						break;
					}
				}
				break;
			}
		}
	}
	while (!Is_up ()) {
		int co = A.a[u][2][2];
		do {
			if (A.a[u][1][2] != co && A.a[u][2][1] != co && A.a[u][2][3] != co && A.a[u][3][2] != co)
				work_formula_up ();
			if (A.a[u][1][2] == co && A.a[u][2][1] == co && A.a[u][2][3] != co && A.a[u][3][2] != co) {
				work_formula_up ();
				work_formula_up ();
				break;
			}
			if (A.a[u][1][2] != co && A.a[u][2][1] == co && A.a[u][2][3] == co && A.a[u][3][2] != co) {
				work_formula_up ();
				break;
			}
			A.U();
		}while (true);
	}
	while (!Is_ceiling ()) {
		int co = A.a[u][2][2];
		do {
			if (A.a[u][1][1] != co && A.a[u][1][3] != co &&
				A.a[u][3][1] != co && A.a[u][3][3] != co && A.a[l][1][3] == co) {
				work_formula_ceiling ();
				break;
			}
			if (A.a[u][1][1] != co && A.a[u][1][3] != co &&
				A.a[u][3][1] == co && A.a[u][3][3] != co) {
				work_formula_ceiling ();
				break;
			}
			int sum = 0;
			for ( int j = 1, k = 1, t = 1; t <= 4; t++) {
				if (A.a[u][j][k] == co) sum++;
				temp = Cwr[j][k].J;
				k = Cwr[j][k].K;
				j = temp;
			}
			if (sum == 2 && A.a[f][1][1] == co) {
				work_formula_ceiling ();
				break;
			}
			A.U();
		}while (true);
	}
	while (!Is_top_corner (1)) {
		if (A.a[f][1][1] != A.a[f][1][3] &&
			A.a[b][1][1] != A.a[b][1][3] &&
			A.a[r][1][1] != A.a[r][1][3] &&
			A.a[l][1][1] != A.a[l][1][3]) {
			work_formula_top_corner ();
		}
		do {
			if (A.a[f][1][1] == A.a[f][1][3]) {
				work_formula_top_corner ();
				break;
			}
			A.U();
		}while (true);
	}
	while (!Is_top_corner (2)) A.U();
	while (!A.Is_recover ()) {
		if (A.a[f][1][2] != A.a[f][2][2] &&
			A.a[b][1][2] != A.a[b][2][2] &&
			A.a[r][1][2] != A.a[r][2][2] &&
			A.a[l][1][2] != A.a[l][2][2]) {
			work_formula_top (1);
		}
		for ( int j = 1; j <= 4; j++)
			if (A.a[j][1][2] == A.a[j][2][2]) {
				work_formula_top (j);
				break;
			}
	}
	return;
}
void ans_work () {
	int len = A.ans.size ();
	for ( int i = 0; i < len; i++) {
		if (A.ans[i] == "0") continue;
		if (i+3 < len && A.ans[i] == A.ans[i+1] && A.ans[i] == A.ans[i+2] && A.ans[i] == A.ans[i+3]) {
			A.ans[i+3] = A.ans[i+2] = A.ans[i+1] = A.ans[i] = "0";
			continue;
		}
		for ( int j = 1; j <= 12; j++)
			if (A.ans[i] == Command[j]) {
				if (i+2 < len && A.ans[i] == A.ans[i+1] && A.ans[i] == A.ans[i+2]) {
					A.ans[i] = j % 2 ? Command[j+1] : Command[j-1];
					A.ans[i+1] = A.ans[i+2] = "0";
					break;
				}
				if ((i+1 < len && j <= 11 && A.ans[i+1] == Command[j+1] && j%2) || (i+1 < len && A.ans[i+1] == Command[j-1] && !(j%2))) {
					A.ans[i] = A.ans[i+1] = "0";
					break;
				}
			}	
	}
	for ( int i = 0; i < A.ans.size (); i++)
		if (A.ans[i] != "0") cout << A.ans[i] << " ";
}
int main () {
	freopen ("cube.in", "r", stdin);
	freopen ("cube.out", "w", stdout);
	A.scan ();
	work ();
	ans_work ();
	fclose (stdin);
	fclose (stdout);
	return 0;
}

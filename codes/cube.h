#ifndef CUBE_H
#define CUBE_H
const char Colors_[7] = {'0', 'R', 'G', 'B', 'O', 'W', 'Y'};
const char Colors[7][10] = {"0", "red", "green", "blue", "oringe", "white", "yellow"};
const int d = 6, u = 5, r = 3, l = 4, f = 1, b = 2;
const int Cwr_edge[5] = {0, 4, 3, 1, 2}, Ccwr_edge[5] = {0, 3, 4, 2, 1};
int temp;
struct dicar;
struct Clockwise_rotation;
struct Counterclockwise_rotation;
void add (int x1, int y1, int z1, int x2, int y2, int z2);
void initialization ();
void get_ (dicar &x);
void get_temp_dicar (int x1, int y1, int z1);
bool Is_cross ();
int judge_down (int co);
void work_formula_down_case_1_Ccwr (dicar &x);
void work_formula_down_case_1_Cwr (dicar &x);
void work_formula_down_case_2_Ccwr (dicar &x);
void work_formula_down_case_2_Cwr (dicar &x);
bool Is_down ();
int judge_d_corner (int co);
void work_formula_d_corner_from_ceiling (dicar &x);
void work_formula_d_corner_from_edge (dicar &x);
bool Is_mid ();
int judge_mid (int co);
void work_formula1_mid (dicar &x);
void work_formula2_mid (dicar &x);
bool Is_up ();
void work_formula_up ();
bool Is_ceiling ();
void work_formula_ceiling ();
bool Is_top_corner (int x);
void work_formula_top_corner ();
void work_formula_top (int x);
void work ();
class cube {
public:
	int a[7][4][4];
	vector <string> ans;
	cube() {
		for ( int i = 1; i <= 6; i++)
			for ( int j = 1; j <= 3; j++)
				for ( int k = 1; k <= 3; k++)
					a[i][j][k] = 0;
	}
	inline void scan() {
		for ( int i = 1; i <= 6; i++) {
			char c[10];
			memset(c, 0, sizeof(c));
			cin >> c;
			for ( int j = 0; j < 9; j++) {
				if (c[j] == 'R') a[i][j/3+1][j%3+1] = 1;
				else if (c[j] == 'G') a[i][j/3+1][j%3+1] = 2;
				else if (c[j] == 'B') a[i][j/3+1][j%3+1] = 3;
				else if (c[j] == 'O') a[i][j/3+1][j%3+1] = 4;
				else if (c[j] == 'W') a[i][j/3+1][j%3+1] = 5;
				else if (c[j] == 'Y') a[i][j/3+1][j%3+1] = 6;
			}
		}
	}
	inline void print() {
		for ( int i = 1; i <= 6; i++) {
			cout << Colors[a[i][2][2]] << endl;
			for ( int j = 1; j <= 3; j++) {
				for ( int k = 1; k <= 3; k++)
					cout << a[i][j][k] << " ";
				cout << endl;
			}
		}
	}
	inline void clockwise_rotation (const int& xx) {
		temp = a[xx][1][1];
		a[xx][1][1] = a[xx][3][1];
		a[xx][3][1] = a[xx][3][3];
		a[xx][3][3] = a[xx][1][3];
		a[xx][1][3] = temp;
		temp = a[xx][1][2];
		a[xx][1][2] = a[xx][2][1];
		a[xx][2][1] = a[xx][3][2];
		a[xx][3][2] = a[xx][2][3];
		a[xx][2][3] = temp;
	}
	inline void counterclockwise_rotation (const int &yy) {
		temp = a[yy][1][1];
		a[yy][1][1] = a[yy][1][3];
		a[yy][1][3] = a[yy][3][3];
		a[yy][3][3] = a[yy][3][1];
		a[yy][3][1] = temp;
		temp = a[yy][1][2];
		a[yy][1][2] = a[yy][2][3];
		a[yy][2][3] = a[yy][3][2];
		a[yy][3][2] = a[yy][2][1];
		a[yy][2][1] = temp;
	}
	inline void R () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][i][3];
			a[d][i][3] = a[b][4-i][1];
			a[b][4-i][1] = a[u][i][3];
			a[u][i][3] = a[f][i][3];
			a[f][i][3] = temp;
		}
		clockwise_rotation (r);
		ans.push_back ("R");
	}
	inline void Ri () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][i][3];
			a[d][i][3] = a[f][i][3];
			a[f][i][3] = a[u][i][3];
			a[u][i][3] = a[b][4-i][1];
			a[b][4-i][1] = temp;
		}
		counterclockwise_rotation (r);
		ans.push_back ("Ri");
	}
	inline void L () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][i][1];
			a[d][i][1] = a[f][i][1];
			a[f][i][1] = a[u][i][1];
			a[u][i][1] = a[b][4-i][3];
			a[b][4-i][3] = temp;
		}
		clockwise_rotation (l);
		ans.push_back ("L");
	}
	inline void Li () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][i][1];
			a[d][i][1] = a[b][4-i][3];
			a[b][4-i][3] = a[u][i][1];
			a[u][i][1] = a[f][i][1];
			a[f][i][1] = temp;
		}
		counterclockwise_rotation (l);
		ans.push_back ("Li");
	}
	inline void B () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][3][i];
			a[d][3][i] = a[l][i][1];
			a[l][i][1] = a[u][1][4-i];
			a[u][1][4-i] = a[r][4-i][3];
			a[r][4-i][3] = temp;
		}
		clockwise_rotation (b);
		ans.push_back ("B");
	}
	inline void Bi () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][3][i];
			a[d][3][i] = a[r][4-i][3];
			a[r][4-i][3] = a[u][1][4-i];
			a[u][1][4-i] = a[l][i][1];
			a[l][i][1] = temp;
		}
		counterclockwise_rotation (b);
		ans.push_back ("Bi");
	}
	inline void D () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[f][3][i];
			a[f][3][i] = a[l][3][i];
			a[l][3][i] = a[b][3][i];
			a[b][3][i] = a[r][3][i];
			a[r][3][i] = temp;
		}
		clockwise_rotation (d);
		ans.push_back ("D");
	}
	inline void Di () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[f][3][i];
			a[f][3][i] = a[r][3][i];
			a[r][3][i] = a[b][3][i];
			a[b][3][i] = a[l][3][i];
			a[l][3][i] = temp;
		}
		counterclockwise_rotation (d);
		ans.push_back ("Di");
	}
	inline void F () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][1][i];
			a[d][1][i] = a[r][4-i][1];
			a[r][4-i][1] = a[u][3][4-i];
			a[u][3][4-i] = a[l][i][3];
			a[l][i][3] = temp;
		}
		clockwise_rotation (f);
		ans.push_back ("F");
	}
	inline void Fi () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[d][1][i];
			a[d][1][i] = a[l][i][3];
			a[l][i][3] = a[u][3][4-i];
			a[u][3][4-i] = a[r][4-i][1];
			a[r][4-i][1] = temp;
		}
		counterclockwise_rotation (f);
		ans.push_back ("Fi");
	}
	inline void U () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[f][1][i];
			a[f][1][i] = a[r][1][i];
			a[r][1][i] = a[b][1][i];
			a[b][1][i] = a[l][1][i];
			a[l][1][i] = temp;
		}
		clockwise_rotation (u);
		ans.push_back ("U");
	}
	inline void Ui () {
		for ( int i = 1; i <= 3; i++) {
			temp = a[f][1][i];
			a[f][1][i] = a[l][1][i];
			a[l][1][i] = a[b][1][i];
			a[b][1][i] = a[r][1][i];
			a[r][1][i] = temp;
		}
		counterclockwise_rotation (u);
		ans.push_back ("Ui");
	}
	inline bool Is_recover () {
		for ( int i = 1; i <= 6; i++)
			for ( int j = 1; j <= 3; j++)
				for ( int k = 1; k <= 3; k++)
					if (a[i][j][k] != a[i][2][2]) return false;
		return true;
	}
};
#endif

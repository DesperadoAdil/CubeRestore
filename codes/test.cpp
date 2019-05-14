#include <cstdio>
#include <ctime>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
#include "cube.h"
cube A;
char Command[13][4] = {"0", "R", "Ri", "L", "Li", "B", "Bi", "D", "Di", "F", "Fi", "U", "Ui"};
char CC[3];
int N, sum_step, max_step, ave_step;
int main () {
	FILE *p, *q;
	srand (time(NULL));
	printf ("Input test time:\n");
	scanf ("%d", &N);
	for ( int o = 1; o <= N; o++) {
		sum_step = 0;
		for ( int j = 1; j <= 3; j++)
			for ( int k = 1; k <= 3; k++) {
				A.a[1][j][k] = 1;
				A.a[2][j][k] = 4;
				A.a[3][j][k] = 2;
				A.a[4][j][k] = 3;
				A.a[5][j][k] = 6;
				A.a[6][j][k] = 5;
			}
		printf ("\nCube Restore Test %d:\n\nDisarrange Operation: ", o);

		for ( int i = 1; i <= 100; i++) {
			int rand_num = rand () % 12;
			if (rand_num == 0) continue;
			switch (rand_num) {
				case 1 : A.R();break;
				case 2 : A.Ri();break;
				case 3 : A.L();break;
				case 4 : A.Li();break;
				case 5 : A.B();break;
				case 6 : A.Bi();break;
				case 7 : A.D();break;
				case 8 : A.Di();break;
				case 9 : A.F();break;
				case 10 : A.Fi();break;
				case 11 : A.U();break;
				case 12 : A.Ui();break;
			}
			printf ("%s ", Command[rand_num]);
		}
		printf ("\n\nJumbled Cube: \n");
		p = fopen ("cube.in", "w");
		for ( int i = 1; i <= 6; i++) {
			for ( int j = 1; j <= 3; j++)
				for ( int k = 1; k <= 3; k++)
					fprintf (p, "%c", Colors_[A.a[i][j][k]]),
					printf ("%c", Colors_[A.a[i][j][k]]);
			fprintf (p, "\n");
			printf ("\n");
		}
		printf ("\nRestore Operation: ");
		fclose (p);
		system ("cube.exe");
		q = fopen ("cube.out", "r");
		while (fscanf (q, "%s", CC) != EOF) {
			int i = 1;
			for ( ; i <= 12; i++)
				if (!strcmp(CC, Command[i])) break;
			switch (i) {
				case 1 : A.R();break;
				case 2 : A.Ri();break;
				case 3 : A.L();break;
				case 4 : A.Li();break;
				case 5 : A.B();break;
				case 6 : A.Bi();break;
				case 7 : A.D();break;
				case 8 : A.Di();break;
				case 9 : A.F();break;
				case 10 : A.Fi();break;
				case 11 : A.U();break;
				case 12 : A.Ui();break;
			}
			printf ("%s ", Command[i]);
			sum_step++;
		}
		fclose (q);
		if (sum_step > max_step) max_step = sum_step;
		ave_step += sum_step;
		if (A.Is_recover()) printf ("\n\nCube Restore Test %d Success!\n\n", o);
		else {
			printf ("\n\nCube Restore Test %d Failed!\n\n", o);
			system ("pause");
		}
		for ( int i = 1; i <= 30; i++) printf ("-");
		printf ("DIVIDER");
		for ( int i = 1; i <= 30; i++) printf ("-");
		printf ("\n\n\n");
	}
	printf ("Run %d Test All Together!\nLongest restore sequence: %d\nShortest restore sequence: %d\nThanks for using.\n", N, max_step, ave_step/N);
	return 0;
}

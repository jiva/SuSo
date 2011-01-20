/*
	suso: A SUdoku SOlver
	by jiva
	Notes: This is still a WIP, completes entire puzzle sometimes. Need to implement: vertChkAI_2() (maybe more than 2), AI for boxes as well.
*/

#include <stdio.h>		/* printf() */
#include <stdlib.h>		/* exit() atoi() */

#define	TRUE	1
#define	FALSE	0

int sboard[9][9];		/* The board */

/* Employ AI to check horz with 2 empties */
int horzChkAI_2()
{
	int i, j, ret = FALSE;
	
	for(i = 0; i < 9; i++)
	{
		int chko[10] = {0};
		int zc = 0, x1 = i, y1 = 0, x2 = i, y2 = 0;
		for(j = 0; j < 9; j++)
		{
			chko[sboard[i][j]]++;
			if(sboard[i][j] == 0)
			{
				zc++;
				if(y1 == 0)
				{
					y1 = j;
				}
				else
				{
					y2 = j;
				}
			}
		}
		if(zc == 2) //Found a target row, find missing values
		{
			int k, mv1 = 0, mv2 = 0, a, b, c, d;
			for(k = 1; k < 10; k++)
			{
				if(chko[k] == 0)
				{
					if(mv1 == 0)
					{
						mv1 = k;
					}
					else
					{
						mv2 = k;
					}
				}
			}
			
			/* Check verticies of missing values: mv1, y1 */
			for(a = 0; a < 9; a++)
			{
				if(sboard[a][y1] == mv1) //mv1 can't go in x1, y1
				{
					sboard[x2][y2] = mv1;
					sboard[x1][y1] = mv2;
					ret = TRUE;
					return ret;
				}
			}
			
			/* Check verticies of missing values: mv1, y2 */
			for(b = 0; b < 9; b++)
			{
				if(sboard[b][y2] == mv1) //mv1 can't go in x2, y2
				{
					sboard[x1][y1] = mv1;
					sboard[x2][y2] = mv2;
					ret = TRUE;
					return ret;
				}
			}
			
			/* Check verticies of missing values: mv2, y1 */
			for(c = 0; c < 9; c++)
			{
				if(sboard[c][y1] == mv2) //mv2 can't go in x1, y1
				{
					sboard[x2][y2] = mv2;
					sboard[x1][y1] = mv1;
					ret = TRUE;
					return ret;
				}
			}
			
			/* Check verticies of missing values: mv2, y2 */
			for(d = 0; d < 9; d++)
			{
				if(sboard[d][y2] == mv2) //mv2 can't go in x2, y2
				{
					sboard[x2][y2] = mv1;
					sboard[x1][y1] = mv2;
					ret = TRUE;
					return ret;
				}
			}
		}
	}
	
	return ret;
}

/* Check boxes for openings */
/*
	Format:
		123
		456
		789
*/
int chkBoxz()
{
	int ret = FALSE;
	
	{
		/* Check box 1 */
		int i, j, zc = 0, tot = 0, sx = 1, sy = 1, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 2 */
		int i, j, zc = 0, tot = 0, sx = 1, sy = 4, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 3 */
		int i, j, zc = 0, tot = 0, sx = 1, sy = 7, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 4 */
		int i, j, zc = 0, tot = 0, sx = 4, sy = 1, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 5 */
		int i, j, zc = 0, tot = 0, sx = 4, sy = 4, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 6 */
		int i, j, zc = 0, tot = 0, sx = 4, sy = 7, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 7 */
		int i, j, zc = 0, tot = 0, sx = 7, sy = 1, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 8 */
		int i, j, zc = 0, tot = 0, sx = 7, sy = 4, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	{
		/* Check box 9 */
		int i, j, zc = 0, tot = 0, sx = 7, sy = 7, ex = 0, ey = 0;
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tot = tot + sboard[i][j];
				if(sboard[i][j] == 0)
				{
					zc++;
					ex = i;
					ey = j;
				}
			}
		}
		if(zc == 1)
		{
			sboard[ex][ey] = 45 - tot;
			ret = TRUE;
		}
	}
	
	return ret;
}

/* Check horizons for openings */
int chkHorz()
{
	int i, j, zc = 0, tot = 0, zptr = 0, ret = FALSE;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			tot = tot + sboard[i][j];
			if(sboard[i][j] == 0)
			{
				zc++;
				zptr = j;
			}
		}
		
		if(zc == 1)
		{
			sboard[i][zptr] = 45 - tot;
			zc = 0;
			tot = 0;
			zptr = 0;
			ret = TRUE;
		}
		else
		{
			zc = 0;
			tot = 0;
			zptr = 0;
		}
	}
	
	return ret;
}

/* Check vertices for openings */
int chkVert()
{
	int i, j, zc = 0, tot = 0, zptr = 0, ret = FALSE;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			tot = tot + sboard[j][i];
			if(sboard[j][i] == 0)
			{
				zc++;
				zptr = j;
			}
		}
		
		if(zc == 1)
		{
			sboard[zptr][i] = 45 - tot;
			zc = 0;
			tot = 0;
			zptr = 0;
			ret = TRUE;
		}
		else
		{
			zc = 0;
			tot = 0;
			zptr = 0;
		}
	}
	
	return ret;
}

/* Zero-out the board */
void nuke()
{
	int i, j;
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			sboard[i][j] = 0;
		}
	}
}

/* print the board */
void printBoard()
{
	int i, j;
	
	printf("Sudoku board\n");
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(sboard[i][j] == 0)
			{
				printf("_ ");
			}
			else
			{
				printf("%d ", sboard[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

/* print the board, string-style */
void printString()
{
	int i, j;
	
	printf("Sudoku board\n");
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			if(sboard[i][j] == 0)
			{
				printf(",");
			}
			else
			{
				printf("%d,", sboard[i][j]);
			}
		}
	}
	printf("\n");
}

/* Convert string to board */
void convert(char *str)
{
	int i = 0, j = 0, k = 0, cc = 0;
	
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ',')
		{
			k++;
			cc++;
			if(cc == 9) // Row is full
			{
				cc = 0;
				k = 0;
				j++;
			}
		}
		else
		{
			sboard[j][k] = atoi(&str[i]);
		}
	}
}


/* Checks if the board is valid: 1 if valid, -1 er/in rows, -2 er/in cols, -3 er/in boxes */
int isValid()
{
	{
		/* Check rows */
		int i, j;
		for(i = 0; i < 9; i++)
		{
			int tots[10] = {0};
			int k;
			for(j = 0; j < 9; j++)
			{
				tots[sboard[i][j]]++;
			}
			for(k = 1; k < 10; k++)
			{
				if(tots[k] == 0)
				{
					return -1;
				}
			}
		}
	}
	
	{
		/* Check cols */
		int i, j;
		for(i = 0; i < 9; i++)
		{
			int tots[10] = {0};
			int k;
			for(j = 0; j < 9; j++)
			{
				tots[sboard[j][i]]++;
			}
			for(k = 1; k < 10; k++)
			{
				if(tots[k] == 0)
				{
					return -2;
				}
			}
		}
	}
	
	{
		/* Check box 1 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 2 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 3 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 4 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 5 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 6 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 7 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 8 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	{
		/* Check box 9 */
		int i, j, sx = 7, sy = 7, k;
		int tots[10] = {0};
		for(i = sx - 1; i <= sx + 1; i++)
		{
			for(j = sy - 1; j <= sy + 1; j++)
			{
				tots[sboard[i][j]]++;
			}
		}
		for(k = 1; k < 10; k++)
		{
			if(tots[k] == 0)
			{
				return -3;
			}
		}
	}
	
	return 1;
}

int main(int argc, char *argv[])
{
	int b1 = TRUE, b2 = TRUE, b3 = TRUE, b4 = TRUE;
	
	if(argc != 2)
	{
		printf("Usage:\t# %s <sudoku_string>\n", argv[0]);
		exit(-1);
	}
	
	nuke();
	convert(argv[1]);
	
	printBoard();
	
	while(b1 || b2 || b3 || b4)
	{
		b1 = chkHorz();
		b2 = chkVert();
		b3 = chkBoxz();
		b4 = horzChkAI_2();
	}
	
	printBoard();
	printString();
	
	printf("Is valid? %d\n", isValid());
	
	exit(0);
}

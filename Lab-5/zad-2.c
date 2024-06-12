#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double **new_matrix (int n, int m)
{
	double **ret = malloc (sizeof (double *) * n);
	for (int i = 0; i < n; i++)
		*(ret + i) = malloc (sizeof (double) * m);
	return ret;
}

void set_matrix (double **matrix, int n, int m, double v)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			*(*(matrix + i) + j) = v;
}

void print_matrix (double **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf ("%lf\t", *(*(matrix + i) + j));
		printf ("\n");
	}
}

void input_matrix (double **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%lf", *(matrix + i) + j);
}

void free_matrix (double **matrix, int n, int m)
{
	for (int i = 0; i < n; i++)
		free (*(matrix + i));
	free (matrix);
}

void copy_matrix (double **A, double **B, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			B[i][j] = A[i][j];
	}
}

double norma_euklidesowa (double *v, int n)
{
	double ret = 0.;
	for (int i = 0; i < n; i++)
	{
		ret += v[i] * v[i];
	}
	return sqrt (ret);
}

double **subtract_matrix (double **A, double **B, int n, int m)
{
	double **ret = new_matrix (n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			*(*(ret + i) + j) = *(*(A + i) + j) - *(*(B + i) + j);
	return ret;
}

double **gauss (double **A, int na, int ma, double **B, int nb, int mb, int N)
{
	int nx = 1, mx = na;
	double **X = new_matrix (nx, mx);
	set_matrix (X, nx, mx, 0.);
	double **X_new = new_matrix (nx, mx);

	int k;
	for (k = 0; k < N; k++)
	{
		for (int i = 0; i < na; i++)
		{
			double sum1 = 0.;	
			double sum2 = 0.;	
			for (int j = 0; j < i; j++)
			{
				sum1 += A[i][j] * X_new[0][j];
			}
			for (int j = i + 1; j < ma; j++)
			{
				sum2 += A[i][j] * X[0][j];
			}
			X_new[0][i] = (B[0][i] - sum1 - sum2) / A[i][i];
		}	
		double **licznik = subtract_matrix (X_new, X, 1, na);
		if (norma_euklidesowa(licznik[0], na) / norma_euklidesowa(X_new[0], na) < 0.000000000000001)
			break;
		free_matrix (licznik, 1, na);
		copy_matrix (X_new, X, nx, mx);
	}
	printf ("Ilosc iteracji: %d\n", k);

	return X;
}

int main ()
{
	int na, ma;
	scanf ("%d%d", &na, &ma);
	double **A = new_matrix (na, ma);
	input_matrix (A, na, ma);

	int nb = 1, mb = ma;
	double **B = new_matrix (nb, mb);
	input_matrix (B, nb, mb);

	double **X = gauss (A, na, ma, B, nb, mb, 100);
	print_matrix (X, 1, na);

	free_matrix (A, na, ma);
	free_matrix (B, nb, mb);
	free_matrix( X, 1, na);
	return 0;
}

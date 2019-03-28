// Gauss Elimination of matrix A without piwoting
// Forward elimlimination
// Backsubstitution

#include<stdio.h>
#include<stdlib.h>

#define N 3
int main()
{
  double A[N][N+1]={ {3.0, 2.0,-4.0, 3.0 },
                     {2.0, 3.0, 3.0, 15.0},
                     {5.0,-3.0, 1.0, 14.0} };

  double x[N];

  int i,j,k;
  double p;

  for(i=0;i<N-1;i++)
  {
    for(j=i+1;j<N;j++)
    {
      p=A[j][i]/A[i][i];
      for(k=i;k<N+1;k++)
      {
       A[j][k]=A[j][k]- p*A[i][k];
      }
    }
  }

  for(i=0;i<N;i++)
  {
    for(j=0;j<N+1;j++)
    {
      printf("%lf\t",A[i][j]);
    }
    printf("\n");
  }


  for(i=N-1;i>=0;i--)
  {
    p=0.0;
    for(j=i+1;j<N;j++)
    {
      p= p + x[j] * A[i][j];
    }  
    x[i]=(A[i][N] - p )/A[i][i];
  }

  for(j=0;j<N;j++)
  {
    printf("%lf\n",x[j]);
  }
}

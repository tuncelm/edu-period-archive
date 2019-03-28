// Gauss Elimination of matrix A

#include<stdio.h>
#define N 3
int main()
{
  double A[N][N]={ {3.0, 2.0,-4.0},
                 {2.0, 3.0, 3.0},
                 {5.0,-3.0, 1.0} };

  int i,j,k;
  double p;

  for(i=0;i<N-1;i++)
  {
    for(j=i+1;j<N;j++)
    {
      p=A[j][i]/A[i][i];
      for(k=i;k<N;k++)
      {
       A[j][k]=A[j][k]- p*A[i][k];
      }
    }
  }

  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
    {
      printf("%lf\t",A[i][j]);
    }
    printf("\n");
  }

}

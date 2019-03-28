// Gauss Elimination of matrix A with partial pivoting
// Forward elimlimination
// Backsubstitution

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 4



void print_matrix(double A[N][N+1])
{
  int i,j;
  printf("\n");
  for(i=0;i<N;i++)
  {
    for(j=0;j<N+1;j++)
    {
      printf("%lf\t",A[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


int find_idx(double A[N][N+1],int col)
{
  int i;
  double maximum=fabs(A[col][col]);
  int row=col;
  for(i=col+1;i<N;i++)
  {
    if( maximum <fabs(A[i][col]) )
    {
      maximum = fabs(A[i][col]); 
      row = i;  
    }    
  }
  return row;
}

void change(double A[N][N+1],int row1,int row2)
{
  int j;
  double swap[N+1];
  for(j=0;j<N+1;j++)
  {
    swap[j]=A[row1][j];
  }
  for(j=0;j<N+1;j++)
  {
    A[row1][j]=A[row2][j];
    A[row2][j]=swap[j];
  }
}



int main()
{
  //http://web.mit.edu/10.001/Web/Course_Notes/GaussElimPivoting.html
  double A[N][N+1]={ {0.02, 0.01, 0.0, 0.0, 0.02 },
                     {1.0,  2.0,  1.0, 0.0, 1.0},
                     {0.0,  1.0,  2.0, 1.0, 4.0},
                     {0.0,  0.0,  100.0, 200.0, 800.0} };

  double x[N];

  int i,j,k;
  double p;

  //printf("\n %d \n ",find_idx(A,0));
  //print_matrix(A);
  //change(A,0,2);
  //print_matrix(A);

  for(i=0;i<N-1;i++)
  {
    
    change(A,find_idx(A,i),i);

    for(j=i+1;j<N;j++)
    {
      p=A[j][i]/A[i][i];
      for(k=i;k<N+1;k++)
      {
       A[j][k]=A[j][k]- p*A[i][k];
      }
    }
    print_matrix(A);
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

# Octave m-file
# LU factoization using gauss elimination by three version
# function [L,U,P]=my_lu(A)

# An example to see the differences between PP nad CPP   
# Use matrix A=[-5,3,7,1;15,-7,-21,-10;-55,29,80,34;35,-2,-10,49] and look at the values of PA-LU

function [L,U,P]=my_lu(A)

[m,n]=size(A);
U=A;
L=eye(m);
P=eye(m);

S=max(abs(U),[],2); # Scaled factor for scaled partial pivoting algorithm.

for k=1:m-1
  # Without pivot
  i=k;
  
  # Partial pivoting
  #[pivot, i] = max (abs (U (k:m,k)));
  #i=i+k-1; 

  # Scaled Partial Pivoting
  #[pivot, i] = max ( abs( U(k:m,k) ) ./ S(k:m) );
  #i=i+k-1; 

  U([k,i],k:m)=U([i,k],k:m);
  L([k,i],1:k-1)=L([i,k],1:k-1);
  P([k,i],:)=P([i,k],:);
  for j=k+1:m
    L(j,k)=U(j,k)/U(k,k);
    U([j],k:m)=U([j],k:m)-L(j,k)*U([k],k:m);
  end
  
end


end

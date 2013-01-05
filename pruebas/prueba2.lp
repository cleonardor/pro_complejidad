max : Dx + Dy;

Ax - 1 c1 - 7 c2 <= Dx;

Ay - 7 c1 - 1 c2 <= Dy;

1 c1 - 7 c2 - Ax <= Dx;

7 c1 - 1 c2 - Ay <= Dy;

Ax - 1 + 14 Sx1 - Dx1 >= 0;
Ax - 1 + 14 Sx1 + Dx1 <= 14;
Ax - 1 <= Dx1;
1 - Ax <= Dx1;

Ay - 7 + 14 Sy1 - Dy1 >= 0;
Ay - 7 + 14 Sy1 + Dy1 <= 14;
Ay - 7 <= Dy1;
7 - Ay <= Dy1;

Ax - 7 + 14 Sx2 - Dx2 >= 0;
Ax - 7 + 14 Sx2 + Dx2 <= 14;
Ax - 7 <= Dx2;
7 - Ax <= Dx2;

Ay - 1 + 14 Sy2 - Dy2 >= 0;
Ay - 1 + 14 Sy2 + Dy2 <= 14;
Ay - 1 <= Dy2;
1 - Ay <= Dy2;

c1 + c2 = 1;
Dx + Dy <= Dx1 + Dy1;
Dx + Dy <= Dx2 + Dy2;

0 <= Ax <= 6;
0 <= Ay <= 6;

Dx >= 0;
Dy >= 0;

Dx1 >= 0;
Dy1 >= 0;
Dx2 >= 0;
Dy2 >= 0;

bin Sx1 , Sx2 ; 

bin Sy1 , Sy2 ; 

bin c1 , c2 ; 

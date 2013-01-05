max : Dx + Dy;

Ax - 0 c1 - 0 c2 <= Dx;

Ay - 0 c1 - 2 c2 <= Dy;

0 c1 - 0 c2 - Ax <= Dx;

0 c1 - 2 c2 - Ay <= Dy;

Ax - 0 + 4 Sx1 - Dx1 >= 0;
Ax - 0 + 4 Sx1 + Dx1 <= 4;
Ax - 0 <= Dx1;
0 - Ax <= Dx1;

Ay - 0 + 4 Sy1 - Dy1 >= 0;
Ay - 0 + 4 Sy1 + Dy1 <= 4;
Ay - 0 <= Dy1;
0 - Ay <= Dy1;

Ax - 0 + 4 Sx2 - Dx2 >= 0;
Ax - 0 + 4 Sx2 + Dx2 <= 4;
Ax - 0 <= Dx2;
0 - Ax <= Dx2;

Ay - 2 + 4 Sy2 - Dy2 >= 0;
Ay - 2 + 4 Sy2 + Dy2 <= 4;
Ay - 2 <= Dy2;
2 - Ay <= Dy2;

c1 + c2 = 1;
Dx + Dy <= Dx1 + Dy1;
Dx + Dy <= Dx2 + Dy2;

0 <= Ax <= 1;
0 <= Ay <= 1;

Dx >= 0;
Dy >= 0;

Dx1 >= 0;
Dy1 >= 0;
Dx2 >= 0;
Dy2 >= 0;

bin Sx1 , Sx2 ; 

bin Sy1 , Sy2 ; 

bin c1 , c2 ; 

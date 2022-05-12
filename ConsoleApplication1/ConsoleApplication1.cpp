
#include <iostream>


const int MaxMoves = 200;

struct record {
    int a;
    int b;
};

long int Ar1[100][100];
record Ar2[10000];

int A, B, C, D, E, F, N, S;
int** Q;
int V[200];
record* O;
record* O1;
long int NO, NO1;


void Rec(int Z, int X, int M) {
 
    if (Q[Z, X] !=0) return;
    for (int i = 1; i < NO1; i++) 
        if((O[i].a = Z) and (O[i].b = X)) return;
    NO1++;
    O1[NO1].a = Z;
    O1[NO1].b = X;
    Q[Z][X] = M;
}

void Re(int Z, int X, int M) {
    int C;
    C = 100 - Z - X;
    std::cout << "----";
    std::cout << "Z = " << Z;
    std::cout << "X = " << X;

    std::cout << "C = " << C;

    if((Z > 0) && (X <= 100 - Z))Rec(0, X + Z, M + 1);
    if ((Z > 0) and (C <= 100 - Z)) Rec(0, X, M + 1);
    if ((X > 0) and (Z <= 100 - X)) Rec(Z + X, 0, M + 1);
    if ((X > 0) and (C <= 100 - X)) Rec(Z, 0, M + 1);
    if ((C > 0) and (Z <= 100 - C)) Rec(Z + C, X, M + 1);
    if ((C > 0) and (X <= 100 - C)) Rec(Z, X + C, M + 1);
    if ((X == 0) and (Z > 0) and (C < 100)) Rec(0, 0, M + 1);
    if ((Z == 0) and (X > 0) and (C < 100)) Rec(0, 0, M + 1);
    for (int i = 1; i < N; i++)
    {
        if((Z >= V[A] - X) && (X < V[A])) Rec(Z - (V[A] - X), V[A], M + 1);
        if((Z > V[A]) && (X + Z - V[A] <= 100)) Rec(V[A], X + Z - V[A], M + 1);
        if((X >= V[A] - Z) && (Z < V[A])) Rec(V[A], X - (V[A] - Z), M + 1);
        if((X > V[A]) && (Z + X - V[A] <= 100)) Rec(Z + X - V[A], V[A], M + 1);
        if((C >= V[A] - Z) && (Z < V[A])) Rec(V[A], X, M + 1);
        if((Z > V[A]) && (C + Z - V[A] <= 100)) Rec(V[A], X, M + 1);
        if((C >= V[A] - X) && (X < V[A])) Rec(Z, V[A], M + 1);
        if((X > V[A]) && (C + X - V[A] <= 100)) Rec(Z, V[A], M + 1);
    }
}

void start();
{
    
    New(O);
    New(O1);
    O^ [1].a: = 100;
    O^ [1].b: = 0;
    Q[100, 0]: = 1;
NO: = 1;
    While NO < >0 do
        Begin
        NO1 : = 0;
    For A : = 1 to NO do
        Re(O ^ [A].a, O ^ [A].b, Q[O ^ [A].a, O ^ [A].b]);
NO: = NO1;
    O^ : = O1^;
    End;
}

Procedure Out;
Var Max : LongInt;
Begin
Max : = MaxLongInt;
For A : = 0 to 99 do
Begin
B : = 99 - A;
If(Max > Q[A, B]) and (Q[A, B] < >0) then
Max : = Q[B, A];
End;
If Max = MaxLongInt then WriteLn('NO') else
Begin
WriteLn('YES');
WriteLn(Max - 1);
End;
Dispose(O);
Dispose(O1);
End;

Begin
ReadFile;
Assign(Output, 'output.txt');
ReWrite(Output);
Work;
Out;
Close(Output);
End.
int main()
{
    std::cout << "Hello World!\n";
}

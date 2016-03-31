#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int *A, *T;

/*计算出N个结点的树，其左子树有多少个结点*/
int GetLeftLength(int N) {
    int h;
    for (h = 0; ; h++)
        if ((pow(2, h) - 1) >= N)
            break;
    //得到树的高度
    
    //设最后一行有res个结点
    int res = N - (pow(2, h-1) - 1);
    if ( res <= (pow(2, h-1) / 2) )
        return (N - res - 1) / 2 + res;
    else
        return (N - res - 1) / 2 + pow(2, h-1) / 2;
}

void Solve(int ALeft, int ARight, int TRoot) {
    int n = ARight - ALeft + 1;
    if (n == 0)  return;
    
    int L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    int TLeftRoot = TRoot*2 + 1;
    int TRightRoot = TLeftRoot + 1;
    Solve(ALeft, ALeft+L-1, TLeftRoot);
    Solve(ALeft+L+1, ARight, TRightRoot);
}

int compareMyType (const void * a, const void * b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int N;
    scanf("%d", &N);
    A = new int[N];
    T = new int[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &A[i]);
    
    qsort(A, N, sizeof(int), compareMyType);
    Solve(0, N-1, 0);
    
    printf("%d", T[0]);
    for (int i = 1; i < N; i++)
        printf(" %d", T[i]);
    printf("\n");
    return 0;
}








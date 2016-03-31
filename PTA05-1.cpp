//
//  PTA05-1.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/29.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#define MaxData -10005
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    int *Data;
    int Size;
    int Capacity;
};

MinHeap Create(int MaxSize) {
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Data = (int *)malloc( (MaxSize+1) * sizeof(int));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MaxData;
    
    return H;
}

/**/
void Insert(MinHeap H, int X) {
    if (H->Size == 0) {
        H->Data[1] = X;
        H->Size++;
    }
    else {
        int i = ++H->Size;
        for ( ; H->Data[i/2] > X; i /= 2)
            H->Data[i] = H->Data[i/2];
        H->Data[i] = X;
    }
   
}
/**/

void PrintRoute(MinHeap H) {
    int i;
    scanf("%d", &i);
    
    printf("%d", H->Data[i]);
    i /= 2;
    for ( ; i > 0; i /= 2)
        printf(" %d", H->Data[i]);
    printf("\n");
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    MinHeap H = Create(N);
    
    /**/
    for (int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        Insert(H, t);
    } //建立最小堆
    /**/
    
    for (int i = 0; i < M; i++) {
        PrintRoute(H);
    }
    return 0;
}







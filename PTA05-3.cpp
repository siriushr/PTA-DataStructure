//
//  PTA05-3.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/30.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <cstdio>
#include <cstdlib>

typedef struct TreeNode *HuffmanTree;
struct TreeNode {
    int Weight;
    char Character;
    HuffmanTree Left, Right;
};

typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    HuffmanTree* Elements;
    int Capacity;
    int Size;
};

void PercDown(MinHeap H, int p) {
    int Parent, Child;
    auto X = H->Elements[p];
    
    for (Parent = p; Parent*2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        
        if ( (Child != H->Size) && (H->Elements[Child]->Weight > H->Elements[Child+1]->Weight))
            Child++; // 找到左右孩子中更小的那个
        
        if (X->Weight <= H->Elements[Child]->Weight)
            break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    
    H->Elements[Parent] = X;
}

void BuildMinHeap(MinHeap H) {
    int i;
    for (i = H->Size/2; i > 0; --i)
        PercDown(H, i);
}

void Insert(MinHeap H, HuffmanTree T) {
    
    if (H->Size == 0) {
        H->Elements[1] = T;
        H->Size++;
    }
    else {
        int i = ++H->Size;
        for ( ; H->Elements[i/2]->Weight > T->Weight; i = i/2)
            H->Elements[i] = H->Elements[i/2];
        H->Elements[i] = T;
    }
}

HuffmanTree DeleteMin(MinHeap H) {
    HuffmanTree Min = H->Elements[1];
    
    HuffmanTree t = H->Elements[H->Size--];
    int Parent, Child;
    for (Parent = 1; Parent*2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        
        if ( (Child != H->Size) && (H->Elements[Child]->Weight > H->Elements[Child+1]->Weight) )
            Child++;
        
        if (H->Elements[Child]->Weight > t->Weight) break;
        else
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = t;
    
    return Min;
}

HuffmanTree Huffman(MinHeap H) {
    int i;
    HuffmanTree T;
    BuildMinHeap(H);
    
    for (i = 0; i < H->Size-1; i++) {
        T = (HuffmanTree)malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    
    T = DeleteMin(H);
    return T;
}

int GetRoute(char c) {
    int route;
    
    return route;
}
int main() {
    int N;
    char *c = new char[N];
    int *f = new int[N];
    for (int i = 0; i < N; i++) {
        scanf("%c %d", &c[i], &f[i]);
    }
    
    MinHeap H = (MinHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = (HuffmanTree*)malloc(sizeof(HuffmanTree) * (N+1));
    for (int i = 0; i < N; i++) {
        H->Elements[i+1]->Character = c[i];
        H->Elements[i+1]->Weight = f[i];
    }
    
    HuffmanTree T = Huffman(H);
    
    int MinRoute = 0;
    for (int i = 1; i <= N; i++) {
        MinRoute += (H->Elements[i]->Weight) * GetRoute(H->Elements[i]->Character);
    }
}




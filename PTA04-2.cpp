//
//  Reversing Linked List.cpp
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/23.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *AVLTree;
struct AVLNode {
    int Data;
    AVLTree Left, Right;
    int Height = 0;
};

int GetHight(AVLTree);
int Max(int, int);
AVLTree SingleLeftRotation(AVLTree);
AVLTree DoubleLeftRightRotation(AVLTree);
AVLTree SingleRightRotation(AVLTree);
AVLTree DoubleRightLeftRotation(AVLTree);
AVLTree Insert(AVLTree, int);

/***********************************/
/***********************************/

int main() {
    int N;
    scanf("%d", &N);
    AVLTree T = NULL;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        T = Insert(T, x);
    }
    printf("%d\n", T->Data);
    return 0;
}
/***********************************/
/***********************************/

int GetHeight(AVLTree T) {
    if(!T)
        return 0;
    else
        return Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
}

int Max(int a, int b) {
    return a > b ? a : b;
}

AVLTree SingleLeftRotation(AVLTree A) {
    /*注意：A必须有一个左子结点B*/
    /*将A与B做左单旋，更新A与B的高度，并返回新的根结点B*/
    
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;
    
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A) {
    /*注意：A必须有一个左子结点B，且B有一个右子结点C*/
    /*将A、B与C做两次单旋，并返回新的结点C*/
    
    /*将B与C做右单旋，返回C*/
    A->Left = SingleRightRotation(A->Left);
    /*将A与C做左单旋，返回C*/
    return SingleLeftRotation(A);
}

AVLTree SingleRightRotation(AVLTree A) {
    /*注意：A必须有一个右子结点B*/
    /*将A与B做右单旋，更新A与B的高度，并返回新的根结点B*/
    
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;
    
    return B;
}

AVLTree DoubleRightLeftRotation(AVLTree A) {
    /*注意：A必须有一个右子结点B，且B有一个左子结点C*/
    /*将A、B与C做两次单旋，并返回新的结点C*/
    
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, int X) {
    /*将X插入AVL树中，然后返回调整后的AVL树*/
    
    /*若插入一个空树，则新建包含一个结点的树*/
    if (!T) {
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        T->Height = 0;
    } /*if(插入空树) 结束*/
    
    else if (X < T->Data) {
        /*插入T的左子树*/
        T->Left = Insert(T->Left, X);
        /*如果需要左旋*/
        if ((GetHeight(T->Left) - GetHeight(T->Right)) == 2) {
            if (X < T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    
    else if (X > T->Data) {
        T->Right = Insert(T->Right, X);
        if ((GetHeight(T->Left) - GetHeight(T->Right)) == -2) {
            if (X < T->Right->Data)
                T = DoubleRightLeftRotation(T);
            else
                T = SingleRightRotation(T);
        }
    }
    
    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    
    return T;
}




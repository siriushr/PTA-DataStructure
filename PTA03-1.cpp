//
//  PTA3-01.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/19.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>
#define Tree int
#define ElementType char
#define MaxSize 10
#define Null -1

struct TreeNode{
    ElementType Element;
    Tree Left = -1;
    Tree Right = -1;
} T1[MaxSize], T2[MaxSize];

Tree CreatTree(struct TreeNode[]);
bool Isormorphic(Tree, Tree);

int main() {
    Tree R1, R2;
    R1 = CreatTree(T1);//建二叉树1
    R2 = CreatTree(T2);//建二叉树2
    
    bool flag = Isormorphic(R1, R2);//比较是否同构
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
    
    return 0;
}

Tree CreatTree(struct TreeNode T[]) {
    int Root;
    char cl, cr;
    int N;
    scanf("%d\n", &N);
    int check[N];
    
    for (int i = 0; i < N; i++)
        check[i] = 0;
    
    for (int i = 0; i < N; i++) {
        scanf("%c %c %c\n", &T[i].Element, &cl, &cr);
        if (cl != '-') {
            T[i].Left = cl-'0';
            check[T[i].Left] = 1;
        } else T[i].Left = Null;
        
        if (cr != '-') {
            T[i].Right = cr-'0';
            check[T[i].Right] = 1;
        } else T[i].Right = Null;
    }
    
    int i;
    for (i = 0; i < N; i++)
        if (!check[i])
            break;
    Root = i;
    
    return Root;
}

bool Isormorphic(Tree R1, Tree R2) {
    if ((R1 == Null) && (R2 == Null)) //both empty
        return true;
    
    if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) //only one is empty
        return false;
    
    if (T1[R1].Element != T2[R2].Element) //root value is not equal
        return false;
    
    if ((T1[R1].Left == Null) && (T2[R2].Left == Null)) //both don't have left subtree
        return (Isormorphic(T1[R1].Right, T2[R2].Right));
    
    if ((T1[R1].Left != Null) && (T2[R2].Left != Null) && (T2[T2[R2].Left].Element == T1[T1[R1].Left].Element)) //no need to swap
        return (Isormorphic(T1[R1].Right, T2[R2].Right));
    else  //need to swap
        return (Isormorphic(T1[R1].Left, T2[R2].Right) && Isormorphic(T1[R1].Right, T2[R2].Left));
}

//
//  PTA04-1.cpp
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/22.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *Tree;
struct TreeNode {
    int Data;
    Tree Left;
    Tree Right;
};

Tree CreateTree(int);
Tree Insert(Tree, int);
bool CompareTree(Tree, Tree);

int main() {
    int N, L;
    scanf("%d %d", &N, &L);
    
    while (true) {
        //生成初始序列
        Tree original = (Tree)malloc(sizeof(TreeNode));
        original = CreateTree(N);
        
        //生成L个需要比较的序列
        Tree test[L];
        for (int i = 0; i < L; i++)
            test[i] = CreateTree(N);
        
        //比较L个序列是否生成与原树相同的树
        for (int i = 0; i < L; i++) {
            if (CompareTree(original, test[i]))
                printf("Yes\n");
            else
                printf("No\n");
        }
        
        //进入下一组
        scanf("%d", &N);
        if (!N) break;
        scanf("%d", &L);
    }
    return 0;
}


Tree CreateTree(int N) {
    Tree Root = (Tree)malloc(sizeof(struct TreeNode));
    Root->Data = 0;
    Root->Left = NULL;
    Root->Right = NULL;
    
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        
        Root = Insert(Root, tmp);
    }
    return Root;
}

Tree Insert(Tree Root, int tmp) {
    if (!Root) {
        Root = (Tree)malloc(sizeof(struct TreeNode));
        Root->Data = tmp;
        Root->Left = Root->Right = NULL;
    } else {
        if (tmp < Root->Data)
            Root->Left = Insert(Root->Left, tmp);
        else if (tmp > Root->Data)
            Root->Right = Insert(Root->Right, tmp);
    }
    return Root;
}

bool CompareTree(Tree A, Tree B) {
    if (!A && !B) //均为空
        return true;
    if ((!A && B) || (A && !B)) //只有一边为空
        return false;
    if (A->Data != B->Data) //根结点的值不相等
        return false;
    else
        return (CompareTree(A->Left, B->Left) && CompareTree(A->Right, B->Right));
}





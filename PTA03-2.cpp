//
//  new.cpp
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/19.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <iostream>
#include <deque>
#define MaxSize 10
#define Null -1
using namespace std;

struct TreeNode {
    int data;
    int left;
    int right;
} T[MaxSize];


int BuildTree(struct TreeNode T[]);
bool IsLeavesNode(int Root);

int main() {
    int R = BuildTree(T);
    deque<int> d;
    d.push_back(R);
    
    int Leaves[10];
    int cnt = 0;
    while (!d.empty()) {
        int tmp = d.front();
        d.pop_front();
        bool flag = IsLeavesNode(tmp);
        if (flag)
            Leaves[cnt++] = tmp;
        else {
            if (T[tmp].left != Null)  d.push_back(T[tmp].left);
            if (T[tmp].right != Null)  d.push_back(T[tmp].right);
        }
    }
    
    printf("%d", Leaves[0]);
    for (int i = 1; i < cnt; i++)
        printf(" %d", Leaves[i]);
    printf("\n");
    return 0;
}

int BuildTree(struct TreeNode T[]) {
    int n, Root;
    scanf("%d\n", &n);
    char cl, cr;
    int check[n];
    for (int i = 0; i < n; i++)
        check[i] = 0;
    
    for (int i = 0; i < n; i++) {
        scanf("%c %c\n", &cl, &cr);
        T[i].data = i;
        if (cl != '-') {
            T[i].left = cl-'0';
            check[T[i].left] = 1;
        } else T[i].left = Null;
        if (cr != '-') {
            T[i].right = cr-'0';
            check[T[i].right] = 1;
        } else T[i].right = Null;
    }
    
    int i;
    for (i = 0; i < n; i++)
        if (!check[i]) break;
    Root = i;
    return Root;
}


bool IsLeavesNode(int Root) {
    if ((T[Root].left == Null) && (T[Root].right == Null))
        return true;
    return false;
}


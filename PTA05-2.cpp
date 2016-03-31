//
//  PTA05-2.cpp
//  myPlayground
//
//  Created by 黄然 on 16/3/31.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>

struct SetType {
    int Data;
    int Parent;
};
typedef struct SetType Set;

int FindRoot(Set S[], int X) {
    int i;
    for (i = 0; S[i].Data != X; i++)
        ;
    for ( ; S[i].Parent > 0; i = S[i].Parent)
        ;
    return i;
}

void CheckEveryComputer(Set S[], int N) {
    int i, cnt = 0;
    for (i = 1; i <= N; i++) {
        if (S[i].Parent == -1) cnt++;
    }
    
    if (cnt == 1)
        printf("The network is connected.\n");
    else if (cnt > 1)
        printf("There are %d components.\n", cnt);
}

int main() {
    /* 1. 读入N，生成大小为N的数组 */
    int N;
    scanf("%d\n", &N);
    Set *S = new Set[N+1];
    
    /* 初始化数组 */
    S[0].Data = N+1;
    S[0].Parent = -1;
    for (int i = 1; i <= N; i++) {
        S[i].Data = i;
        S[i].Parent = -1;
    }
    
    /* 2. 循环读入case数据，不是“S”时继续循环 */
    char c;
    scanf("%c", &c);
    while (c != 'S') {
        /* 读入两台电脑的编号 */
        int c1, c2;
        scanf("%d %d\n", &c1, &c2);
        
        //计算两台电脑的根结点
        int r1, r2;
        r1 = FindRoot(S, c1);
        r2 = FindRoot(S, c2);
        
        /* 根据c的类型分情况处理数据 */
        /* 如果c== C， 检查两台电脑是否相连，即是否有同一个根 */
        if (c == 'C') {
            if (r1 == r2) printf("yes\n");
            else printf("no\n");
        } // 如果c == I，检查电脑是否相连，不相连则让它们相连
        else if (c == 'I') {
            if (r1 != r2)
                S[r1].Parent = r2;
        }
        
        /* 读入下一组case */
        scanf("%c", &c);
    }
    
    // 3.检查是否每一台电脑都已经相连
    CheckEveryComputer(S, N);
    
    return 0;
}






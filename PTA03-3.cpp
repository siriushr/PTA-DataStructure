//
//  PTA03-3.cpp
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/20.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define MaxSize 30
using namespace std;

vector<vector<int>> GetOrder(int);
void GetPostOrder(vector<int>, int, vector<int>, int, vector<int>&, int, int);

int main() {
    int N;
    cin >> N;
    auto res = GetOrder(N);
    vector<int> PostOrder(N, 0);
    GetPostOrder(res[0], 0, res[1], 0, PostOrder, 0, N);
    
    //输出
    cout << PostOrder[0];
    for (int i = 1; i < N; i++)
        cout << " " << PostOrder[i];
    cout << endl;
    return 0;
}

vector<vector<int>> GetOrder(int N) {
    vector<int> PreOrder(N, 0);
    vector<int> InOrder(N, 0);
    stack<int> st;
    int preL = 0, inL = 0;
    
    for (int i = 0; i < 2*N; i++) {
        string str;
        int tmp;
        cin >> str;
        if (str == "Push") {
            cin >> tmp;
            PreOrder[preL++] = tmp;
            st.push(tmp);
        }
        if (str == "Pop") {
            InOrder[inL++] = st.top();
            st.pop();
        }
    }
    
    return {PreOrder, InOrder};
}

void GetPostOrder(vector<int> PreOrder, int preL, vector<int> InOrder, int inL, vector<int>& PostOrder, int postL, int N)
{
    if (N == 0)  return;
    if (N == 1) {
        PostOrder[postL] = PreOrder[preL];
        return;
    }
    
    auto Root = PreOrder[preL];
    PostOrder[postL + N - 1] = Root;
    
    //在中序序列上找出root的位置
    int i = 0;
    while (i < N) {
        if (InOrder[inL + i] == Root) break;
        i++;
    }
    
    //计算出root结点左右的子树个数
    int L = i, R = N - i - 1;
    //递归
    GetPostOrder(PreOrder, preL + 1, InOrder, inL, PostOrder, postL, L);
    GetPostOrder(PreOrder, preL + 1 + L, InOrder, inL + L + 1, PostOrder, postL + L, R);
    
}





















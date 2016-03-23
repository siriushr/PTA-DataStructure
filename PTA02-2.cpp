//
//  new.cpp
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/12.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    char head[8], next[8];
    int value;
};
Node NodeList[100001];

int main() {
    int begin, n, k;
    cin >> begin >> n >> k;
    map<int,pair<int, int>> mp;
    
    for (int i = 0; i < n; ++i) {
        cin >> NodeList[i].head >> NodeList[i].value >> NodeList[i].next;
        mp[atoi(NodeList[i].head)] = make_pair(atoi(NodeList[i].next), i);
    }
    
    vector<int> vec;
    while (begin != -1) {
        vec.push_back(mp[begin].second);
        begin = mp[begin].first;
    }
    
    for(int i = 0; i+k <= vec.size(); i+=k)
        reverse(vec.begin()+i, vec.begin()+i+k);
    
    printf("%s %d ", NodeList[vec[0]].head, NodeList[vec[0]].value);
    for (int i = 1; i < vec.size(); i++)
        printf("%s\n%s %d ", NodeList[vec[i]].head, NodeList[vec[i]].head, NodeList[vec[i]].value);
    printf("-1\n");
    
    return 0;
}

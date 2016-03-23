#include <iostream>
using namespace std;

class Stack {
private:
    int* elem;
    int _top;
public:
    Stack(int s = 10, int sentinel = 0) {
        elem = new int[s+1];
        _top = 0;
        elem[0] = sentinel;
    }
    ~Stack() {
        if(elem) delete[] elem;
    }
    
    bool empty() { return !_top; }
    int size() { return _top; }
    void push(int value) { elem[++_top] = value; }
    int pop() {
        if (empty()) return _top;
        else return _top--;
    }
    int top() { return elem[_top]; }
};

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    
    
    for (int i = 0; i < k; i++) {   //一共k组数据，循环k次
        int b[n];
        int a = 1;
        bool flag = true;
        Stack s(n);
        for (int x = 0; x < n; x++)
            cin >> b[x];
        
        for (int j = 0; j < n; j++) {
            while (s.top() < b[j]) {
                s.push(a++);
            }
            if (s.size() > m || s.top() > b[j]) {
                flag = false;
                break;
            }
            if (s.top() == b[j])
                s.pop();
        }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}




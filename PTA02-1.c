//
//  PTA02-1.c
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/12.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef;
    int expo;
    Polynomial link;
};

Polynomial ReadPoly();
Polynomial Mult(Polynomial, Polynomial);
Polynomial Add(Polynomial, Polynomial);
void PrintPoly(Polynomial);
void Attach(int, int, Polynomial*);

int main() {
    Polynomial p1, p2, pp, ps;
    
    p1 = ReadPoly();
    p2 = ReadPoly();
    pp = Mult(p1, p2);
    ps = Add(p1, p2);
    PrintPoly(pp);
    PrintPoly(ps);
    
    return 0;
}

Polynomial ReadPoly() {
    int n, c, e;
    Polynomial p, front, rear;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    rear = p;
    
    scanf("%d", &n);
    
    while(n--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &rear);
    }
    
    front = p;
    p = p->link;
    free(front);
    return p;
}

void Attach(int c, int e, Polynomial *Prear) {
    Polynomial t = (Polynomial)malloc(sizeof(struct PolyNode));
    t->coef = c;
    t->expo = e;
    t->link = NULL;
    (*Prear)->link = t;
    *Prear = t;
}

Polynomial Add(Polynomial p1, Polynomial p2) {
    Polynomial t1, t2, p, front, rear;
    t1 = p1;
    t2 = p2;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    rear = p;
    
    while (t1 && t2) {
        if (t1->expo == t2->expo) {
            if (t1->coef + t2->coef != 0)
                Attach(t1->coef + t2->coef, t1->expo, &rear);
            t1 = t1->link;
            t2 = t2->link;
        } else if (t1->expo > t2->expo) {
            Attach(t1->coef, t1->expo, &rear);
            t1 = t1->link;
        } else {
            Attach(t2->coef, t2->expo, &rear);
            t2 = t2->link;
        }
    }
    
    while (t1) {
        Attach(t1->coef, t1->expo, &rear);
        t1 = t1->link;
    }
    while (t2) {
        Attach(t2->coef, t2->expo, &rear);
        t2 = t2->link;
    }
    
    front = p;
    p = p->link;
    free(front);
    return p;
}

Polynomial Mult(Polynomial p1, Polynomial p2) {
    Polynomial t1, t2, p, rear, front, t;
    int c, e;
    
    if (!p1 || !p2) {
        return NULL;
    }
    
    t1 = p1; t2 = p2;
    p = (Polynomial)malloc(sizeof(struct PolyNode));
    p->link = NULL;
    rear = p;
    
    while (t2) {
        Attach(t1->coef*t2->coef, t1->expo+t2->expo, &rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    
    while (t1) {
        t2 = p2;
        rear = p;
        while (t2) {
            c = t1->coef * t2->coef;
            e = t1->expo + t2->expo;
            while (rear->link && rear->link->expo > e) {
                rear = rear->link;
            }
            if (rear->link && rear->link->expo == e) {
                if (rear->link->coef + c)
                    rear->link->coef += c;
                else {
                    t = rear->link;
                    rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expo = e;
                t->link = rear->link;
                rear->link = t;
                rear = rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    front = p;
    p = p->link;
    free(front);
    return p;
}

void PrintPoly(Polynomial p) {
    int flag = 0;
    
    if (!p) {
        printf("0 0\n");
        return;
    }
    
    while (p) {
        if (!flag)
            flag = 1;
        else
            printf(" ");
        printf("%d %d", p->coef, p->expo);
        p = p->link;
    }
    printf("\n");
}
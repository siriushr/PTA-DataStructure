//
//  W1L1-2.c
//  PTA-Data Structure
//
//  Created by 黄然 on 16/3/2.
//  Copyright © 2016年 黄然. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXK 1e5

clock_t start, stop;

double f1(double x);
double f2(double x);
double count_time(double (*f)(double x), double x);

int main() {
    double x;
    scanf("%lf", &x);
    
    //normal way
    printf("f1_duration = %.2lf\n", count_time(&f1, x));
    
    //faster way
    printf("f2_duration = %.2lf\n", count_time(&f2, x));
    
    return 0;
}

double f1(double x)
{
    double p;
    for (int i = 1; i <= 100; ++i)
        p += pow(x, i) / i;
    return p;
}

double f2(double x)
{
    double p = 1.0/100;
    for (int i = 99; i >= 1; --i)
        p += (double)1/i + x * p;
    p = 1 + x * p;
    return 0;
}

double count_time(double (*f)(double x), double x)
{
    double duration;
    start = clock();
    for (int i = 0; i < MAXK; ++i)
        f(x);
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK;
    return duration;
}
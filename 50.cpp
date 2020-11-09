#include<bits/stdc++.h>
class Solution {
public:
    double func(double x, long long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        double a = func(x, n /2);
        return n % 2== 0?a * a : a * a * x;
    }
    double myPow(double x, int n) {
        long long m = n;
        return m > 0 ? func(x, m) : (1 / func(x, -m));
    }
};
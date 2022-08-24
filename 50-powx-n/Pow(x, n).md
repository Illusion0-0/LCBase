#### [Pow(x, n)](https://leetcode.com/problems/powx-n/)

1. ` x*x*x*....n times ` which takes O(n) time

2. It can be calculated in O(log(n)) time using: [Binary Ecponentiation](https://cp-algorithms.com/algebra/binary-exp.html#effective-computation-of-large-exponents-modulo-a-number)
   Log(n) because length of binary bits of n is *floor(log(n))+1*

```cpp
double myPow(double x, int n) {
        double res=1;
        if(n<0){x=1/x;n=abs(n);}
        while(n>0){
            if(n&1){
                res=res*x;
            }
            x=x*x;
            n =n>>1;
        }
        return res;
}
```

```text
Time Complexity: O(log(n))
Space Complexity: O(1)
```
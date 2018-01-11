# Problem 372 - Super Pow

Your task is to calculate $a^b$ mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example 1:
```text
a = 2
b = [3]

Result: 8
```

Example 2:
```text
a = 2
b = [1,0]

Result: 1024
```

### Math-based solution

[The original explanation](https://leetcode.com/problems/super-pow/discuss/84466/).

Knowledge base:
- [Euler's Theorem](https://en.wikipedia.org/wiki/Euler's_theorem)
- [Fermat's little theorem](https://en.wikipedia.org/wiki/Fermat's_little_theorem)

Preliminaries:

1. Euler's totient function:
$$
\phi(m*n)=\phi(m)\phi(n), when\ gcd(m,n)=1
$$

1. If x is a prime number, then:
$$
\phi(x)=x(1-\frac{1}{x})
$$

1. If a and n are coprime positive number, then:
$$
a^{\phi(n)}=n*k+1
$$
$$
a^{\phi(n)}mod\ n=1
$$

1337 has two divisors 7 and 191, and both of them are prime, thus:
$$
\phi(1337)=\phi(7)\phi(191)\ formula(1)
$$
$$
\phi(7)=7*(1-\frac{1}{7})=6,\ \phi(191)=190\ formula(2)
$$
$$
\phi(1337)=1140
$$

1. If x has both divisor 7 and 191, then `x % 1337 == 0`.
1. If x has neither 7 nor 191, that means x and 1337 are coprime.
Then forumula (3) applied:
$$
a^b\%1337=a^{b/\phi(1337)*\phi(1337)+b\%\phi(1337)}\%1337=()(a^{1140})^{b/1140}a^{b\%1140})\%1337
$$
Let `k` be `b\1140`, note that a<sup>1140</sup>%1337=1 based on formula (3):
$$
(((a^{1140})^k\%1337)(a^{b\%1140}\%1337))\%1337
$$
Finally:
$$
a^b\%1337=a^{b\%1140}\%1337
$$

So we can start solving this problem based on this mathematical solution.
 
### Easy-to-understand solution

[Original explanation](https://leetcode.com/problems/super-pow/discuss/84472)

Base:
$$
If\ x=a*b
$$
Then:
$$
x\%k=((a\%k)(b\%k))\%k
$$
So we can always take last digit of exponent and recurse this process.
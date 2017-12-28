# Problem 278 - First Bad Version
I misunderstood the requirement of problem and failed to analyse the conditions. I try to solve the problem with a hash table to reduce calls to the given api.
The key condition is "Since each version is developed based on the previous version, all the versions after a bad version are also bad.".
It means if version k(k <= n) is bad version, k..n versions are bad version. This trait is suitable for binary search algorithm.
So binary search algorithm is the solution to this problem.
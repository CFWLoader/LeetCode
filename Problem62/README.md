# Problem 62 - Unique Paths

I have learnt this problme in former Combination Math Lecture. So I don't wanna think this problme by myself. So the solution directly use the conclusion in Combination.

This problem assumes a `m * n` grid matrix. Starts at (0,0) and ends at (m,n). This means all paths would cost `N = m + n - 2` steps to reach goal. So there is `Permutation(N,N)` paths with repeats. Vertical direction would take `Permutation(m-1,m-1)` repeat paths and Horizonal direction would take `Permutaion(n-1,n-1)`. Do `P(N,N)/P(n-1,n-1)`, then we exclude the repeat in horizonal. Thus we apply `P(N,N)/(P(n-1,n-1)*P(m-1,m-1))` we can get 2-dimensional paths combination.

Let `k = m - 1`, considering `n - 1 = N - (m - 1)`, thus the formula can transform to `P(N,N)/(P(N-k,N-k)*P(k,k))`. Think about the definition of combination, the final formula becomes to `C(N,k)`.

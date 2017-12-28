# Problem 240 - Search a 2D Matrix II

I was considering using 2D dichotomy. But I found out it may not be correct. Then there is a `O(m+n)` solution in the discuss and I took it.

Here is the original analysis:
```
We start search the matrix from top right corner, initialize the current position to top right corner, if the target is greater than the value in current position, then the target can not be in entire row of current position because the row is sorted, if the target is less than the value in current position, then the target can not in the entire column because the column is sorted too. We can rule out one row or one column each time, so the time complexity is O(m+n).
```

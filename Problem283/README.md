# Problem 283 - Move Zeroes
At the first time I met this problem, there were two solution stroke my brain:<br/>
    1. Directly exchange elements' position.
    2. Use C++ STL remove_if() function.
Solution 1 seems complex for me because extra space for algorithm is forbidden.
After I coded Solution 2, I found how to code Solution 1. We can directly discard zeroes. After the rearrangement, we can 
"recover" the zeroes in the last n slots in the array.
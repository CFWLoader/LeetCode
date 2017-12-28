# Problem 260 - Single Number III
Solution idea:
-   Use exclusive or to sum the array and the result is the exclusive or sum of this two single numbers.
-   Calculate the lowest bit values 1 in the exclusive or sum.
-   Use the flag in step 2 to split the array to two arrays.
-   Use exclusive or to sum this two split arrays respectively and find the results.
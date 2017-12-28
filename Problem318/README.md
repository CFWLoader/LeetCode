# Problem 318 - Maximum Product of Word Lengths
Excellent Solution idea:
-   Due to the words consist of lower cases, use bits to record which character presents in the word.(State Compress)
-   Use _And_ operation to test two words has common characters.
-   If the result is equals to zero, calculate the product of this two words. Or the product is zero.
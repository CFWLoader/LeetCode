# Problem 160 - Intersection of Two Linked Lists
Required algorithm performance:<br/>
T(n) = O(n), S(n) = O(1).<br/>
Algorithm details:
1. Find the sizes of two linked lists. If their tails are different, return null.
1. Calculate the deviation(D) of two linked lists and let the longer linked list's pointer point to the next Dth node.
1. Iterate two linked lists simultaneously until find the common node.
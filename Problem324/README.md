# Wiggle Sort II
### Problem
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....<br/>
### File description
Solution.py contains the TLE codes.<br/>
Solution1.py records the AC codes.<br/>
### Heuristic of Solution
1. General heuristic is like counting sort, saving the frequency of numbers.
1. Considering the requirement, we need to solve core issue -- arranging lesser number in even index slots and greater number in odd index slots.
1. If we always arrange minimum number or maximum number, algorithm may fails because the rest numbers are equals.
1. So the notions 'lesser number' and 'greater number' are  important.
1. We keep the number being arranged in current iteration is lightly lesser or greater the medium number, that why we need statistic of numbers.
1. The natural disadvantage of this heuristic is that it must fix the situation that the quantity of 'lesser number' is equals to 'greater numbers''s, the
number to be arranged is hard to determined.
1. So there is an extra step to judge the number in this situation:
    2. If the slot should be filled with 'lesser number', we choose the left one of the medium.
    2. If the slot should be filled with 'greater number', we choose the right one of the medium.
More details in source codes.
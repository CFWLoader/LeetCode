# Problem 263 - Ugly Number
TLE-Solution is my own trivial idea, it brutally finds the factors of the number via searching the prime numbers. So the prime number searching algorithm will cause TLE.
The good solution's idea is only concern about calculating the factor 2, 3 and 5. If the number can't be perfectly divided by them, it must be no ugly number.
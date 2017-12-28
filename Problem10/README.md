# Problem 10 - Regular Expression Matching
I failed to solve this problem by myself.<br/>
The accepted solution's idea:<br/>
1. If the next character of p is NOT '*', then it must match the current character of s. Continue pattern matching with the next character of both s and p.
1. If the next character of p is '*', then we do a brute force exhaustive matching of 0, 1, or more repeats of current character of p... Until we could not match any more characters.
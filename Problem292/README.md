#   Nim Game
I try to solve it by myself and figure out a TLE solution.<br/>
Foremost, solve this problem requires the base that inferring the winning situation.<br/>
Let's start.<br/>
1. There is a stone, we get it and win.
2. There are two stones, we get them and win.
3. There are three stones, we get them and win.
4. There are four stones, we get 1-3 and nim win.
5. There are five stones, we get 1 and nim will face situation 4.
6. There are six stones, we get two and nim will face situation 4.
....<br/>
Above, we can infer that when there happen the number of stones is 4*x we will lose.<br/>
Other situation we can win. The strategy is keep the sum of every turn is 4.<br/>
Here we just judge we can win or not.
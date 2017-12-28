//
// Created by cfwloader on 10/16/15.
//

#ifndef PROBLEM292_BADSOLUTION_H
#define PROBLEM292_BADSOLUTION_H

/**
 * This is a TLE solution with my thoughts.
 * Mainly use alpha-beta cut-off method.
 */
class BadSolution
{
public:

    bool canWinNim(int n)
    {
        return winInMyTurn(n);
    }

    bool winInMyTurn(int n)
    {
        if (n <= 3) return true;

        return winInNimTurn(n - 1) && winInNimTurn(n - 2) && winInNimTurn(n - 3);
    }

    bool winInNimTurn(int n)
    {
        if(n <= 3) return false;

        return winInMyTurn(n - 1) || winInMyTurn(n - 2) || winInMyTurn(n - 3);
    }

private:
};

#endif //PROBLEM292_BADSOLUTION_H

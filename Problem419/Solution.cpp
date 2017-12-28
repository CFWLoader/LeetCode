class Solution
{
public:
	int countBattleships(vector<vector<char>>& board)
	{
		int count = 0, rowSize = board.size();

		for(int i = 0; i < rowSize; ++i)
		{
			int columnSize = board[i].size();

			for(int j = 0; j < columnSize; ++j)
			{
				if(board[i][j] == '.')
				{
					continue;
				}

				if(i > 0 && board[i - 1][j] == 'X')
				{
					continue;
				}

				if(j > 0 && board[i][j - 1] == 'X')
				{
					continue;
				}

				++count;
			}
		}

		return count;
	}
};

class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int res = 0;
		if (A.empty() || A[0].empty())
		{
			return res;
		}
		for (int i = 0; i < A[0].length(); ++i)
		{
			for (int j = 1; j < A.size(); ++j)
			{
				if (A[j][i] < A[j - 1][i])
				{
					++res;
					break;
				}
			}
		}
		return res;
	}
};
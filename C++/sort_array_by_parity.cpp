class Solution
{
public:
	vector<int> sortArrayByParity(vector<int>& A)
	{
		int i = 0, j = A.size() - 1;
		for (int k = 0; k < A.size(); )
		{
			if (i >= j)
			{
				break;
			}
			if (A[k] % 2 == 0)
			{
				++i;
				++k;
			}
			else
			{
				A[k] ^= A[j];
				A[j] ^= A[k];
				A[k] ^= A[j];
				--j;
			}
		}
		return A;
	}
};
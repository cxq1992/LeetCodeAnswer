class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		std::vector<int> res;
		res.reserve(A.size());
		int i = 0;
		for (; i < A.size(); ++i)
		{
			if (A[i] >= 0)
			{
				break;
			}
		}
		for (int j = i - 1; j >= 0 || i < A.size();)
		{
			if (j < 0)
			{
				res.emplace_back(A[i] * A[i]);
				++i;
				continue;
			}
			if (i >= A.size())
			{
				res.emplace_back(A[j] * A[j]);
				--j;
				continue;
			}
			int tmp_squre_i = A[i] * A[i];
			int tmp_squre_j = A[j] * A[j];
			if (tmp_squre_j < tmp_squre_i)
			{
				res.emplace_back(tmp_squre_j);
				--j;
			}
			else if (tmp_squre_i < tmp_squre_j)
			{
				res.emplace_back(tmp_squre_i);
				++i;
			}
			else
			{
				res.emplace_back(tmp_squre_i);
				res.emplace_back(tmp_squre_i);
				--j;
				++i;
			}
		}
		return std::move(res);
	}
};
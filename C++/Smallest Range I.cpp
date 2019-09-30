class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int min_num = INT_MAX, max_num = INT_MIN;
		for (int x : A)
		{
			min_num = std::min(min_num, x);
			max_num = std::max(max_num, x);
		}
		min_num += K;
		max_num -= K;
		return min_num >= max_num ? 0 : max_num - min_num;
	}
};
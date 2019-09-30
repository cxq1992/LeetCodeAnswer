class Solution {
public:
	int heightChecker(vector<int>& heights) {
		std::vector<int> tmp(heights.begin(), heights.end());
		std::sort(tmp.begin(), tmp.end());
		int res = 0;
		for (int i = 0; i < heights.size(); ++i)
		{
			if (heights[i] != tmp[i])
			{
				++res;
			}
		}
		return res;
	}
};
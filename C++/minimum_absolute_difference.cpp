class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		std::vector<std::vector<int>> res;
		std::sort(arr.begin(), arr.end());
		int global_min = INT_MAX;
		for (int i = 1; i < arr.size(); ++i)
		{
			int tmp_min = arr[i] - arr[i - 1];
			if (tmp_min > global_min)
			{
				continue;
			}
			if (tmp_min < global_min)
			{
				res.clear();
				global_min = tmp_min;

			}
			
			res.emplace_back(std::vector{ arr[i - 1], arr[i] });
		}
		return std::move(res);
	}
};
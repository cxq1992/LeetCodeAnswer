class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		std::unordered_map<int, int> counter_map;
		for (int integer : arr)
		{
			++counter_map[integer];
		}
		std::unordered_set<int> counter_set;
		for (auto& item : counter_map)
		{
			if (counter_set.find(item.second) != counter_set.end())
			{
				return false;
			}
			counter_set.insert(item.second);
		}
		return true;
	}
};
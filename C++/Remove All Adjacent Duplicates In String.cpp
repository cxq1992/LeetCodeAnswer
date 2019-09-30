class Solution {
public:
	string removeDuplicates(string S) {
		std::string res;
		for (char ch : S)
		{
			bool same = false;
			while (!res.empty() && res.back() == ch)
			{
				same = true;
				res.pop_back();
			}
			if (!same)
			{
				res.push_back(ch);
			}
		}
		return res;
	}
};
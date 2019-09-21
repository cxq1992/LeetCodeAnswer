class Solution
{
public:
	string removeOuterParentheses(string S)
	{
		string res;
		int left_side = 0;
		for (char ch : S)
		{
			if (!left_side)
			{
				++left_side;
				continue;
			}
			if (ch == ')')
			{
				--left_side;
				if (!left_side)
				{
					continue;
				}
			}
			if (ch == '(')
			{
				++left_side;
			}
			res.push_back(ch);
		}
		return res;
	}
};
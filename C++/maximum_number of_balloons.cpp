class Solution {
public:
	int maxNumberOfBalloons(string text) {
		int chars[26] = { 0 };
		int res = 0;
		string ballon = "balloon";
		for (char ch : text)
		{
			++chars[ch - 'a'];
		}
		while (true)
		{
			int i = 0;
			for (; i < ballon.length(); ++i)
			{
				if (chars[ballon[i] - 'a']-- == 0)
				{
					break;
				}
			}
			if (i != ballon.length())
			{
				break;
			}
			++res;
		}
		return res;
	}
};
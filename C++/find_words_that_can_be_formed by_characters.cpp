class Solution {
public:
	int countCharacters(vector<string>& words, string chars) {
		int my_chars[26] = { 0 };
		for (auto ch : chars)
		{
			++my_chars[ch - 'a'];
		}
		int res = 0;
		for (auto& word : words)
		{
			int tmp_chars[26] = { 0 };
			memcpy(tmp_chars, my_chars, sizeof(my_chars));
			int i = 0;
			for (; i < word.length(); ++i)
			{
				if (tmp_chars[word[i] - 'a']-- == 0)
				{
					break;
				}
			}
			if (i == word.length())
			{
				res += word.length();
			}
		}
		return res;
	}
};
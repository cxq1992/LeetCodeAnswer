#include <string>
class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		std::vector<std::string> res;
		size_t i = 0;
		while (i < text.length() && text[i] == ' ')
		{
			++i;
		}
		while (i < text.length())
		{
			for (size_t j = 0; j < first.length() && i < text.length(); ++j)
			{
				if (text[i] != frist[j])
				{
					break;
				}
			}
			if ()
		}
		for (size_t i = 0; i < text.length(); ++i)
		{

		}
	}
};
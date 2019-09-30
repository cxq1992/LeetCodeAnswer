#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		std::unordered_set<std::string> tmp;
		for (auto& email : emails)
		{
			bool first_plus = false;
			bool find_at = false;
			std::string clean_email;
			for (auto ch : email)
			{
				if (find_at)
				{
					clean_email.push_back(ch);
					continue;
				}
				if (ch == '@')
				{
					find_at = true;
					clean_email.push_back(ch);
					continue;
				}
				if (ch == '.' || first_plus)
				{
					continue;
				}
				if (ch == '+')
				{
					first_plus = true;
					continue;
				}
				clean_email.push_back(ch);
			}
			std::cout << clean_email << std::endl;
			tmp.insert(clean_email);
		}
		return tmp.size();
	}
};

int main()
{
	std::vector<std::string> emails = { "test.email+alex@leetcode.com",
		"test.email.leet+alex@code.com" };
	std::cout << Solution().numUniqueEmails(emails) << std::endl;

}
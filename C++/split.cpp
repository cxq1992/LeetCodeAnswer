#include <iostream>
#include <string>
#include <vector>
void Split(const std::string & target, char ch, std::vector<std::string> *res)
{
	std::string tmp;
	for (auto item : target)
	{
		if (item == ch && !tmp.empty())
		{
			res->emplace_back(tmp);
			tmp = "";
		}
		tmp.push_back(ch);
	}
}

int main()
{
	std::string str = "hello,world,hihihim,  shi, sh sh,ss,";
	std::vector<std::string> res;
	Split(str, ',', &res);
	for (auto & item : res)
	{
		std::cout << item << std::endl;
	}
}
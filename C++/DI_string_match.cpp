class Solution {
public:
	vector<int> diStringMatch(string S) {
		std::vector<int> res;
		
	}
private:
	void DFS(std::string& S, std::vector<int>* res)
	{
		for (int i = 0; i < S.length(); ++i)
		{
			res->push_back(i);
			if (DFS(S, i, res))
			{
				return;
			}
			res->clear();
		}
	}

	bool DFS(std::string& S, int pos, std::vector<int>* res)
	{
		if (S.length() == res->size() - 1)
		{
			return true;
		}
		if (pos < 0 || pos >= S.length())
		{
			return false;
		}
		return S[pos] == 
	}
};
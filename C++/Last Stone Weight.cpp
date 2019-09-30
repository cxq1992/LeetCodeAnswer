#include <queue>
class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		std::priority_queue<int> p_queue(stones.begin(), stones.end());
		while (true)
		{
			if (p_queue.empty())
			{
				return 0;
			}
			if (p_queue.size() == 1)
			{
				return p_queue.top();
			}
			int diff = p_queue.top();
			p_queue.pop();
			diff -= p_queue.top();
			p_queue.pop();
			if (diff)
			{
				p_queue.push(diff);
			}
		}
		
	}
};
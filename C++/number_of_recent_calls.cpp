class RecentCounter {
public:
	RecentCounter() {

	}

	int ping(int t) {
		while (!_list.empty() && _list.front() + 3000 < t)
		{
			_list.pop_front();
		}
		_list.push_back(t);
		return _list.size();
	}
private:
	std::list<int> _list;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
#include <map>
class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    std::vector<int> res;
    std::map<int, int> num_count;
    for (auto x : arr1) {
      ++num_count[x];
    }
    for (auto x : arr2) {
      while (num_count[x]--) {
        res.emplace_back();
      }
    }
    for (auto x : num_count) {
      while (x.second--) {
        res.emplace_back(x.first);
      }
    }
    return std::move(res)
  }
};
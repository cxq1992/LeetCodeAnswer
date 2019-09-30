class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int last_even = 0, last_odd = 1;
		for (; last_even < A.size() && last_odd < A.size();)
		{
			int even_mod = A[last_even] % 2;
			int even_mod_pos = last_even % 2;
			int odd_mod = A[last_odd] % 2;
			int odd_mod_pos = last_odd % 2;
			if (even_mod == even_mod_pos && odd_mod == odd_mod_pos)
			{
				last_even += 2;
				last_odd += 2;
				continue;
			}
			if (even_mod != even_mod_pos && odd_mod != odd_mod_pos)
			{
				A[last_even] ^= A[last_odd];
				A[last_odd] ^= A[last_even];
				A[last_even] ^= A[last_odd];
				last_even += 2;
				last_odd += 2;
				continue;
			}
			if (even_mod == even_mod_pos)
			{
				last_even += 2;
			}
			if (odd_mod == odd_mod_pos)
			{
				last_odd += 2;
			}

		}
		return std::move(A);

	}
};
#include <iostream>
#include <vector>
#include<queue>
#include<map>
#include<algorithm>
#include <string>
//1. O(n)
std::vector<int> ProductExceptSelf(const std::vector<int>& nums)
{	
	int multiply_sum{1};
	for (auto num : nums)
	{
		if (num != 0)
		{
			multiply_sum *= num;
		}
	}

	std::vector<int> answer;
	auto temp = std::find(nums.begin(), nums.end(), 0);

	for (auto num : nums)
	{
		if (temp != nums.end() )
		{
			if (num != 0)
			{
				answer.push_back(0);
			}
			else
			{
				answer.push_back(multiply_sum);
			}
		}
		else
		{
			answer.push_back(multiply_sum / num);
		}
	}

	return answer;
}

//2.
//
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
//O(n)
bool IsSameBT(TreeNode* p, TreeNode* q)
{
	if (p == nullptr && p == q)
	{
		return true;
	}
	std::queue<TreeNode*> pq;
	std::queue<TreeNode*> qq;

	pq.push(q);
	qq.push(q);

	while (!pq.empty())
	{
		
		auto nodeP = pq.front();
		auto nodeQ = qq.front();

		if (nodeP->val != nodeQ->val)
		{
			return false;
		}

		pq.pop();
		qq.pop();

		if (nodeP->left) { pq.push({ nodeP->left }); }
		if (nodeP->right) { pq.push({ nodeP->right}); }

		if (nodeQ->left) { qq.push({ nodeQ->left }); }
		if (nodeQ->right) { qq.push({ nodeQ->right }); }

	}
	return true;
}
//3.
//O(n)
int GetMinMaxAggroCount(const std::vector<int> times, const std::vector<int> actions, int maxAggro)
{
	int aggro{}, indx{}, answer{}, action{};
	int maxTime = *(max_element(times.begin(), times.end()))+1;

	for (int i = 0; i < maxTime; i++)
	{
		if (aggro == 0 || aggro == maxAggro)
		{
			answer++;
		}
		if (i == times[indx])
		{
			action += actions[indx];
			indx++;
		}

		aggro += action;

		if (aggro > maxAggro)
		{
			aggro = maxAggro;
		}
		if (aggro < 0)
		{
			aggro = 0;
		}
	}

	return answer;
}
//4.
// O(n)
int PossibleWaysToClimb(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	int answer{ 1 };
	int previous{ 1 };
	int temp{};

	for (int i = 2; i < n; i++)
	{
		temp = answer;
		answer += previous;
		previous = temp;
	}
}


//5.
//O(n)
int NumberOFDecodings(std::string s)
{
	if (s[0] == '0')
	{
		return 0;
	}
	if (s.size() == 1)
	{
		return 1;
	}

	int num{};
	int answer{1};
	int previous{ 1 };
	int temp{};

	for (auto i = 0; i < s.size()-1; i++)
	{
		num = (s[i] - 48) * 10 + s[i+1]- 48;
		if (num <= 26)
		{
			if (s[i+1] != '0')
			{
				temp = answer;
				answer += previous;
				previous = temp;
			}
			else
			{
				answer = previous;
				previous = 0;
			}
		}
		else
		{
			if (s[i+1] != '0')
			{
				previous = answer;
			}
			else
			{
				return 0;
			}
		}
	}

	return answer;
}

int main()
{
	/*for (auto e : ProductExceptSelf({ -1,1,0,3,-3 }))
	{
		std::cout << e << ", ";
	}*/

	//std::cout << GetMinMaxAggroCount({ 1,4,5,10,11 }, { 4,-2,-5,4,1 }, 10);

	std::cout << PossibleWaysToClimb(2);


	//std::string s{ "110" };
	//std::cout << NumberOFDecodings(s);

}

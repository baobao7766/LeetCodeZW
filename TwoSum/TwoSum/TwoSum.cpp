//TwoSum:
//Given an array of integers, find two numbers such that they add up to a specific target number.
//The function twoSum should return indices of the two numbers such that they add up to the target, 
//where index1 must be less than index2. 
//Please note that your returned answers (both index1 and index2) are not zero-based.
//You may assume that each input would have exactly one solution.
//Input: numbers={2, 7, 11, 15}, target=9
//Output: index1=1, index2=2

#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

//class Solution {
//public:
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        vector<int> *index;
//		index = new vector<int>(2);
//		vector<int>::iterator iter = index->begin();
//
//		for (*iter = 0; (*iter != numbers.size()) && (numbers[*iter] <= target); ++*iter){
//			for (*(iter+1) = *iter + 1; *(iter+1) != numbers.size() && (numbers[*(iter+1)] <= target); ++*(iter+1)){
//				if (numbers[*iter] + numbers[*(iter+1)] == target)
//					return *index;
//			}
//		}
//		return *index;
//    }
//}; 

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> index;
		int i, sum;
		map<int,int> hashMap;
		for (i = 0; i < numbers.size(); ++i){
			if (!hashMap.count(numbers[i]))
				hashMap.insert(pair<int,int> (numbers[i],i));
			if (hashMap.count(target-numbers[i])){
				int n = hashMap[target-numbers[i]];
				if (n < i){
					index.push_back(n+1);
					index.push_back(i+1);
					return index;
				}
			}
		}
		return index;
	}
};


int main ()
{
	int ini[] = {2,7,8,9,2};
	vector<int> numbers;
	cout << "The sequence is: " << endl;
	for(int ival=0; ival!=(sizeof(ini)/sizeof(ini[0])); ++ival){
		numbers.push_back(ini[ival]);
		cout << ini[ival] << ' ';
	}
	cout << endl;

	int target = 9;

	Solution Sol;
	cout << "The index of numbers you want are: " << 
		Sol.twoSum(numbers, target)[0] << ',' << 
		Sol.twoSum(numbers, target)[1] << endl;
	system("pause");
	return 0;
}
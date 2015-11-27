#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord.size()==0||endWord.size()==0) return 0;

		queue<string> Q;
		Q.push(beginWord);
		Q.push(" ");

		int d = 1;
		if(wordDict.find(beginWord) != wordDict.end()){
			wordDict.erase(beginWord);
		}
		
		while(!Q.empty()){
			string str = Q.front();
			Q.pop();
			if(str != " "){
				int len = str.size();
				for(int i=0; i!=len; ++i){
					char tamp = str[i];
					for(char j='a'; j <= 'z'; ++j){
						if(j == tamp){ 
							continue;
						}else{
							str[i] = j;
							if(str == endWord) return d+1;	// �ҵ��������� ���ؾ��롣
							if(wordDict.find(str) != wordDict.end()){ // �� wordDict ���ҵ��� str��
								Q.push(str);
								wordDict.erase(str);
							}//end if
						}//end if-else
					}//end for
					str[i] = tamp;
				}//end for
			}else if(!Q.empty()){
				++d;
				Q.push(" ");
			}
			return 0;

		}//end while
    }
}; 
///////////////////////////////////////////////////////////////////

//int main ()
//{
//	/* definition */
//	string str[] = {"hot","dog"};
//	int len = sizeof(str)/sizeof(str[0]);
//	unordered_set<string> wordDict(str, str + len);
//
//	/* processing */
//	Solution solution;
//	int d = solution.ladderLength("hot","dog", wordDict);
//	cout << d << endl;
//	/* print */
//	
//
//	system("pause");
//	return 0;
//}
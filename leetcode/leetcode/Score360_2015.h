#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void Classify(string str)
{
	vector<int> score;
	int sum = 0;
	for(size_t i=str.length(); i!=0; --i){
		if(str[i-1]==' '){
			score.push_back(atoi(str.substr(i-1).c_str()));
			str.erase(i,str.npos);
		}
	}
	score.push_back(atoi(str.c_str()));
	
	vector<int>::iterator it_score = score.begin();
	while(it_score != score.end()){
		sum += *it_score;
		++it_score;	
	}

	if((score[0]<90)|(score[1]<90)|(score[2]<60)|(score[3]<60)|(sum<310)){
		cout << "Fail" << endl;
	}else if(sum < 350){
		cout << "Zifei" << endl;
	}else{
		cout << "Gongfei" << endl;
	}
}


//int main(int argc ,char* argv[])
//{
//    int nline = 0;
//	string str;
//	cin >> nline;
//	vector<string> vecStr;
//
//	getline(cin, str);	//“∆∂ØIO÷∏’Î
//	for(int i=0; i!=nline; ++i){
//		getline(cin, str);
//		vecStr.push_back(str);
//		//cout << "str:" << str << endl; //test
//	}
//
//	vector<string>::iterator it = vecStr.begin();
//	while(it != vecStr.end()){
//		Classify(*it);
//		++it;
//	}
//
//	system("pause");
//	return 0;
//}
	
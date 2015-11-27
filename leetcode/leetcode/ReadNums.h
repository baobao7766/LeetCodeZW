//=======================================================
// int ReadNums(int *a)
// 从标准行中读入一组数，每个数之间以空格或者其他字符隔开，
// 读入这些数字并保存到整形数组之中
// 注意：数组 a 的大小要大于输入的最大长度
//=======================================================

#include <iostream>

using namespace std;

// 方法一：
static inline int ReadNums1(int *a)
{
    int i = 0;
    char c;
    while((c=getchar())!='\n')
    {
        if(c>='0'&&c<='9')
        {
            ungetc(c,stdin);	//把 param1(c) 写入到流 param2(stdin) 中
            cin>>a[i++];		//再把 stdin 中的字符写入整形数组
        }
    }
	return i;
}

// 方法二：
static inline int ReadNums2(int *a)
{
    int i = 0;
    char c;
    string str = "";
    while((c=getchar())!='\n')
    {
        if(c>='0'&&c<='9')
        {
            str += c;
        }
        else if(c ==' ')
        {
            a[i++] = atoi(str.c_str());	//atoi():将字符数组转化为整形，param 必须为 const char*
            str = "";
        }
    }
	a[i++] = atoi(str.c_str());
    str = "";
	return i;
}

// 测试函数：
static inline void testReadNums()
{
	int a[50];
    int N = ReadNums2(a);

	//test ReadNums
	cout << "Show array \"a\":" << endl;
	for(int j=0; j<N; j++) {
		cout<<"a["<<j<<"]: "<<a[j]<<endl;
	}
}


////======================================================
////	This is a test file of zhouwei's leetcode homework.
////	Author: baobao7766
////	Time:   2015/04/17
////======================================================
//#include <iostream>
//#include <string>
//#include <vector>
//#include <stack>
//
//#include "ReadNums.h"
//
//using namespace std;
//
//
//int main(int argc ,char* argv[])
//{
//	int arr[50];
//	int n = 0;
//	char c;
//	int *p1 = arr;
//	int *p2 = arr+1;
//	int temp = 0;
//	int cnt = 0;
//
//	while((c=getchar())!='\n')
//	{
//		if(c>='0' && c<='9')
//		{
//			ungetc(c,stdin);
//			cin >> arr[n++];
//		}
//	}
//
//	cout << "Show read array:" << endl;
//	for(int i=0; i<n; i++)
//	{
//		cout << "arr[" << i << "]: " << arr[i] << endl;
//	}
//
//	cnt = 0;
//	while(cnt<n/2 && p1 != NULL && (p1+2)!=NULL){
//		if(*p1 > *(p1+2)){
//			temp = *p1;
//			*p1 = *(p1+2);
//			*(p1+2) = temp;
//		}else{
//			p1 += 2;
//		}
//		cnt++;
//	}
//
//	cnt = 0;
//	while(cnt<n/2 && (p2+2) != NULL && (p2+2) != NULL){
//		if(*p2 > *(p2+2)){
//			temp = *p2;
//			*p2 = *(p2+2);
//			*(p2+2) = temp;
//		}else{
//			p2 += 2;
//		}
//		cnt++;
//	}
//
//	cout << "Show read array after processing: " << endl;
//	for(int i=0; i<n; i++)
//	{
//		cout << "arr[" << i << "]: " << arr[i] << ' ';
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
//	
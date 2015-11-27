//=======================================================
// int ReadNums(int *a)
// �ӱ�׼���ж���һ������ÿ����֮���Կո���������ַ�������
// ������Щ���ֲ����浽��������֮��
// ע�⣺���� a �Ĵ�СҪ�����������󳤶�
//=======================================================

#include <iostream>

using namespace std;

// ����һ��
static inline int ReadNums1(int *a)
{
    int i = 0;
    char c;
    while((c=getchar())!='\n')
    {
        if(c>='0'&&c<='9')
        {
            ungetc(c,stdin);	//�� param1(c) д�뵽�� param2(stdin) ��
            cin>>a[i++];		//�ٰ� stdin �е��ַ�д����������
        }
    }
	return i;
}

// ��������
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
            a[i++] = atoi(str.c_str());	//atoi():���ַ�����ת��Ϊ���Σ�param ����Ϊ const char*
            str = "";
        }
    }
	a[i++] = atoi(str.c_str());
    str = "";
	return i;
}

// ���Ժ�����
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
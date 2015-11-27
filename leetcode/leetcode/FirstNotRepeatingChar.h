//==================================================
//	第一个只出现一次的字符
//==================================================
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

char FirstNotRepeatingChar(const char* pStr)
{
    if(pStr == NULL)
        return '\0';

	char outstr = 0;
    const int tableSize = 26;
	unsigned int hashTable[tableSize];

	for(unsigned int i=0; i<tableSize; ++i)
		hashTable[i] = 0;

	const char* pHashKey = pStr;
    while(*pHashKey != '\0')
        hashTable[*(pHashKey++)-'a'] ++;

	pHashKey = pStr;
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey - 'a'] == 1)
            return (*pHashKey);

		pHashKey++;
    }

    return '\0';
} 

int test_FirstNotRepeatingChar()
{
	/* definition */
	int T = 0, i = 0;
	string str;
	vector<char> outputs;
	cin >> T;

	getline(cin,str);
	for(i=0; i<T; ++i)
	{
		getline(cin,str);
		outputs.push_back(FirstNotRepeatingChar(str.c_str()));
	}

	vector<char>::iterator it = outputs.begin();
	while(it != outputs.end()){
		cout << *it << endl;
		++it;
	}

	return 0;
}
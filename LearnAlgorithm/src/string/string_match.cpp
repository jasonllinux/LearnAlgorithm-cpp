#include "string_match.h"

#include <iostream>
using namespace std;


//简单的匹配方法
void nativeStringMatch(char* target, char* pattern) {
	int tarLen = 0;        // Length of Target
	int patLen = 0;        // Length of Pattern

	//计算pattern的长度
	while ('\0' != pattern[patLen]) {
		patLen++;
	}
	//从target字符串 中遍历
	while ('\0' != target[tarLen]) {
		int tmpTarLen = tarLen;

		for (int i = 0; i < patLen; i++) {
			if (target[tmpTarLen++] != pattern[i])
				break;
			if (i == patLen-1)
				cout << "Native String Matching,pattern occurs with shift "
						<< tarLen << endl;
		}

		tarLen++;
	}
}

/*TODO 缺陷
 * 如果 target 比 pattern 长度还小
 */

//-------------KMP字符串匹配方法-----------------------------------------------------
//计算前缀函数
void CptPfFunc(char Pattern[], int PrefixFunc[]) {
	int iLen = 0;    //pattern 的长度
	while ('\0' != Pattern[iLen]) {
		iLen++;
	}
	int LOLP = 0;     // Length of longest prefix
	PrefixFunc[1] = 0;

	for (int NOCM = 2; NOCM < iLen + 1; NOCM++) // NOCM represent the number of characters matched
			{
		while (LOLP > 0 && (Pattern[LOLP] != Pattern[NOCM - 1])) {
			LOLP = PrefixFunc[LOLP];
		}
		if (Pattern[LOLP] == Pattern[NOCM - 1]) {
			LOLP++;
		}
		PrefixFunc[NOCM] = LOLP;
	}
}

void kmpStringMatch(char* target, char* pattern) {
	int MAX_SIZE = 256;
	int prefixFunc[MAX_SIZE];  //前缀函数

	int TarLen = 0;
	int PatLen = 0;

	//计算两个字符串的长度 ?? 是否用strlen代替
	while ('\0' != target[TarLen])
		TarLen++;

	while ('\0' != pattern[PatLen])
		PatLen++;

	// 计算pattern的前缀函数
	CptPfFunc(pattern, prefixFunc);

	int NOCM = 0;     // Number of characters matched

	for (int i = 0; i < TarLen; i++) {
		while (NOCM > 0 && pattern[NOCM] != target[i])
			NOCM = prefixFunc[NOCM];
		if (pattern[NOCM] == target[i])
			NOCM++;
		if (NOCM == PatLen) {
			cout << "KMP String Matching,pattern occurs with shift "
					<< i - PatLen + 1 << endl;
			NOCM = prefixFunc[NOCM];
		}
	}
}


//===================================Test Cases
void test_string_match() {
	char target[] = "hithisismypcandpcpc";
	char pattern[] = "and";
	nativeStringMatch(target, pattern);
	kmpStringMatch(target, pattern);
}



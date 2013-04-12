#include "string_util.h"
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void test_itoa();
void test_atoi();
void test_string_copy();
void test_string_match();
void test();

int main(void) {

//	test_atoi();
//	test_itoa();
//	test();
	test_string_copy();
	test_string_match();
}

void test() {
	printf("string\n");
	char str[] = "";
	int num = 98765;
	string_itoa(num, str);
	printf("string: %s", str);
}

void test_string_copy() {
	char src[] = "hello";
	char dest[6];
	string_copy(dest, src);
	printf("dest: %s", dest);
}

void test_itoa() {
	int num = 12345, j = 0, i = 0;
	char temp[7], str[7];

	while (num) {
		temp[i] = num % 10 + '0';
		i++;
		num = num / 10;
	}

	temp[i] = 0;
	printf("temp = %s \n", temp);
	i = i - 1;
	printf("temp = %d \n", i);
	while (i >= 0) {
		str[j] = temp[i];
		j++;
		i--;
	}
	str[j] = 0;
	printf("string: %s \n", str);

}

void test_atoi() {
	int i = 0, sum = 0;
	char temp[7] = { '1', '2', '3', '4', '5', '6', '\0' };
	while (temp[i]) {
		sum = sum * 10 + (temp[i] - '0');
		i++;
	}
	printf("sum = %d \n", sum);

}

void string_itoa(int num, char s[]) {
	int i, j, sign;
	if ((sign = num) < 0) //记录符号
		num = -num; //使n成为正数
	i = 0;
	do {
		s[i++] = num % 10 + '0'; //取下一个数字
	} while ((num /= 10) > 0); //删除该数字
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	for (j = i; j >= 0; j--) //生成的数字是逆序的，所以要逆序输出
		printf("%c", s[j]);
}

int string_atoi(char str[]) {
//	int i, n, sign;
	int i, sum;
	/*
	 for (i = 0; isspace (s[i]); i++)
	 //跳过空白符
	 ;
	 sign = (str[i] == '-') ? -1 : 1;
	 if (str[i] == '+' || str[i] == '-') //跳过符号
	 i++;
	 */
	for (sum = 0; isdigit(str[i]); i++)
		sum = 10 * sum + (str[i] - '0'); //将数字字符转换成整形数字
//	return sign * n;
	return sum;

}

// 赋值
void string_copy(char* dest, char* src) {
	// destination 的内存必须足够大
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*src = '\0';
}

int string_comp(char* str1, char* str2) {
	return 0;
}

//----------------------字符字串算法-----------------

//最简单的匹配方法
void nativeStringMatch(char* target, char* pattern) {
	int tarLen = 0;        // Length of Target
	int patLen = 0;        // Length of Pattern

	//计算pattern的长度
	while ('\0' != pattern[patLen]) {
		patLen++;
	}
	//从target字符串 中遍历
	while ('\0' != target[tarLen]) {
		int TmpTarLen = tarLen;
		for (int i = 0; i < patLen; i++) {
			if (target[TmpTarLen++] != pattern[i])
				break;
			if (i == patLen - 1)
				cout << "Native String Matching,pattern occurs with shift "
						<< tarLen << endl;
		}
		tarLen++;
	}

}

//-------------KMP字符串匹配方法-----------------------------------------------------
//计算前缀函数
void CptPfFunc(char Pattern[], int PrefixFunc[]) {
	register int iLen = 0;    // Length of Pattern[]
	while ('\0' != Pattern[iLen]) {
		iLen++;
	}
	int LOLP = 0;     // Lenth of longest prefix
	PrefixFunc[1] = 0;

	for (int NOCM = 2; NOCM < iLen + 1; NOCM++) // NOCM represent the number of characters matched
			{
		while (LOLP > 0 && (Pattern[LOLP] != Pattern[NOCM - 1]))
			LOLP = PrefixFunc[LOLP];
		if (Pattern[LOLP] == Pattern[NOCM - 1])
			LOLP++;
		PrefixFunc[NOCM] = LOLP;
	}
}

void kmpStringMatch(char* target, char* pattern) {
	int MAX_SIZE = 256;
	int prefixFunc[MAX_SIZE];  //前缀函数

	int TarLen = 0;
	int PatLen = 0;

	// Compute the length of array Target and Pattern
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

//------------------------------------------------------------------

void test_string_match() {
	char target[] = "hithisismypcandpcpc";
	char pattern[] = "and";
	nativeStringMatch(target, pattern);
	kmpStringMatch(target, pattern);
}


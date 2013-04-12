/*
 *
 * 关于String的一些自己实现的方法
 *
 */

//字符串和整型间的转换
void string_itoa(int num, char str[]);

int string_atoi(char str[]);

//字符串的赋值
void string_copy(char* dest, char* src);

//两个字符串的长度
int string_comp(char* str1, char* str2);

//TODO 字符串的长度
int string_length(char str[]);

//-------------字符字串算法
void nativeStringMatch(char* target, char* pattern);
void kmpStringMatch(char* target, char* pattern);


//----------------测试用例-----------
void test_itoa();
void test_atoi();
void test();
void test_string_copy();
void test_string_match();

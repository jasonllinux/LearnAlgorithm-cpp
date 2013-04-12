/*
 *
 * 关于String的一些自己实现的方法
 *
 */

/*
 * Integer to ASCII
 */

void string_itoa(int num, char str[]);

int string_atoi(char str[]);


void string_copy(char* dest, char* src);

int string_comp(char* str1, char* str2);

//-------------字符字串算法
void nativeStringMatch(char* target, char* pattern);
void kmpStringMatch(char* target, char* pattern);

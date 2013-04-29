

//字符串和整型间的转换
void string_itoa(int num, char str[]);

int string_atoi(char str[]);
//----------------------------------------

//字符串的赋值
void string_copy(char* dest, char* src);

//两个字符串的长度
int string_cmp(char* str1, char* str2);

//两个字符串连接
char *string_cat(char* dst, const char* src);

//字符串的长度
int string_len(char* str);

//模拟strstr函数
char* string_str(char *str1, char *str2);



//-------------测试用例-------------------

void test_string_func();

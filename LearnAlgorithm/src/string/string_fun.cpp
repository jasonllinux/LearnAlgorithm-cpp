#include "string_fun.h"
#include "stdio.h"
#include <ctype.h>



// TODO 参数Const 赋值
void string_copy(char* dest, char* src) {
	// destination 的内存必须足够大
	while (*src != '\0') {
		*dest++ = *src++;
//		dest++;
//		src++;
	}
	*dest = '\0';
}

int string_comp(char* str1, char* str2) {
	return 0;
}

//整型转换成ASICII码
//void string_itoa(int num, char s[]) {
//	int i, j, sign;
//	if ((sign = num) < 0) //记录符号
//		num = -num; //使n成为正数
//	i = 0;
//	do {
//		s[i++] = num % 10 + '0'; //取下一个数字
////		printf("s[i]: %c \n", s[i]); //TODO 测试
//	} while ((num /= 10) > 0); //删除该数字
//	if (sign < 0)
//		s[i++] = '-';
//	s[i] = '\0';
//	for (j = i; j >= 0; j--) //生成的数字是逆序的，所以要逆序输出
//		printf("%c", s[j]);
//}

void string_itoa(int value, char *str)
{
    if (value < 0) //如果是负数,则str[0]='-',并把value取反(变成正整数)

    {
        str[0] = '-';
        value = 0-value;
    }
    int i,j;
    for(i=1; value > 0; i++,value/=10) {//从value[1]开始存放value的数字字符，不过是逆序，等下再反序过来

        str[i] = value%10+'0'; //将数字加上0的ASCII值(即'0')就得到该数字的ASCII值
//        printf("str[%d]: %c \n", i,str[i]);
    }

    for(j=i-1,i=1; j-i>=1; j--,i++) //将数字字符反序存放

    {
        str[i] = str[i]^str[j];
        str[j] = str[i]^str[j];
        str[i] = str[i]^str[j];
    }
    if(str[0] != '-') //如果不是负数，则需要把数字字符下标左移一位，即减1

    {
        for(i=0; str[i+1]!='\0'; i++)
            str[i] = str[i+1];
        str[i] = '\0';
    }
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

//-------------------------Test Cases----------------------------

void test_string_func() {
	printf("string\n");
	char str[6] = {'\0'};
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


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成随机整数
int random_int(int max_num) {
	return rand() % max_num + 1;
}

// 生成四则运算题目
void generate_question(char operator, int max_num, int use_parentheses, int use_decimal) {
	int num1, num2, answer;
	switch (operator) {
		case '+':
			num1 = random_int(max_num);
			num2 = random_int(max_num - num1);
			answer = num1 + num2;
			printf("%d + %d = %d\n", num1, num2, answer);
			break;
		case '-':
			num1 = random_int(max_num);
			num2 = random_int(num1);
			answer = num1 - num2;
			printf("%d - %d = %d\n", num1, num2, answer);
			break;
		case '*':
			num1 = random_int(max_num / 2);
			num2 = random_int(max_num / 2);
			answer = num1 * num2;
			printf("%d * %d = %d\n", num1, num2, answer);
			break;
		case '/':
			num2 = random_int(max_num / 2);
			answer = random_int(max_num / 2);
			num1 = num2 * answer;
			printf("%d / %d = %d\n", num1, num2, answer);
			break;
		default:
			printf("Invalid operator\n");
			return;
	}
}

// 生成指定数量的四则运算题�?
void generate_questions(int num_questions, char operator, int max_num, int use_parentheses, int use_decimal) {
	for (int i = 0; i < num_questions; i++) {
		generate_question(operator, max_num, use_parentheses, use_decimal);
	}
}

int main() {
	srand(time(NULL));
	int num_questions, max_num, use_parentheses, use_decimal;
	char operator;
	printf("请输入题目数量：");
	scanf("%d", &num_questions);
	printf("请输入最大数字：");
	scanf("%d", &max_num);
	printf("请选择运算符：\n");
	printf("1. +\n2. -\n3. *\n4. /\n5. 不指定\n");
	scanf("%d", &operator);
	if (operator == 5) {
		operator = '+-*/'[rand() % 4];
	} else {
		operator = "+-*/"[operator - 1];
	}
	printf("是否需要括号？�? 否，1 是）");
	scanf("%d", &use_parentheses);
	printf("是否需要小数？�? 否，1 是）");
	scanf("%d", &use_decimal);
	generate_questions(num_questions, operator, max_num, use_parentheses, use_decimal);
	return 0;
}
// stringX.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctype.h>
#include "list.h"


int myatoi(const char *str)
{
	int c;
	int total;
	int sign;

	//去掉空格
	while(isspace(*str)){
		++str;
	}

	//第1个非空字符
	c = *str++;

	//保存第1个
	sign = c;
	if (c == '-' || c == '+'){
		c = *str++;
	}

	total = 0;
	while(isdigit(c)){
		total = total * 10 + (c - '0');
		c = *str++;
	}
	if (sign == '-') {
		return -total;
	}else {
		return total;
	}
}

void link_node_print(link_node *p)
{
	int i = 1;
	while(p != NULL){
		printf("第%d个节点值为:%d\n",i++,p->value);
		p= p->next;
	}

	printf("=================\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	char *s = "-1234567s121";
	int i = myatoi(s);
	printf("%d\n",i);


	link_node *p = NULL;
	link_node_create(&p,10);
	link_node_print(p);

	link_node_insert(&p,5,100);
	link_node_print(p);

	int d = link_node_delete(&p,10);
	link_node_print(p);

	printf("按降序排列\n");
	link_node_sort_bubble(&p,true);
	link_node_print(p);

	printf("按升序排列\n");
	link_node_sort_bubble(&p,false);
	link_node_print(p);
	system("pause");
	return 0;
}


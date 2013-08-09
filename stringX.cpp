// stringX.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//ȥ���ո�
	while(isspace(*str)){
		++str;
	}

	//��1���ǿ��ַ�
	c = *str++;

	//�����1��
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
		printf("��%d���ڵ�ֵΪ:%d\n",i++,p->value);
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

	printf("����������\n");
	link_node_sort_bubble(&p,true);
	link_node_print(p);

	printf("����������\n");
	link_node_sort_bubble(&p,false);
	link_node_print(p);
	system("pause");
	return 0;
}


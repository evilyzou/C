#include <stdio.h>
#include <stdlib.h>

typedef struct link_node {
	int value;
	link_node* next;

}link_node;

//����һ��link_node����
int link_node_create(link_node **p_list,int size)
{
	link_node *p = NULL;
	*p_list =(link_node *)malloc(sizeof(link_node));
	(*p_list) ->value = 1;
	if (p_list ==NULL)
		return -1;

	(*p_list)->next = NULL;
	for (int i=1;i<size;i++){
		p =(link_node *)malloc(sizeof(link_node));
		if (p == NULL)
			return -1;

		p->value = i+1;
		p->next = (*p_list)->next;
		(*p_list)->next = p;
	}
	return 1;
}

//��ָ��λ�ò���ֵΪval�Ľڵ�
int link_node_insert(link_node **p_list,int pos,int val)
{
	link_node *p = *p_list;
	if (pos <0 )
		return -1;

	int i =0;
	while( p != NULL && i < pos-1 ){
		p = p->next;
		i++;
	}

	if (p == NULL || i > pos -1 )
		return -1;


	link_node *new_node = (link_node *)malloc(sizeof(link_node));
	if (new_node == NULL)
		return -1;

	new_node->value = val;
	new_node->next = p->next;
	p->next = new_node;

	return 1;
}

//ɾ��ָ��λ�õĽڵ�
int link_node_delete(link_node **p_list,int pos)
{
	if (pos <0 )
		return -1;

	link_node *p = *p_list;

	int i =0;
	while (p!= NULL && i < pos -1){
		p = p->next;
		i++;
	}

	if (p == NULL ||p->next == NULL || i >pos -1)
		return -1;

	link_node *delete_node = p->next;
	p->next = delete_node->next;

	free(delete_node);
	return 1;
}

//��link_node����(ð������) desc=true ����desc=false ����
void link_node_sort_bubble(link_node **p_list,bool desc)
{
	link_node *head = *p_list;
	while(head != NULL){
		link_node *p = head->next;
		while(p != NULL){
			if (!desc && head->value > p->value) {
				int val = p->value;
				p->value = head->value;
				head->value = val;
			} else if(desc && head->value < p->value) {
				int val = p->value;
				p->value = head->value;
				head->value = val;
			}	
			p = p->next;
		}
		head = head->next;
	}
}

link_node* merge(link_node **first_link,const link_node* second_link)
{
	return NULL;
}
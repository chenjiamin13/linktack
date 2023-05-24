#include <stdio.h>
#include "linklist.h"

//1.����һ���յĵ�������(��ͷ��������)
link_node_t* CreateEpLinkList()
{
	//����һ���ڵ㣬������ڵ㵱������ͷ�ڵ�
	link_list_t p = (link_list_t)malloc(sizeof(link_node_t));
	if (p == NULL) {
		printf("error\n");
		return NULL;
	}
	p->next = NULL;//ͷ�ڵ��ʼ��
	return p;
}

//4.���������ȵĺ���
int LengthLinkList(link_node_t* p)
{
	int len = 0;//���泤��
	while (p->next != NULL) {//��ͷ��ѭ������
		p = p->next;
		len++;
	}
	return len;
}

//2.���������ָ��λ�ò�������
//p���������ͷָ�� post �����λ�� data���������
int InsertIntoPostLinkList(link_node_t* p, int post, datatype data)
{
	//1.�ݴ��ж�
	if (post<0 || post>LengthLinkList(p)) {
		printf("�������\n");
		return -1;
	}
	//2.��ͷָ���ƶ���ָ�����λ�õ�ǰһ�����
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.�����½ڵ㣬�����������
	link_list_t pnew = NULL;
	 pnew= (link_list_t)malloc(sizeof(link_node_t));
	if (pnew == NULL) {
		printf("error\n");
		return NULL;
	}
	pnew->data = data;//��ʼ������ֵ��������������
	pnew->next = NULL;
	//4.���½ڵ���������У��������棬����ǰ��
	pnew->next = p->next;
	p->next = pnew;
	return 0;
}

//3.������������
void ShowLinkList(link_node_t* p) 
{
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//6.�жϵ��������Ƿ�Ϊ�� 1����� 0����ǿ�
int IsEpLinkList(link_node_t* p)
{
	return p->next == NULL;
}

//5.ɾ������������ָ��λ�õ����� post �������ɾ����λ��
int DeletePostLinkList(link_node_t* p, int post)
{
	//1.�ݴ��ж�
	if (post < 0 || post >= LengthLinkList(p) || IsEpLinkList(p)) {
		printf("error\n");
		return -1;
	}
	//2.��ͷָ���ƶ���ָ��ɾ��λ�õ�ǰһ�����
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.����ɾ��
	link_list_t pdel = NULL;
	//(1)����һ��ָ��pdelָ��ɾ��λ��
	pdel = p->next;
	//(2)�����ɾ���ڵ�
	p->next = pdel->next;
	//(3)�ͷű�ɾ���ڵ�
	free(pdel);
	pdel = NULL;
	return 0;
}

//7.�޸�ָ��λ�õ����� post ���޸ĵ�λ�� data�޸ĳɵ�����
int ChangePostLinkList(link_node_t* p, int post, datatype data)
{
	//1.�ݴ��ж�
	if (post < 0 || post >= LengthLinkList(p)) {
		printf("error\n");
		return -1;
	}
	//2.��ͷָ���ƶ����޸Ľڵ��λ��
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.�޸�����
	p->data = data;
}

//8.����ָ�����ݳ��ֵ�λ�� data�����ҵ����� //search ����
int SearchDataLinkList(link_node_t* p, datatype data)
{
	int post = 0;//��¼����λ��
	//��������
	while (p->next != NULL) {
		p = p->next;
		if (p->data == data) {
			return post;
		}
		post++;
	}
	//������û���ҵ�
	return -1;
}

//9.ɾ�����������г��ֵ�ָ������,data�������������г��ֵ�����data����ɾ��
int DeleteDataLinkList(link_node_t* p, datatype data)
{
	link_node_t* pdel = NULL;//ָ��ɾ���ڵ�
	//1.����һ��ָ��q��ָ��ͷ�ڵ���һ���ڵ㣬��q����ͷ��������ͷָ��
	link_node_t* q = p->next;
	//2.��q������ͷ������data�Ƚϣ���ͬ��ɾ��
	while (q != NULL) {
		if (q->data == data) {
			pdel = q;
			//�����ɾ���ڵ�
			p->next = pdel->next;
			free(pdel);
			pdel = NULL;
			q = p->next;
		}
		else {
			p = p->next;
			q = p->next;//qʼ�ձ���ָ��p�ڵ����һ��
		}
	}
	return 0;
}

/*
	(1) ��ͷ�ڵ��뵱ǰ����Ͽ����Ͽ�ǰ����ͷ�ڵ����һ���ڵ㣬
	��֤�����������ҵõ�������һ��q����ͷ�ڵ����һ���ڵ㣬
		�Ͽ���ǰ���൱��һ���յ�����������һ����ͷ�ĵ�������
	(2) ������ͷ��������нڵ㣬��ÿһ���ڵ㵱���½ڵ���������ͷ�ڵ����һ���ڵ�
	(ÿ�β����ͷ�ڵ����һ���ڵ�λ��--ͷ�巨)
*/
//10.ת������
void ReverseLinkList(link_node_t* p)
{
	//����һ��temp��ʱ�������ڵ�
	link_list_t temp = NULL;
	//1.�Ͽ�ǰ����ͷ�ڵ���һ���ڵ�
	link_list_t q = p->next;
	//2.�Ͽ�����
	p->next = NULL;
	//3.������ͷ����
	while (q != NULL) {
		//��ǰq��һ���ڵ㱣������
		temp = q->next;
		//�������棬����ǰ��
		q->next = p->next;
		p->next = q;
		//q�ƶ���ָ����ͷ������һ���ڵ�
		q = temp;
	}
}

//11.��յ�������
void ClearLinkList(link_node_t* p)
{
	link_list_t pdel = NULL;
	//��ͷ�ı���һ�µ�������
	while (p->next != NULL) {
		//(1)pdelֻ�뱻ɾ��λ��
		pdel = p->next;
		//(2)�����ɾ���ڵ�
		p->next = pdel->next;
		//(3)�ͷű�ɾ���ڵ�
		free(pdel);
		pdel = NULL;
	}
}





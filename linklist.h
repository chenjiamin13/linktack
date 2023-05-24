#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node_t
{
	datatype data;//������
	struct node_t* next;//ָ����,ָ������ṹ���ָ��
}link_node_t, * link_list_t;

//1.����һ���յĵ�������(��ͷ��������)
link_node_t* CreateEpLinkList();
//2.���������ָ��λ�ò�������
//p���������ͷָ�� post �����λ�� data���������
int InsertIntoPostLinkList(link_node_t* p, int post, datatype data);
//3.������������
void ShowLinkList(link_node_t* p);
//4.���������ȵĺ���
int LengthLinkList(link_node_t* p);
//5.ɾ������������ָ��λ�õ����� post �������ɾ����λ��
int DeletePostLinkList(link_node_t* p, int post);
//6.�жϵ��������Ƿ�Ϊ�� 1����� 0����ǿ�
int IsEpLinkList(link_node_t* p);
//7.�޸�ָ��λ�õ����� post ���޸ĵ�λ�� data�޸ĳɵ�����
int ChangePostLinkList(link_node_t* p, int post, datatype data);
//8.����ָ�����ݳ��ֵ�λ�� data�����ҵ����� //search ����
int SearchDataLinkList(link_node_t* p, datatype data);
//9.ɾ�����������г��ֵ�ָ������,data�������������г��ֵ�����data����ɾ��
int DeleteDataLinkList(link_node_t* p, datatype data);
//10.ת������
void ReverseLinkList(link_node_t* p);
//11.��յ�������
void ClearLinkList(link_node_t* p);
#endif
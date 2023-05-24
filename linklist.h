#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;
typedef struct node_t
{
	datatype data;//数据域
	struct node_t* next;//指针域,指向自身结构体的指针
}link_node_t, * link_list_t;

//1.创建一个空的单向链表(有头单向链表)
link_node_t* CreateEpLinkList();
//2.向单向链表的指定位置插入数据
//p保存链表的头指针 post 插入的位置 data插入的数据
int InsertIntoPostLinkList(link_node_t* p, int post, datatype data);
//3.遍历单向链表
void ShowLinkList(link_node_t* p);
//4.求单向链表长度的函数
int LengthLinkList(link_node_t* p);
//5.删除单向链表中指定位置的数据 post 代表的是删除的位置
int DeletePostLinkList(link_node_t* p, int post);
//6.判断单向链表是否为空 1代表空 0代表非空
int IsEpLinkList(link_node_t* p);
//7.修改指定位置的数据 post 被修改的位置 data修改成的数据
int ChangePostLinkList(link_node_t* p, int post, datatype data);
//8.查找指定数据出现的位置 data被查找的数据 //search 查找
int SearchDataLinkList(link_node_t* p, datatype data);
//9.删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
int DeleteDataLinkList(link_node_t* p, datatype data);
//10.转置链表
void ReverseLinkList(link_node_t* p);
//11.清空单向链表
void ClearLinkList(link_node_t* p);
#endif
#include <stdio.h>
#include "linklist.h"

//1.创建一个空的单向链表(有头单向链表)
link_node_t* CreateEpLinkList()
{
	//创建一个节点，把这个节点当作链表头节点
	link_list_t p = (link_list_t)malloc(sizeof(link_node_t));
	if (p == NULL) {
		printf("error\n");
		return NULL;
	}
	p->next = NULL;//头节点初始化
	return p;
}

//4.求单向链表长度的函数
int LengthLinkList(link_node_t* p)
{
	int len = 0;//保存长度
	while (p->next != NULL) {//有头的循环条件
		p = p->next;
		len++;
	}
	return len;
}

//2.向单向链表的指定位置插入数据
//p保存链表的头指针 post 插入的位置 data插入的数据
int InsertIntoPostLinkList(link_node_t* p, int post, datatype data)
{
	//1.容错判断
	if (post<0 || post>LengthLinkList(p)) {
		printf("插入错误\n");
		return -1;
	}
	//2.将头指针移动，指向插入位置的前一个结点
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.创建新节点，保存插入数据
	link_list_t pnew = NULL;
	 pnew= (link_list_t)malloc(sizeof(link_node_t));
	if (pnew == NULL) {
		printf("error\n");
		return NULL;
	}
	pnew->data = data;//初始化，赋值我们想插入的数据
	pnew->next = NULL;
	//4.将新节点插入链表中，先连后面，再连前面
	pnew->next = p->next;
	p->next = pnew;
	return 0;
}

//3.遍历单向链表
void ShowLinkList(link_node_t* p) 
{
	while (p->next != NULL) {
		p = p->next;
		printf("%d ", p->data);
	}
	printf("\n");
}

//6.判断单向链表是否为空 1代表空 0代表非空
int IsEpLinkList(link_node_t* p)
{
	return p->next == NULL;
}

//5.删除单向链表中指定位置的数据 post 代表的是删除的位置
int DeletePostLinkList(link_node_t* p, int post)
{
	//1.容错判断
	if (post < 0 || post >= LengthLinkList(p) || IsEpLinkList(p)) {
		printf("error\n");
		return -1;
	}
	//2.将头指针移动，指向删除位置的前一个结点
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.进行删除
	link_list_t pdel = NULL;
	//(1)定义一个指针pdel指向被删除位置
	pdel = p->next;
	//(2)跨过被删除节点
	p->next = pdel->next;
	//(3)释放被删除节点
	free(pdel);
	pdel = NULL;
	return 0;
}

//7.修改指定位置的数据 post 被修改的位置 data修改成的数据
int ChangePostLinkList(link_node_t* p, int post, datatype data)
{
	//1.容错判断
	if (post < 0 || post >= LengthLinkList(p)) {
		printf("error\n");
		return -1;
	}
	//2.将头指针移动到修改节点的位置
	int i;
	for (i = 0; i < post; i++) {
		p = p->next;
	}
	//3.修改数据
	p->data = data;
}

//8.查找指定数据出现的位置 data被查找的数据 //search 查找
int SearchDataLinkList(link_node_t* p, datatype data)
{
	int post = 0;//记录查找位置
	//遍历链表
	while (p->next != NULL) {
		p = p->next;
		if (p->data == data) {
			return post;
		}
		post++;
	}
	//遍历完没有找到
	return -1;
}

//9.删除单向链表中出现的指定数据,data代表将单向链表中出现的所有data数据删除
int DeleteDataLinkList(link_node_t* p, datatype data)
{
	link_node_t* pdel = NULL;//指向被删除节点
	//1.定义一个指针q，指向头节点下一个节点，把q当无头单向链表头指针
	link_node_t* q = p->next;
	//2.用q遍历无头链表，和data比较，相同就删除
	while (q != NULL) {
		if (q->data == data) {
			pdel = q;
			//跨过被删除节点
			p->next = pdel->next;
			free(pdel);
			pdel = NULL;
			q = p->next;
		}
		else {
			p = p->next;
			q = p->next;//q始终保持指向p节点的下一个
		}
	}
	return 0;
}

/*
	(1) 将头节点与当前链表断开，断开前保存头节点的下一个节点，
	保证后面链表能找得到，定义一个q保存头节点的下一个节点，
		断开后前面相当于一个空的链表，后面是一个无头的单向链表
	(2) 遍历无头链表的所有节点，将每一个节点当做新节点插入空链表头节点的下一个节点
	(每次插入的头节点的下一个节点位置--头插法)
*/
//10.转置链表
void ReverseLinkList(link_node_t* p)
{
	//定义一个temp暂时保存后面节点
	link_list_t temp = NULL;
	//1.断开前保存头节点下一个节点
	link_list_t q = p->next;
	//2.断开链表
	p->next = NULL;
	//3.遍历无头链表
	while (q != NULL) {
		//提前q下一个节点保存起来
		temp = q->next;
		//先连后面，再连前面
		q->next = p->next;
		p->next = q;
		//q移动，指向无头链表下一个节点
		q = temp;
	}
}

//11.清空单向链表
void ClearLinkList(link_node_t* p)
{
	link_list_t pdel = NULL;
	//有头的遍历一下单向链表
	while (p->next != NULL) {
		//(1)pdel只想被删除位置
		pdel = p->next;
		//(2)跨过被删除节点
		p->next = pdel->next;
		//(3)释放被删除节点
		free(pdel);
		pdel = NULL;
	}
}





#include <stdio.h>
#include "linklist.h"

int main()
{
	link_list_t p = CreateEpLinkList();
	InsertIntoPostLinkList(p, 0, 1);
	InsertIntoPostLinkList(p, 1, 2);
	InsertIntoPostLinkList(p, 2, 3);
	InsertIntoPostLinkList(p, 3, 4);
	ShowLinkList(p);//1234
	//DeletePostLinkList(p, 1);
	//ShowLinkList(p);//134
	//ClearLinkList(p);
	//ShowLinkList(p);
	//int c = 0;
	//c=SearchDataLinkList(p, 1);
	//printf("%d\n", c);
	//DeleteDataLinkList(p, 3);
	//ShowLinkList(p);

	ReverseLinkList(p);
	ShowLinkList(p);
	return 0;
}
#include<stdio.h>
#include<malloc.h>
typedef struct Node{
	int data;
	struct Node * next;
}LinkNode;

//�������� 
void CreateList(LinkNode *&L,int a[],int n)
{
	LinkNode *tail;
	for(int i = 0;i<n;i++)
	{
		LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode));
		newNode->data = a[i];
		newNode->next = NULL;
		if(i == 0)
		{
			L = newNode;
			tail = L;
		}
		else
		{
			tail->next=newNode;
			tail = newNode;
		}
	}
}

//������� 
void Print(LinkNode * L)
{
	if(L == NULL){
		return;
	} 
	else 
	{
		printf("%d ",L->data);
		Print(L->next);
	}
}

void ReversePrint(LinkNode * L)
{
	if(L==NULL)		//LΪ��ʱ�ݹ���ڣ�ֱ�ӷ��� 
	{
		return;
	}
	else
	{
		ReversePrint(L->next);	//L��Ϊ��ʱ���ݹ������һ�ڵ� 
		printf("%d ",L->data);
	}
}
int main()
{
	int a []= {1,2,3,4,1,5};
	LinkNode * L;
	int n = sizeof(a)/sizeof(int);
	CreateList(L,a,n);
	Print(L); 
	printf("\n");
	ReversePrint(L);
	return 0;
}

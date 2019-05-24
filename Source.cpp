#include<iostream>
using namespace std;
struct NODE
{
	int data;
	NODE* pLeft;
	NODE* pRight;
};
NODE* CreateNode(int x)
{
	NODE* p = new NODE();
	p->data = x;
	p->pLeft = p->pRight = NULL;
	return p;
}
NODE* FindInsert(NODE* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}
void InsertNode(NODE*& root, int x)
{
	NODE* n = CreateNode(x);
	if (root == NULL)
	{
		root = n;
		return;
	}
	else
	{
		NODE* f = FindInsert(root, x);
		if (f != NULL)
		{
			if (f->data > x)
			{
				f->pLeft = n;
			}
			else
			{
				f->pRight = n;
			}
		}
	}
}
void CreateTree(NODE*& root, int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		InsertNode(root, a[i]);
	}
}
void NLR(NODE* root)
{
	if (root != NULL)
	{
		printf("%d \t", root->data);
		NLR(root->pLeft);
		NLR(root->pRight);
	}
}
void LNR(NODE* root)
{
	if (root != NULL)
	{
		LNR(root->pLeft);
		printf("%d \t", root->data);
		LNR(root->pRight);
	}
}
void LRN(NODE* root)
{
	if (root != NULL)
	{
		LRN(root->pLeft);
		LRN(root->pRight);
		printf("%d \t", root->data);
	}
}
int main()
{
	NODE* root = NULL;
	int a[] = { 18, 31, 15, 2, 20, 12, 30, 9, 8, 4 };
	int n = 10;
	CreateTree(root, a, n);
	//NLR(root);
	//LNR(root);
	LRN(root);

	return 0;
}
int Dem(NODE* c)
{
    if (c!=NULL)
    {
        int pLeft = Dem(c->pLeft);
        int pRight = Dem(c->pRight);
        if (c->pLeft != NULL && c->pRight != NULL)
            return 1 + pLeft + pRight;
        return pLeft + pRight;
    }
    return 0;
}

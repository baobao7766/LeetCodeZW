/*
    ��ϰʹ�������������������������ҽڵ㡢��ӽڵ㡢ɾ���ڵ�
*/

#include "stdio.h"
#include "string.h"
#include "assert.h"
#include "stdlib.h"
#include "windows.h"

#define COUNT 3

//����һ���ڵ�ṹ��
struct NODE
{
    unsigned long uID;
    char strName[16];  //��ָ��Ļ�������ʳ�ͻ�쳣
    NODE *next;
};

//����һ������n���ڵ�������Ӽ����������ݽ����ʼ����������������׽ڵ�ָ��
NODE *createNode(int n)
{
    NODE *pHead, //�׽ڵ�ָ�� 
         *pRear, //β�ڵ�ָ��
         *pNew; //�½ڵ�ָ��
    int i;
    char *strName = new char[16];
    for (i=0; i<n; i++)
    {
        pNew = new NODE;
        do 
        {
            printf("������ID�����ƣ� ");
            scanf("%d %s",&pNew->uID, strName);    
            if (strlen(strName) > 16)
            {
                printf("�������Ƴ��ȳ�����Χ�����������룺 ");
                Sleep(1000);
            }
        } while(strlen(strName) > 16);
        strcpy(pNew->strName, strName);

        if (0==i)
        {
            pRear = pHead = pNew;
        } 
        else
        {
            pRear->next = pNew;
        }
        pNew->next = NULL;
        pRear = pNew;
    }
    delete []strName;
    return pHead;
}

//��ӡ���������нڵ������
void printNode(NODE *pHead)
{
    NODE *pTemp = pHead;
    assert(pTemp != NULL);
    while (pTemp != NULL)
    {
        printf("%d %s ",pTemp->uID, pTemp->strName);
        pTemp = pTemp->next;
    }
}

//��ѯ�����о���ָ��ID�Ľڵ㣬�����ش˽ڵ�ָ��
NODE *searchNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest = pHead;
    assert(pDest != NULL);
    while (pDest->next!=NULL && pDest->uID!=uID)
    {
        pDest = pDest->next;
    }
    if (pDest->uID == uID)
    {
        return pDest;
    } 
    else
    {
        printf("����ʧ�ܣ�δ�ҵ��Ҷ�ID�Ľڵ㣡 ");
        return NULL;
    }
}

//ɾ��ָ��ID�Ľڵ�
NODE *deleteNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest, //Ҫɾ���Ľڵ�
         *pBefore; //ǰһ���ڵ�
    pDest = pHead;
    assert(pDest != NULL);
    while (pDest->next!=NULL && pDest->uID!=uID)
    {
        pBefore = pDest;
        pDest = pDest->next;
    }
    if (pDest->uID == uID)
    {
        if (pDest == pHead)
        {
            pHead = pDest->next;
        } 
        else
        {
            pBefore->next = pDest->next;
        }
        free(pDest);
        printf("�ڵ��ѱ�ɾ���� ");
    } 
    else
    {
        printf("δ�ҵ�ָ���ڵ㣬�޷�����ɾ���� ");
    }
    return pHead;
}

//��ָ��ID�Ľڵ�����һ���µĽڵ�
NODE *insertNode(NODE *pHead, unsigned long uID)
{
    NODE *pDest, *pNew;
    pDest = pHead;
    assert(pDest != NULL);
    while(pDest->next!=NULL && pDest->uID!=uID)
    {
        pDest = pDest->next;
    }
    if(pDest->uID == uID)
    {
        pNew = new NODE;
        printf("�������½ڵ��ID�����ƣ� ");
        scanf("%d %s",&pNew->uID,pNew->strName);
        pNew->next = pDest->next;
        pDest->next = pNew;
        printf("�ڵ������ɣ� ");
    }
    else
    {
        printf("δ�ҵ�ָ���ڵ㣡 ");
    }
    return pHead;
}

//////////////////////////////////////////////////////////////////////

void main()
{
    NODE *pHead, *pDest;
    int nSelect;
    bool isExit = false;
    unsigned long uID;
    printf("�������ʾ�������ݳ�ʼ������ ");
    pHead = createNode(COUNT);
    assert(pHead != NULL);
    printf("�������ɹ����洢�������£� ");
    printNode(pHead);
    while (!isExit)
    {
        printf("-------------------------- ");
        printf("��ѡ��Ҫ���еĲ����� ");
        printf("1.��ӡ���������нڵ����ݣ� ");
        printf("2.����ID��ѯ���ơ� ");
        printf("3.ɾ��ָ��ID�Ľڵ㡣 ");
        printf("4.��ָ��ID�Ľڵ�����һ���µĽڵ㡣 ");
        printf("5.�˳��� ");
        printf("--------------------------- ");
        scanf("%d",&nSelect);
        switch(nSelect)
        {
        case 1:
            printf("�������нڵ��������£� ");
            printNode(pHead);
            break;
        case 2:
            printf("������Ҫ��ѯ�Ľڵ��ID�� ");
            scanf("%d",&uID);
            pDest = searchNode(pHead, uID);
            if (pDest != NULL)
            {
                printf("���ҵ��ڵ㣬����Ϊ��%s ",pDest->strName);
            }
            break;
        case 3:
            printf("������Ҫɾ���Ľڵ��ID�� ");
            scanf("%d",&uID);
            pHead = deleteNode(pHead, uID);
            break;
        case 4:
            printf("������Ҫɾ���Ľڵ��ID�� ");
            scanf("%d",&uID);
            pHead = insertNode(pHead, uID);
            break;
        case 5:
            isExit = true;
            printf("�������˳��� ");
            break;
        default:
            printf("��������������ѡ�� ");
            break;
        }
    }
}
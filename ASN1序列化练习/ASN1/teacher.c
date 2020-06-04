#include "teacher.h"
#include "itcast_asn1_der.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int encodeTeacher(Teacher * p, char ** outData, int * outlen)
{
	ITCAST_ANYBUF* temp = NULL;
	ITCAST_ANYBUF* head = NULL;
	ITCAST_ANYBUF* next = NULL;
	// 1. ��name���� -> char*
	// char* -> ITCAST_ANYBUF
	DER_ITCAST_String_To_AnyBuf(&temp, p->name, strlen(p->name)+1);
	DER_ItAsn1_WritePrintableString(temp, &head);
	DER_ITCAST_FreeQueue(temp);
	// 2. age����
	DER_ItAsn1_WriteInteger(p->age, &head->next);
	// 3. p����
	next = head->next;
	EncodeChar(p->p, strlen(p->p) + 1, &next->next);
	// 4. plen����
	next = next->next;
	DER_ItAsn1_WriteInteger(p->plen, &next->next);
	// 5. �����������
	DER_ItAsn1_WriteSequence(head, &temp);
	// 6. ����������ֵ
	*outData = temp->pData;
	*outlen = temp->dataLen;
	// 7. �ͷ��ڴ� - �ͷ�����
	DER_ITCAST_FreeQueue(head);

	return 0;
}

/*
	typedef struct _Teacher
	{
		char name[64];
		int age;
		char *p;
		long plen;
	}Teacher;
*/
int decodeTeacher(char * inData, int inLen, Teacher ** p)
{
	ITCAST_ANYBUF* temp = NULL;
	ITCAST_ANYBUF* head = NULL;
	ITCAST_ANYBUF* next = NULL;

	Teacher* pt = (Teacher*)malloc(sizeof(Teacher));

	// 1. char* -> ITCAST_ANYBUF
	DER_ITCAST_String_To_AnyBuf(&temp, inData, inLen);
	// 2. ITCAST_ANYBUF -> ��ԭ��һ����, �õ���һ��������ͷ���
	DER_ItAsn1_ReadSequence(temp, &head);
	DER_ITCAST_FreeQueue(temp);
	// 3. ����name
	DER_ItAsn1_ReadPrintableString(head, &temp);
	memcpy(pt->name, temp->pData, temp->dataLen);
	DER_ITCAST_FreeQueue(temp);

	// 4. ����age
	next = head->next;
	DER_ItAsn1_ReadInteger(next, &pt->age);

	// 5. ����p
	next = next->next;
	DER_ItAsn1_ReadPrintableString(next, &temp);
	pt->p = (char*)malloc(temp->dataLen);
	strcpy(pt->p, temp->pData);
	DER_ITCAST_FreeQueue(temp);

	// 6. ����plen
	next = next->next;
	DER_ItAsn1_ReadInteger(next, &pt->plen);

	// 7. ����������ֵ
	*p = pt;

	// 8. �ͷ��ڴ�
	DER_ITCAST_FreeQueue(head);

	return 0;
}

void freeTeacher(Teacher ** p)
{
	// 1. free (*p)
	// 2. (*p)->p 
	if ((*p))
	{
		if ((*p)->p)
		{
			free((*p)->p);
			(*p)->p = NULL;
		}
		free((*p));
		(*p) = NULL;
	}
}

#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "transaction.h"
#include "KISA_SHA256.h"

typedef struct block
{
	struct block* next;

	//head
	char version[65];
	char previousBlockHash[65];
	char merkleRoot[10000];
	unsigned int generatedTime;

	//transaction
	TS transaction[100];
	int tsSize;

}Block;

//opensource
int strcmp_unsigned(const char* s1, const char* s2)
{
	unsigned char* p1 = (unsigned char*)s1;
	unsigned char* p2 = (unsigned char*)s2;

	while ((*p1) && (*p1 == *p2))
	{
		++p1;
		++p2;
	}
	return (*p1 - *p2);
}

//selfmade source
void firstSetBlock(Block* block)
{
	srand((unsigned)time(NULL));

	block->next = NULL;

	char* version = "1.0";
	strcpy(block->version, version);

	char* previousBlockHash = "0000000000000000000000000000000000000000000000000000000000000000";
	strcpy(block->previousBlockHash, previousBlockHash);

	char* merkleRoot = "";
	strcpy(block->merkleRoot, merkleRoot);

	block->generatedTime = time(NULL);

	block->tsSize = 0;
}

void merkleRoot(Block* block)
{
	Block* previous = malloc(sizeof(Block));
	Block* present = malloc(sizeof(Block));
	present = block;

	while (1)
	{
		if (present->next != NULL)
		{
			previous = present;
			present = present->next;
		}
		else
		{
			strcat(present->merkleRoot, previous->transaction[previous->tsSize].result);
			break;
		}
	}

	previous = NULL;
	present = NULL;
	free(previous);
	free(present);
}

void previousBlockHash(Block* block)
{
	Block* previous = malloc(sizeof(Block));
	Block* present = malloc(sizeof(Block));
	present = block;

	while (1)
	{
		if (present->next != NULL)
		{
			previous = present;
			present = present->next;
		}
		else
		{
			char temp[10000];
			char* tmp[11] = { 0, };
			char result[32] = { 0, };
			strcpy(temp, "");

			strcat(temp, previous->version);
			strcat(temp, previous->previousBlockHash);
			strcat(temp, previous->merkleRoot);
			strcat(temp, itoa(previous->generatedTime, tmp, 11));

			SHA256_Encrpyt(temp, strlen(temp), result);
			strcat(present->previousBlockHash, result);
			break;
		}
	}

	previous = NULL;
	present = NULL;
	free(previous);
	free(present);
}

void addBlock(Block* block)
{
	Block* present = malloc(sizeof(Block));
	present = block;

	for (int i = 0; ; i++)
	{
		if (present->next != NULL)
		{
			present = present->next;
		}
		else
		{
			Block* temp = malloc(sizeof(Block));

			temp->next = NULL;
			strcpy(temp->version, present->version);
			strcpy(temp->previousBlockHash, "");
			strcpy(temp->merkleRoot, present->merkleRoot);
			temp->generatedTime = time(NULL);
			temp->tsSize = present->tsSize + 1;
			memcpy(temp->transaction, present->transaction, sizeof(int) * present->tsSize);
			present->next = temp;
			
			temp = NULL;
			free(temp);
			break;
		}
	}

	present = NULL;
	free(present);
}

void print(Block* block)
{
	Block* present = malloc(sizeof(Block));
	present = block;

	while (1)
	{
		printf("블럭버전:\t%s\n", present->version);
		printf("이전블럭해시:\t%s\n", present->previousBlockHash);
		printf("머클루트:\t\"%s\" to sha256\n", present->merkleRoot);
		printf("생성시간:\t%d\n", present->generatedTime);
		printf("\n\n");

		if (present->next != NULL)
		{
			present = present->next;
		}
		else
		{
			break;
		}
	}

	present = NULL;
	free(present);
}
#endif // !BLOCK_H
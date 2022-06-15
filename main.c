#include "block.h"

int add(Block* b)
{
	char sender[20];
	char receiver[20];
	float amount;

	printf("보내는 사람>>\t");
	scanf("%s", sender);
	printf("받는 사람>>\t");
	scanf("%s", receiver);
	printf("보내는 양>>\t");
	scanf("%f", &amount);
	printf("블럭이 추가되었습니다.\n\n");

	setSender(&b->transaction[b->tsSize], sender);
	setReceiver(&b->transaction[b->tsSize], receiver);
	setAmount(&b->transaction[b->tsSize], amount);
	setResult(&b->transaction[b->tsSize]);

	addBlock(b);
	merkleRoot(b);
	previousBlockHash(b);
}

int main()
{
	Block* head = malloc(sizeof(Block));
	firstSetBlock(head);
	
	int menu;
	while (1)
	{
		printf("1. 블럭추가\n");
		printf("2. 블럭열람\n");
		printf("3. 종료\n");
		printf(">> ");
		scanf("%d", &menu);
		printf("\n\n");

		if (menu == 1)
			add(head);
		else if (menu == 2)
			print(head);
		else if (menu == 3)
			break;
	}
}
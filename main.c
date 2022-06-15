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



	/*알겟니?
		내덕동, 율량동, 사천동 이 세 동 중에 살아야댐
		청여고 78기? 여야댐
		그리고 음...
		나랑 같이 수학여행 제주도로 간 사람들 만
		그리고 우리집에 5번 이상 온 사람들
		우리집에서 자고 간 사람들
		우리 엄마랑 아빠랑 인사도 하고 차도 같이 타 본 사람들
		우리 가게에서 주말에 점심 만들어서 먹어본 적 있는 사람들
		우리 가게에서 고양이한테 밥 줘본 적 있는 사람들
		그리고 민영이가 숏컷할 때 민영이의 머리를 나눠가진 사람들
		아니야
		스승의날에 기헌쌤 만난 사람들
		기헌티
		애기
		기허니~*/
}
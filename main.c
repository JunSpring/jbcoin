#include "block.h"

int add(Block* b)
{
	char sender[20];
	char receiver[20];
	float amount;

	printf("������ ���>>\t");
	scanf("%s", sender);
	printf("�޴� ���>>\t");
	scanf("%s", receiver);
	printf("������ ��>>\t");
	scanf("%f", &amount);
	printf("������ �߰��Ǿ����ϴ�.\n\n");

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
		printf("1. �����߰�\n");
		printf("2. ��������\n");
		printf("3. ����\n");
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



	/*�˰ٴ�?
		������, ������, ��õ�� �� �� �� �߿� ��ƾߴ�
		û���� 78��? ���ߴ�
		�׸��� ��...
		���� ���� ���п��� ���ֵ��� �� ����� ��
		�׸��� �츮���� 5�� �̻� �� �����
		�츮������ �ڰ� �� �����
		�츮 ������ �ƺ��� �λ絵 �ϰ� ���� ���� Ÿ �� �����
		�츮 ���Կ��� �ָ��� ���� ���� �Ծ �� �ִ� �����
		�츮 ���Կ��� ���������� �� �ົ �� �ִ� �����
		�׸��� �ο��̰� ������ �� �ο����� �Ӹ��� �������� �����
		�ƴϾ�
		�����ǳ��� ����� ���� �����
		����Ƽ
		�ֱ�
		�����~*/
}
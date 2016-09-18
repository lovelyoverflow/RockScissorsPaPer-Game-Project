#include "common.h"
#include "gameMoney.h"

static int youMoney;
static int comMoney;

static int betMoney;

void setComMoney(int com)
{
	comMoney = com;
}

void setYouMoney(int you)
{
	youMoney = you;
}

void betting(void)
{
	int bet;

	while (1)
	{
		fputs("�ǵ��� ũ�� �Է�: ", stdout);
		scanf("%d", &bet);

		if (bet > youMoney)
		{
			puts("���� �ݾ� �ʰ��Դϴ�!");
			continue;
		}
		else if (bet > comMoney)
		{
			puts("��ǻ�� �ݾ� �ʰ��Դϴ�!");
			continue;
		}
		else
			break;
	}

	betMoney = bet;
}

void IncreComMoney(void)
{
	youMoney -= betMoney;
	comMoney += betMoney;
}

void IncreYouMoney(void)
{	
	comMoney -= betMoney;
	youMoney += betMoney;
}


int getComMoney(void)
{
	return comMoney;
}

int getYouMoney(void)
{
	return youMoney;
}

int WhoIsZero(void)
{
	if (youMoney <= 0 || comMoney <= 0)
		return 1;
	else
		return 0;
}

void ShowCurMoney(void)
{
	printf("���� ����� �Ӵ�: %d \n", youMoney);
	printf("���� ��ǻ�� �Ӵ�: %d \n", comMoney);
}
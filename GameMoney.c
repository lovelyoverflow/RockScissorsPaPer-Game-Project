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
		fputs("판돈의 크기 입력: ", stdout);
		scanf("%d", &bet);

		if (bet > youMoney)
		{
			puts("소유 금액 초과입니다!");
			continue;
		}
		else if (bet > comMoney)
		{
			puts("컴퓨터 금액 초과입니다!");
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
	printf("현재 당신의 머니: %d \n", youMoney);
	printf("현재 컴퓨터 머니: %d \n", comMoney);
}
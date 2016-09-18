#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "GameMoney.h"
#include "GameContinue.h"

void GameSave(void)
{
	FILE * fp = fopen("save.sav", "w");

	int comMoney;
	int youMoney;
	int WTimes;
	int GTimes;
	double Odds;

	comMoney = getComMoney();
	youMoney = getYouMoney();

	WTimes = ReTurnTheWTimes();
	GTimes = ReTurnTheGTimes();

	Odds = ShowOdds();

	fwrite(&comMoney, sizeof(int), 1, fp);
	fwrite(&youMoney, sizeof(int), 1, fp);
	fwrite(&WTimes, sizeof(int), 1, fp);
	fwrite(&GTimes, sizeof(int), 1, fp);
	fwrite(&Odds, sizeof(double), 1, fp);
}

void GameContinue(void)
{
	FILE * fp = fopen("save.sav", "r");

	int comMoney;
	int youMoney;
	int WTimes;
	int GTimes;
	double Odds;

	fread(&comMoney, sizeof(int), 1, fp);
	fread(&youMoney, sizeof(int), 1, fp);
	fread(&WTimes, sizeof(int), 1, fp);
	fread(&GTimes, sizeof(int), 1, fp);
	fread(&Odds, sizeof(int), 1, fp);

	setComMoney(comMoney);
	setYouMoney(youMoney);

	setWinTimes(WTimes);
	setGameTimes(GTimes);

	ContinueOdds(Odds);
}

int TheFileExist(void)
{
	FILE * fp = fopen("save.sav", "r");

	if (fp == NULL)
		return -1;
	else
		return 1;
}

int MoneyIsZero(void)
{
	FILE * fp = fopen("save.sav", "r");

	int comMoney;
	int youMoney;

	fread(&comMoney, sizeof(int), 1, fp);
	fread(&youMoney, sizeof(int), 1, fp);

	if (comMoney == 0 || youMoney == 0)
		return 1;
	else
		return -1;
}
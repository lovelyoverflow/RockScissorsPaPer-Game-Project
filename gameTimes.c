#include "common.h"
#include "gameTimes.h"
	
static int GTimes;	
static int WTimes;
static int Odds;

void setGameTimes(Times)
{
	GTimes = Times;
}

void setWinTimes(Times)
{
	WTimes = Times;
}

void GameTimes(void)
{
	GTimes++;
}

void WinTimes(void)
{
	WTimes++;
}

int ReTurnTheGTimes(void)
{
	return GTimes;
}

int ReTurnTheWTimes(void)
{
	return WTimes;
}

void ContinueOdds(double odd)
{
	Odds = odd;
}

double ShowOdds(void)
{
	return ((double)WTimes / GTimes) * 100;
}
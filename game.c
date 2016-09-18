/* Name: game.c  ver 1.0
 * Content: 게임 관련 함수 정의.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "GameMoney.h"

/* 함    수: int ChoiceOfCom(void).
 * 기    능: 무작위 값을 반환.
 * 반    환: 0~99의 범위에 있는 값을 반환.
 *
 */
int ChoiceOfCom(void) 
{
	srand((size_t)time(NULL));
	return rand() % 3 + 1;
}

/* 함    수: int ChoiceOfMe(void).
 * 기    능: 사용자의 선택을 입력받음.
 * 반    환: 사용자 입력.
 *
 */
int ChoiceOfMe(void)
{
	int me;

	puts("1. 가위    2. 바위    3. 보    4. 종료");
	fputs("당신의 선택은? ", stdout);

	scanf_s("%d", &me);

	if (me != 4)
		GameTimes();

	return me;
}

/* 함    수: void WhoIsWinner(int com, int you)
 * 기    능: 승자를 가림. 
 * 반    환: void
 *
 */
void WhoIsWinner(int com, int you)
{
	int win = you - com;

	switch (win)
	{
	case 0:
		puts("무승부");
		break;
	case 1: case -2:	
		puts("승리");
		IncreYouMoney();
		WinTimes();
		break;
	default:
		IncreComMoney();
		puts("패배");
		break;
	}
}

void ShowRSP(int RSP)
{
	switch (RSP)
	{
	case SCISSORS:
		puts("가위");
		break;

	case ROCK:
		puts("바위");
		break;

	case PAPER:
		puts("보");
		break;
	}
}
/* end of file */
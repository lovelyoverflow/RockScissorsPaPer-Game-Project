/* Name: game.c  ver 1.0
 * Content: ���� ���� �Լ� ����.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */
#include <time.h>
#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "GameMoney.h"

/* ��    ��: int ChoiceOfCom(void).
 * ��    ��: ������ ���� ��ȯ.
 * ��    ȯ: 0~99�� ������ �ִ� ���� ��ȯ.
 *
 */
int ChoiceOfCom(void) 
{
	srand((size_t)time(NULL));
	return rand() % 3 + 1;
}

/* ��    ��: int ChoiceOfMe(void).
 * ��    ��: ������� ������ �Է¹���.
 * ��    ȯ: ����� �Է�.
 *
 */
int ChoiceOfMe(void)
{
	int me;

	puts("1. ����    2. ����    3. ��    4. ����");
	fputs("����� ������? ", stdout);

	scanf_s("%d", &me);

	if (me != 4)
		GameTimes();

	return me;
}

/* ��    ��: void WhoIsWinner(int com, int you)
 * ��    ��: ���ڸ� ����. 
 * ��    ȯ: void
 *
 */
void WhoIsWinner(int com, int you)
{
	int win = you - com;

	switch (win)
	{
	case 0:
		puts("���º�");
		break;
	case 1: case -2:	
		puts("�¸�");
		IncreYouMoney();
		WinTimes();
		break;
	default:
		IncreComMoney();
		puts("�й�");
		break;
	}
}

void ShowRSP(int RSP)
{
	switch (RSP)
	{
	case SCISSORS:
		puts("����");
		break;

	case ROCK:
		puts("����");
		break;

	case PAPER:
		puts("��");
		break;
	}
}
/* end of file */
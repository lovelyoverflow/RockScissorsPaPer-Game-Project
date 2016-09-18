/* Name: main.c  ver 1.0
 * Content: 게임 main 함수.
 * Implementation: YSW
 * 
 * Last modified 2008/01/01
 */

#include "common.h"
#include "game.h"
#include "gameTimes.h"
#include "GameMoney.h"
#include "GameContinue.h"

int main(void)
{
    int com;
    int you;
	int youMoney;
	int choice;
	double Odds;

	if (TheFileExist() == 1 && MoneyIsZero() != 1)
	{
		fputs("게임을 이어서 하시겠습니까?	 (Yes.1	No.2): ", stdout);
		scanf("%d", &choice);

		if (choice == 1)
		{
			GameContinue();
		}
		else
		{
			fputs("당신의 머니: ", stdout);
			scanf("%d", &youMoney);

			setComMoney(1000);
			setYouMoney(youMoney);
		}
	}
	else
	{
		fputs("당신의 머니: ", stdout);
		scanf("%d", &youMoney);

		setComMoney(1000);
		setYouMoney(youMoney);
	}

	puts("자! 게임을 시작합니다.");
    puts("");
    
	while (1)
	{
		betting();

		puts("☆☆☆☆☆☆ 대결! ☆☆☆☆☆☆!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == 4)
		{	
			fputs("게임을 저장하시겠습니까? (Yes.1	No.2): ", stdout);
			scanf("%d", &choice);

			if(choice == 1)
				GameSave();	

			break;

		}

		puts("★★★★★★ 결과! ★★★★★★!!");

		fputs("컴퓨터의 선택은 ", stdout);
		ShowRSP(com);

		fputs("당신의 선택은 ", stdout);
		ShowRSP(you);
		
		WhoIsWinner(com, you);
		Odds = ShowOdds();

		printf("승률: %f%% \n", Odds);
		ShowCurMoney();

		if (WhoIsZero() == 1)
		{
			GameSave();
			break;
		}

		getchar();
		getchar();

		system("cls");
	}

    puts("");
    return 0;
}
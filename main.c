/* Name: main.c  ver 1.0
 * Content: ���� main �Լ�.
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
		fputs("������ �̾ �Ͻðڽ��ϱ�?	 (Yes.1	No.2): ", stdout);
		scanf("%d", &choice);

		if (choice == 1)
		{
			GameContinue();
		}
		else
		{
			fputs("����� �Ӵ�: ", stdout);
			scanf("%d", &youMoney);

			setComMoney(1000);
			setYouMoney(youMoney);
		}
	}
	else
	{
		fputs("����� �Ӵ�: ", stdout);
		scanf("%d", &youMoney);

		setComMoney(1000);
		setYouMoney(youMoney);
	}

	puts("��! ������ �����մϴ�.");
    puts("");
    
	while (1)
	{
		betting();

		puts("�١١١١١� ���! �١١١١١�!!");
		com = ChoiceOfCom();
		you = ChoiceOfMe();
		puts("");

		if (you == 4)
		{	
			fputs("������ �����Ͻðڽ��ϱ�? (Yes.1	No.2): ", stdout);
			scanf("%d", &choice);

			if(choice == 1)
				GameSave();	

			break;

		}

		puts("�ڡڡڡڡڡ� ���! �ڡڡڡڡڡ�!!");

		fputs("��ǻ���� ������ ", stdout);
		ShowRSP(com);

		fputs("����� ������ ", stdout);
		ShowRSP(you);
		
		WhoIsWinner(com, you);
		Odds = ShowOdds();

		printf("�·�: %f%% \n", Odds);
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
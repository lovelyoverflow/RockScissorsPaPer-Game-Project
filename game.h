#ifndef __GAME_H__
#define __GAME_H__

enum {SCISSORS=1, ROCK, PAPER};

int ChoiceOfCom(void);
int ChoiceOfMe(void);
void WhoIsWinner(int com, int you);
void ShowRSP(int RSP);

#endif
/* end of file */

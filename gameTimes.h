#ifndef __GAME_TIMES_H__
#define __GAME_TIMES_H__

void GameTimes(void);
void WinTimes(void);

int ReTurnTheGTimes(void);
int ReTurnTheWTimes(void);

void setGameTimes(Times);
void setWinTimes(Times);

void ContinueOdds(double odd);

double ShowOdds(void);

#endif
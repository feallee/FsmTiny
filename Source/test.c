#include <stdio.h>
#include "FsmTny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"¹ú¸è.mp3"

void StopState(unsigned int value);
void PlayState(unsigned int value);
void PauseState(unsigned int value);

void StopState(unsigned int value)
{
	printf("Í£Ö¹×´Ì¬:°´¼ü=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		FsmTny_Change(PlayState);
	}
}

void PlayState(unsigned int value)
{
	printf("²¥·Å×´Ì¬(%s):°´¼ü=%u\n", MP3, value);
	if (value == KEY_PLAY_PAUSE)
	{
		FsmTny_Change(PauseState);
	}
	else if (value == KEY_STOP)
	{
		FsmTny_Change(StopState);
	}
}

void PauseState(unsigned int value)
{
	printf("ÔÝÍ£×´Ì¬:°´¼ü=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		FsmTny_Change(PlayState);
	}
	else if (value == KEY_STOP)
	{
		FsmTny_Change(StopState);
	}
}

int main(void)
{
	FsmTny_Initialize(StopState, NULL);
	//Ä£Äâ°´¼üÊÂ¼þ¡£
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_STOP);
	FsmTny_Transit(KEY_STOP);
	FsmTny_Dispose();
	return 0;
}
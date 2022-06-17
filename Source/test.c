#include <stdio.h>
#include "FsmTny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"����.mp3"

void StopState(unsigned int value);
void PlayState(unsigned int value);
void PauseState(unsigned int value);

void StopState(unsigned int value)
{
	printf("ֹͣ״̬:����=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		FsmTny_Change(PlayState);
	}
}

void PlayState(unsigned int value)
{
	printf("����״̬(%s):����=%u\n", MP3, value);
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
	printf("��ͣ״̬:����=%u\n", value);
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
	//ģ�ⰴ���¼���
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_PLAY_PAUSE);
	FsmTny_Transit(KEY_STOP);
	FsmTny_Transit(KEY_STOP);
	FsmTny_Dispose();
	return 0;
}
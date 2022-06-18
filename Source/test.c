#include <stdio.h>
#include "FsmTny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"����.mp3"

FsmTny fsm;

void StopState(unsigned int value);
void PlayState(unsigned int value);
void PauseState(unsigned int value);

void StopState(unsigned int value)
{
	printf("\nֹͣ״̬:���յ�����=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("��ʼ����:%s\n",MP3);
		FsmTny_Change(&fsm, PlayState);
	}
}

void PlayState(unsigned int value)
{
	printf("\n����״̬:���յ�����=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("��ʼ��ͣ\n");
		FsmTny_Change(&fsm, PauseState);
	}
	else if (value == KEY_STOP)
	{
		printf("��ʼֹͣ\n");
		FsmTny_Change(&fsm, StopState);
	}
}

void PauseState(unsigned int value)
{
	printf("\n��ͣ״̬:���յ�����=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("��������:%s\n", MP3);
		FsmTny_Change(&fsm, PlayState);
	}
	else if (value == KEY_STOP)
	{
		printf("��ʼֹͣ\n");
		FsmTny_Change(&fsm, StopState);
	}
}

int main(void)
{

	FsmTny_Initialize(&fsm, StopState, NULL);
	//ģ�ⰴ���¼���
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_STOP);	
	FsmTny_Dispose(&fsm);
	return 0;
}
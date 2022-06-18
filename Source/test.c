#include <stdio.h>
#include "FsmTny.h"

#define KEY_PLAY_PAUSE	1
#define KEY_STOP	2

#define MP3	"国歌.mp3"

FsmTny fsm;

void StopState(unsigned int value);
void PlayState(unsigned int value);
void PauseState(unsigned int value);

void StopState(unsigned int value)
{
	printf("\n停止状态:接收到按键=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("开始播放:%s\n",MP3);
		FsmTny_Change(&fsm, PlayState);
	}
}

void PlayState(unsigned int value)
{
	printf("\n播放状态:接收到按键=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("开始暂停\n");
		FsmTny_Change(&fsm, PauseState);
	}
	else if (value == KEY_STOP)
	{
		printf("开始停止\n");
		FsmTny_Change(&fsm, StopState);
	}
}

void PauseState(unsigned int value)
{
	printf("\n暂停状态:接收到按键=%u\n", value);
	if (value == KEY_PLAY_PAUSE)
	{
		printf("继续播放:%s\n", MP3);
		FsmTny_Change(&fsm, PlayState);
	}
	else if (value == KEY_STOP)
	{
		printf("开始停止\n");
		FsmTny_Change(&fsm, StopState);
	}
}

int main(void)
{

	FsmTny_Initialize(&fsm, StopState, NULL);
	//模拟按键事件。
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_PLAY_PAUSE);
	FsmTny_Transit(&fsm, KEY_STOP);	
	FsmTny_Dispose(&fsm);
	return 0;
}
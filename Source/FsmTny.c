
#include "FsmTny.h"

static FsmTnyState Initial, Final, Current, Next;

void FsmTny_Initialize(FsmTnyState initialState, FsmTnyState finalState)
{
	Current = Initial = initialState;
	Final = finalState;
	Next = NULL;
}

FsmTnyState FsmTny_GetCurrent(void)
{	
	return Current;
}

unsigned char FsmTny_Transit(unsigned int value)
{
	unsigned char r = 0;
	if (Current!= Final)
	{
		if (Current)
		{			
			Current(value);
			if (Next)
			{
				Current = Next;
				Next = NULL;
			}
			r = 1;
		}
	}
	return r;
}

void FsmTny_Change(FsmTnyState state)
{
	Next = state;
}

void FsmTny_Dispose(void)
{}

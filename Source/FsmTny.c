
#include "FsmTny.h"

void FsmTny_Initialize(FsmTny* fsmTny, FsmTnyState initialState, FsmTnyState finalState)
{
	if (fsmTny)
	{
		fsmTny->Current = fsmTny->Initial = initialState;
		fsmTny->Final = finalState;
		fsmTny->Next = NULL;
	}
}

FsmTnyState FsmTny_GetCurrent(FsmTny* fsmTny)
{
	return fsmTny ? fsmTny->Current : NULL;
}

unsigned char FsmTny_Transit(FsmTny* fsmTny, unsigned int value)
{
	unsigned char r = 0;
	if (fsmTny)
	{
		if (fsmTny->Current != fsmTny->Final)
		{
			if (fsmTny->Current)
			{
				fsmTny->Current(value);
				if (fsmTny->Next)
				{
					fsmTny->Current = fsmTny->Next;
					fsmTny->Next = NULL;
				}
				r = 1;
			}
		}
	}
	return r;
}

void FsmTny_Change(FsmTny* fsmTny, FsmTnyState state)
{
	if (fsmTny)
	{
		fsmTny->Next = state;
	}
}

void FsmTny_Dispose(FsmTny* fsmTny)
{
	if (fsmTny)
	{
		fsmTny->Initial = fsmTny->Final = fsmTny->Current = fsmTny->Next = NULL;
	}
}

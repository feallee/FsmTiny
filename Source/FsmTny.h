/*--------------------------------------------------------------------------
FSMTNY.H

Finite state machine(Mealy) tiny version 1.0 functions for ANSI C.

Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSMTNY_H_
#define __FSMTNY_H_
#include <stddef.h>
#define FSMTNY_VERSION	10

/// <summary>
/// 表示状态机中的一种状态。如果需要切换状态，则必须在状态函数返回之前调用此函数。
/// 注意：只允许在状态函数里调用函数 FsmTny_Change 和 FsmTny_GetCurrent，且不允许调用下面的函数：
/// FsmTny_Initialize，FsmTny_Transit 和 FsmTny_Dispose。
/// </summary>
typedef void (*FsmTnyState)(unsigned int value);

/// <summary>
/// 表示一个状态机。
/// </summary>
typedef struct
{
	/// <summary>
	/// 起始状态。
	/// </summary>
	FsmTnyState Initial;
	/// <summary>
	/// 最终状态。
	/// </summary>
	FsmTnyState Final;
	/// <summary>
	/// 当前状态。
	/// </summary>
	FsmTnyState Current;
	/// <summary>
	/// 新状态。
	/// </summary>
	FsmTnyState Next;
}FsmTny;


/// <summary>
/// 使用指定起始状态和最终状态初始化状态机，并设置状态机的当前状态为起始状态。
/// </summary>
/// <param name="fsmTny">状态机。</param>
/// <param name="initialState">起始状态。</param>
/// <param name="finalState">最终状态。</param>
void FsmTny_Initialize(FsmTny* fsmTny, FsmTnyState initialState, FsmTnyState finalState);

/// <summary>
/// 获取状态机的当前状态。
/// </summary>
/// <param name="fsmTny">状态机。</param>
FsmTnyState FsmTny_GetCurrent(FsmTny* fsmTny);

/// <summary>
/// 执行状态转换。在发生某事件后调用。
/// </summary>
/// <param name="fsmTny">状态机。</param>
/// <param name="value">事件关联的变量值。如果有更多的关联变量，可以使用全局变量进行数据共享。</param>
/// <returns>返回状态转换成功标志。0=失败，1=成功。</returns>
unsigned char FsmTny_Transit(FsmTny* fsmTny, unsigned int value);

/// <summary>
/// 指定状态机的新状态。
/// </summary>
/// <param name="fsmTny">状态机。</param>
/// <param name="state">新状态。如果为 NULL 则无效。</param>
void FsmTny_Change(FsmTny* fsmTny, FsmTnyState state);

/// <summary>
/// 释放状态机使用的资源。
/// </summary>
/// <param name="fsmTny">状态机。</param>
void FsmTny_Dispose(FsmTny* fsmTny);

#endif

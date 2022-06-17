/*--------------------------------------------------------------------------
FSMTNY.H

Finite state machine(Mealy) tiny functions for ANSI C.

Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSMTNY_H_
#define __FSMTNY_H_
#include <stddef.h>
/// <summary>
/// 表示状态机中的一种状态。
/// 注意：只允许在状态函数里调用函数 FsmTny_Change 和 FsmTny_GetCurrent，且不允许调用下面的函数：
/// FsmTny_Initialize，FsmTny_Transit 和 FsmTny_Dispose。
/// </summary>
typedef void (*FsmTnyState)(unsigned int value);

/// <summary>
/// 使用指定起始状态和最终状态初始化状态机，并设置状态机的当前状态为起始状态。
/// </summary>
/// <param name="initialState">起始状态。</param>
/// <param name="finalState">最终状态。</param>
void FsmTny_Initialize(FsmTnyState initialState, FsmTnyState finalState);

/// <summary>
/// 获取状态机的当前状态。
/// </summary>
FsmTnyState FsmTny_GetCurrent(void);

/// <summary>
/// 执行状态转换。在发生某事件后调用。
/// </summary>
/// <param name="value">事件关联的变量值。如果有更多的关联变量，可以使用全局变量进行数据共享。</param>
/// <returns>返回状态转换成功标志。0=失败，1=成功。</returns>
unsigned char FsmTny_Transit(unsigned int value);

/// <summary>
/// 指定状态机的新状态。如果需要切换状态，则必须在状态函数返回前调用此函数。
/// </summary>
/// <param name="state">新状态。如果为 NULL 则无效。</param>
void FsmTny_Change(FsmTnyState state);

/// <summary>
/// 释放状态机使用资源。
/// </summary>
void FsmTny_Dispose(void);

#endif

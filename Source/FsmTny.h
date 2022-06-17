/*--------------------------------------------------------------------------
FSMTNY.H

Finite state machine(Mealy) tiny functions for ANSI C.

Powered by feallee@hotmail.com at #2022/06/17#.
--------------------------------------------------------------------------*/
#ifndef __FSMTNY_H_
#define __FSMTNY_H_
#include <stddef.h>
/// <summary>
/// ��ʾ״̬���е�һ��״̬��
/// ע�⣺ֻ������״̬��������ú��� FsmTny_Change �� FsmTny_GetCurrent���Ҳ������������ĺ�����
/// FsmTny_Initialize��FsmTny_Transit �� FsmTny_Dispose��
/// </summary>
typedef void (*FsmTnyState)(unsigned int value);

/// <summary>
/// ʹ��ָ����ʼ״̬������״̬��ʼ��״̬����������״̬���ĵ�ǰ״̬Ϊ��ʼ״̬��
/// </summary>
/// <param name="initialState">��ʼ״̬��</param>
/// <param name="finalState">����״̬��</param>
void FsmTny_Initialize(FsmTnyState initialState, FsmTnyState finalState);

/// <summary>
/// ��ȡ״̬���ĵ�ǰ״̬��
/// </summary>
FsmTnyState FsmTny_GetCurrent(void);

/// <summary>
/// ִ��״̬ת�����ڷ���ĳ�¼�����á�
/// </summary>
/// <param name="value">�¼������ı���ֵ������и���Ĺ�������������ʹ��ȫ�ֱ����������ݹ���</param>
/// <returns>����״̬ת���ɹ���־��0=ʧ�ܣ�1=�ɹ���</returns>
unsigned char FsmTny_Transit(unsigned int value);

/// <summary>
/// ָ��״̬������״̬�������Ҫ�л�״̬���������״̬��������ǰ���ô˺�����
/// </summary>
/// <param name="state">��״̬�����Ϊ NULL ����Ч��</param>
void FsmTny_Change(FsmTnyState state);

/// <summary>
/// �ͷ�״̬��ʹ����Դ��
/// </summary>
void FsmTny_Dispose(void);

#endif

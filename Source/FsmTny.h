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
/// ��ʾ״̬���е�һ��״̬�������Ҫ�л�״̬���������״̬��������֮ǰ���ô˺�����
/// ע�⣺ֻ������״̬��������ú��� FsmTny_Change �� FsmTny_GetCurrent���Ҳ������������ĺ�����
/// FsmTny_Initialize��FsmTny_Transit �� FsmTny_Dispose��
/// </summary>
typedef void (*FsmTnyState)(unsigned int value);

/// <summary>
/// ��ʾһ��״̬����
/// </summary>
typedef struct
{
	/// <summary>
	/// ��ʼ״̬��
	/// </summary>
	FsmTnyState Initial;
	/// <summary>
	/// ����״̬��
	/// </summary>
	FsmTnyState Final;
	/// <summary>
	/// ��ǰ״̬��
	/// </summary>
	FsmTnyState Current;
	/// <summary>
	/// ��״̬��
	/// </summary>
	FsmTnyState Next;
}FsmTny;


/// <summary>
/// ʹ��ָ����ʼ״̬������״̬��ʼ��״̬����������״̬���ĵ�ǰ״̬Ϊ��ʼ״̬��
/// </summary>
/// <param name="fsmTny">״̬����</param>
/// <param name="initialState">��ʼ״̬��</param>
/// <param name="finalState">����״̬��</param>
void FsmTny_Initialize(FsmTny* fsmTny, FsmTnyState initialState, FsmTnyState finalState);

/// <summary>
/// ��ȡ״̬���ĵ�ǰ״̬��
/// </summary>
/// <param name="fsmTny">״̬����</param>
FsmTnyState FsmTny_GetCurrent(FsmTny* fsmTny);

/// <summary>
/// ִ��״̬ת�����ڷ���ĳ�¼�����á�
/// </summary>
/// <param name="fsmTny">״̬����</param>
/// <param name="value">�¼������ı���ֵ������и���Ĺ�������������ʹ��ȫ�ֱ����������ݹ���</param>
/// <returns>����״̬ת���ɹ���־��0=ʧ�ܣ�1=�ɹ���</returns>
unsigned char FsmTny_Transit(FsmTny* fsmTny, unsigned int value);

/// <summary>
/// ָ��״̬������״̬��
/// </summary>
/// <param name="fsmTny">״̬����</param>
/// <param name="state">��״̬�����Ϊ NULL ����Ч��</param>
void FsmTny_Change(FsmTny* fsmTny, FsmTnyState state);

/// <summary>
/// �ͷ�״̬��ʹ�õ���Դ��
/// </summary>
/// <param name="fsmTny">״̬����</param>
void FsmTny_Dispose(FsmTny* fsmTny);

#endif

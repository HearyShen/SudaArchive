#include "sapi.h"
#include "sphelper.h"

#pragma comment(lib, "sapi.lib")	// ����lib��

void main()
{
	ISpVoice *pSpVoice;		// ����TTS����ӿ�ָ��
	::CoInitialize(NULL);	// COM��ʼ��

	CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice);	// ��ȡISpVoice�ӿ�ָ��

	printf("Speak\n");
	pSpVoice->SetVolume(100);	// ��������
	pSpVoice->Speak(TEXT(L"Tom"),	// L��Ϊ�ַ���ǰ׺����֪������ʹ�õȿ������ֽڵ�Unicode�ַ���
		SPF_DEFAULT,	// SND_SYNC/SPF_DEFAULT ͬ�����ţ��ڲ������Speak�ŷ��أ���SND_ASYNC/SPF_ASYNC �첽���ţ���ʼ����ʱSpeak�������ء�
		NULL);

	printf("Speak return.\n");
	getchar();
	pSpVoice->Release();
	::CoUninitialize();
}
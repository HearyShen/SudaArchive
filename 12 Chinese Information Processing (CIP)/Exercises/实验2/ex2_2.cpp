#include "sapi.h"
#include "sphelper.h"

#pragma comment(lib, "sapi.lib")	// 引用lib库

void main()
{
	ISpVoice *pSpVoice;		// 定义TTS引擎接口指针
	::CoInitialize(NULL);	// COM初始化

	CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice);	// 获取ISpVoice接口指针

	printf("Speak\n");
	pSpVoice->SetVolume(100);	// 设置音量
	pSpVoice->Speak(TEXT(L"Tom"),	// L作为字符串前缀，告知编译器使用等宽两个字节的Unicode字符集
		SPF_DEFAULT,	// SND_SYNC/SPF_DEFAULT 同步播放，在播放完后Speak才返回；另：SND_ASYNC/SPF_ASYNC 异步播放，开始播放时Speak立即返回。
		NULL);

	printf("Speak return.\n");
	getchar();
	pSpVoice->Release();
	::CoUninitialize();
}
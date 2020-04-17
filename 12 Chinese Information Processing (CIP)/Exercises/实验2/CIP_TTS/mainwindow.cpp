/**
  中文信息梳理
  实验二 - TTS发音
  1427405017
  沈家赟
  2017.11.5
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushBtn_read, SIGNAL(clicked(bool)), this, SLOT(readText()));
    connect(ui->pushBtn_spell, SIGNAL(clicked(bool)), this, SLOT(spellText()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * readText
 * 朗读输入的字符串
*/
void MainWindow::readText()
{
    QString text;
    wchar_t wCharArr[MAX_SIZE];

    text = ui->textEdit->toPlainText();
    if( text.length() > MAX_SIZE)
    {
        QMessageBox::warning(this, "预览", "输入数据过长",QMessageBox::Ok);
        return;
    }

    // 转换为等宽两个字节的Unicode字符集
    memset(wCharArr, 0, sizeof(wCharArr));  // 注意，容器使用前清空！否则会朗读残留数据
    text.toWCharArray(wCharArr);


    ISpVoice *pSpVoice;		// 定义TTS引擎接口指针
    ::CoInitialize(NULL);	// COM初始化

    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice);	// 获取ISpVoice接口指针

    std::cout<<"Speak"<<std::endl;
    pSpVoice->SetVolume(100);	// 设置音量
    pSpVoice->Speak(wCharArr,	// 使用等宽两个字节的Unicode字符集
        SPF_DEFAULT,	// SND_SYNC/SPF_DEFAULT 同步播放，在播放完后Speak才返回；另：SND_ASYNC/SPF_ASYNC 异步播放，开始播放时Speak立即返回。
        NULL);

    std::cout<<"Speak return."<<std::endl;
    pSpVoice->Release();
    ::CoUninitialize();

    return;
}


/**
 * spellText
 * 拼读输入的字符串
*/
void MainWindow::spellText()
{
    QString text;
    wchar_t wCharArr[MAX_SIZE];

    text = "<spell>" + ui->textEdit->toPlainText() + "</spell>";
    if( text.length() > MAX_SIZE)
    {
        QMessageBox::warning(this, "预览", "输入数据过长",QMessageBox::Ok);
        return;
    }

    // 转换为等宽两个字节的Unicode字符集
    memset(wCharArr, 0, sizeof(wCharArr));  // 注意，容器使用前清空！否则会朗读残留数据
    text.toWCharArray(wCharArr);


    ISpVoice *pSpVoice;		// 定义TTS引擎接口指针
    ::CoInitialize(NULL);	// COM初始化

    CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_INPROC_SERVER, IID_ISpVoice, (void **)&pSpVoice);	// 获取ISpVoice接口指针

    std::cout<<"Speak"<<std::endl;
    pSpVoice->SetVolume(100);	// 设置音量
    pSpVoice->SetRate(-4);      // 设置速度
    pSpVoice->Speak(wCharArr,	// 使用等宽两个字节的Unicode字符集
        SPF_DEFAULT,	// SND_SYNC/SPF_DEFAULT 同步播放，在播放完后Speak才返回；另：SND_ASYNC/SPF_ASYNC 异步播放，开始播放时Speak立即返回。
        NULL);

    std::cout<<"Speak return."<<std::endl;
    pSpVoice->Release();
    ::CoUninitialize();

    return;
}


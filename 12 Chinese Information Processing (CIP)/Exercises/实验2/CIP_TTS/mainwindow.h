#ifndef MAINWINDOW_H
/**
  中文信息梳理
  实验二 - TTS发音
  1427405017
  沈家赟
  2017.11.5
*/

#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>

#include "sapi.h"
#include "sphelper.h"

#pragma comment(lib, "sapi.lib")	// 引用lib库

#define MAX_SIZE 200

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void readText();
    void spellText();
};

#endif // MAINWINDOW_H

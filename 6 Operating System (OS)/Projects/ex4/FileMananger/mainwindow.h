#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onUserClicked(QListWidgetItem*);
    void onFileClicked(QListWidgetItem*);
    void onFileDoubleClicked(QListWidgetItem*);
    void onPathReturned();
    void onBtnOpenClicked(bool);
    void onBtnNewClicked(bool);
    void onBtnDeleteClicked(bool);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

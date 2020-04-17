/**
  操作系统课程设计
  实验四 - 文件管理
  1427405017
  沈家赟
  2017.6.10
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     * 以上为MainWindow构造函数默认初始化部分
     * 此处开始初始化组件显示
    */
    ui->lineEdit_path->setText("/home");
    onPathReturned();
    ui->label_properties->setText("Welcome");
    QDir mainDir(ui->lineEdit_path->text());
    ui->listWidget_users->clear();

    /*
     * 解析出/home目录下的用户列表
     * 清除.和..目录文件
    */
    QStringList users = mainDir.entryList();
    for(int i=0;i<users.size();i++)
    {
        if(users.at(i)=="." || users.at(i)=="..")
        {
            users.removeAt(i);
            i--;
        }
    }
    ui->listWidget_users->addItems(users);

    ui->pushButton_delete->setEnabled(false);


    /*
     * signal & slot
     * 在MainWindow的构造函数中实现signal和slot的信号连接
     * slot命名风格均定为：on<Widget><Event>
    */
    // 列表框图
    connect(ui->listWidget_users, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onUserClicked(QListWidgetItem*)));
    connect(ui->listWidget_files, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(onFileClicked(QListWidgetItem*)));
    connect(ui->listWidget_files, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onFileDoubleClicked(QListWidgetItem*)));

    // 路径框
    connect(ui->lineEdit_path, SIGNAL(returnPressed()), this, SLOT(onPathReturned()));

    // 功能按钮
    connect(ui->pushButton_open, SIGNAL(clicked(bool)), this, SLOT(onBtnOpenClicked(bool)));
    connect(ui->pushButton_new, SIGNAL(clicked(bool)), this, SLOT(onBtnNewClicked(bool)));
    connect(ui->pushButton_delete, SIGNAL(clicked(bool)), this, SLOT(onBtnDeleteClicked(bool)));
}


/**
 * 默认析构函数
 * 释放ui对象的所有内存空间
*/
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * onUserClicked
 * 单击用户，选中用户并切换到目标用户的文件目录
*/
void MainWindow::onUserClicked(QListWidgetItem *item)
{
    QString currentUser = item->text();

    ui->lineEdit_path->setText("/home/"+currentUser);
    onPathReturned();
}

/**
 * onFileClicked
 * 单击文件，选中文件并在属性框显示文件基本属性（大小，所属用户、所属组等信息）
*/
void MainWindow::onFileClicked(QListWidgetItem *item)
{

//    ui->lineEdit_path->setText(ui->lineEdit_path->text()+item->text());

    QString path = ui->lineEdit_path->text()+"/"+item->text();
    QFile file(path);
    QFileInfo info(file);

    QString prop_type = info.isDir()?"Dir":"File";
    QString prop_size = QString::number(info.size())+" Bytes";

    QString properties = info.fileName()+"\n"
            +prop_type+"\n"
            +prop_size+"\n"
            +"User: "+info.owner()+"\n"
            +"Group: "+info.group();

    ui->label_properties->setText(properties);
//    std::cout<<properties.toStdString()<<std::endl;

    file.close();

    ui->pushButton_delete->setEnabled(true);
}

/**
 * onFileDoubleClicked
 * 双击文件，表示进入目录文件或打开一般文件
*/
void MainWindow::onFileDoubleClicked(QListWidgetItem *item)
{
    QString path = ui->lineEdit_path->text()+"/"+item->text();
    QFile file(path);
    QFileInfo info(file);

    if(info.isDir())
    {
        QDir dir(path);
        QStringList entryList = dir.entryList();

        // 刷新文件列表
        ui->listWidget_files->clear();
        ui->listWidget_files->addItems(entryList);
        // 刷新当前路径编辑框
        ui->lineEdit_path->setText(info.absoluteFilePath());

        std::cout<<"Change Dir to "<<info.absoluteFilePath().toStdString()<<std::endl;
    }
    else
    {
        file.open(QFile::ReadOnly);
        QString content = file.readAll();
        QString demoStr;
//        ui->label_properties->setText(content);

        /*
         * 生成预览字符串
         * 截取过长的文件内容，避免窗口异常
        */
        if(content.length()>600)
        {
            demoStr = content.mid(0,600);
            demoStr += "\n\n...\n";
        }
        else
        {
            demoStr = content;
        }
        QMessageBox::information(this, "预览", demoStr,QMessageBox::Ok);
    }

    file.close();
}

/**
 * onPathReturned
 * 处理路径框数据，如果用户回车确认修改当前路径，则切换到目标路径
*/
void MainWindow::onPathReturned()
{
    QString path = ui->lineEdit_path->text();
    QFile file(path);
    QFileInfo info(file);

    if(info.isDir())
    {
        QDir dir(path);
        QStringList entryList = dir.entryList();

        ui->listWidget_files->clear();
        ui->listWidget_files->addItems(entryList);
    }
    else
    {
        ui->label_properties->setText("目标路径不存在或不是有效目录！");
    }

    file.close();
}

/**
 * onBtnOpenClicked
 * 处理“打开”按钮，打开选中目录或文件
*/
void MainWindow::onBtnOpenClicked(bool)
{
    if(ui->listWidget_files->selectedItems().empty())
        return;

    std::cout<<"Open"<<std::endl;
    onFileDoubleClicked(ui->listWidget_files->selectedItems().at(0));
}

/**
 * onBtnNewClicked
 * 处理“新建”按钮，新建文件
*/
void MainWindow::onBtnNewClicked(bool)
{
    bool finish;
    QString filename = QInputDialog::getText(this, "新建文件", "文件名：", QLineEdit::Normal,"newFile.txt",&finish);
    if(finish)
    {
        std::cout<<filename.toStdString()<<std::endl;
    }
    else
    {
        return;
    }

    QString path = ui->lineEdit_path->text()+"/"+filename;
    QFile file(path);
    if(!file.open(QFile::ReadWrite))
    {
        std::cout<<"Error "<<file.errorString().toStdString()<<std::endl;
        ui->label_properties->setText(file.errorString());
        file.close();
        return;
    }
    file.write("Hello World!");

    file.close();

    onPathReturned();   // 刷新显示当前路径

    std::cout<<"New"<<path.toStdString()<<std::endl;
}

/**
 * onBtnDeleteClicked
 * 处理“删除”按钮，删除文件
*/
void MainWindow::onBtnDeleteClicked(bool)
{
    if(ui->listWidget_files->selectedItems().empty())
        return;

    QString path = ui->lineEdit_path->text()+"/"+ui->listWidget_files->selectedItems().at(0)->text();

    QFile file(path);
    if(!file.open(QFile::ReadWrite))
    {
        std::cout<<"Error "<<file.errorString().toStdString()<<std::endl;
        ui->label_properties->setText(file.errorString());
        file.close();
        return;
    }

    int ret = QMessageBox::warning(this, "删除", "确认要删除？", QMessageBox::Yes, QMessageBox::No);
    if(ret == QMessageBox::No)
    {
        file.close();
        return;
    }


    if(!file.remove())
    {
        ui->label_properties->setText(file.errorString());
    }
    std::cout<<"del success"<<std::endl;

    file.close();

    onPathReturned();   // 刷新显示当前路径

    std::cout<<"Delete"<<path.toStdString()<<std::endl;
}




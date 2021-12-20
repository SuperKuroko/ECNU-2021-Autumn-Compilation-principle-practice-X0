#include <fstream>
#include "widget.h"
#include "x0.tab.h"
#ifdef __cplusplus
extern "C" {
#endif
    void init();
    void set_address(int n);
    void display_table();
    void display_pcode();
    void interpret();
    void reset();
    void myerror();
    int position_fun(char* a);
    void X0_Compiler(const char *file);
#ifdef __cplusplus
}
#endif
Widget::Widget(QWidget *parent): QWidget(parent)
{
    setFixedSize(2500,1600);
    setWindowTitle("Lex-Yacc");
    InitMenuBar();
    InitToolBar();
    InitStatusBar();
}

void Widget::InitMenuBar()
{
    //菜单栏
    MenuBar = new QMenuBar(this);

    //文件
    MenuBarFile= new QMenu(QStringLiteral("文件(&F)"));

    NewFile = new QAction(QStringLiteral("新建文件"), this);
    NewFile->setShortcut(Qt::CTRL | Qt::Key_N);
    NewFile->setIcon(QIcon(":/IMG/img/NewFile2.jpeg"));
    MenuBarFile->addAction(NewFile);

    OpenFile = new QAction(QStringLiteral("打开文件"), this);
    OpenFile->setShortcut(Qt::CTRL | Qt::Key_O);
    OpenFile->setIcon(QIcon(":/IMG/img/OpenFile2.jpeg"));
    MenuBarFile->addAction(OpenFile);

    SaveFile = new QAction(QStringLiteral("保存文件"), this);
    SaveFile->setShortcut(Qt::CTRL | Qt::Key_S);
    SaveFile->setIcon(QIcon(":/IMG/img/SaveFile.jpeg"));
    MenuBarFile->addAction(SaveFile);

    SaveAs = new QAction(QStringLiteral("另存为"), this);
    SaveAs->setIcon(QIcon(":/IMG/img/SaveAs.jpeg"));
    MenuBarFile->addAction(SaveAs);

    CloseFile = new QAction(QStringLiteral("关闭文件"), this);
    CloseFile->setShortcut(Qt::CTRL | Qt::Key_W);
    CloseFile->setIcon(QIcon(":/IMG/img/CloseFile.jpeg"));
    MenuBarFile->addAction(CloseFile);

    Exit = new QAction(QStringLiteral("退出"), this);
    Exit->setShortcut(Qt::ALT | Qt::Key_F4);
    Exit->setIcon(QIcon(":/IMG/img/Exit.jpeg"));
    MenuBarFile->addAction(Exit);

    //运行
    RunFile= new QMenu(QStringLiteral("运行(&R)"));

    Run = new QAction(QStringLiteral("运行"), this);
    Run->setShortcut(Qt::CTRL | Qt::Key_R);
    RunFile->addAction(Run);

    //帮助
    Help = new QMenu(QStringLiteral("帮助(&H)"));

    Author = new QAction(QStringLiteral("作者信息"), this);
    Author->setShortcut(Qt::CTRL | Qt::Key_F11);
    Help->addAction(Author);

    MenuBar->addMenu(MenuBarFile);
    MenuBar->addMenu(RunFile);
    MenuBar->addMenu(Help);


}

void Widget::InitToolBar()
{
    ToolBar = new QToolBar(this);
    ToolBar->move(20,50);
    OpenFile_tb = new QToolButton(this);
    OpenFile_tb->setIcon(QIcon(":/IMG/img/OpenFile.jpeg"));
    OpenFile_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    OpenFile_tb->setText(QStringLiteral("打开"));
    ToolBar->addWidget(OpenFile_tb);

    //添加其他按钮...
    //添加分隔符
    ToolBar->addSeparator();
}


void Widget::InitStatusBar()
{
    QStatusBar *pStatusBar = new QStatusBar(this);
    pStatusBar->move(0,500);
    pStatusBar->setFixedSize(2500,500);
    QLabel *pWelCome = new QLabel(QStringLiteral("  就绪"));
    pStatusBar->addWidget(pWelCome);

    QProgressBar * pProgressBar = new QProgressBar();
    pProgressBar->setRange(0,100);
    pProgressBar->setValue(20);
    pProgressBar->setMaximumWidth(200);
    pStatusBar->addPermanentWidget(pProgressBar);
    QLabel *pTimeLabel = new QLabel();
    pStatusBar->addPermanentWidget(pTimeLabel);

    QTimer *pTimer = new QTimer(this);
    //timeUpdate_Slot();
    pTimer->start(1000);
    //connect(pTimer, SIGNAL(timeout()),this,SLOT(timeUpdate_Slot()));

    //更新时间的槽函数中的代码
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeStr = currentTime.toString(QStringLiteral("yyyy年MM月dd日 hh:mm:ss"));

    pTimeLabel->setText(timeStr);
}
void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(rect());
    painter.setPen(QPen(Qt::black,1));
    painter.drawLine(0,40,2500,40);
}

Widget::~Widget()
{

}


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

using namespace std;
Widget::Widget(QWidget *parent): QWidget(parent)
{
    setFixedSize(2000,1600);
    setWindowTitle("X0 Compiler: none file");
    InitMenuBar();
    InitToolBar();
    InitStatusBar();
    InitTextEdit();
}


void Widget::InitMenuBar()
{
    MenuBar = new QMenuBar(this);
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

    RunFile= new QMenu(QStringLiteral("运行(&R)"));

    Make = new QAction(QStringLiteral("编译"), this);
    Make->setShortcut(Qt::Key_F9);
    Make->setIcon(QIcon(":/IMG/img/Make.jpeg"));
    RunFile->addAction(Make);

    SRun = new QAction(QStringLiteral("单步执行"), this);
    SRun->setShortcut(Qt::Key_F11);
    SRun->setIcon(QIcon(":/IMG/img/SRun.jpeg"));
    RunFile->addAction(SRun);

    MRun = new QAction(QStringLiteral("编译运行"), this);
    MRun->setShortcut(Qt::CTRL | Qt::Key_R);
    MRun->setIcon(QIcon(":/IMG/img/MRun.jpeg"));
    RunFile->addAction(MRun);

    View = new QMenu(QStringLiteral("视图(&V)"));

    vtable = new QAction(QStringLiteral("符号表"), this);
    vtable->setShortcut(Qt::Key_F4);
    vtable->setIcon(QIcon(":/IMG/img/Table.jpeg"));
    View->addAction(vtable);

    vout = new QAction(QStringLiteral("输出结果"), this);
    vout->setShortcut(Qt::Key_F5);
    vout->setIcon(QIcon(":/IMG/img/Out.jpeg"));
    View->addAction(vout);

    verror = new QAction(QStringLiteral("编译信息"), this);
    verror->setShortcut(Qt::Key_F6);
    verror->setIcon(QIcon(":/IMG/img/Error.jpeg"));
    View->addAction(verror);

    Help = new QMenu(QStringLiteral("帮助(&H)"));

    Author = new QAction(QStringLiteral("作者信息"), this);
    Author->setShortcut(Qt::CTRL | Qt::Key_F11);
    Author->setIcon(QIcon(":/IMG/img/Kuroko.png"));
    Help->addAction(Author);

    MenuBar->addMenu(MenuBarFile);
    MenuBar->addMenu(View);
    MenuBar->addMenu(RunFile);
    MenuBar->addMenu(Help);

    connect(NewFile, SIGNAL(triggered()),this, SLOT(createFile()));
    connect(OpenFile, SIGNAL(triggered()),this, SLOT(openFileDialog()));
    connect(SaveFile, SIGNAL(triggered()),this, SLOT(saveFile()));
    connect(SaveAs, SIGNAL(triggered()),this, SLOT(saveFileDialog()));
    connect(CloseFile, SIGNAL(triggered()),this, SLOT(closeFile()));
    connect(vtable, SIGNAL(triggered()),this, SLOT(displayTable()));
    connect(vout, SIGNAL(triggered()),this, SLOT(displayResult()));
    connect(verror, SIGNAL(triggered()),this, SLOT(displayError()));
    connect(Make, SIGNAL(triggered()),this, SLOT(BuildXcode()));
    connect(SRun, SIGNAL(triggered()),this, SLOT(SingleRun()));
    connect(MRun, SIGNAL(triggered()),this, SLOT(BuildRun()));
    connect(Author, SIGNAL(triggered()),this, SLOT(AuthorInfo()));
}

void Widget::InitToolBar()
{
    ToolBar = new QToolBar(this);
    ToolBar->move(20,50);

    NewFile_tb = new QToolButton(this);
    NewFile_tb->setIcon(QIcon(":/IMG/img/NewFile.jpeg"));
    NewFile_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    NewFile_tb->setText(QStringLiteral("新建文件"));
    ToolBar->addWidget(NewFile_tb);
    ToolBar->addSeparator();

    OpenFile_tb = new QToolButton(this);
    OpenFile_tb->setIcon(QIcon(":/IMG/img/OpenFile.jpeg"));
    OpenFile_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    OpenFile_tb->setText(QStringLiteral("打开文件"));
    ToolBar->addWidget(OpenFile_tb);
    ToolBar->addSeparator();

    SaveFile_tb = new QToolButton(this);
    SaveFile_tb->setIcon(QIcon(":/IMG/img/SaveFile.jpeg"));
    SaveFile_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    SaveFile_tb->setText(QStringLiteral("保存文件"));
    ToolBar->addWidget(SaveFile_tb);
    ToolBar->addSeparator();

    SaveAs_tb = new QToolButton(this);
    SaveAs_tb->setIcon(QIcon(":/IMG/img/SaveAs.jpeg"));
    SaveAs_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    SaveAs_tb->setText(QStringLiteral("另存为"));
    ToolBar->addWidget(SaveAs_tb);
    ToolBar->addSeparator();

    CloseFile_tb = new QToolButton(this);
    CloseFile_tb->setIcon(QIcon(":/IMG/img/CloseFile2.jpeg"));
    CloseFile_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    CloseFile_tb->setText(QStringLiteral("关闭文件"));
    ToolBar->addWidget(CloseFile_tb);
    ToolBar->addSeparator();

    Table_tb = new QToolButton(this);
    Table_tb->setIcon(QIcon(":/IMG/img/Table.jpeg"));
    Table_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Table_tb->setText(QStringLiteral("符号表"));
    ToolBar->addWidget(Table_tb);

    Out_tb = new QToolButton(this);
    Out_tb->setIcon(QIcon(":/IMG/img/Out2.jpeg"));
    Out_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Out_tb->setText(QStringLiteral("输出结果"));
    ToolBar->addWidget(Out_tb);

    Error_tb = new QToolButton(this);
    Error_tb->setIcon(QIcon(":/IMG/img/Error.jpeg"));
    Error_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Error_tb->setText(QStringLiteral("编译信息"));
    ToolBar->addWidget(Error_tb);

    Build_tb = new QToolButton(this);
    Build_tb->setIcon(QIcon(":/IMG/img/Make.jpeg"));
    Build_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Build_tb->setText(QStringLiteral("编译文件"));
    ToolBar->addWidget(Build_tb);

    SRun_tb = new QToolButton(this);
    SRun_tb->setIcon(QIcon(":/IMG/img/SRun.jpeg"));
    SRun_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    SRun_tb->setText(QStringLiteral("单步调试"));
    ToolBar->addWidget(SRun_tb);

    MRun_tb = new QToolButton(this);
    MRun_tb->setIcon(QIcon(":/IMG/img/MRun.jpeg"));
    MRun_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    MRun_tb->setText(QStringLiteral("编译执行"));
    ToolBar->addWidget(MRun_tb);

    Kuroko_tb = new QToolButton(this);
    Kuroko_tb->setIcon(QIcon(":/IMG/img/Kuroko.png"));
    Kuroko_tb->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    Kuroko_tb->setText(QStringLiteral("作者信息"));
    ToolBar->addWidget(Kuroko_tb);
    ToolBar->addSeparator();

    connect(NewFile_tb, SIGNAL(clicked(bool)),this, SLOT(createFile()));
    connect(OpenFile_tb, SIGNAL(clicked(bool)),this, SLOT(openFileDialog()));
    connect(SaveFile_tb, SIGNAL(clicked(bool)),this, SLOT(saveFile()));
    connect(SaveAs_tb, SIGNAL(clicked(bool)),this, SLOT(saveFileDialog()));
    connect(CloseFile_tb, SIGNAL(clicked(bool)),this, SLOT(closeFile()));
    connect(Table_tb, SIGNAL(clicked(bool)),this, SLOT(displayTable()));
    connect(Out_tb, SIGNAL(clicked(bool)),this, SLOT(displayResult()));
    connect(Error_tb, SIGNAL(clicked(bool)),this, SLOT(displayError()));
    connect(Build_tb, SIGNAL(clicked(bool)),this, SLOT(BuildXcode()));
    connect(SRun_tb, SIGNAL(clicked(bool)),this, SLOT(SingleRun()));
    connect(MRun_tb, SIGNAL(clicked(bool)),this, SLOT(BuildRun()));
    connect(Kuroko_tb, SIGNAL(clicked(bool)),this, SLOT(AuthorInfo()));
}


void Widget::InitStatusBar()
{
    pStatusBar = new QStatusBar(this);
    pStatusBar->move(1000,1520);
    pStatusBar->setFixedSize(1000,100);
    pInfo = new QLabel(QStringLiteral("尚未编译"));
    pStatusBar->addWidget(pInfo);

    pProgressBar = new QProgressBar();
    pProgressBar->setRange(0,100);
    pProgressBar->setValue(0);
    pProgressBar->setMaximumWidth(200);
    pStatusBar->addPermanentWidget(pProgressBar);

    pTimeLabel = new QLabel();
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeStr = currentTime.toString(QStringLiteral("yyyy年MM月dd日 hh:mm:ss"));
    pTimeLabel->setText(timeStr);
    pTimer = new QTimer(this);
    pTimer->start(1000);
    connect(pTimer, SIGNAL(timeout()),this,SLOT(timeUpdate()));
    pStatusBar->addPermanentWidget(pTimeLabel);

}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    painter.setBrush(Qt::white);
    painter.setPen(QPen(Qt::black,1));
    painter.drawLine(0,40,2500,40);
    painter.drawLine(0,140,2500,140);
    if(isSRun)
    {
        int width = 150,height = 50;
        int x1 = 1800,y1 = 1480;
        for(int i = 1;i <= st;i++)
        {
            if(z[i] == 0) painter.setBrush(Qt::white);
            if(z[i] == 1) painter.setBrush(Qt::blue);
            if(z[i] == 2) painter.setBrush(Qt::red);
            painter.drawRect(x1,y1,width,height);
            painter.drawText(x1+75,y1+35,QString::fromStdString(to_string(s[i])));
            painter.drawText(x1-30,y1+35,QString::fromStdString(to_string(i-1)));
            y1 -= height;
        }
    }
}

void Widget::timeUpdate()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeStr = currentTime.toString(QStringLiteral("yyyy年MM月dd日 hh:mm:ss"));
    pTimeLabel->setText(timeStr);
}

void Widget::InitTextEdit()
{
    xcode = new QTextEdit(this);
    xcode->move(2,150);
    xcode->setFixedSize(1400,800);
    xcode->setFont(QFont("宋体",12));
    xcode->setPlaceholderText("代码区");
    xcode->setReadOnly(true);

    ycode = new QTextEdit(this);
    ycode->move(1450,150);
    ycode->setFixedSize(250,1380);
    ycode->setFont(QFont("宋体",12));
    ycode->setReadOnly(true);
    ycode->setPlaceholderText("中间代码");

    result = new QTextEdit(this);
    result->move(2, 1000);
    result->setFixedSize(1400,530);
    result->setFont(QFont("宋体",12));
    result->setReadOnly(true);
    result->setPlaceholderText("符号表");

}

void Widget::InitVar()
{
    fileName = "";
    hasOpened = false;
    isBuild = false;
    isSRun = false;
}


void Widget::createFile()
{
    fileName = "";
    hasOpened = true;
    setWindowTitle("X0 Compiler: new file");
    xcode->setText("");
    ycode->setText("");
    result->setText("");
    xcode->setReadOnly(false);
    isSRun = false;
    update();
}

void Widget::openFileDialog()
{
    fileName = QFileDialog::getOpenFileName(this,tr("选择文件"), ".", tr("Text Files(*.txt)")).toStdString();
    if(!fileName.empty())
    {
        xcode->setReadOnly(false);
        hasOpened = true;
        setWindowTitle("X0 Compiler: "+QString::fromStdString(fileName));
        ifstream in(fileName);
        string s,text = "";
        while(getline(in,s)) text += s+"\n";
        in.close();
        xcode->setText(QString::fromStdString(text));
        ycode->setText("");
        result->setText("");
        isSRun = false;
        update();
    }
}

void Widget::saveFile()
{
    if(!hasOpened)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚未打开或创建文件!", QMessageBox::Ok);
        return ;
    }

    if(fileName.empty())
    {
        saveFileDialog();
        return ;
    }

    string s = xcode->toPlainText().toStdString();
    ofstream o(fileName);
    o<<s;
    o.close();
}

void Widget::saveFileDialog()
{
    if(!hasOpened)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚未打开或创建文件!", QMessageBox::Ok);
        return ;
    }
    fileName = QFileDialog::getSaveFileName(this, tr("保存文件"),"", tr("Text Files(*.txt)")).toStdString();

    if (!fileName.empty())
    {
        setWindowTitle("X0 Compiler: "+QString::fromStdString(fileName));
        string s = xcode->toPlainText().toStdString();
        ofstream o(fileName);
        o<<s;
        o.close();
    }
}

void Widget::closeFile()
{
    setWindowTitle("X0 Compiler: none file");
    fileName = "";
    hasOpened = false;
    xcode->setReadOnly(true);
    xcode->setText("");
    ycode->setText("");
    result->setText("");
    isSRun = false;
    update();
}

void Widget::displayTable()
{
    if(!isBuild)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚进行编译!", QMessageBox::Ok);
        return ;
    }
    ifstream in("table.txt");
    string s,text = "";
    while(getline(in,s)) text += s+"\n";
    in.close();
    result->setText(QString::fromStdString(text));
}

void Widget::displayResult()
{
    if(!isBuild)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚进行编译!", QMessageBox::Ok);
        return ;
    }
    ifstream in("out.txt");
    string s,text = "";
    while(getline(in,s)) text += s+"\n";
    in.close();
    result->setText(QString::fromStdString(text));
}

void Widget::displayError()
{
    if(!isBuild)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚进行编译!", QMessageBox::Ok);
        return ;
    }
    ifstream in("error.txt");
    string s,text = "";
    while(getline(in,s)) text += s+"\n";
    in.close();
    result->setText(QString::fromStdString(text));

}

void Widget::displayXcode()
{
    ifstream in("code.txt");
    string s,text = "";
    while(getline(in,s)) text += s+"\n";
    in.close();
    ycode->setText(QString::fromStdString(text));

}

void Widget::BuildXcode()
{
    if(!hasOpened)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚未打开或创建文件!", QMessageBox::Ok);
        return ;
    }

    if(fileName.empty())
    {
        saveFileDialog();
        return ;
    }
    saveFile();
    isBuild = true;
    pInfo->setText("编译完成");
    X0_Compiler(fileName.c_str());
    readXcode();
    displayTable();
    displayXcode();
}

void Widget::SingleRun()
{
    if(!isBuild)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚进行编译!", QMessageBox::Ok);
        return ;
    }
    if(!isSRun)
    {
        pInfo->setText("单步执行模式");
        isSRun = true;
        pProgressBar->setValue(0);
        if ((sout = fopen("out.txt", "w")) == NULL)
        {
            QMessageBox::critical(NULL,  "错误",  "Can't open out.txt file!", QMessageBox::Ok);
            exit(1);
        }
        sp = 0; /* 指令指针 */
        sb = 1; /* 指令基址 */
        st = 0; /* 栈顶指针 */
        si = pcode[sp];
        sp++;
        fprintf(sout,"Start X0\n");
        memset(s, 0 ,sizeof(s));
        memset(z, 0 ,sizeof(z));
        z[1] = z[2] = z[3] = 2;
        runXcodeStepByStep();
        update();
    }
    else
    {
        if(sp == 0)
        {
            QMessageBox::about(NULL, "编译信息", "指令已被全部执行完！");
            pInfo->setText("执行完成");
            isSRun = false;
            fprintf(sout,"End X0\n");
            fclose(sout);
            return ;
        }
        si = pcode[sp];
        sp++;
        pProgressBar->setValue(sp*100/pi);
        runXcodeStepByStep();
        for(int i = st+1;i < 100;i++) z[i] = 0;
        update();
    }
}

void Widget::BuildRun()
{
    if(!hasOpened)
    {
        QMessageBox::critical(NULL,  "错误",  "您尚未打开或创建文件!", QMessageBox::Ok);
        return ;
    }

    if(fileName.empty())
    {
        saveFileDialog();
        return ;
    }
    saveFile();
    isBuild = true;
    pInfo->setText("编译完成");
    pProgressBar->setValue(100);
    X0_Compiler(fileName.c_str());
    readXcode();
    displayTable();
    displayXcode();
    runXcode();

}

void Widget::getInput(int mod, const char* info)
{
    while(true)
    {
        bool ok,f = true;
        if(mod == 0)sin = QInputDialog::getText(this, tr("输入框"),
                                             tr(info), QLineEdit::Normal,
                                             "0", &ok).toStdString();
        if(mod == 1)sin = QInputDialog::getText(this, tr("输入框"),
                                             tr(info), QLineEdit::Normal,
                                             "a", &ok).toStdString();
        if(mod == 2)sin = QInputDialog::getText(this, tr("输入框"),
                                             tr(info), QLineEdit::Normal,
                                             "0", &ok).toStdString();
        if(sin.empty())
        {
            QMessageBox::critical(NULL,  "错误",  "输入为空", QMessageBox::Ok);
            continue ;
        }
        if(mod == 0 || mod == 2)
        {
            for(int i = 0;i < (int)sin.size();i++)
            {
                if(sin[i] < '0' || sin[i] > '9')
                {
                    f = false;
                    break;
                }
            }
        }
        if(mod == 1 && sin.size() != 1) f = false;
        if(f && ok)
        {
            break;
        }
    }
}

void Widget::runXcodeStepByStep()
{
    switch (si.f)
    {
        case pop:
            st = st - si.a;
            break;
        case lit:
            st = st + 1;
            s[st] = si.a;
            break;
        case opr:
            switch (si.a)
            {
                case 0:
                    st = sb - 1;
                    sp = s[st + 3];
                    sb = s[st + 2];
                    st += si.l;
                    break;
                case 1:
                    s[st] = - s[st];
                    break;
                case 2:
                    st = st - 1;
                    s[st] = s[st] + s[st + 1];
                    break;
                case 3:
                    st = st - 1;
                    s[st] = s[st] - s[st + 1];
                    break;
                case 4:
                    st = st - 1;
                    s[st] = s[st] * s[st + 1];
                    break;
                case 5:
                    st = st - 1;
                    s[st] = s[st] / s[st + 1];
                    break;
                case 6:
                    s[st] = s[st] % 2;
                    break;
                case 8:
                    st = st - 1;
                    s[st] = (s[st] == s[st + 1]);
                    break;
                case 9:
                    st = st - 1;
                    s[st] = (s[st] != s[st + 1]);
                    break;
                case 10:
                    st = st - 1;
                    s[st] = (s[st] < s[st + 1]);
                    break;
                case 11:
                    st = st - 1;
                    s[st] = (s[st] >= s[st + 1]);
                    break;
                case 12:
                    st = st - 1;
                    s[st] = (s[st] > s[st + 1]);
                    break;
                case 13:
                    st = st - 1;
                    s[st] = (s[st] <= s[st + 1]);
                    break;
                case 14:
                    if(si.l == 0)
                    {

                        fprintf(sout, "%d", s[st]);
                    }
                    else if(si.l == 1)
                    {

                        fprintf(sout,"%c",s[st]);
                    }
                    else if(si.l == 2)
                    {

                        fprintf(sout,"%s",(s[st]==0)?"false":"true");
                    }
                    break;
                case 15:
                    fprintf(sout,"\n");
                    break;
                case 16:
                    st = st + 1;
                    fprintf(sout, "?");
                    if(si.l == 0)
                    {
                        getInput(0, "read a int:");
                        s[st] = stoi(sin);
                        fprintf(sout, "%d\n", s[st]);
                    }
                    else if(si.l == 1)
                    {
                        getInput(1, "read a char:");
                        s[st] = sin[0];
                        fprintf(sout, "%c\n", s[st]);
                    }
                    else
                    {
                        getInput(2, "read a bool:");
                        s[st] = stoi(sin);
                        fprintf(sout, "%d\n", s[st]);
                        if(s[st] != 0) s[st] = 1;
                    }
                    break;
                case 17:
                    st = st - 1;
                    s[st] = s[st] % s[st + 1];
                    break;
                case 18:
                    st = st - 1;
                    if(s[st] != 0) s[st] = 1;
                    if(s[st+1] != 0) s[st+1] = 1;
                    if(si.l == 0) s[st] = s[st]&s[st+1];
                    else if(si.l == 1) s[st] = s[st]|s[st+1];
                    else if(si.l == 2) s[st] = s[st]^s[st+1];
                    break;
                case 19:
                    if(s[st] != 0) s[st] = 0;
                    else s[st] = 1;
                    break;
                case 20:
                    s[st] = s[st]%2;
                    break;
            }
            break;
        case lod:
            st = st + 1;
            s[st] = s[si.a+sb];
            break;
        case sto:
            if(si.l == 0) s[sb+si.a] = s[st];
            else if(si.l == 1) s[st+si.a] = s[st];
            break;
        case stv:
            s[sb] = s[st];
            break;
        case ast:
            st = st - 1;
            s[s[st]+sb] = s[st+1];
            s[st] = s[st+1];
            break;
        case ald:
            s[st] = s[s[st]+sb];
            break;
        case cal:	        /* 调用子过程 */
            s[st + 1] = 0;
            s[st + 2] = sb;	/* 将本过程基地址入栈，即建立动态链 */
            s[st + 3] = sp;	/* 将当前指令指针入栈，即保存返回地址 */
            sb = st + 1;	    /* 改变基地址指针值为新过程的基地址 */
            sp = si.a;	    /* 跳转 */
            break;
        case ini:
            for(int i = st+1;i <= st+3;i++) z[i] = 2;
            for(int i = st+4;i <= st+si.a;i++) z[i] = 1;
            st = st + si.a;
            break;
        case jmp:
            sp = si.a;
            break;
        case jpc:
            if (s[st] == 0)
                sp = si.a;
            st = st - 1;
            break;
    }
}


void Widget::AuthorInfo()
{
    QMessageBox::about(NULL, "Kuroko个人信息", "吴子靖 10185102141 \n华东师范大学 计算机科学与技术系 \n21秋季编译原理实践大作业 \n主站:Kuroko.info");
}

void Widget::readXcode()
{
    ifstream in("code.txt");
    pi = 0;
    int n,l,a;
    string f;
    fct m1[12] = {
        lit,     opr,     lod,
        sto,     cal,     ini,
        jmp,     jpc,     pop,
        ast,     ald,     stv
    };

    string m2[12] = {
        "lit",     "opr",     "lod",
        "sto",     "cal",     "ini",
        "jmp",     "jpc",     "pop",
        "ast",     "ald",     "stv"
    };

    while(in>>n>>f>>l>>a)
    {
        int i;
        for(i = 0;i < 12;i++)
            if(m2[i] == f) break;

        pcode[pi].f = m1[i];
        pcode[pi].l = l;
        pcode[pi++].a = a;
    }
}


void Widget::runXcode()
{
    FILE* fout;
    if ((fout = fopen("out.txt", "w")) == NULL)
    {
        QMessageBox::critical(NULL,  "错误",  "Can't open out.txt file!", QMessageBox::Ok);
        exit(1);
    }
    int p = 0; /* 指令指针 */
    int b = 1; /* 指令基址 */
    int t = 0; /* 栈顶指针 */
    instruction i;
    fprintf(fout,"Start X0\n");
    memset(s, 0 ,sizeof(s));
    do {
        i = pcode[p];
        p = p + 1;
        switch (i.f)
        {
            case pop:
                t = t - i.a;
                break;
            case lit:
                t = t + 1;
                s[t] = i.a;
                break;
            case opr:
                switch (i.a)
                {
                    case 0:
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        t += i.l;
                        break;
                    case 1:
                        s[t] = - s[t];
                        break;
                    case 2:
                        t = t - 1;
                        s[t] = s[t] + s[t + 1];
                        break;
                    case 3:
                        t = t - 1;
                        s[t] = s[t] - s[t + 1];
                        break;
                    case 4:
                        t = t - 1;
                        s[t] = s[t] * s[t + 1];
                        break;
                    case 5:
                        t = t - 1;
                        s[t] = s[t] / s[t + 1];
                        break;
                    case 6:
                        s[t] = s[t] % 2;
                        break;
                    case 8:
                        t = t - 1;
                        s[t] = (s[t] == s[t + 1]);
                        break;
                    case 9:
                        t = t - 1;
                        s[t] = (s[t] != s[t + 1]);
                        break;
                    case 10:
                        t = t - 1;
                        s[t] = (s[t] < s[t + 1]);
                        break;
                    case 11:
                        t = t - 1;
                        s[t] = (s[t] >= s[t + 1]);
                        break;
                    case 12:
                        t = t - 1;
                        s[t] = (s[t] > s[t + 1]);
                        break;
                    case 13:
                        t = t - 1;
                        s[t] = (s[t] <= s[t + 1]);
                        break;
                    case 14:
                        if(i.l == 0)
                        {
                            fprintf(fout, "%d", s[t]);
                        }
                        else if(i.l == 1)
                        {

                            fprintf(fout,"%c",s[t]);
                        }
                        else if(i.l == 2)
                        {
                            fprintf(fout,"%s",(s[t]==0)?"false":"true");
                        }
                        break;
                    case 15:
                        fprintf(fout,"\n");
                        break;
                    case 16:
                        t = t + 1;
                        fprintf(fout, "?");
                        if(i.l == 0)
                        {
                            getInput(0, "read a int:");
                            s[t] = stoi(sin);
                            fprintf(fout, "%d\n", s[t]);
                        }
                        else if(i.l == 1)
                        {
                            getInput(1, "read a char:");
                            s[t] = sin[0];
                            fprintf(fout, "%c\n", s[t]);
                        }
                        else
                        {
                            getInput(2, "read a bool:");
                            s[t] = stoi(sin);
                            fprintf(fout, "%d\n", s[t]);
                            if(s[t] != 0) s[t] = 1;
                        }
                        break;
                    case 17:
                        t = t - 1;
                        s[t] = s[t] % s[t + 1];
                        break;
                    case 18:
                        t = t - 1;
                        if(s[t] != 0) s[t] = 1;
                        if(s[t+1] != 0) s[t+1] = 1;
                        if(i.l == 0) s[t] = s[t]&s[t+1];
                        else if(i.l == 1) s[t] = s[t]|s[t+1];
                        else if(i.l == 2) s[t] = s[t]^s[t+1];
                        break;
                    case 19:
                        if(s[t] != 0) s[t] = 0;
                        else s[t] = 1;
                        break;
                    case 20:
                        s[t] = s[t]%2;
                        break;
                }
                break;
            case lod:
                t = t + 1;
                s[t] = s[i.a+b];
                break;
            case sto:
                if(i.l == 0) s[b+i.a] = s[t];
                else if(i.l == 1) s[t+i.a] = s[t];
                break;
            case stv:
                s[b] = s[t];
                break;
            case ast:
                t = t - 1;
                s[s[t]+b] = s[t+1];
                s[t] = s[t+1];
                break;
            case ald:
                s[t] = s[s[t]+b];
                break;
            case cal:	        /* 调用子过程 */
                s[t + 1] = 0;
                s[t + 2] = b;	/* 将本过程基地址入栈，即建立动态链 */
                s[t + 3] = p;	/* 将当前指令指针入栈，即保存返回地址 */
                b = t + 1;	    /* 改变基地址指针值为新过程的基地址 */
                p = i.a;	    /* 跳转 */
                break;
            case ini:
                t = t + i.a;
                break;
            case jmp:
                p = i.a;
                break;
            case jpc:
                if (s[t] == 0)
                    p = i.a;
                t = t - 1;
                break;
        }
    } while (p != 0);
    fprintf(fout,"End X0\n");
    fclose(fout);
}



Widget::~Widget()
{

}

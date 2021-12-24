#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMenuBar>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QToolBar>
#include <QToolButton>
#include <QStatusBar>
#include <QLabel>
#include <QProgressBar>
#include <QTimer>
#include <QDateTime>
#include <QMenu>
#include <QStatusBar>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <QInputDialog>
using namespace std;

enum fct
{
    lit,     opr,     lod,
    sto,     cal,     ini,
    jmp,     jpc,     pop,
    ast,     ald,     stv,
};

struct instruction
{
    fct f;
    int l;
    int a;
};



class Widget : public QWidget
{
    Q_OBJECT

public:
    string sin;
    FILE* sout;
    instruction pcode[2000];
    int pi,sp,sb,st;
    instruction si;
    int s[100];
    int z[100];
    string fileName;
    bool hasOpened;
    bool isBuild;
    bool isSRun;
    QToolBar *ToolBar;
    QMenuBar *MenuBar;
    QMenu *MenuBarFile,*RunFile,*View,*Help;
    QAction *OpenFile, *SaveFile, *NewFile, *SaveAs, *CloseFile, *Exit, *Author;
    QAction *Make,*SRun,*MRun,*vtable,*vout,*verror;
    QToolButton *OpenFile_tb,*SaveFile_tb,*NewFile_tb,*SaveAs_tb,*CloseFile_tb;
    QToolButton *Table_tb,*Out_tb,*Error_tb,*Build_tb,*SRun_tb,*MRun_tb,*Kuroko_tb;
    QLabel *pInfo, *pTimeLabel;
    QStatusBar *pStatusBar;
    QProgressBar *pProgressBar;
    QTimer *pTimer;
    QLineEdit *xin;
    QTextEdit *xcode,*ycode,*result;
    QPushButton *confirm;
    Widget(QWidget *parent = nullptr);
    void InitMenuBar();
    void InitToolBar();
    void InitTextEdit();
    void InitStatusBar();
    void InitVar();
    void displayXcode();
    void readXcode();
    void runXcode();
    void runXcodeStepByStep();
    void refreshCode();
    void paintEvent(QPaintEvent*);
    void getInput(int mod, const char *info);
    ~Widget();

private slots:
    void createFile();
    void openFileDialog();
    void saveFile();
    void saveFileDialog();
    void closeFile();
    void displayTable();
    void displayResult();
    void displayError();
    void BuildXcode();
    void SingleRun();
    void BuildRun();
    void AuthorInfo();
    void timeUpdate();

};
#endif // WIDGET_H

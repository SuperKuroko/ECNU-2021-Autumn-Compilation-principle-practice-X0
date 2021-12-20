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
class Widget : public QWidget
{
    Q_OBJECT

public:
    QToolBar *ToolBar;
    QMenuBar *MenuBar;
    QMenu *MenuBarFile,*RunFile,*Help;
    QAction *OpenFile, *SaveFile, *NewFile, *SaveAs, *CloseFile, *Exit, *Author,*Run;
    QToolButton *OpenFile_tb;
    Widget(QWidget *parent = nullptr);
    void InitMenuBar();
    void InitToolBar();
    void InitStatusBar();
    void paintEvent(QPaintEvent*);
    ~Widget();
};
#endif // WIDGET_H

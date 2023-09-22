#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/tcp/tcploader.h"
#include "../flow/scanload.h"
#include "../sql/sqlqueryconsole.h"
#include "qmenubar.h"
#include "qmenu.h"
#include "qmainwindow.h"
#include "qtabwidget.h"

#if defined(INTERFACE_LIBRARY)
#  define INTERFACE_IMEXPORT Q_DECL_EXPORT
#else
#  define INTERFACE_IMEXPORT Q_DECL_IMPORT
#endif

class INTERFACE_IMEXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setStyle(QCString filename);
    void setLoginIP(QCString ip);
    void setLoginUser(QCString user);
private slots:
    void onCheckConnectedState();
private:
    QTabWidget * mTab;
    ScanLoad * mScanPanel;
    SqlQueryConsole * mQueryPanel;
    GradientHiddenWidget * www;
    QString mLoginIP;
    QTimer mCheckConnectedTimer;
private:
};
#endif // MAINWINDOW_H

#ifndef SQLQUERYCONSOLE_H
#define SQLQUERYCONSOLE_H

#include "sqldbquerytree.h"
#include "sqldbquerytable.h"
#include "sqldbquerypanel.h"

/*
 * 细胞增殖实验:
 *          需要绘制所有孔，孔内所有视野的平均聚集度-时间曲线，做成视频
 *          孔内的平均曲线，还有孔内不同视野的曲线画到一个图
 *          全板的平均曲线，或者几个孔的平均曲线，同时不同孔的平均曲线画到一个图
 *          绘图误差线的问题
*/

class SqlQueryConsole : public QWidget
{
    Q_OBJECT
public:
    explicit SqlQueryConsole(QWidget *parent = nullptr);
    void setCurrentUser(QCString user );
public slots:
    void launchAnalysisDlg();
    void launchPhotograph();
    void updateStatus(const QString& table);
private:
    void initStatus();
    SqlDBQueryTree* tree ;
    SqlDBQueryTable*table;
    SqlDBQueryPanel*panel;
    QStatusBar * status1;
    QStatusBar * status2;
signals:

};

#endif // SQLQUERYCONSOLE_H

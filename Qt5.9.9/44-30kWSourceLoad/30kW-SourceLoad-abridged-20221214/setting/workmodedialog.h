#ifndef WORKMODEDIALOG_H
#define WORKMODEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QRadioButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QDebug>
#include <core/enum.h>

class WorkModeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WorkModeDialog(WORKMODE mode,QWidget * parent = Q_NULLPTR);
    bool isCVMode;
signals:
      void workModeChanged(WORKMODE); //把工作模式信息发出,mainSettings接收,最终mTableSizeDlg接收
};

#endif // WORKMODEDIALOG_H

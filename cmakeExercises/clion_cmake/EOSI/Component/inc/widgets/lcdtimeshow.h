#ifndef LCDTIMESHOW_H
#define LCDTIMESHOW_H

#include "label.h"

class COMPONENT_IMEXPORT LCDTimeShow : public QWidget
{
    Q_OBJECT
private:
    QTimer * mTimer;
    QHBoxLayout * mLayout;
    Label * mDateTime;
public:
    explicit LCDTimeShow(QWidget *parent = nullptr);
signals:

};

#endif // LCDTIMESHOW_H

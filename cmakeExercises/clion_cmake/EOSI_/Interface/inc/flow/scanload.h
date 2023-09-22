#ifndef SCANLOAD_H
#define SCANLOAD_H

#include "../../../include/widgets/pushbutton.h"
#include "scanvesselconfig.h"

class ScanLoad : public QWidget
{
    Q_OBJECT
public:
    explicit ScanLoad(QWidget *parent = nullptr);
    void setCurrentUser(QCString user);
    void setStyle(const QString& s);
private:
    PushButton * btn;
    ScanVesselConfig * config;
    QString style;
    QString cuser;
private slots:
    void onClicked();
signals:

};

#endif // SCANLOAD_H

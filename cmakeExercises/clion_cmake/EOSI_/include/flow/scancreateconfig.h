#ifndef SCANCREATECONFIG_H
#define SCANCREATECONFIG_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "qradiobutton.h"

class ScanCreateConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    enum ScanCreateMode {New,Current,Previous,EmptyMode};
    Q_ENUM(ScanCreateMode);
    explicit ScanCreateConfig(QWidget *parent = nullptr);
    void clearRadioState();
private:
    QRadioButton * createNewButton() const;
    QRadioButton * copyCurrentButton() const;
    QRadioButton * copyPreviousButton() const;
    QRadioButton * btnNew;
    QRadioButton * btnCurrent;
    QRadioButton * btnPrevious;
private slots:
    void onCreateConfig();
signals:
    void createMode(ScanCreateMode mode);
};

#endif // SCANCREATECONFIG_H

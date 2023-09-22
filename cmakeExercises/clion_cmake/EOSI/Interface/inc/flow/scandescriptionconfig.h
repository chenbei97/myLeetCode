#ifndef SCANDESCRIPTIONCONFIG_H
#define SCANDESCRIPTIONCONFIG_H

#include "widgets/gradienthiddenwidget.h"
#include "widgets/combobox.h"
#include "widgets/pushbutton.h"
#include "widgets/lineedit.h"
#include "widgets/groupbox.h"
#include "widgets/textedit.h"

class ScanDescriptionConfig : public GradientHiddenWidget
{
    Q_OBJECT
public:
    explicit ScanDescriptionConfig(QWidget *parent = nullptr);
    QString experName();
    QString personName();
    QString cellType() const;
    QString description() const;
private:
    LineEdit * mExperName;
    LineEdit * mExperPerson;
    LineEdit * mCellType;
    QTextEdit * mDescription;
signals:

};

#endif // SCANDESCRIPTIONCONFIG_H

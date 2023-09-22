#ifndef SCANDESCRIPTIONCONFIG_H
#define SCANDESCRIPTIONCONFIG_H

#include "../../../include/widgets/gradienthiddenwidget.h"
#include "../../../include/widgets/combobox.h"
#include "../../../include/widgets/pushbutton.h"
#include "../../../include/widgets/lineedit.h"
#include "../../../include/widgets/groupbox.h"
#include "../../../include/widgets/textedit.h"

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

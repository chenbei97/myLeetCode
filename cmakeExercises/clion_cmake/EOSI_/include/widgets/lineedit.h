#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "qlineedit.h"
#include "qvalidator.h"
#include "../public.h"

class COMPONENT_IMEXPORT LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget*parent = nullptr);
    explicit LineEdit(const QString&text,QWidget*parent = nullptr);
    void setIntRange(int min,int max);
    void setRegExp(const QRegExp &rx);
private:
    QIntValidator * validator = nullptr;
    QRegExpValidator *regexValidator = nullptr;
};

#endif // LINEEDIT_H

#ifndef DOUBLETEXTEDIT_H
#define DOUBLETEXTEDIT_H

#include "groupbox.h"
#include "qtextedit.h"
#include "qframe.h"

class COMPONENT_IMEXPORT DoubleTextEdit : public QWidget
{
    Q_OBJECT
public:
    explicit DoubleTextEdit(QWidget *parent = nullptr);
    void setLeftTitle(const QString& title);
    void setRightTitle(const QString& title);
    void setLeftText(const QString& text);
    void setRightText(const QString& text);
    void setLeftReadonly(bool r);
    void setRightReadonly(bool r);
    void setReadonly(bool r);

    QString leftText() const;
    QString rightText() const;
private:
    GroupBox * leftbox;
    GroupBox * rightbox;
    QTextEdit * leftedit;
    QTextEdit * rightedit;
signals:

};

#endif // DOUBLETEXTEDIT_H

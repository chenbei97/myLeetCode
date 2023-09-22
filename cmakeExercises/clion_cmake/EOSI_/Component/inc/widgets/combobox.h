#ifndef COMBOBOX_H
#define COMBOBOX_H


#include "qcombobox.h"
#include "standarditemmodel.h"
#include "lineedit.h"
#include "../public.h"

class COMPONENT_IMEXPORT ComboBox : public QComboBox
{
    Q_OBJECT
private:
    LineEdit * mLineEdit = nullptr;
public:
    explicit ComboBox(QWidget*parent = nullptr);
    explicit ComboBox(const QString&text,QWidget*parent = nullptr);
    explicit ComboBox(const QStringList&texts,QWidget*parent = nullptr);
    void setAlignment(Qt::Alignment align);
    void toggleLineEdit();
};

#endif // COMBOBOX_H

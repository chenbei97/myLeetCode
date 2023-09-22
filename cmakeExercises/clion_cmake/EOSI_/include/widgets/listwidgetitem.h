#ifndef LISTWIDGETITEM_H
#define LISTWIDGETITEM_H

#include "qlistwidget.h"
#include "../public.h"

class COMPONENT_IMEXPORT ListWidgetItem : public QListWidgetItem
{
    //Q_OBJECT
public:
    explicit ListWidgetItem(QListWidget * parent = 0);
    explicit ListWidgetItem(const QString&text,QListWidget * parent = 0);
};

#endif // LISTWIDGETITEM_H

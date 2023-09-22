#include "../../inc/widgets/listwidgetitem.h"

ListWidgetItem::ListWidgetItem(QListWidget * parent) :QListWidgetItem(parent)
{
    setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
}

ListWidgetItem::ListWidgetItem(const QString&text,QListWidget * parent) :QListWidgetItem(parent)
{
    setText(text);
    setFlags(Qt::ItemIsEnabled|Qt::ItemIsEditable|Qt::ItemIsSelectable);
}

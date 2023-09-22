#ifndef TABLEWIDGETBASE_H
#define TABLEWIDGETBASE_H

#include "qtablewidget.h"
#include "qtabbar.h"
#include "qheaderview.h"
#include "qscrollbar.h"
#include "../public.h"

class COMPONENT_IMEXPORT TableWidgetBase : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidgetBase(int rows,int cols,QWidget * parent = nullptr);
    TableWidgetBase* clone();
};

#endif // TABLEWIDGETBASE_H

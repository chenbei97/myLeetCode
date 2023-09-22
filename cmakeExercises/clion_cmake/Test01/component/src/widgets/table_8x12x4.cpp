#include "../../inc/widgets/table_8x12x4.h"

Table_8x12x4::Table_8x12x4(QWidget *parent) : QWidget(parent)
{
    TableWidgetBase * table_2x2 ;

    TableWidgetBase * table_8x12 = new TableWidgetBase(8,12);
    table_8x12->verticalHeader()->show();
    table_8x12->horizontalHeader()->show();

    table_8x12->setVerticalHeaderLabels(QStringList()<<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H");

    table_8x12->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table_8x12->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    for (int row = 0; row < 8; ++row)
        for(int col = 0; col < 12; ++col)
        {
            table_2x2  = new TableWidgetBase(2,2);
            table_8x12->setCellWidget(row,col,table_2x2);

        }

    for(int row = 0; row <  table_8x12->rowCount();++row)
         table_8x12->setRowHeight(row,TableWidgetItemHeight*2);
    for(int col = 0; col <  table_8x12->columnCount(); ++col)
         table_8x12->setColumnWidth(col,TableWidgetItemWidth*2);

    QVBoxLayout * lay = new QVBoxLayout;
    lay->setMargin(0);
    lay->setSpacing(0);
    lay->addWidget(table_8x12);

    setLayout(lay);
    resize(table_8x12->size());
    INIT_FONT;
}

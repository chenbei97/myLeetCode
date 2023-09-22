#include "../../inc/widgets/table_nx2.h"

Table_nx2::Table_nx2(QWidget *parent) : QWidget(parent)
{
    TableWidgetBase * table_1x2 = new TableWidgetBase(20,2);
    table_1x2->setColumnWidth(0,TableNx2WidgetItemNameWidth);
    table_1x2->setColumnWidth(1,TableNx2WidgetItemDescriptionWidth);

    for(int r = 0; r < table_1x2->rowCount(); ++r)
        table_1x2->setRowHeight(r,TableNx2WidgetItemHeight);

    table_1x2->verticalHeader()->show();
    table_1x2->horizontalHeader()->show();

    table_1x2->setHorizontalHeaderLabels(QStringList()<<"name"<<"description");

    table_1x2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table_1x2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    table_1x2->setEditTriggers(QTableWidget::EditTrigger::DoubleClicked);


    QVBoxLayout * lay = new QVBoxLayout;
    lay->setMargin(0);
    lay->setSpacing(0);
    lay->addWidget(table_1x2);

    setLayout(lay);
    resize(table_1x2->size());
    INIT_FONT;
}

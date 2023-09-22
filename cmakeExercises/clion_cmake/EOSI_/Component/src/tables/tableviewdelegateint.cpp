#include "../../inc/tables/tableviewdelegateint.h"

TableViewDelegateInt::TableViewDelegateInt(int min,int max,QObject*parent):QStyledItemDelegate(parent)
{
    bottom = min;
    top = max;
}

void TableViewDelegateInt::setRange(int min, int max)
{
    bottom = min;
    top = max;
}

QWidget *TableViewDelegateInt::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    LineEdit * textEdit = new LineEdit(parent);
    textEdit->setIntRange(bottom,top);
    return textEdit;
}

void TableViewDelegateInt::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.model()->data(index,Qt::EditRole | Qt::DisplayRole).toString();
    LineEdit * textEdit = static_cast<LineEdit*>(editor);

//    auto row = index.row();
//    auto col = index.column();
//    auto model = index.model();

//    if (col == PointXColumn || col == PointYColumn) {
//        QString xvals;
//        QString yvals;
//        for(int r = 0 ; r < model->rowCount(); ++r) {
//            if (r != row) {
//                auto x = model->data(model->index(r,PointXColumn)).toString();
//                auto y = model->data(model->index(r,PointYColumn)).toString();
//                xvals.append(x);
//                xvals.append("|");
//                yvals.append(y);
//                yvals.append("|");
//            }
//        }
//        xvals.chop(1);
//        yvals.chop(1);

//        // [1-8]     //([1-9]|1[0-2])    //([1-9]|1[0-9]|2[0-4])
//        QString regexp1 ; QString("^(?!%1)(%2)$").arg(xvals);
//        QString regexp2 ; QString("^(?!(%1))[0-9]+$").arg(yvals);
//        if (top < 10)  {
//            regexp1 = QString("^(?!%1)([1-%2])$").arg(xvals).arg(top);
//            regexp2 = QString("^(?!%1)([1-%2])$").arg(yvals).arg(top);
//        } else if (top > 20) {
//            regexp1 = QString("^(?!%1)([1-9]|1[0-9]|2[0-%2])$").arg(xvals).arg(top-20);
//            regexp2 = QString("^(?!%1)([1-9]|1[0-9]|2[0-%2])$").arg(yvals).arg(top-20);
//        } else {
//            regexp1 = QString("^(?!%1)([1-9]|1[0-%2])$").arg(xvals).arg(top-10);
//            regexp2 = QString("^(?!%1)([1-9]|1[0-%2])$").arg(yvals).arg(top-10);
//        }

//        qDebug()<<regexp1<<" ... "<<regexp2;
//        if (col == PointXColumn)
//            textEdit->setRegExp(QRegExp(regexp1));
//        if (col == PointYColumn)
//           textEdit->setRegExp(QRegExp(regexp2));
//    }
   textEdit->setText(text);
}

void TableViewDelegateInt::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{ // 双击的时候才触发这个函数
    LineEdit *textEdit = static_cast<LineEdit*>(editor);
    model->setData(index, textEdit->text(), Qt::EditRole);
}

void TableViewDelegateInt::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}


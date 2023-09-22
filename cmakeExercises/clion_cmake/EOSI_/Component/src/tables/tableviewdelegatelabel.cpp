#include "../../inc/tables/tableviewdelegatelabel.h"

QWidget *TableViewDelegateLabel::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const
{
    Q_UNUSED(index);
    Q_UNUSED(option);
    Label * label = new Label(parent);
    return label;
}

void TableViewDelegateLabel::paint(QPainter *painter, const QStyleOptionViewItem &option,
           const QModelIndex &index) const
{
    // 1. 画边框
    auto pen = painter->pen();
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(option.rect);

    // 2. 画图
    auto pix_var = index.model()->data(index, Qt::DecorationRole);
    if (pix_var.isValid()){
        auto pix = pix_var.value<QPixmap>();
        painter->drawPixmap(option.rect,pix);
    }

    // 3. 画已选中高亮
        /*绘制已被选中使用过的项 在前*/
       pen = painter->pen(); // 边框颜色统一红色
       pen.setColor(TableViewBorderHighlightColor);
       painter->setPen(pen);

       auto selected = index.model()->data(index,TableModelDataRole::isSelected);
       QColor scolor = TableViewSelectedHighlightColor;
       scolor.setAlpha(TableViewHighlightColorAlpha);
       if (selected.isValid())
       {
           if (selected.toBool())
           {
               painter->fillRect(option.rect,scolor);
               painter->drawRect(option.rect);
           }
       }

        /*绘制当前具有焦点的项 在后*/
        auto isCurrent = index.model()->data(index,TableModelDataRole::isCurrent);
        auto ccolor  = TableViewCurrentHighlightColor;
        ccolor.setAlpha(TableViewHighlightColorAlpha);
        pen = painter->pen();
        pen.setColor(ccolor);
        painter->setPen(pen);
       if (isCurrent.isValid())
       {
           if (isCurrent.toBool())
           {
               painter->fillRect(option.rect,ccolor);
               painter->drawRect(option.rect);
           }
       }

    // 4. 画鼠标高亮
   if (option.state & QStyle::State_Selected ) // 如果小部件被选择就高亮这个颜色组,否则项不会被高亮
   {
       auto backColor = TableViewMouseHighlightColor;
       backColor.setAlpha(TableViewHighlightColorAlpha);

       auto pen = painter->pen();
       pen.setColor(TableViewBorderHighlightColor);// 边框颜色
       painter->setPen(pen);

       painter->drawRect(option.rect);
       painter->fillRect(option.rect,backColor);
   }
}

void TableViewDelegateLabel::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QPixmap img = index.model()->data(index,Qt::DecorationRole).value<QPixmap>();
    QString text = index.model()->data(index,Qt::EditRole | Qt::DisplayRole).toString();
    Label * label = static_cast<Label*>(editor);
    label->setText(text);
    label->setPixmap(img);
}

void TableViewDelegateLabel::setModelData(QWidget *editor, QAbstractItemModel *model,
                  const QModelIndex &index) const
{
    Label *label = static_cast<Label*>(editor);
    model->setData(index, label->text(), Qt::EditRole);
    model->setData(index, label->pixmap(), Qt::DecorationRole);
}

void TableViewDelegateLabel::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

bool TableViewDelegateLabel::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        auto  v = index.model()->data(index, Qt::DecorationRole);
        if (v.isValid())
        {
            Picture * dlg = new Picture();
            dlg->setAttribute(Qt::WA_DeleteOnClose);
            auto icon = v.value<QPixmap>();
            dlg->setPixmap(icon);

            if (!dlg->pixmap().isNull())
                dlg->show();
            else dlg->close();
        }
    }
    return QStyledItemDelegate::editorEvent(event,model,option,index);
}


#include "../../inc/tables/tableviewdelegate2x2.h"

void TableViewDelegate2x2::setEditorData(QWidget *editor, const QModelIndex &index) const
{//从TableModel拿数据,对编辑器进行显示,实际没调用,是不支持自定义的
//    TableViewWidget2x2 *cell = static_cast<TableViewWidget2x2*>(editor);
//    auto  v1 = index.model()->data(index, Qt::DecorationRole);
//    LOG<<"v1 = "<<v1;
//    if (v1.isValid())
//    {
//        auto icons = v1.value<QVector<QPixmap*>>();
//        LOG<<"icons.count() = "<<icons.count();
//        if (icons.count() == 4){ // 启动的时候如果数据有效一定4个数据
//            if (icons[0]) // 可能是nullptr
//                cell->setPixmap(0,icons[0]);
//            if (icons[1])
//                cell->setPixmap(1,icons[1]);
//            if (icons[2])
//                cell->setPixmap(2,icons[2]);
//            if (icons[3])
//                cell->setPixmap(3,icons[3]);
//        }
//    }
    return QStyledItemDelegate::setEditorData(editor,index);
}

void TableViewDelegate2x2::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{ // 显示组件有变化自动更新到Model的方式,也没被调用
//    TableViewWidget2x2 *cell = static_cast<TableViewWidget2x2*>(editor);
//    QVariant v;
//    v.setValue(cell->pixmaps());
//    model->setData(index, v, Qt::DecorationRole); //拿到图标的名称
//   model->setData(index, QColor(Qt::red), TableModelDataRole::HighlightBorderColor);
    return QStyledItemDelegate::setModelData(editor,model,index);
}


bool TableViewDelegate2x2::editorEvent(QEvent *event, QAbstractItemModel *model,
                                   const QStyleOptionViewItem &option, const QModelIndex &index)
{ // TableView的cell的鼠标事件可以在这里拿到,但不会传递给代理组件
    if(event->type()  == QEvent::MouseButtonPress
            || event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent * mouse = static_cast<QMouseEvent*>(event);
        model->setData(index,mouse->pos(),TableModelDataRole::MousePosition);

        if (event->type() == QEvent::MouseButtonDblClick)
        {
            int x = option.rect.x();
            int y = option.rect.y();
            int w = option.rect.width();
            int h = option.rect.height();

            QRect rect11 = QRect(x,y,w/2,h/2);
            QRect rect12 = QRect(x+w/2,y,w/2,h/2);
            QRect rect21 = QRect(x,y+h/2,w/2,h/2);
            QRect rect22 = QRect(x+w/2,y+h/2,w/2,h/2);

            // 可以拿到代理的父类TableView,能做什么事这里留待思考~
            //auto tableview = static_cast<const TableView*>(option.widget);

            auto  v = index.model()->data(index, Qt::DecorationRole);
            if (v.isValid())
            {
                Picture * dlg = new Picture();
                dlg->setAttribute(Qt::WA_DeleteOnClose);
                auto icons = v.value<QVector<QPixmap*>>();
                LOG<<"is valid pixmaps.count = "<<icons.count();// 如果有效能够保证数量(TableModel的setPixmap那些函数)一定是4
                if (icons.count() == 4) {// 但是如果是通过setData来直接设置的没有提供数量检查会有越界问题,不一定是4
                    // 如果是空指针没法画(无论鼠标是否点击),如果不是空指针,鼠标点击了画
                    // 下边4个路径只可能执行1条,或者都不执行
                    if (icons[0] && rect11.contains(mouse->pos()))
                        dlg->setPixmap(*icons[0]);
                    if (icons[1] && rect12.contains(mouse->pos()))
                        dlg->setPixmap(*icons[1]);
                    if (icons[2] && rect21.contains(mouse->pos()))
                        dlg->setPixmap(*icons[2]);
                    if (icons[3] && rect22.contains(mouse->pos()))
                        dlg->setPixmap(*icons[3]); 
                }
                else { // 数量不是4,可能是任意1个,2个或3个 ,还可以是0,而且不知道这些图对应的位置
                    // 可能是1,2,3也可能是1,2,4,不知道画到哪个区域上
                    // 所以源头上不要使用setData直接设置Qt::DecorationRole
                }
                // 不论因为什么原因,如果没有图,不用显示
                if (!dlg->pixmap().isNull())
                    dlg->show();
                else dlg->close();
            }
        }
        event->accept();
    }
    return QStyledItemDelegate::editorEvent(event,model,option,index);
}

QWidget *TableViewDelegate2x2::createEditor(QWidget *parent,
       const QStyleOptionViewItem &option, const QModelIndex &index) const
{/*
生成编辑组件的方式只会在触发编辑状态时如双击才会实例化组件,但有时需求是编辑组件一直显示
只能 paint 里用 QStyle 的 drawControl,但是支持的组件有限
因为 Qt的view只在单元格处于可见区域时才进行渲染,所以没有提供这项功能
view只有一个 setIndexWidget 的接口,用于展示静态数据, 不过每一个项都用这个设置会很费内存
实际上createEditor,setModelData,setEditData都没被触发调用,全靠paintEvent绘制
view使用openPersistentEditor时才会实例化
*/
//    auto editor = new TableViewWidget2x2(parent);
//    //editor->installEventFilter(const_cast<TableViewWidget2x2*>(this));
//    LOG<<"editor == nullptr? "<<(editor==nullptr);
//    return editor;
    return QStyledItemDelegate::createEditor(parent,option,index);
}

/*
void WidgetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const
{
    if (index.column() == 1) {
        int progress = index.data().toInt();

        QStyleOptionProgressBar progressBarOption;
        progressBarOption.rect = option.rect;
        progressBarOption.minimum = 0;
        progressBarOption.maximum = 100;
        progressBarOption.progress = progress;
        progressBarOption.text = QString::number(progress) + "%";
        progressBarOption.textVisible = true;

        QApplication::style()->drawControl(QStyle::CE_ProgressBar,
                                           &progressBarOption, painter);
    } else
        QStyledItemDelegate::paint(painter, option, index);
*/
void  TableViewDelegate2x2::paint(QPainter *painter, const QStyleOptionViewItem &option,
                                  const QModelIndex &index) const
{
    paintBorder(painter,option); // 1. 绘制外部和内部边框,通用区域要先绘制否则会被覆盖

    paintPixmap(painter,option,index); // 2. 然后绘制显示的图片

    paintSelectedHighlight(painter,option,index); // 3. 已被选中单元格的高亮绘制

    paintMouseHighlight(painter,option,index); // 4. 鼠标点击的高亮区域绘制
}

void TableViewDelegate2x2::paintMouseHighlight(QPainter *painter, const QStyleOptionViewItem &option,
                                          const QModelIndex &index) const
{
    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    int h = option.rect.height();

    QRect rect11 = QRect(x,y,w/2,h/2);
    QRect rect12 = QRect(x+w/2,y,w/2,h/2);
    QRect rect21 = QRect(x,y+h/2,w/2,h/2);
    QRect rect22 = QRect(x+w/2,y+h/2,w/2,h/2);

    // || option.state &QStyle::State_MouseOver
    if (option.state & QStyle::State_Selected ) // 如果小部件被选择就高亮这个颜色组,否则项不会被高亮
    {
        auto backColor = index.model()->data(index, TableModelDataRole::HighlightColor).value<QColor>();
        if (!backColor.isValid())
            backColor = TableViewMouseHighlightColor;
        auto mousePos  = index.model()->data(index,TableModelDataRole::MousePosition).toPoint();
        backColor.setAlpha(TableViewHighlightColorAlpha); // 设置透明度,不然fillRect会把绘制的图片覆盖掉

        auto pen = painter->pen();
        pen.setColor(TableViewBorderHighlightColor);// 边框颜色
        painter->setPen(pen);

        // 鼠标属于的子区域进行高亮绘制
        if (rect11.contains(mousePos)){
            painter->drawRect(rect11);
            painter->fillRect(rect11,backColor);
        }
        if (rect12.contains(mousePos)) {
            painter->drawRect(rect12);
            painter->fillRect(rect12,backColor);
        }
        if (rect21.contains(mousePos)) {
            painter->drawRect(rect21);
            painter->fillRect(rect21,backColor);
        }
        if (rect22.contains(mousePos)){
            painter->drawRect(rect22);
            painter->fillRect(rect22,backColor);
        }
    }
}

void TableViewDelegate2x2::paintPixmap(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    int h = option.rect.height();

    QRect rect11 = QRect(x,y,w/2,h/2);
    QRect rect12 = QRect(x+w/2,y,w/2,h/2);
    QRect rect21 = QRect(x,y+h/2,w/2,h/2);
    QRect rect22 = QRect(x+w/2,y+h/2,w/2,h/2);

    // 数据传入时数据源头能够保证一次性传入4个数据 即使为nullptr
    auto v = index.model()->data(index, Qt::DecorationRole);
    if (v.isValid()){
            auto icons = v.value<QVector<QPixmap*>>();
            if (icons.count() == 4) { // 有效一定4个数据,这里不判断也行
                if (icons[0]) // 可能是nullptr
                    painter->drawPixmap(rect11,*(icons[0]));
                if (icons[1])
                    painter->drawPixmap(rect12,*(icons[1]));
                if (icons[2])
                    painter->drawPixmap(rect21,*(icons[2]));
                if (icons[3])
                    painter->drawPixmap(rect22,*(icons[3]));
            }
    }
}

void TableViewDelegate2x2::paintBorder(QPainter *painter, const QStyleOptionViewItem &option) const
{
    // 1. 外边框是黑色
    auto pen = painter->pen();
    pen.setWidth(5);
    pen.setColor(Qt::black);
    painter->setPen(pen);
    painter->drawRect(option.rect);

    // 2. 内边框是十字形灰色
    pen.setWidth(3);
    pen.setColor(Qt::gray);
    painter->setPen(pen);

    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    int h = option.rect.height();
    painter->drawLine(QPointF(x+w/2,y),QPointF(x+w/2,y+h));
    painter->drawLine(QPointF(x,y+h/2),QPointF(x+w,y+h/2));
}

void TableViewDelegate2x2::paintSelectedHighlight(QPainter *painter, const QStyleOptionViewItem &option,
                                     const QModelIndex &index) const
{
    /*每个单元格的左上角位置和大小*/
    int x = option.rect.x();
    int y = option.rect.y();
    int w = option.rect.width();
    int h = option.rect.height();

    /*划分单元格为4个子区域*/
    QRect rect11 = QRect(x,y,w/2,h/2);
    QRect rect12 = QRect(x+w/2,y,w/2,h/2);
    QRect rect21 = QRect(x,y+h/2,w/2,h/2);
    QRect rect22 = QRect(x+w/2,y+h/2,w/2,h/2);

    /*绘制已被选中使用过的项 在前*/
    auto pen = painter->pen(); // 边框颜色统一红色
    pen.setColor(TableViewBorderHighlightColor);
    painter->setPen(pen);

    uint32_t  selected = index.model()->data(index,TableModelDataRole::SelectedItems).toUInt();
    auto scolor = index.model()->data(index,TableModelDataRole::SelectedColor).value<QColor>();
    if (!scolor.isValid()) {
        scolor = TableViewSelectedHighlightColor;
        scolor.setAlpha(TableViewHighlightColorAlpha);
    }
    switch (selected) {
        case TableViewCellSelected::None:break;
        case TableViewCellSelected::All:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);
                break;

        case TableViewCellSelected::OnlyTopLeft:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);break;
        case TableViewCellSelected::OnlyTopRight:
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);break;
        case TableViewCellSelected::OnlyBottomLeft:
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);break;
        case TableViewCellSelected::OnlyBottomRight:
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;

        case TableViewCellSelected::Top:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);break;
        case TableViewCellSelected::Bottom:
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::Right:
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::Left:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);break;
        case TableViewCellSelected::DiagLeft: // 0x0101
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::DiagRight: // 0x1010
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);break;

        case TableViewCellSelected::ExceptTopLeft:
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::ExceptTopRight:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::ExceptBottomLeft:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect22,scolor);painter->drawRect(rect22);break;
        case TableViewCellSelected::ExceptBottomRight:
                painter->fillRect(rect11,scolor);painter->drawRect(rect11);
                painter->fillRect(rect12,scolor);painter->drawRect(rect12);
                painter->fillRect(rect21,scolor);painter->drawRect(rect21);break;
    }

    /*绘制当前具有焦点的项 在后*/
    uint32_t isCurrent = index.model()->data(index,TableModelDataRole::CurrentItem).toUInt();
    auto ccolor = index.model()->data(index,TableModelDataRole::CurrentColor).value<QColor>();
    if (!ccolor.isValid()) {
        ccolor = TableViewCurrentHighlightColor;
        ccolor.setAlpha(TableViewHighlightColorAlpha);
    }
    switch (isCurrent) {
        case 0:break; // 不具有焦点
        case 0b0001:
            painter->fillRect(rect11,ccolor);painter->drawRect(rect11);break;
        case 0b0010:
            painter->fillRect(rect12,ccolor);painter->drawRect(rect12);break;
        case 0b0100:
            painter->fillRect(rect21,ccolor);painter->drawRect(rect21);break;
        case 0b1000:
            painter->fillRect(rect22,ccolor);painter->drawRect(rect22);break;
        default:break; // 其它值忽略
    }

}

void TableViewDelegate2x2::updateEditorGeometry(QWidget *editor,
                const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

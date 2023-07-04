#ifndef _H_DELEGATE_H
#define _H_DELEGATE_H

/*
自定义代理组件必须继承以下4个函数:createEditor,setEditorData,setModelData,updateEditorGeometry
QItemDelegate: 为基于QAbstractItemView子类的项目视图提供自定义显示功能和编辑器小部件
在项目视图中编辑数据时，QItemDelegate提供了一个编辑器小部件，这是一个在进行编辑时放置在视图顶部的小部件。
编辑器是通过QItemEditorFactory创建的；QItemEditorFactory提供的默认静态实例安装在所有项目委托上
您可以使用setItemEditorFactory()设置自定义工厂，也可以使用QItemEditorFactory::setDefaultFactory()设置新的默认工厂。
编辑的是存储在具有Qt:：EditRole的项目模型中的数据

QStyledItemDelegate:区别是会使用当前的样式来创建项,建议使用QStyledItemDelegate
提供了在QAbstractItemDelegate中定义的paint()和sizeHint()虚拟函数的默认实现，以确保委托实现视图所期望的正确基本行为
此外还有个公共函数 : 此函数返回模型的Qt::DisplayRole的字符串。value是模型提供的Qt:：DisplayRole的值
virtual QString displayText(const QVariant &value, const QLocale &locale) const;
模型中项目的数据被分配了ItemDataRole；每个项目可以为每个角色存储一个QVariant。
QStyledItemDelegate实现了用户期望的最常见数据类型的显示和编辑，包括布尔值、整数和字符串。
根据数据在模型中所扮演的角色，数据的绘制方式会有所不同。
下表介绍了代理可以为每个角色处理的角色和数据类型。
通常，只要确保模型为每个角色返回适当的数据，以确定项目在视图中的外观就足够了

Role                        Accepted Types
Qt::BackgroundRole          QBrush
Qt::BackgroundColorRole     QColor (obsolete; use Qt::BackgroundRole instead)
Qt::CheckStateRole          Qt::CheckState
Qt::DecorationRole          QIcon, QPixmap, QImage and QColor
Qt::DisplayRole             QString and types with a string representation
Qt::EditRole                See QItemEditorFactory for details
Qt::FontRole                QFont
Qt::SizeHintRole            QSize
Qt::TextAlignmentRole       Qt::Alignment
Qt::ForegroundRole          QBrush 
Qt::TextColorRole           QColor (obsolete; use Qt::ForegroundRole instead)


QStyleOptionViewItem: 具备以下性质
    
    QStyleOptionViewItem::Position decorationPosition 项装饰的位置:Left(def), Right, Top, Bottom
    QStyleOptionViewItem::ViewItemFeatures features 项的特点:None, WrapText, Alternate, HasCheckIndicator, HasDisplay, HasDecoration
    QStyleOptionViewItem::ViewItemPosition viewItemPosition 项在一行中的位置:Invalid, Beginning, Middle, End, OnlyOne

    Qt::CheckState checkState 前提项具备特征HasCheckIndicator
    Qt::Alignment decorationAlignment 项的对齐方式 Qt::AlignLeft
    Qt::Alignment displayAlignment 项的显示值对齐方式 Qt::AlignLeft
    Qt::TextElideMode textElideMode 项文本多时省略号的位置 Qt::ElideMiddle

    QBrush backgroundBrush
    QFont font 项的格式,默认应用程序的格式
    QIcon icon 项的图标
    QSize decorationSize 项的尺寸 QSize(-1,-1)
    QModelIndex index 项在模型中的索引
    QString text 项的文本
    bool showDecorationSelected 项是否高亮

    *以下从QStyleOption继承*
    type: QStyleOption::OptionType
    fontMetrics: 绘制文本的字体度量 默认使用应用程序的
    direction: 文本布局方向 Qt::LeftToRight
    rect: 项的包裹矩形区域
    palette: 项的颜色板
    version: 项样式版本 默认值1
    void initFrom(const QWidget *widget):基于指定的小部件初始化state、direction、rect、palette、fontMetrics和styleObject成员变量
    state: 绘制的状态样式 QStyle::State
        State_None 0x00000000表示小部件没有状态。
        State_Active 0x00010000表示小部件处于活动状态。（常用）
        State_AutoRaise 0x00001000用于指示是否应在工具按钮上使用自动升高外观。
        State_Children 0x00080000用于指示项视图分支是否有子级。
        State_DownArrow 0x00000040用于指示是否应在小部件上显示向下箭头。
        State_Editing 0x00400000用于指示是否在小部件上打开了编辑器。
        State_Enabled 0x00000001用于指示小部件是否已启用。（常用）
        State_HasEditFocus 0x01000000用于指示小部件当前是否具有编辑焦点。
        State_HasFocus 0x00000100用于指示小部件是否有焦点。
        State_Horizontal 0x00000080用于指示小部件是否水平排列，例如。工具栏。
        State_KeyboardFocusChange 0x00800000用于指示焦点是否随键盘更改，例如制表符、后制表符或快捷键。
        State_MouseOver 0x00002000用于指示小部件是否在鼠标下。
        State_NoChange 0x00000010用于表示三态复选框。
        State_Off 0x00000008用于指示是否未检查小部件。
        State_On 0x00000020用于指示是否检查了小部件。
        State_Raised 0x00000002用于指示按钮是否升起。
        State_ReadOnly 0x02000000用于指示小部件是否为只读。
        State_Selected 0x00008000用于指示是否选择了小部件。（常用）
        State_Item 0x00100000项目视图用于指示是否应绘制水平分支。
        State_Open 0x00040000项目视图用于指示是否打开了树分支。
        State_Sibling 0x00200000项目视图用于指示是否需要绘制垂直线（用于同级）。
        State_Sunken 0x00000004用于指示小部件是否凹陷或按下。
        State_UpArrow 0x00004000用于指示小部件上是否应显示向上箭头。
        State_Mini 0x08000000用于指示迷你风格的Mac小部件或按钮。
        State_Small 0x04000000用于指示小型Mac小部件或按钮。

*/
#include <QItemDelegate>
#include <QStyledItemDelegate>
#include <QSqlRelationalDelegate>
#include <QComboBox>
#include <QImage>
#include <QLabel>
#include <QSpinBox>
#include <QPainter>
#include <QPixmap>

#define combo_create1

namespace SimpleDelegate {

    /*-----------------combobox---------------------*/
    class comboBoxDelegate : public QItemDelegate
    {
        Q_OBJECT

        private:
            #ifdef combo_create1
            QStringList m_ItemList;//选择列表
            boolm_isEdit; //是否可编辑
            #endif

        public:
            comboBoxDelegate(QObject *parent=0){};

            #ifdef combo_create1
            void setItems(QStringList items, bool isEdit)//初始化设置列表内容，是否可编辑
            {
                m_ItemList=items;
                m_isEdit=isEdit;
            }
            #endif

            QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const override
            {
                Q_UNUSED(option);
                Q_UNUSED(index);
                QComboBox *editor = new QComboBox(parent); // 注意,基于parent创建
            
            #ifdef combo_create1 
                for (int i=0;i<m_ItemList.count();i++)   // 根据外部来创建项
                    editor->addItem(m_ItemList.at(i));
                editor->setEditable(m_isEdit); //是否可编辑
            #else
                editor->addItem("优");// 直接创建1个具备4个项的combobox
                editor->addItem("良");
                editor->addItem("一般");
                editor->addItem("不合格"); 
            #endif
                return editor;
            }

            void setEditorData(QWidget *editor, const QModelIndex &index) const override
            {
                QString str = index.model()->data(index, Qt::EditRole).toString(); 
                QComboBox *comboBox = static_cast<QComboBox*>(editor);
                comboBox->setCurrentText(str);
            }

            void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const override
            {
                QComboBox *comboBox = static_cast<QComboBox*>(editor);
                QString str = comboBox->currentText();
                model->setData(index, str, Qt::EditRole);
            }

            void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,const QModelIndex &index) const override
            {
                Q_UNUSED(index);
                editor->setGeometry(option.rect);
            }
    };

    /*-----------------spinbox---------------------*/
    class spinBoxDelegate: public QStyledItemDelegate
    {
        Q_OBJECT

        public:
            spinBoxDelegate(QObject *parent=0){};

            QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const Q_DECL_OVERRIDE
            {
                QSpinBox *editor = new QSpinBox(parent);
                editor->setFrame(false);
                editor->setMinimum(0);
                editor->setMaximum(10000);
            }

            void setEditorData(QWidget *editor, const QModelIndex &index) const Q_DECL_OVERRIDE
            {
                int value = index.model()->data(index, Qt::EditRole).toInt();
                QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
                spinBox->setValue(value);
            }

            void setModelData(QWidget *editor, QAbstractItemModel *model,
                            const QModelIndex &index) const Q_DECL_OVERRIDE
            {
                QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
                spinBox->interpretText(); //解释数据，如果数据被修改后，就触发信号
                int value = spinBox->value();
                model->setData(index, value, Qt::EditRole);
            }

            void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const Q_DECL_OVERRIDE
            {
                Q_UNUSED(index);
                editor->setGeometry(option.rect);
            }
    };

}; /*----------------------简单应用----------------------*/


namespace MiddleDelegate {
    class PictureDelegate : public QStyledItemDelegate
    {
        Q_OBJECT
    public:
        PictureDelegate(QObject*parent = 0){};

        void setEditorData(QWidget *editor, const QModelIndex &index) const override
        {
            QImage img = index.model()->data(index,Qt::DecorationRole).value<QImage>();
            //QString text = index.model()->data(index,Qt::EditRole | Qt::DisplayRole).toString();
            QLabel * label = static_cast<QLabel*>(editor);
            label->setPixmap(QPixmap::fromImage(img));
            //label->setText(text);
        }
        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override
        {
            QLabel * label = static_cast<QLabel*>(editor);
            model->setData(index,label->pixmap()->toImage(),Qt::DecorationRole);
            //model->setData(index,label->text(),Qt::EditRole | Qt::DisplayRole);
        }

        void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override
        {
            editor->setGeometry(option.rect);
            Q_UNUSED(index);
        }

        QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override
        {
            QLabel * label = new QLabel(parent);
            // label->setAlignment(Qt::AlignCenter); // 图像无法通过此设置居中,因为不是文本角色,而文本的居中
            // 完全可以在QAbstractTableModel的data()函数内的Qt::TextAlignmentRole角色返回Qt::AlignCenter
            return label;
        }

        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override
        {
           QStyleOptionViewItem viewOption(option);
           if (option.state.testFlag(QStyle::State_HasFocus)) // 如果小部件有焦点的话去除
               viewOption.state = viewOption.state ^ QStyle::State_HasFocus;

            // (1) 获取当前的图像
            QImage img =  index.model()->data(index,Qt::DecorationRole).value<QImage>();

            // (2) 获取当前项所在的位置及其大小
            QRect cell=option.rect; // （x,y,w,h）

            // (3) 如果图像宽度小于且高度也小于单元格那么图像可以在单元格内包含
            // 如果图像宽度或者图像高度比单元格大,就要缩放图像,防止图像超出显示范围
            if (cell.width() > img.width())
            {
                if (cell.height() > img.height()) {  // 图像尺寸都小于单元格
               }
                else { // 只有图像高度超出单元格高度
                        img = img.scaledToHeight(cell.height()); // 让图像高度适应单元格
                }
            }
            else {
                if (cell.height() > img.height()) { // 只有图像宽度超出单元格宽度
                    img = img.scaledToWidth(cell.width()); // 让图像宽度适应单元格
               }
                else { // 图像尺寸都大于单元格
                    img = img.scaled(cell.width(),cell.height(),Qt::KeepAspectRatio); //那就让图像变成单元格尺寸
                }
            }

            // (4) 图像确保在单元格内部之后再考虑居中的问题
            // 图像居中时水平坐标等于单元格x坐标+单元格宽度/2-图像宽度/2
            // 图像居中时垂直坐标等于单元格y坐标+单元格高度/2-图像高度/2
            int center_x = 0, center_y = 0;
            center_x = cell.x()+cell.width()/2-img.width()/2;
            center_y = cell.y()+cell.height()/2-img.height()/2;

            painter->drawPixmap(center_x,center_y,QPixmap::fromImage(img)); // 绘制项图像
        }
    };
}; /*----------------------中等应用----------------------*/


namespace DifficultDelegate{
    class BookDelegate : public QSqlRelationalDelegate
    {
        public:
            BookDelegate(QObject *parent):star(QPixmap(":images/star.png")){};

            void paint(QPainter *painter, const QStyleOptionViewItem &option,
                    const QModelIndex &index) const override
            {
                if (index.column() != 5) 
                {
                    QStyleOptionViewItem opt = option;
                    opt.rect.adjust(0, 0, -1, -1); // 适当减少宽度和高度1
                    QSqlRelationalDelegate::paint(painter, opt, index);

                } else {
                    // 下方代码的用处是点击能够执行重绘，否则增加和减少星星的效果不会产生
                    QPalette::ColorGroup cg = (option.state & QStyle::State_Enabled) ?
                        (option.state & QStyle::State_Active) ? QPalette::Normal :QPalette::Inactive
                                                            :QPalette::Disabled;
                    // 如果矩形框是State_Active，则是QPalette::Normal 否则 QPalette::Inactive(最小化窗口时会有)
                    // 如果矩形框是State_Enabled，是上边的二选一结果，否则是QPalette::Disabled
                    // 颜色组一般就是QPalette::Active进行重绘

                    if (option.state & QStyle::State_Selected) // 如果小部件被选择就高亮这个颜色组,否则项不会被高亮
                        painter->fillRect(option.rect,option.palette.color(cg, QPalette::Highlight));

                    const QAbstractItemModel *model = index.model();
                    int rating = model->data(index, Qt::DisplayRole).toInt();// 要显示的星星数量
                    int width = star.width();
                    int height = star.height();
                    int x = option.rect.x(); // 当前项的水平位置
                    int y = option.rect.y() + (option.rect.height() / 2) - (height / 2); // 当前项的垂直位置适当向下平移到居中
                    // 也就是原本矩形的高度减去要图片的高度再除2才是要平移的距离，然后y固定即可
                    for (int i = 0; i < rating; ++i) { // 重新绘制
                        painter->drawPixmap(x, y, star);
                        x += width; 
                    }
                    drawFocus(painter, option, option.rect.adjusted(0, 0, -1, -1));
                }

                QPen pen = painter->pen();
                painter->setPen(option.palette.color(QPalette::Mid));
                painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
                painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
                painter->setPen(pen);

            }

            QSize sizeHint(const QStyleOptionViewItem &option,
                        const QModelIndex &index) const override
            {
                if (index.column() == 5)
                    return QSize(5 * star.width(), star.height()) + QSize(1, 1); //限制宽度，最多5个星
                return QSqlRelationalDelegate::sizeHint(option, index) + QSize(1, 1);
            }

            bool editorEvent(QEvent *event, QAbstractItemModel *model,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index) override
            {
                if (index.column() != 5)
                    return QSqlRelationalDelegate::editorEvent(event, model, option, index);

                if (event->type() == QEvent::MouseButtonPress) { // 可以通过点击区域来增加或者减少星星，鼠标事件只能在5列触发
                    QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
                    // 等价于qMax(min, qMin(val, max)). 结果是max(min,val)或max(min,max)，也就是结果是val或max
                    auto totalwidth = qreal(mouseEvent->pos().x()- option.rect.x()) ; // 鼠标水平位置减去矩形的水平位置
                    qDebug()<<"mouse.x = "<<mouseEvent->pos().x()<<"  opt.x = "<<option.rect.x();
                    auto val =  int(0.7 +  totalwidth/ star.width()); // 0.7应该是一些偏置微调,得到可以放置星星的数量
                    int stars = qBound(0, val, 5); // 得到是几颗星，从而得到评分数，取值val或者5，上边界
                    model->setData(index, QVariant(stars)); 
                    return false;
                }

                return true;
            }

            QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                const QModelIndex &index) const override
            {
                if (index.column() != 4) 
                    return QSqlRelationalDelegate::createEditor(parent, option, index);

                QSpinBox *sb = new QSpinBox(parent);
                sb->setFrame(false); //4列是spinbox
                sb->setMaximum(2100);
                sb->setMinimum(-1000);

                return sb;
            }

    private:
        QPixmap star;
};

};/*----------------------困难应用----------------------*/
#endif
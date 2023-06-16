#include "picturedelegate.h"
#include <QDebug>

PictureDelegate::PictureDelegate(QObject*parent):QStyledItemDelegate(parent)
{

}

QWidget* PictureDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
     QLabel * label = new QLabel(parent);
     //label->setAlignment(Qt::AlignCenter);
     return label;
}

void PictureDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
//            QStyleOptionViewItem viewOption(option);
//            if (option.state.testFlag(QStyle::State_HasFocus))
//                viewOption.state = viewOption.state ^ QStyle::State_HasFocus;

            QImage img =  index.model()->data(index,Qt::DecorationRole).value<QImage>();
            // 图像的宽度和高度是固定值
            int center_x = 0, center_y = 0;
            QRect cell=option.rect; // （x,y,w,h）单元格的位置和大小

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

            // 单元格的范围必须比图像大,这样图像居中时水平坐标等于单元格坐标+单元格宽度/2-图像宽度/2
            center_x = cell.x()+cell.width()/2-img.width()/2;
            center_y = cell.y()+cell.height()/2-img.height()/2;

        //qDebug()<<QString("w = %1, h = %2, x = %3, y = %4").arg(width).arg(height).arg(x).arg(y);
            painter->drawPixmap(center_x,center_y,QPixmap::fromImage(img));
}

void PictureDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QImage img = index.model()->data(index,Qt::DecorationRole).value<QImage>();
    //QString text = index.model()->data(index,Qt::EditRole | Qt::DisplayRole).toString();
    QLabel * label = static_cast<QLabel*>(editor);
    if (label) {
    //label->setAlignment(Qt::AlignCenter);
     label->setPixmap(QPixmap::fromImage(img));
    }
}

void PictureDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLabel * label = static_cast<QLabel*>(editor);
    model->setData(index,label->pixmap()->toImage(),Qt::DecorationRole);
    //model->setData(index,label->text(),Qt::EditRole | Qt::DisplayRole);
}

void PictureDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
    Q_UNUSED(index);
}

#include "../../inc/flow/scanprevioustablemodel.h"

ScanPreviousTableModel::ScanPreviousTableModel(QObject *parent) : QStandardItemModel(parent)
{

}

ScanPreviousTableModel::ScanPreviousTableModel(int rows, int columns, QObject *parent):QStandardItemModel(rows,columns,parent)
{

}

bool  ScanPreviousTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) return false;

    auto row = index.row();
    auto col = index.column();


    if (role == Qt::EditRole) {

        if (col == GroupNameColumn || col == PointNameColumn) {
            auto text = value.toString(); // 所在组
            if (text.isEmpty())
                return false;
        } // x,y,order由于intValidator的存在不会是空的且必须是数字

        if (col == PointXColumn || col == PointYColumn) {//点不能重复选择
            QVector<QPoint> points;
            for(int r = 0 ; r < rowCount(); ++r) {
                if (r != row) {
                    auto x = data(this->index(r,PointXColumn)).toUInt();
                    auto y = data(this->index(r,PointYColumn)).toUInt();
                    points.append(QPoint(x,y)); // 除了当前行的以外点
                }
            }

            QPoint point; // 当前的点
            if (col== PointXColumn) {
                point.setX(value.toUInt());
                point.setY(data(this->index(row,PointYColumn)).toUInt());
            }
            if (col== PointYColumn) {
                point.setX(data(this->index(row,PointXColumn)).toUInt());
                point.setY(value.toUInt());
            }

            //qDebug()<<"points = " <<points<<"\npoint = "<<point;
            if (points.contains(point)) { // 特定的两列只有点不重复才改变
                return false;
            }
        }

        if (col == PointNameColumn) { // 同一个组的不能重名
            QVector<QString> names; // 同一个组的所有点名称
            auto group = data(this->index(row,GroupNameColumn)).toString(); // 所在组

            for(int r = 0 ; r < rowCount(); ++r) {
                if (r != row) {
                    auto g =  data(this->index(r,GroupNameColumn)).toString();
                    if (group == g) { // 同组
                        auto n =  data(this->index(r,PointNameColumn)).toString();
                        names.append(n);
                    }
                }
            }
            auto name = value.toString();
            //qDebug()<<"group = "<<group<<" name = "<<name<<" names = "<<names;
            if (names.contains(name))
                return false;
        }

        if (col == PointOrderColumn) { // 同一个组的次序不能重复
            QVector<int> orders; // 拿到所在组的除当前行以外的所有次序
            auto group = data(this->index(row,GroupNameColumn)).toString(); // 所在组
            //qDebug()<<"current group = "<<group<<" current row = "<<row;
            for(int r = 0 ; r < rowCount(); ++r) {
                if (r != row) { // 不能是当前行
                    auto g =  data(this->index(r,GroupNameColumn)).toString();
                    //qDebug()<<"第"<<r<<"行的group = "<<g;
                    if (group == g) { // 是同组的
                        auto o =  data(this->index(r,PointOrderColumn)).toUInt();
                        //qDebug()<<"第"<<r<<"行的order = "<<o;
                        orders.append(o);
                    }
                }
            }

            auto order = value.toUInt(); // 想要编辑的值
            //qDebug()<<"orders = "<<orders<<" order = "<<order;
            if (orders.count() == 0) { // 组只有1条记录,那么其他行没次序,value必须等于1
                if (order!=1)
                    return false;
            }
            if (orders.contains(order))
                return false;
        }
    }
    return QStandardItemModel::setData(index,value,role);
}

QVariant ScanPreviousTableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::TextAlignmentRole)
        return  Qt::AlignCenter;

    return QStandardItemModel::data(index, role);
}


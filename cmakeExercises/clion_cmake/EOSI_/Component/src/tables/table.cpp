#include "../../inc/tables/table.h"

Table::Table(QWidget *parent) : QWidget(parent) ,mDelegateType(DefaultDelegate)
{
    initObject();
    initLayout();
    initConnections();
}

Table::Table(int rows,int cols,QWidget *parent) : QWidget(parent) ,mDelegateType(DefaultDelegate)
{
    initObject();
    mModel->setRowCount(rows);
    mModel->setColumnCount(cols);
    initLayout();
    initConnections();
}

void Table::initLayout()
{
    mView->setModel(mModel);
    mView->setSelectionModel(mSelection);
    if (mDelegateType == Widget2x2Delegate)
        mView->updateCellSize(); // 如果是2x2的代理才重新调整单元格大小

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->setMargin(0);
    lay->setSpacing(0);
    lay->addWidget(mView);

    resize(mView->size());
    INIT_FONT;
}

void Table::initConnections()
{
    connect(this,&Table::currentItemChanged,this,&Table::onCurrentItemChanged);
//    connect(mModel,&StandardItemModel::dataChanged,this,
//            [=](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles ){
//            qDebug()<<topLeft<<"   "<<bottomRight<<"   "<<roles;
//    });
}

void Table::initObject()
{
    mView = new TableView;
    mDelegate = nullptr;
    mModel = new StandardItemModel(mView);
    mSelection = new QItemSelectionModel(mModel);
}

void Table::setDelegate(QStyledItemDelegate *delegate)
{
//    if (mDelegate != delegate)
//        delete  mDelegate;
    mDelegate = delegate;
    mView->setItemDelegate(delegate);
}

void Table::setDelegateType(DelegateType type)
{
    mDelegateType = type;
}

DelegateType Table::delegateType() const
{
    return mDelegateType;
}


 void Table::setItemCount(int rows,int cols)
 {
     mModel->clear();
     mModel->setRowCount(rows);
     mModel->setColumnCount(cols);
     mView->updateCellSize();
 }

QVariant Table::data(const QModelIndex &index, int role) const
{
    if (!mModel) return QVariant();
    return mModel->data(index,role);
}

QVariant Table::data(int row, int col, int role) const
{
    if (!mModel) return QVariant();
    return mModel->data(index(row,col),role);
};

bool Table::setData(const QModelIndex &index, const QVariant &value, int role)
{// 这里设置无法保证数量一定是4还不知道位置信息,会出现越界问题
    if (delegateType() == Widget2x2Delegate && role == Qt::DecorationRole)
        return false; // Widget2x2代理的不允许通过setData存图片数据,因为无法保证数量是4

    if (!mModel) return false;
    return mModel->setData(index,value,role);
};

bool Table::setData(int row, int col, const QVariant &value, int role)
 {// 不要使用setData来设置而应该使用下方的setPixmap
    if (delegateType() == Widget2x2Delegate && role == Qt::DecorationRole)
        return false;
    if (!mModel) return false;
    return mModel->setData(index(row,col),value,role);
};

bool Table::setItemData(const QModelIndex &index, const QMap<int, QVariant> &roles)
{ // setItemData同理
    if (delegateType() == Widget2x2Delegate && roles.keys().contains(Qt::DecorationRole)) return false;
    if (!mModel) return false;
    return mModel->setItemData(index,roles);
};

bool Table::setItemData(int row, int col, const QMap<int, QVariant> &roles)
{
    if (delegateType() == Widget2x2Delegate && roles.keys().contains(Qt::DecorationRole)) return false;
    if (!mModel) return false;
    return mModel->setItemData(index(row,col),roles);
};

QMap<int,QVariant> Table::itemData(const QModelIndex &index) const
{
    if (!mModel) return QMap<int,QVariant>();
    return mModel->itemData(index);
};

QMap<int,QVariant> Table::itemData(int row, int col) const
{
    if (!mModel) return QMap<int,QVariant>();
    return mModel->itemData(index(row,col));
};

void Table::setHeaderData(const QStringList&labels,Qt::Orientation oriention)
{
    if (oriention == Qt::Horizontal)
        mModel->setHorizontalHeaderLabels(labels);
    else mModel->setVerticalHeaderLabels(labels);
}

void Table::setRowData(int row,const QVariantList& rowValues,int role)
{
    auto c = rowValues.count();
    if (c > mModel->columnCount()) return; // 数量不能超过实际列数,否则越界
    for(int col = 0; col < c; ++col) {
        setData(row,col,rowValues.at(col),role);
    }
}

void Table::setRowData(int row,const QStringList& rowValues)
{ // 一个便捷方法只设置文本
    QVariantList list;
    foreach(auto val, rowValues)
        list.append(val);
    setRowData(row,list,Qt::EditRole);
}

QModelIndex Table::index(int row, int col) const
{
    if (!mModel) return QModelIndex();
    return mModel->index(row,col);
}

// 代理是label或者默认default
bool Table::setPixmap(int row,int col,QPixmap*pix)
{
    if (delegateType() == Widget2x2Delegate)
        return false;
    return mModel->setData(index(row,col),*pix,Qt::DecorationRole);
}

bool Table::setPixmap(int row,int col,const QPixmap&pix)
{
    if (delegateType() == Widget2x2Delegate)
        return false;
    return setPixmap(row,col,new QPixmap(pix));
}


QPixmap* Table::pixmap(int row,int col) const
{
    if (delegateType() == Widget2x2Delegate)
        return nullptr;
    auto pix = mModel->data(index(row,col),Qt::DecorationRole).value<QPixmap>();
    return new QPixmap(pix);
}

bool Table::setSelectedItem(int row, int col, bool isSelected)
{
    if (delegateType() == Widget2x2Delegate)
        return false;
    return mModel->setData(index(row,col),isSelected,TableModelDataRole::isSelected);
}

bool Table::setCurrentItem(int row,int col,bool isCurrent)
{// 设置当前项
    if (delegateType() == Widget2x2Delegate)
        return false;
    bool r =  mModel->setData(index(row,col),isCurrent,TableModelDataRole::isCurrent);
    if (r) emit currentItemChanged(row,col); // 当前项只能有1个
    return r;
}

// 代理是Widget2x2Delegate
bool Table::setPixmap(int row,int col,int pos,QPixmap*pix)
{
    if (delegateType() != Widget2x2Delegate)
        return false;
    QVariant var;
    auto variant = mModel->data(index(row,col),Qt::DecorationRole);
    if (!variant.isValid()) // 没有存过数据
    {
        QVector<QPixmap*> v(4,nullptr);
        v[pos] = pix; // 指定位置存图
        var.setValue(v);
    }else { // 存过数据
        auto v = variant.value<QVector<QPixmap*>>();
        Q_ASSERT(v.count() == 4); // 不管使用setPixmaps还是setPixmap,都会保证数量为4
        v[pos] = pix;// 指定位置存图
        var.setValue(v);
    }
    return mModel->setData(index(row,col),var,Qt::DecorationRole);
}

bool Table::setPixmap(int row,int col,int pos,const QPixmap&pix)
{
    if (delegateType() != Widget2x2Delegate)
        return false;
    return setPixmap(row,col,pos,new QPixmap(pix));
}


QPixmap* Table::pixmap(int row,int col, int pos) const
{
    if (delegateType() != Widget2x2Delegate)
        return nullptr;
    return pixmaps(row,col)[pos];
}

QVector<QPixmap*> Table::pixmaps(int row,int col) const
{
    if (delegateType() != Widget2x2Delegate)
        return QVector<QPixmap*>();
    auto pixs = mModel->data(index(row,col),Qt::DecorationRole).value<QVector<QPixmap*>>();
    Q_ASSERT(pixs.count() == 4);
    return  pixs;
}

bool Table::setPixmaps(int row,int col, const QVector<QPixmap*>& pixs)
{ // 只用于传4张图片的,满足条件就是全部覆盖无需再先取出数据
    if (delegateType() != Widget2x2Delegate)
        return false;
    if (pixs.count() !=4 ) return false;
    QVariant v;
    v.setValue(pixs);
    return mModel->setData(index(row,col),v,Qt::DecorationRole);
}

bool Table::setPixmaps(int row,int col, const QVector<QPair<int,QPixmap*>> &pixs)
{ // 传递1-4张均可 ,pixs是指定位置绑定1张图
    if (delegateType() != Widget2x2Delegate)
        return false;
    if (pixs.count()<=0 || pixs.count() > 4) return false;

    QVector<QPair<int,QPixmap*>>::const_iterator iter;
    auto variant = mModel->data(index(row,col),Qt::DecorationRole);
    if (variant.isValid()) // 存过数据,有效的保证过一定4个图
    {
        auto v = variant.value<QVector<QPixmap*>>();
         Q_ASSERT(v.count() == 4);
        for(iter=pixs.begin(); iter!=pixs.end(); ++iter)
        {
            //auto [pos, pix] = *iter; // c++17
            int pos = iter->first;
            QPixmap * pix = iter->second;
            if (pos < 0 || pos > 3) return false; // 检查位置信息是否正确,不能越界
            v[pos] = pix; // 替换对应位置的图
        }
    }
    else { // 没存过数据,一定要保证4个图
        QVector<QPixmap*> v(4,nullptr);
        for(iter=pixs.begin(); iter!=pixs.end(); ++iter)
        {
            int pos = iter->first;
            QPixmap * pix = iter->second;
            if (pos < 0 || pos > 3) return false; // 检查位置信息是否正确,不能越界
            v[pos] = pix; // 替换对应位置的图,不替换的还是nullptr
        }
    }

    return true;
}

bool Table::setSelectedItems(int row, int col, uint32_t info)
{
    if (delegateType() != Widget2x2Delegate)
        return false;
    if (info < 0 || info > 15)  // 枚举值的范围0b0000-0b1111
        return false;
    return mModel->setData(index(row,col),info,TableModelDataRole::SelectedItems);
}

bool Table::setCurrentItems(int row,int col,uint32_t info)
{// 设置当前项
    if (delegateType() != Widget2x2Delegate)
        return false;
    if (info != 0 && info != 0b1000 && info != 0b0100 && info != 0b0010 && info != 0b0001)
        return false;

    bool r =  mModel->setData(index(row,col),info,TableModelDataRole::CurrentItem);
    if (r) emit currentItemChanged(row,col); // 当前项只能有1个

    return r;
}

void Table::onCurrentItemChanged(int row,int col)
{ // 一旦当前项改变,其它所有单元格包括子单元格的isCurrent都要置false
    if (mModel)
    {
        for (int r = 0; r <mModel->rowCount(); ++r ){
            for (int c= 0; c < mModel->columnCount(); ++c){
                if (r == row && c == col )
                    continue;
                mModel->setData(index(r,c),false,TableModelDataRole::isCurrent);// label
                mModel->setData(index(r,c),false,TableModelDataRole::CurrentItem);// Widget2x2Delegate
            }
        }
    }
}


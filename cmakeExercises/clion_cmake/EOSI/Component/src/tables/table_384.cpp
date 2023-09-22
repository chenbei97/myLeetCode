#include "../../inc/tables/table_384.h"

Table_384::Table_384(QWidget *parent) : QWidget(parent)
{
    mView = new TableView;
    //mView->setEditTriggers(TableView::DoubleClicked);
    mDelegate = new TableViewDelegate2x2;
    mModel = new TableModel(mView);
    mModel->setItemCount(8,12);
    mSelection = new QItemSelectionModel(mModel);

    mView->setItemDelegate(mDelegate);
    mView->setModel(mModel);
    mView->setSelectionModel(mSelection);

    mView->updateCellSize();

    QVBoxLayout * lay = new QVBoxLayout(this);
    lay->setMargin(0);
    lay->setSpacing(0);

    lay->addWidget(mView);
    resize(mView->size());

    connect(this,&Table_384::currentItemChanged,this,&Table_384::onCurrentItemChanged);

    INIT_FONT;
}

bool Table_384::setPixmap(int row,int col,int pos,QPixmap*pix)
{
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

bool Table_384::setPixmap(int row,int col,int pos,const QPixmap&pix)
{
    return setPixmap(row,col,pos,new QPixmap(pix));
}


QPixmap* Table_384::pixmap(int row,int col, int pos) const
{
    return pixmaps(row,col)[pos];
}

QVector<QPixmap*> Table_384::pixmaps(int row,int col) const
{
    auto pixs = mModel->data(index(row,col),Qt::DecorationRole).value<QVector<QPixmap*>>();
    Q_ASSERT(pixs.count() == 4);
    return  pixs;
}

bool Table_384::setPixmaps(int row,int col, const QVector<QPixmap*>& pixs)
{ // 只用于传4张图片的,满足条件就是全部覆盖无需再先取出数据
    if (pixs.count() !=4 ) return false;
    QVariant v;
    v.setValue(pixs);
    return mModel->setData(index(row,col),v,Qt::DecorationRole);
}

bool Table_384::setPixmaps(int row,int col, const QVector<QPair<int,QPixmap*>> &pixs)
{ // 传递1-4张均可 ,pixs是指定位置绑定1张图
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

bool Table_384::setSelectedItems(int row, int col, uint32_t info)
{
    if (info < 0 || info > 15)  // 枚举值的范围0b0000-0b1111
        return false;
    return mModel->setData(index(row,col),info,TableModelDataRole::SelectedItems);
}

bool Table_384::setCurrentItem(int row,int col,uint32_t info)
{// 设置当前项
    if (info != 0 && info != 0b1000 && info != 0b0100 && info != 0b0010 && info != 0b0001)
        return false;

    bool r =  mModel->setData(index(row,col),info,TableModelDataRole::CurrentItem);
    if (r) emit currentItemChanged(row,col); // 当前项只能有1个

    return r;
}


void Table_384::onCurrentItemChanged(int row,int col)
{ // 一旦当前项改变,其它所有单元格包括子单元格的CurrentItem都要置零
    for (int r = 0; r <mModel->rowCount(); ++r ){
        for (int c= 0; c < mModel->columnCount(); ++c){
            if (r == row && c == col )
                continue;
            mModel->setData(index(r,c),0,TableModelDataRole::CurrentItem);
            //LOG<<"row = "<<row<<" col = "<<col;
        }
    }
}

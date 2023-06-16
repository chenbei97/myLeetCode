#include "picturemodel.h"

PictureModel::PictureModel(QObject *parent):QAbstractTableModel(parent)
{
        mRows = mCols = 3;

        QVector<QString> text = {"1","2","3"};
        mText << text;
       text = {"4","5","6"};
        mText << text;
        text = {"7","8","9"};
         mText << text;

        QVector<QImage> * rowImages;
        QSize size = QSize(300,(int)300*0.618);
        int tem = 1;
        for(int row = 1; row <= mRows ; ++row )
        {
            rowImages = new QVector<QImage>;
            for (int col = 1; col <= mCols; ++col)
            {
                rowImages->push_back(QImage(QString("../50-TableShowPictures/%1.jpg").arg(tem)).scaled(size));
                tem++;
            }
            mImages.append(rowImages);
        }
}

bool PictureModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        mText[index.row()].replace(index.column(), value.toString());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

QVariant PictureModel::data(const QModelIndex &index, int role) const
{
    if ( role == Qt::EditRole || role == Qt::DisplayRole)
       // return mText[index.row()][index.column()];
        return QVariant();

    else if (role == Qt::DecorationRole)
        return mImages[index.row()]->at(index.column());


    else if (role == Qt::TextAlignmentRole)
        return  Qt::AlignCenter;
//    else if (role == Qt::StatusTipRole)
//    {
//        return QString("bytesPerLine = %1").arg(mImages[index.row()]->at(index.column()).bytesPerLine());
//    }
    return QVariant();
}

Qt::ItemFlags PictureModel::flags(const QModelIndex &index) const
{
    //return  QAbstractItemModel::flags(index) | Qt::ItemIsEditable ;
    return QAbstractItemModel::flags(index);
}

int PictureModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCols;
}

int PictureModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return mRows;
}

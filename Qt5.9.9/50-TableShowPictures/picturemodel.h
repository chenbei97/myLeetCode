#ifndef PICTUREMODEL_H
#define PICTUREMODEL_H

#include <QAbstractTableModel>
#include <QImage>

class PictureModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit PictureModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    //QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
private:
    QList<QVector<QImage>*> mImages;
    QList<QVector<QString>> mText;
    int mRows;
    int mCols;
};

#endif // PICTUREMODEL_H

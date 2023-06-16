#ifndef TABLESHOWPICTURES_H
#define TABLESHOWPICTURES_H

#include <QMainWindow>
#include "picturemodel.h"
#include "picturedelegate.h"
#include <QTableView>
#include <QTableWidget>
#include <QResizeEvent>

class TableShowPictures : public QMainWindow
{
    Q_OBJECT
private:
       PictureModel * mModel;
       PictureDelegate * mDelegate;
       //QTableWidget * mView;
       QTableView * mView;
public:
    TableShowPictures(QWidget *parent = nullptr);
    ~TableShowPictures();
    void resizeEvent(QResizeEvent*e) override;
private slots:
    void onIconSizeChanged(const QSize&size);
};
#endif // TABLESHOWPICTURES_H

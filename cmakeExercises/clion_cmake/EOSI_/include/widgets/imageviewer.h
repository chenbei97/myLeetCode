#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include "picture.h"
#include "pushbutton.h"

typedef PictureV2::Picture PicturePanel;

class COMPONENT_IMEXPORT ImageViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ImageViewer(QWidget *parent = nullptr);
    void clearHistoryPixmaps();
    void setPixmap(int index);
    void appendPixmap(const QPixmap&pix,const QString& path);
    void setForwardEnabled(bool enable);
    void setBackwardEnabled(bool enable);
private:
    PicturePanel * mPicture;
    PushButton *forwardButton;
    PushButton *backButton;
    QStringList mPixOriginPaths;
    QVector<QPixmap> mPixmaps;
    int currentIndex;
private slots:
    void on_forwardButton_clicked();
    void on_backButton_clicked();
    void onCurrentIndexChanged();
private : signals:
    void currentIndexChanged();
signals:
    void indexChanged(int index);

};

#endif // IMAGEVIEWER_H

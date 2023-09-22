#ifndef PICTURE_H
#define PICTURE_H

#include "qmenu.h"
#include "label.h"

//namespace PictureVersion {

    inline namespace PictureV1 {
        class COMPONENT_IMEXPORT Picture : public QWidget
        {
            Q_OBJECT
            Q_PROPERTY(QPixmap pixmap READ  pixmap WRITE setPixmap)
            Q_PROPERTY(QString info READ  info WRITE setInfo)

            QLabel * mPix;
            QLabel * mInfo;
            QMenu * mMenu;
            QAction * mExpertAction;

        public:
            explicit Picture(QWidget *parent = nullptr);
            void resizeEvent(QResizeEvent *event) override;

            void setPixmap(const QPixmap& pix);
            QPixmap pixmap() const;

            void setInfo(const QString& info);
            QString info() const;

            void hideInfo();
            void showInfo();
        signals:
        };
    } // endV1

    namespace PictureV2
    {
        class COMPONENT_IMEXPORT Picture : public QWidget
        {
                Q_OBJECT
            public:
                explicit Picture(QWidget *parent = nullptr);
                void paintEvent(QPaintEvent *event) override;
                void mouseDoubleClickEvent(QMouseEvent *event) override;
                void setPixmap(const QPixmap&pix,const QString& path);
            private:
                QPixmap pixmap;
                QMenu * mMenu;
                QAction * mAction;
                QAction * mShowOriginAction;
                QString mOrginPath;
                void showOriginalPixmap();
            signals:
                void mouseDoubleClicked();
        };
    } // endV2

    namespace PictureV3
    {
        class COMPONENT_IMEXPORT Picture : public QWidget
        {
                Q_OBJECT
            public:
                explicit Picture(QWidget *parent = nullptr);
                void paintEvent(QPaintEvent *event) override;
                void setPixmap(const QPixmap&pix);
            private:
                QPixmap  pixmap;
        };
    } // endV3

//} // end PictureVersion

#endif // PICTURE_H

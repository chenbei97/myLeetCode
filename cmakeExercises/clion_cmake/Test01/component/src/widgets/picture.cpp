#include "../../inc/widgets/picture.h"


//namespace PictureVersion {

    inline namespace  PictureV1
    {
        Picture::Picture(QWidget *parent) : QWidget(parent)
        {
            mPix = new QLabel;
            mInfo = new QLabel;
            hideInfo();

            mMenu = new QMenu(this);
            mExpertAction = new QAction(tr("导出"),this);
            mMenu->addAction(mExpertAction);

            connect(mExpertAction,&QAction::triggered,[=]{
                auto pix = mPix->pixmap();
                auto dir = QFileDialog::getExistingDirectory(this,tr("选择保存目录"));
                if (dir.isEmpty()) return ;
                pix->save(dir +"/"+ QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss")+".jpg");
            });

            QVBoxLayout * lay = new QVBoxLayout(this);
            lay->addWidget(mPix);
             lay->addWidget(mInfo);

             setContextMenuPolicy(Qt::CustomContextMenu);
             connect(this,&Picture::customContextMenuRequested,[=](const QPoint&){
                 mMenu->exec(QCursor::pos());
             });
        }

        void Picture::resizeEvent(QResizeEvent *event)
        {
            //auto size = event->size();
            //LOG<<"size = "<<size;

        //    mPix->setGeometry(0,0,size.width(),size.height()*0.9);
        //    mInfo->setGeometry(0,size.height()*0.8,size.width(),size.height()*0.1);
            event->accept();
        }

        void Picture::setPixmap(const QPixmap& pix)
        {
            if (pix.isNull()) return;
            mPix->setPixmap(pix);
        }

        QPixmap Picture::pixmap() const
        {
            if (!mPix->pixmap())
                return QPixmap();
            return *mPix->pixmap();
        }

        void Picture::setInfo(const QString& info)
        {
            mInfo->setText(info);
            mInfo->setToolTip(info);
        }

        QString Picture::info() const
        {
            return mInfo->text();
        }

        void Picture::hideInfo()
        {
            mInfo->hide();
        }

        void Picture::showInfo()
        {
            mInfo->show();
        }
    } // endV1

    namespace PictureV2
    {
        Picture::Picture(QWidget *parent) : QWidget(parent)
        {
            mMenu = new QMenu(this);
            mAction = new QAction(tr("导出"),this);
            mShowOriginAction = new QAction(tr("原图"),this);
            mMenu->addAction(mAction);
            mMenu->addAction(mShowOriginAction);
            connect(mAction,&QAction::triggered,[=]{
                auto dir = QFileDialog::getExistingDirectory(this,tr("选择保存目录"));
                if (dir.isEmpty()) return ;
                pixmap.save(dir +"/"+ QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-mm-ss")+".jpg");
            });
            connect(mShowOriginAction,&QAction::triggered,this,&Picture::showOriginalPixmap);
            setContextMenuPolicy(Qt::CustomContextMenu);
            connect(this,&Picture::customContextMenuRequested,[=](){mMenu->exec(QCursor::pos());});
            mMenu->setEnabled(false);

            //setMinimumSize(400,300);
        }

        void Picture::setPixmap(const QPixmap&pix,const QString& path)
        {
            mOrginPath = path;
            pixmap = pix;
            if (!pix.isNull()) {
                mMenu->setEnabled(true);
            }
            update();
        }

        void Picture::paintEvent(QPaintEvent *event)
        {
            if (!pixmap.isNull()) {
                QPainter painter(this);
                painter.setRenderHint(QPainter::Antialiasing);
                painter.drawPixmap(rect(),pixmap);
            }
            event->accept();
        }

        void Picture::mouseDoubleClickEvent(QMouseEvent *event)
        {
            showOriginalPixmap();
            emit mouseDoubleClicked();
            event->accept();
        }

        void Picture::showOriginalPixmap()
        {
//            if (mOrginPath.isEmpty()) return;
//
//            PictureV3::Picture * dlg = new PictureV3::Picture;
//
//            dlg->setAttribute(Qt::WA_DeleteOnClose);
//            dlg->setPixmap(QPixmap(mOrginPath));
//            dlg->show();
        }

    } // endV2

    namespace PictureV3
    {
        Picture::Picture(QWidget *parent) : QWidget(parent)
        {
        }

        void Picture::setPixmap(const QPixmap&pix)
        {
            pixmap = pix;
            update();
        }

        void Picture::paintEvent(QPaintEvent *event)
        {
            if (!pixmap.isNull()) {
                resize(pixmap.size());
                QPainter painter(this);
                painter.setRenderHint(QPainter::Antialiasing);
                painter.drawPixmap(rect(),pixmap);
            }
            event->accept();
        }
    } // endV3
//}

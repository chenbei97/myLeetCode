#include "../../inc/widgets/imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent) : QWidget(parent)
{
    currentIndex = -1;
    mPicture = new PicturePanel;
    forwardButton = new PushButton(this);
    backButton = new PushButton(this);
    mPicture->setMinimumHeight(300);
    mPicture->setMinimumWidth(400);
    forwardButton->setMinimumHeight(25);
    backButton->setMinimumHeight(25);
    forwardButton->setMinimumWidth(50);
    backButton->setMinimumWidth(50);

    forwardButton->setIcon(QIcon(IMAGE_FORWARD));
    backButton->setIcon(QIcon(IMAGE_BACKWARD));
    forwardButton->setEnabled(false);
    backButton->setEnabled(false);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addStretch();
    hlayout->addWidget(backButton);
    hlayout->addSpacing(10);
    hlayout->addWidget(forwardButton);
    hlayout->addStretch();

    auto lay = new QVBoxLayout;
    lay->setSpacing(5);
    lay->setMargin(0);
    lay->addWidget(mPicture);
    lay->addStretch();
    lay->addLayout(hlayout);

    setLayout(lay);

    connect(forwardButton, SIGNAL(clicked()), this, SLOT(on_forwardButton_clicked()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
    connect(this,&ImageViewer::currentIndexChanged,this,&ImageViewer::onCurrentIndexChanged);
}

void ImageViewer::appendPixmap(const QPixmap&pix,const QString& path)
{
    mPicture->setPixmap(pix,path);
    mPixmaps.append(pix);
    mPixOriginPaths.append(path);
    currentIndex = mPixmaps.count()-1;
}

void ImageViewer::setPixmap(int index)
{ // index为图片的第几张
    LOG<<"index = "<<index<<"  count = "<<mPixmaps.count();
    if (index < 0 || index > mPixmaps.count() - 1){
        mPicture->setPixmap(QPixmap(),""); // 不要发射信号,否则点击普通孔会导致使能变化然后越界错误
    }
    else {
        mPicture->setPixmap(mPixmaps.at(index),mPixOriginPaths.at(index));
        currentIndex = index;
        emit currentIndexChanged();
    }
}

void ImageViewer::setForwardEnabled(bool enable)
{
    forwardButton->setEnabled(enable);
}

void ImageViewer::setBackwardEnabled(bool enable)
{
    backButton->setEnabled(enable);
}

void ImageViewer::clearHistoryPixmaps()
{
    mPixOriginPaths.clear();
    mPixmaps.clear();
    currentIndex = -1;
    setBackwardEnabled(false);
    setForwardEnabled(false);
}

void ImageViewer::on_forwardButton_clicked()
{
    currentIndex++;
    emit currentIndexChanged();
    if (currentIndex > mPixmaps.count()-1)
        return;
    setPixmap(currentIndex);
    emit indexChanged(currentIndex);
}

void ImageViewer::on_backButton_clicked()
{
    currentIndex--;
    emit currentIndexChanged();
    if (currentIndex < 0)
        return;
    setPixmap(currentIndex);
    emit indexChanged(currentIndex);
}

void ImageViewer::onCurrentIndexChanged()
{
    LOG<<"currentIndex = "<<currentIndex;
    if (mPixmaps.count() == 1) { // 图片只有1张
        forwardButton->setEnabled(false);
        backButton->setEnabled(false);
        return;
    }

    if (currentIndex == mPixmaps.count() -1 ) { // 最后1张
        forwardButton->setEnabled(false);
        backButton->setEnabled(true);
    }
    else if (currentIndex == 0) { // 第一张
        backButton->setEnabled(false);
        forwardButton->setEnabled(true);
    }
    else { // 其它
        forwardButton->setEnabled(true);
        backButton->setEnabled(true);
    }

}

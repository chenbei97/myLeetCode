#include "../../inc/widgets/imagecontrolbar.h"

ImageControlBar::ImageControlBar(QWidget * parent) :QWidget(parent)
{
    forwardButton = new QPushButton(this);
    backButton = new QPushButton(this);

    forwardButton->setIcon(QIcon(":/images/forward.png"));
    backButton->setIcon(QIcon(":/images/backward.png"));

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addStretch();
    hlayout->addWidget(backButton);
    hlayout->addWidget(forwardButton);
    hlayout->addStretch();

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addStretch();
    layout->addLayout(hlayout);

    setLayout(layout);

    connect(forwardButton, SIGNAL(clicked()), this, SLOT(on_forwardButton_clicked()));
    connect(backButton, SIGNAL(clicked()), this, SLOT(on_backButton_clicked()));
    connect(forwardButton, SIGNAL(clicked()), this, SIGNAL(next()));
    connect(backButton, SIGNAL(clicked()), this, SIGNAL(back()));

    //setMaximumHeight(20);
}

void ImageControlBar::on_forwardButton_clicked()
{
    // 处理前进操作，例如切换图片等
}

void ImageControlBar::on_backButton_clicked()
{
    // 处理后退操作，例如切换图片等
}

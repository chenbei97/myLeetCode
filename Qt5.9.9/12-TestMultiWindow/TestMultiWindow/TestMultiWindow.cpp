#include "TestMultiWindow.h"
#include "ui_TestMultiWindow.h"
#include <QPainter>

TestMultiWindow::TestMultiWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestMultiWindow)
{
      ui->setupUi(this);

      ui->tabWidget->setVisible(false); // 先隐藏
      ui->tabWidget->clear();//清除所有页面
      ui->tabWidget->tabsClosable(); // 给每个page增加关闭按钮
      this->setCentralWidget(ui->tabWidget); // 设置为中心显示,就会替代背景图片的显示
      this->setWindowState(Qt::WindowFullScreen); //窗口最大化显示
      this->setWindowState(Qt::WindowMaximized); //窗口最大化显示，效果一样
      this->setAutoFillBackground(true); // 自动填充背景
     // this->setAttribute(Qt::WA_DeleteOnClose); //关闭时自动删除,加上它会出问题,多删除了1次
     //  Qt::WindowFlags    flags=this->windowFlags();
     // this->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //设置对话框固定大小,这样放大和缩小窗口就不可用了
}

TestMultiWindow::~TestMultiWindow()
{
  delete ui;
}

//绘制窗口背景图片
void TestMultiWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    // void QPainter::drawPixmap(int x, int y, int width, int height, const QPixmap &pixmap);
    // 使用给定的宽度width和高度height将像素图绘制到位置 (x, y) 的矩形中
    int x  = 0, y = ui->toolBar->height(), width = this->width(); // 位置在工具栏下方,左上角是(0,0),所以y是工具栏高度,x就是0
    int height = this->height()-ui->toolBar->height()-ui->statusbar->height(); // 图片的高度就是主窗口高度减去状态栏和工具栏的高度
    painter.drawPixmap(x,y,width,height, QPixmap(":/images/back2.jpg"));
}

// 为QFormDoc独立Widget窗口的动作设置使能
// 在QFormDoc的closeEvent函数被调用,这样窗口关闭以后可以启用打开使能
void TestMultiWindow::setActWidgetEnable(bool able)
{
    ui->actWidget->setEnabled(able);
}

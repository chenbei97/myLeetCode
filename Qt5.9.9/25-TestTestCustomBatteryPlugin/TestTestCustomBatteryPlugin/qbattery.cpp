#include "qbattery.h"
#include    <QPainter>

QBattery::QBattery(QWidget *parent) :QWidget(parent)
{

}

// 1. 自定义电池外观
void QBattery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter    painter(this);
    QRect rect(0,0,this->width(),this->height()); //viewport矩形区
    painter.setViewport(rect);//设置Viewport
    painter.setWindow(0,0,120,50); // 设置窗口大小，逻辑坐标
    painter.setRenderHint(QPainter::Antialiasing); // 设置渲染提示
    painter.setRenderHint(QPainter::TextAntialiasing);

    // 绘制电池边框
    QPen pen;//设置画笔
    pen.setWidth(2); //线宽
    pen.setColor(this->mColorBorder); //用于绘制边界的颜色
    pen.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
    pen.setCapStyle(Qt::FlatCap);//线端点样式
    pen.setJoinStyle(Qt::BevelJoin);//线的连接点样式
    painter.setPen(pen);

    QBrush  brush;//设置画刷
    brush.setColor(this->mColorBack); // 背景的画刷颜色
    brush.setStyle(Qt::SolidPattern); // 画刷填充样式
    painter.setBrush(brush);

    // 绘制1个矩形作为背景,到上下左边界距离1,到右边界距离0
    // 背景颜色就是mColorBack,边框颜色mColorBorder
    rect.setRect(1,1,109,48);// 所以起点变成(1,1),宽度是109,高度48
    painter.drawRect(rect);//绘制电池边框

    // 现在是绘制电池的正极头,背景和边框都是相同颜色均为mColorBorder
    rect.setRect(110,15,10,20); // 这个位置和宽度长度需要事先自己设计好
    brush.setColor(this->mColorBorder); // 重设画刷颜色
    painter.setBrush(brush);
    painter.drawRect(rect); //画电池正极头

    //画电池柱
    if (this->mPowerLevel>this->mWarnLevel)
    {  //正常颜色电量柱
        brush.setColor(this->mColorPower); //画刷颜色设为绿色
        pen.setColor(this->mColorPower); //划线颜色设为绿色
    }
    else
    { //电量低电量柱
        brush.setColor(this->mColorWarning); //画刷颜色设为红色
        pen.setColor(this->mColorWarning); //划线颜色设为红色
    }
    painter.setBrush(brush);
    painter.setPen(pen);

    if (this->mPowerLevel>0)
    {
        rect.setRect(5,5,this->mPowerLevel,40);
        painter.drawRect(rect);//画电池柱
    }

    // 绘制电量百分比文字
    QFontMetrics textSize(this->font()); // 这个类可以将字符串的字体格式进行像素级量化
    QString powStr=QString::asprintf("%d%%",this->mPowerLevel);
    QRect textRect=textSize.boundingRect(powStr);//得到字符串的rect范围

    painter.setFont(this->font());
    pen.setColor(this->mColorBorder); //划线颜色
    painter.setPen(pen);

    painter.drawText(55-textRect.width()/2, // 把字体格式占据的像素宽度和长度考虑进去
               23+textRect.height()/2,
               powStr);
}

// 2. 设置组件缺省大小调整比例
//QSize QBattery::sizeHint()
//{
//    // 此属性保存小部件的推荐大小 如果此属性的值是无效大小，则不推荐大小
//    // 如果此小部件没有布局，则 sizeHint() 的默认实现返回无效大小，否则返回布局的首选大小
//    int H=this->height(); // 获取主窗口的高度(总是保持一致)
//    int W=H * 1000 / 618; // 黄金比例
//    QSize   size(W,H);
//    return size;
//}

// 3.设置当前电量值
void QBattery::setPowerLevel(int pow)
{
    this->mPowerLevel=pow;
    emit powerLevelChanged(pow); //触发信号
    this->repaint(); // 重新绘制外观
}

// 4. 读取当前电量值
int QBattery::powerLevel()
{
    return this->mPowerLevel;
}

// 5. 设置电量低阈值
void QBattery::setWarnLevel(int warn)
{
    this->mWarnLevel = warn;
    this->repaint();
}

// 6. 读取电量低阈值
int QBattery::warnLevel()
{
    return this->mWarnLevel;
}


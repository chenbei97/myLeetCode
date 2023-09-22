#ifndef RANDOMCOLOR_H
#define RANDOMCOLOR_H

#include "qcolor.h"
#include "qrandom.h"
#include "qdatetime.h"
#include "../alias.h"
#include "qmath.h"

static QColor getRandomColor()
{// HSL空间里如果L分量小于200可以避免白色
    QRandomGenerator generator(QTime::currentTime().msec());
    auto h = generator.bounded(50,360);
    auto s = generator.bounded(50,256);
    auto l = generator.bounded(50,200);
    QColor c = QColor::fromHsl(h,s,l);
    return c;
}

static QColor getRandomColor(int alpha)
{// HSL空间里如果L分量小于200可以避免白色
    auto c = getRandomColor();
    c.setAlpha(alpha);
    return c;
}


static QColorVector getUniqueRandomColors(int count)
{
    QColorVector list;
    QColor c;
    for (int i = 0; i < count; ++i) {
        c = getRandomColor();
        while (list.contains(c)) {
            c = getRandomColor();
        }
        list.append(c);
    }
    Q_ASSERT(list.count() == count);
    return list;
}

static QColorVector getUniqueRandomColors(int count,int alpha)
{
    QColorVector list;
    QColor c;
    for (int i = 0; i < count; ++i) {
        c = getRandomColor();
        while (list.contains(c)) {
            c = getRandomColor(alpha);
        }
        list.append(c);
    }
    Q_ASSERT(list.count() == count);
    return list;
}

// Mersenne Twister伪随机数生成器
// 生成指定范围内的随机整数
static int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// 生成随机颜色
static QVector<QColor> generateRandomColors(int numColors) {
//    const int hueMax = 360;
//    int hueDiff =  hueMax / numColors;

    QVector<QColor> colors;
    const int redMax = 256;
    const int greenMax = 256;
    const int blueMax = 256;

    // 初始化Mersenne Twister算法的种子
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>(0, numColors - 1)(gen);

    for (int i = 0; i < numColors; i++) {
        // 生成随机RGB值
        int red = generateRandomNumber(0, redMax);
        int green = generateRandomNumber(0, greenMax);
        int blue = generateRandomNumber(0, blueMax);
        auto color = QColor(red,green,blue);

        if (color.lightness() < 128 || color.value() < 128) { i--; continue;}

//        bool isValid = true;
//        foreach(auto c, colors) {
//            if (qAbs(color.hue()- c.hue() < hueDiff)) {
//                isValid = false;
//                break;
//            }
//        }
//        if (!isValid) {i--;continue;}

         colors.push_back(color);

        }
        return colors;
}

// 生成具有连续的、递增的非线性的颜色梯度的10个颜色
static QVector<QColor> generateColorGradientColors(int numColors) {
    double h1 = 0.0;  // 第一个颜色的H值
    double h2 = 360.0;  // 第二个颜色的H值
    double step = (h2 - h1) / (numColors - 1);  // 每两个相邻颜色的H值之间的步长
    double s = 1.0;  // 饱和度
    double v = 1.0;  // 亮度
    QVector<QColor> colors;
    for (int i = 0; i < numColors; i++) {
        int red = qRound(v * (255.0 - s) * std::sin(i * step * M_PI / 180.0) + 255.0);
        int green = qRound(v * (255.0 - s) * std::sin((i + 1.0) * step * M_PI / 180.0) + 255.0);
        int blue = qRound(v * (255.0 - s) * std::sin((i + 2.0) * step * M_PI / 180.0) + 255.0);
        //int color = red * 65536 + green * 256 + blue;
        colors.push_back(QColor(red,green,blue));
    }
    return colors;
}

static const QColorVector ClassicColors = { // 13x5 = 65个颜色
    "#474747","#6B6B6B","#8F8F8F","#BABABA","#E3E3E3", // 灰色
    "#400E0A","#6B1710","#942017","#C72B1E","#FF3727", // 红色
    "#422525","#693B3A","#9C5756","#D17573","#FF8F8D", // 褐色->玫瑰红
    "#2E2D0E","#545319","#817F26","#C4C13A","#EDE946", // 黄色 - 金色
    "#173233","#285859","#3E888A","#5AC5C7","#73FCFF", // 青色
    "#290916","#471027","#7A1C43","#BF2C69","#FF3B8B", // 深粉 => 淡粉 (255,59,139)
    "#1C4011","#377D22","#57BA48","#67EB40","#70FF45",  // 浅绿(32,255,177)
    "#094A33","#107D57", "#18B880","#1AD191","#20FFB1",   // 绿色
    "#2D0B30","#48114D","#741B7C", "#B82BC4","#EF38FF",// 紫色 (239,56,255)
    "#0E2445","#112E57","#1D4B8F","#2766C2","#3386FF", // 蓝色
    "#2D2E42","#454766","#686B99","#8589C4","#ADB2FF", // 靛蓝 (173,178,255)
    "#130529","#270B54","#3F1287","#5B1AC4", "#7621FF",// 深蓝偏紫
    "#000D59","#001282","#0018A8","#0021E8", "#0024FF"// 深蓝偏蓝
};

template <typename T>
static bool is_iterable(T&& iterable) {
    return std::begin(iterable) != std::end(iterable);
}

template <typename T>
static bool isQColor(const T& element)
{
    return element.type() == QMetaType::QColor;
}

#include "qpainter.h"
#include "qlayout.h"
#include "qevent.h"
#include "qwidget.h"

class ColorPanel : public QWidget
{
    Q_OBJECT
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::HighQualityAntialiasing);

        const int cols = 5;

        int rows = ClassicColors.count() / cols;
        int num = ClassicColors.count() % cols;
        //qDebug()<<"rows = "<<rows<<" cols = "<<cols;

        auto w = width();
        auto h = height();
        auto len = w>=h? h: w;
        auto r1 = len / cols / 2;
        auto r2 = len / (num?rows+1:rows) / 2;
        auto radius = r1>=r2? r2:r1;
        auto diameter = radius * 2;
        auto topleft = QPoint(radius,radius);
        topleft+=QPoint((w-cols*diameter)/2,(h-(num?rows+1:rows)*diameter)/2);

        for(int r = 0 ; r < rows; ++r)
            for(int c = 0; c < cols; ++c) {
            auto path = QPainterPath();
            auto center = topleft + QPoint(c*diameter,r*diameter);
            path.moveTo(center);
            path.addEllipse(center,radius,radius);
            painter.setBrush(ClassicColors.at(r*cols+c)); // 二维坐标映射到一维列表 (1,0)->(1,4) 1x5+5 = 9 (5,9)
            painter.drawPath(path);

        }

        event->accept();
    }
};

static QColorVector getClassicColors(int count)
{
    QColorVector colors;
    while (colors.count() < count) {
        auto idx = generateRandomNumber(0,ClassicColors.count()-1); // 这里不要越界
        auto color = ClassicColors.at(idx);
        if (!colors.contains(color))
            colors.append(color);
    }
    return colors;
}



#endif // RANDOMCOLOR_H

//
// Created by chenbei on 2023/9/20.
//

#ifndef TEST3_PUBLIC_H
#define TEST3_PUBLIC_H

#include "alias.h"

#include <QAction>
#include <QEventLoop>
#include <QMessageBox>
#include <QTimeLine>
#include <QPainter>
#include <QTimer>
#include <QStyledItemDelegate>


#include <QGraphicsEffect>
#include <QPropertyAnimation>

#include <QHeaderView>
#include <QTableView>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include <QGridLayout>
#include <QLayout>
#include <QBoxLayout>

#include <QFileDialog>
#include <QFile>
#include <QStandardItemModel>
#include <QDir>
#include <QTextStream>
#include <QStandardPaths>

#include <QMutex>
#include <QThread>

#include <QMouseEvent>
#include <QShowEvent>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QtNetwork/QTcpSocket>
/*
 * 16:9 => [1366*768 1600*900](不支持) 1920*1080(最常见) 3840*2160(不支持)
 * 16:10 =>1440*900(不支持) 2560*1600(常见) 2880*1800(不支持)
 * 3:2 => 2160*1440 2256*1504 3000*2000 (不支持)
 * 1280 * 800的尺寸（小屏幕）
*/
#define SCREEN_2560X1600 (2560*1600)
//#define SCREEN_1920X1080 (1920*1080)
//#define SCREEN_1280X800 (1280*800)
//#define SCREEN_3840X2160 (3840*2160)

#if defined(COMPONENT_LIBRARY)
#  define COMPONENT_IMEXPORT Q_DECL_EXPORT
#else
#  define COMPONENT_IMEXPORT Q_DECL_IMPORT
#endif

// 便捷函数
#define INIT_MINSIZE(w,h) (setMinimumSize(w,h))
#define INIT_MINWIDTH(w) (setMinimumWidth(w))
#define INIT_MINHEIGHT(w) (setMinimumHeight(w))
#define INIT_MAXSIZE(w,h) (setMaximumSize(w,h))
#define INIT_MAXWIDTH(w) (setMaximumWidth(w))
#define INIT_MAXHEIGHT(h) (setMaximumHeight(h))
#define INIT_RESIZE(w,h) (resize(w,h))
#define INIT_RESIZE_GOLDENSIZE (resize(width(),(int)(width()*0.618)))
#define SQLQUERYQDebug(q) (qDebug()<<"record => "<<q.lastError().text() <<"  "<<q.isActive()<<"  "<<q.record())
#define LOG (qDebug()<<"["<<QTime::currentTime().toString("h:mm:ss:zzz")<<__FUNCTION__<<"] ")

// 其它常量
#define IPLimit ("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b") // 限定输入IP地址正则表达式
#define PWDLimit ("^(?![A-Za-z0-9]+$)(?![a-z0-9\\W]+$)(?![A-Za-z\\W]+$)(?![A-Z0-9\\W]+$)[a-zA-Z0-9\\W]{8,20}$") // 限定8位数字字母大小写密码
#define AnimationDuration_1000ms 1000 // 渐变动画周期
#define TimerDuration_1000ms 1000 // 时间控件定时周期
#define SplitterHandleWidth 5 // 分隔条的手柄宽度
#define Pi 3.1415926535
#define RadianRate (Pi/180)
#define PatternColorAlpha 125
#define DefaultFontFamily ("Times New Roman") // 默认字体
#define TableViewHighlightColorAlpha 100 // 单元格高亮颜色的透明度0-255之间
#define TableViewMouseHighlightColor (QColor("#FFFD55")) // 鼠标点击单元格高亮颜色
#define TableViewSelectedHighlightColor (QColor(Qt::green)) // 已被选择的单元格高亮颜色
#define TableViewCurrentHighlightColor (QColor("#001BE8")) // 当前具有焦点单元格的高亮颜色
#define TableViewBorderHighlightColor (QColor(Qt::red)) // 统一的单元格边框高亮颜色
#define SplashProgressBarMaxLimit 10000 // 进度条的最大值
#define SPLASH_LOAD_TIME 1000 // splash启动的时间 , /100是每次设置进度条的延时时间
#define MAIN_SPLASH_RELATIVE_TIME 150 // main和splash启动的最大相对时间差 150/1000= 90%~100%之间
#define MAIN_LOAD_TIME (SPLASH_LOAD_TIME-QRandomGenerator::global()->bounded(1,MAIN_SPLASH_RELATIVE_TIME+1)) // 主窗口定时启动的延迟时间

// EOSI输出到bin目录,images在bin的上2级文件夹
#define CURRENT_PATH QDir::currentPath()
#define CONFIG_PATH "config.ini"
#define PYTHON_SCRIPT_PATH "tcp.py"
#define QSS_PATH ":/qdarkstyle/dark/darkstyle.qss"

#define LOGIN_LOGO_PATH ":/images/logo.png"
#define LOGIN_BACK_PATH ":/images/login_back.jpg"
#define LOGIN_OK_PATH ":/images/login_ok.png"
#define LOGIN_NOTOK_PATH ":/images/login_notok.png"
#define LOGIN_OK_PATH_24x24 ":/images/login_ok_24x24.png"
#define LOGIN_NOTOK_PATH_24x24 ":/images/login_notok_24x24.png"
#define LOGIN_OK_PATH_16x16 ":/images/login_ok_16x16.png"
#define LOGIN_NOTOK_PATH_16x16 ":/images/login_notok_16x16.png"
#define SPLASH_BACK_PATH ":/images/cell.png"
#define IMAGE_FORWARD ":/images/forward.png"
#define IMAGE_BACKWARD ":/images/backward.png"
#define PREVIEW_TEST_PATH ":/images/test/%1.jpg"


#ifdef SCREEN_2560X1600 // 默认按照2560X1600的尺寸
#define DefaultFontSize 12 // 默认字体大小12号字
#define WindowWidth 1800
#define WindowHeight 1100
// 登录窗口设置
#define LoginButtonHeight 180 // button的高度也是整体行布局的高度,不要太大否则忘记密码注册账户被挤压
#define LoginButtonWidth 630 // button的宽度-和groubox一致比较好看
#define LoginGap1 150 // button和groupbox的距离
#define LoginGroupboxWidth 630 // groupbox 因为单行控件最小默认300宽度,宽度要调整>600
#define LoginGroupboxHeight LoginButtonHeight // groupbox-button高度一致
#define LoginGap2 35 // icon和groupbox的距离,要大于icon的size
#define LoginIconSize 32 // icon的size
#define LoginLeftMarginCompensate 0 // 左边距补偿
#define LoginRightMargin ((WindowWidth-LoginButtonWidth-LoginGap1-\
                                                LoginGroupboxWidth-LoginGap2-LoginIconSize)/2) // 计算出应有的左右边距
#define LoginLeftMargin (LoginRightMargin+LoginLeftMarginCompensate) // 左边距需要多增加一些距离补偿
#define LoginLogoWidth 300 // logo的宽度
#define LoginLogoHeight 80 // logo的高度
#define LoginDateTimeWidth 400 // 时间控件的宽度
#define LoginDateTimeHeight LoginLogoHeight // 和logo高度一致

#define ScanCreateConfigSpacing 250 // 创建模式选择3个radio button之间的距离
#define ScanPreviousFlowSpacing 300 // 来自数据库还是文件 2个按钮的距离

#define TableWidgetItemWidth 100 // 表格项的宽度
#define TableWidgetItemHeight 100 // 表格项的高度
#define TableWidgetItemMinWidth 20 // 默认15改为20
#define TableNx2WidgetItemNameWidth 100
#define TableNx2WidgetItemDescriptionWidth (TableNx2WidgetItemNameWidth*8)
#define TableNx2WidgetItemHeight 30


#define NewExperPushButtonMinWidth 350 // 350*0.5 // 新建实验的按钮最小宽度
#define NewExperButtonMinHeight 100 // 100*0.5 // 新建实验的按钮最小高度

#define TableViewRowHeight 200 // TableWidget2x2的代理宽度高度
#define TableViewColumnWidth 200

#define SqlDBQueryTreeMaxWidth 300

// 单行控件的最小最大尺寸: spinbox,pushbutton,label,combobox,lineedit
#define ComponentMinWidth 300
#define ComponentMaxWidth 600
#define ComponentMinHeight 40
#define ComponentMaxHeight 50

// progress稍有变化
#define ProgressBarMinWidth 400
#define ProgressBarMaxWidth 800
#define ProgressBarMinHeight 40
#define ProgressBarMaxHeight 50

// 1080尺寸 1920/2560=0.75 1080/1600=0.675
#elif defined(SCREEN_1920X1080)
#define DefaultFontSize 12 // 默认字体大小12号字
    #define WindowWidth 1400 // 1800*0.75=1350
    #define WindowHeight 1000*0.75
    // 登录窗口设置
    // 水平距离 500+500+100
    #define LoginButtonHeight 200*0.5 // button的高度也是整体行布局的高度 用0.5再小一些
    #define LoginButtonWidth 420 // button的宽度-和groubox一致比较好看
    #define LoginGap1 200*0.75 // button和groupbox的距离
    #define LoginGroupboxWidth 420 // groupbox 因为单行控件最小默认修改为200,宽度要调整>400
    #define LoginGroupboxHeight LoginButtonHeight // groupbox-button高度一致
    #define LoginGap2 16*0.75 // icon和groupbox的距离
    #define LoginIconSize 24 // icon的size
    #define LoginLeftMarginCompensate 150*0.4 // 左边距补偿 少一些不用0.75
    #define LoginRightMargin ((WindowWidth-LoginButtonWidth-LoginGap1-\
                                                LoginGroupboxWidth-LoginGap2-LoginIconSize)/2*0.75) // 计算出应有的左右边距
    #define LoginLeftMargin (LoginRightMargin+LoginLeftMarginCompensate) // 左边距需要多增加一些距离补偿
    #define LoginLogoWidth 300*0.75 // logo的宽度
    #define LoginLogoHeight 80*0.675 // logo的高度
    #define LoginDateTimeWidth 400*0.75 // 时间控件的宽度
    #define LoginDateTimeHeight LoginLogoHeight // 和logo高度一致

    #define TableWidgetItemWidth 100*0.75 // 表格项的宽度
    #define TableWidgetItemHeight 100*0.75 // 表格项的高度 正方形要一致
    #define TableWidgetItemMinWidth 20 // 默认15改为20
    #define TableNx2WidgetItemNameWidth 100
    #define TableNx2WidgetItemDescriptionWidth (TableNx2WidgetItemNameWidth*6) // 当前实验-描述列不要x8,小一些
    #define TableNx2WidgetItemHeight 30*0.675

    #define TableViewRowHeight 100 // TableWidget2x2的代理宽度高度
    #define TableViewColumnWidth 100

    #define SqlDBQueryTreeMaxWidth 300


    // 单行控件的最小最大尺寸: spinbox,pushbutton,label,combobox,lineedit
    #define ComponentMinWidth 200
    #define ComponentMaxWidth 400
    #define ComponentMinHeight 30
    #define ComponentMaxHeight 40

    // progress稍有变化
    #define ProgressBarMinWidth 300
    #define ProgressBarMaxWidth 600
    #define ProgressBarMinHeight 30
    #define ProgressBarMaxHeight 40

// 1280/2560=0.5 800/1600=0.5
#else
    #define DefaultFontSize 10 // 默认字体大小10号字
    #define WindowWidth 1000
    #define WindowHeight 600
    // 登录窗口设置
    #define LoginButtonHeight 80 // 200*0.5 // button的高度也是整体行布局的高度 用0.5再小一些
    #define LoginButtonWidth 220 // button的宽度-和groubox一致比较好看
    #define LoginGap1 80// 200*0.5 // button和groupbox的距离
    #define LoginGroupboxWidth 220 // groupbox 因为单行控件最小默认修改为100,宽度要调整>200
    #define LoginGroupboxHeight LoginButtonHeight // groupbox-button高度一致
    #define LoginGap2 16*0.5 // icon和groupbox的距离
    #define LoginIconSize 16 // icon的size
    #define LoginLeftMarginCompensate 150*0.3 // 左边距补偿 少一些不用0.75
    #define LoginRightMargin ((WindowWidth-LoginButtonWidth-LoginGap1-\
                                                LoginGroupboxWidth-LoginGap2-LoginIconSize)/2*0.5) // 计算出应有的左右边距
    #define LoginLeftMargin (LoginRightMargin+LoginLeftMarginCompensate) // 左边距需要多增加一些距离补偿
    #define LoginLogoWidth 300*0.5 // logo的宽度
    #define LoginLogoHeight 80*0.5 // logo的高度
    #define LoginDateTimeWidth 400*0.5 // 时间控件的宽度
    #define LoginDateTimeHeight LoginLogoHeight // 和logo高度一致

    #define TableWidgetItemWidth 100*0.5 // 表格项的宽度
    #define TableWidgetItemHeight 100*0.5 // 表格项的高度 正方形要一致
    #define TableWidgetItemMinWidth 20 // 默认15改为20
    #define TableNx2WidgetItemNameWidth 60
    #define TableNx2WidgetItemDescriptionWidth (TableNx2WidgetItemNameWidth*8) // 查询实验-描述列的宽度
    #define TableNx2WidgetItemHeight 30*0.5

    #define TableViewRowHeight 80 // TableWidget2x2的代理宽度高度
    #define TableViewColumnWidth 80

    #define SqlDBQueryTreeMaxWidth 300


    #define NewExperPushButtonMinWidth 175 // 350*0.5 // 新建实验的按钮最小宽度
    #define NewExperButtonMinHeight 50 // 100*0.5 // 新建实验的按钮最小高度

    // 单行控件的最小最大尺寸: spinbox,pushbutton,label,combobox,lineedit
    #define ComponentMinWidth 80
    #define ComponentMaxWidth 200
    #define ComponentMinHeight 25
    #define ComponentMaxHeight 50

    // progress稍有变化
    #define ProgressBarMinWidth 200
    #define ProgressBarMaxWidth 400
    #define ProgressBarMinHeight 25
    #define ProgressBarMaxHeight 50

#endif // 结束尺寸条件

#define INIT_FONT (setFont(QFont("Times New Roman",DefaultFontSize)))
#define INIT_WINDOW_MINSIZE (INIT_MINSIZE(WindowWidth,WindowHeight))
#define INIT_COMPONENT_MINSIZE (INIT_MINSIZE(ComponentMinWidth,ComponentMinHeight))
#define INIT_COMPONENT_MAXSIZE (INIT_MAXSIZE(ComponentMaxWidth,ComponentMaxHeight))
#define INIT_PROGRESSBAR_MINSIZE (INIT_MINSIZE(ProgressBarMinWidth,ProgressBarMinHeight))
#define INIT_PROGRESSBAR_MAXSIZE (INIT_MAXSIZE(ProgressBarMaxWidth,ProgressBarMaxHeight))
#define INIT_BUTTON_MINSIZE (INIT_MINSIZE(LoginButtonWidth,LoginButtonHeight)) // 登录窗口的按钮尺寸
#define INIT_VERIFYDB_MINSIZE (INIT_MINSIZE((ComponentMinWidth*2+50),\
                                            (ComponentMinHeight*5+100))) // 验证数据库对话框的宽度和高度
#define INIT_MODIFYPWD_MINSIZE (INIT_MINSIZE((ComponentMinWidth*2+100),\
                                            (ComponentMinHeight*4+50))) // 修改密码对话框的宽度和高度


/*
qss不是完全支持所有的css2，比如text-align官方文档就有说明，只支持 QPushButton and QProgressBar
qss的执行是有优先级的，如果没有指定父对象，则对所有的应用
比如在窗体widget中 {color:#ff0000;} 这样会对widget以及widget的所有子对象应用该样式
你需要指定类名或者对象名，比如 #widget{color:#ff0000;} 这样就只会对widget对象应用该样式
另一种写法 QWidget#widget{color:#ff0000;}，只想对窗体本身而不是子控件按钮标签等 .QWidget{color:#ff0000;}
*/


// 主要是修改字体大小
#ifdef SCREEN_1920X1080
#define LoginLogo_BeiHuiKeJi_Style ("QLabel#beihuikeji{font-size: 40px; font-family: '黑体'; "\
                                                                  "font: bold; border: solid 1px;color:white;}")
    // 新建用户和忘记密码2个按钮的风格
    #define LoginMain_CreateUserForgetPwdStyle ("QPushButton#createuser,#forgetpwd{border:none;color:#919191;font-size:20px;}")

    // 新建实验的实验类型按钮风格 NewExperButtonMinHeight=70,圆角半径<35至少,实际30也不管用
    #define MainNewExper_ButtonStyle ("color:white;border:2px solid black;border-radius:25px;"\
                                                                "background-color:#2F7CAD;font-size:30px;") // 圆角半径小一些
    // 登录窗口的按钮风格
    #define LoginMain_ButtonStyle ("border:2px solid black;border-radius:5px;background-color:skyblue;font-size:50px;")

    // 点击3个按钮,当前实验、新建实验和查询实验切换按钮的颜色
    //https://blog.csdn.net/goforwardtostep/article/details/53464925
    // "QPushButton:pressed{padding-left:8px;padding-top:8px;background-color:#B5E61D;}" /*凸起效果*/
    #define MainTool_ButtonStyle1 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#0B5D18;font-size:50px;}")
    #define MainTool_ButtonStyle2 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#B5E61D;font-size:50px;}")

#elif SCREEN_2560X1600
#define LoginLogo_BeiHuiKeJi_Style ("QLabel#beihuikeji{font-size: 60px; font-family: '黑体'; "\
                                                                      "font: bold; border: solid 1px;color:white;}")
// 新建用户和忘记密码2个按钮的风格
#define LoginMain_CreateUserForgetPwdStyle ("QPushButton#createuser,#forgetpwd{border:none;color:#919191;font-size:28px;}")

// 新建实验的实验类型按钮风格
#define MainNewExper_ButtonStyle ("color:white;border:2px solid black;border-radius:50px;"\
                                                                "background-color:#2F7CAD;font-size:30px;")
// 登录窗口的按钮风格
#define LoginMain_ButtonStyle ("border:2px solid black;border-radius:5px;background-color:skyblue;font-size:50px;")

// 点击3个按钮,当前实验、新建实验和查询实验切换按钮的颜色
//https://blog.csdn.net/goforwardtostep/article/details/53464925
// "QPushButton:pressed{padding-left:8px;padding-top:8px;background-color:#B5E61D;}" /*凸起效果*/
#define MainTool_ButtonStyle1 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#0B5D18;font-size:50px;}")
#define MainTool_ButtonStyle2 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#B5E61D;font-size:50px;}")
#else SCREEN_1280X800
#define LoginLogo_BeiHuiKeJi_Style ("QLabel#beihuikeji{font-size: 30px; font-family: '黑体'; "\
                                                                      "font: bold; border: solid 1px;color:white;}")
    // 新建用户和忘记密码2个按钮的风格
    #define LoginMain_CreateUserForgetPwdStyle ("QPushButton#createuser,#forgetpwd{border:none;color:#919191;font-size:16px;}")

    // 新建实验的实验类型按钮风格
    #define MainNewExper_ButtonStyle ("color:white;border:2px solid black;border-radius:20px;"\
                                                                "background-color:#2F7CAD;font-size:20px;")
    // 登录窗口的按钮风格
    #define LoginMain_ButtonStyle ("border:2px solid black;border-radius:5px;background-color:skyblue;font-size:30px;")

    // 点击3个按钮,当前实验、新建实验和查询实验切换按钮的颜色
    //https://blog.csdn.net/goforwardtostep/article/details/53464925
    // "QPushButton:pressed{padding-left:8px;padding-top:8px;background-color:#B5E61D;}" /*凸起效果*/
    #define MainTool_ButtonStyle1 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#0B5D18;font-size:30px;}")
    #define MainTool_ButtonStyle2 ("QPushButton{color:white;border:2px solid black;"\
                                                    "width:50px;height:50px;border-radius:25px;"\
                                                    "background-color:#B5E61D;font-size:30px;}")
#endif


// 必须使用QWidget#Widget或QWidget#LoginMain,否则子控件的背景也会被设置,只设置窗口的
#define LoginMain_Style  ("QWidget#LoginMain{background-image:url(:/images/login_back.jpg)}")



#define ExperTitle_Style ("QLabel#expertitle{background-color:yellow;"\
                    "border:none;font-size:30px;color:green;font-weight:bold;}")



// 其他, component's style
#define SplitterStyle ("QSplitter::handle { background-color: #F2A072 }")
#define ProgressBarStyle ("QProgressBar{border:2px solid grey;border-radius:5px;text-align:center;}"\
                                    "QProgressBar::chunk{background-color: #CD96CD;width: 10px;margin: 0.5px;}")





//#define MainStackStyle ("border: 2px solid black; margin:20px;")
#define MainStackStyle ("border: none")

#define LoginGroupBoxStyle ("border:1px solid black;"\
                                                "background-color:lightgrey;"\
                                                "font-size:30px;"\
                                                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                                "stop: 0 #E0E0E0, stop: 1 #FFFFFF);")

#define MainQueryExperGroupBoxStyle ("QGroupBox {border:1px solid black;color:black;"\
                                                "background-color:lightgrey;"\
                                                "margin-top:20px;"\
                                                "font-size:30px;"\
                                                "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                                "stop: 0 #E0E0E0, stop: 1 #FFFFFF);}"\
                                                 "QGroupBox > QLabel {border:none;font-size:25px;}")



#define LoginUserPwdValidateStyle ("QPushButton {"\
                                                            "border: 2px solid #EA224B;"\
                                                            "border-radius: 10px;"\
                                                            "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"\
                                                                                              "stop: 0 #f6f7fa, stop: 1 #75FA8D);"\
                                                            "min-width: 80px;"\
                                                            "color:#2F79E6;"\
                                                            "}")

//#define LoginLineEditStyle ("QLineEdit{"\
//                                                "border: 2px solid green;"\
//                                                "border-radius: 10px;"\
//                                                "padding: 0 8px;"\
//                                                "background: #F7F552;"\
//                                                "selection-background-color: darkgray;"\
//                                                "};")

#define LoginDbDirLabelStyle  ("QLabel{"\
                                                "border: 2px solid green;"\
                                                "border-radius: 10px;"\
                                                "padding: 2px;"\
                                                "background-color:#F7F552;"\
                                                "}")





#define MainQueryComboBoxStyle ("QComboBoc{border: 1px solid gray;"\
                                                            "border-radius: 3px;"\
                                                            "padding: 1px 18px 1px 3px;"\
                                                            "min-width: 6em;}"\
                                                            "QComboBox>QLineEdit{color:black;font-size:25px;}"\
                                                            "QComboBox::drop-down {"\
                                                            "subcontrol-origin: padding;"\
                                                            "subcontrol-position: top right;"\
                                                            "width: 15px;"\
                                                            "border-left-width: 1px;"\
                                                            "border-left-color: black;"\
                                                            "border-left-style: solid; "\
                                                            "border-top-right-radius: 3px;"\
                                                            "border-bottom-right-radius: 3px;}"\
                                                            "QComboBox:on {padding-top: 3px;padding-left: 4px;}")

#endif //TEST3_PUBLIC_H

#ifndef MAINSPLASH_H
#define MAINSPLASH_H

#include "../../../include/widgets/progressbar.h"
#include "qscreen.h"
#include "qsplashscreen.h"


class UpdateProgress : public QObject
{
    Q_OBJECT
    QMutex mMutex;
public slots:
    void calculate()
    {
        mMutex.lock();
        QList<int> mValueList;

        // 初始化用于进度条显示的值
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        for(int i =0;i<100;i++)
        mValueList.append(qrand()%(SplashProgressBarMaxLimit+1));
        std::sort(mValueList.begin(),mValueList.end()); //递增排序
        //LOG<<"current thread id = "<<QThread::currentThreadId();
        //LOG<<"valueList = "<<mValueList;
        mValueList[99] = SplashProgressBarMaxLimit;
        emit progressValueList(mValueList);
        mMutex.unlock();
    }
signals:
    void progressValueList(const QList<int> &valueList);
};

class UpdateProgressController : public QObject
{
    Q_OBJECT
    QThread mThread;
    ProgressBar * mBar;
    UpdateProgress* mWorker;
    int mDuration;
public:
    UpdateProgressController(ProgressBar*bar,int duration) : mBar(bar), mDuration(duration){
        mWorker = new UpdateProgress;// ① 新建一个工作对象 用于得到随机序列
        mWorker->moveToThread(&mThread); // ② 工作对象移入子线程
        connect(&mThread, &QThread::finished, mWorker, &QObject::deleteLater); // ③ 线程结束后删除workder对象

        connect(this, &UpdateProgressController::startSplash, mWorker, &UpdateProgress::calculate); // ④ 按钮需要操作updateProgress信号,这个信号绑定了要执行的计算
        //connect(this,&UpdateProgressController::endCalculate,mWorker,&UpdateProgress::stopCalculate); // 外部停止计算(不起作用)
        connect(mWorker, &UpdateProgress::progressValueList, this, &UpdateProgressController::setProgressBarValue); // ⑤ 工作对象的完成信号可以反馈给控制器也要绑定好

        mThread.start(QThread::HighestPriority);
    }
    ~UpdateProgressController(){
        mThread.quit();
        mThread.wait();
    }
private slots:
    void setProgressBarValue(const QList<int>& v){
        //进度条延时显示值的动态效果
        double tempTime=mDuration / 100.0;   // 分成100份

        for (int i = 1; i <= v.count(); ++ i)
        {// 不同的延时设置一次值模拟增加的效果,执行100次延时设置
            QTimer::singleShot((int)(i*tempTime), this, [=]{
                //LOG<<(double)v[i-1]/SplashProgressBarMaxLimit*100.0<<"%";
                mBar->setValue(v[i-1]);
                if (i == 100) {
                    emit endSplash();
                    //qDebug()<<"i = "<<i<<" is emit endSplash() "<<QTime::currentTime();
                    //注意:!! 这行语句必须再QTimer::singleShot去执行,如果放在外边或者for外边总会被先执行
                    // 窗口就直接关闭,看不到设置进度的效果
                }
            });
        }
        //LOG<<"curr id = "<<QThread::currentThreadId();
    }
signals:
    void startSplash();
    void endSplash();
};


#if defined(INTERFACE_LIBRARY)
#  define INTERFACE_IMEXPORT Q_DECL_EXPORT
#else
#  define INTERFACE_IMEXPORT Q_DECL_IMPORT
#endif

class  INTERFACE_IMEXPORT MainSplash : public QSplashScreen
{
    Q_OBJECT
private:
    int mDuration; // 窗口持续的时间
    UpdateProgressController * mController;
    ProgressBar * mBar;
    const int mBarHeight = 30;
    bool mEndSplash = false;
    void setEndSplash();

public:
    explicit MainSplash(const QPixmap &pixmap,int duration,QWidget *parent = nullptr);
    ~MainSplash();
    void startSplash();
    void mousePressEvent(QMouseEvent *) override;
    void resizeEvent(QResizeEvent*e) override;
    bool isEndSplash() const;
signals:
    void endSplashInner();
    void endSplashOuter();
};

#endif // MAINSPLASH_H

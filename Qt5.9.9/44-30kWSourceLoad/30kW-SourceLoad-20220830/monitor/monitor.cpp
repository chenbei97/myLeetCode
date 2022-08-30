#include "monitor/monitor.h"

Monitor::Monitor(WORKMODE  workmode,QWidget *parent) : QMainWindow(parent)
{
        this->resize(1200,800);
        this->setFont(QFont("Times New Roman",12)); //格式和字体要先初始化,然后基于此时窗口初始化布局,放在后头就会错误
        this->mWorkMode = workmode;


        QString title;
        if (workmode == WORKMODE::CV)
        {
              this->initCVUI();
              title = tr("监控界面(CV模式)");
        }
        else {
              this->initCCUI();
              title = tr("监控界面(CC模式)");
        }
        this->initConnections();
        this->setWindowTitle(title);
}

WORKMODE Monitor::workMode() const
{
      return this->mWorkMode;
}

Monitor::PRSettings Monitor::prsettings() const
{
      return mPRSettings;
}

Monitor::CVSettings Monitor::cvsettings() const
{
      return mCVSettings;
}

Monitor::CCSettings Monitor::ccsettings() const
{
      return mCCSettings;
}

void Monitor::setPRSettings(const Monitor::PRSettings &settings)
{
      mPRSettings = settings;
}

void Monitor::setCVSettings(const Monitor::CVSettings &settings)
{
      mCVSettings = settings;
}

void Monitor::setCCSettings(const Monitor::CCSettings &settings)
{
      mCCSettings = settings;
}

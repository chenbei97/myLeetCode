#pragma once
#ifndef _LOGINMAIN_H_
#define _LOGINMAIN_H_

#include "../../../include/widgets/pushbutton.h"
#include "../../../include/widgets/label.h"
#include "../../../include/widgets/lineedit.h"
#include "qstyleoption.h"
#include "../../../include/utilities/encry.h"
#include "loginlogo.h"
#include "logintool.h"
#include "loginnext.h"

#if defined(INTERFACE_LIBRARY)
#  define INTERFACE_IMEXPORT Q_DECL_EXPORT
#else
#  define INTERFACE_IMEXPORT Q_DECL_IMPORT
#endif

class  INTERFACE_IMEXPORT LoginMain : public QDialog
{
	Q_OBJECT

public:
	explicit LoginMain(QWidget* parent = nullptr);
    QString loginIP() const;
    QString loginUser() const;
    void paintEvent(QPaintEvent *event) override;
private:
    void onShowMainWindow();
private:
    QVBoxLayout * mMainLay;
    LoginLogo * mLogo;// 公司Logo
    LoginTool * mTool; // 工具
    LoginNext * mNext;// Next进入主界面
signals:
};
#endif // !_LOGINMAIN_H_


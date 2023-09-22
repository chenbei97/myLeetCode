#include "../../inc/login/loginlogo.h"

LoginLogo::LoginLogo()
{
    mLogo = new Label;
    mLogo->setPixmap(QPixmap(LOGIN_LOGO_PATH)
                     .scaled(LoginLogoWidth,LoginLogoHeight));
    mLogo->setFixedSize(LoginLogoWidth,LoginLogoHeight);
    mLogo->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    mText = new Label(tr("高分生物"));
    mText->setObjectName("beihuikeji");
    mText->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    mText->setStyleSheet(LoginLogo_BeiHuiKeJi_Style);

    mTime = new LCDTimeShow;

    addWidget(mLogo,0,Qt::AlignLeft); // 依次是图片,"高分生物"和右侧的时间控件
    addWidget(mText,0,Qt::AlignLeft);
    addStretch(); // 这边让文字和图片可以接近,用添加空白项无法解决
    addWidget(mTime,0,Qt::AlignRight);
}


#include <table/tablesampleperiod.h>

TableSamplePeriod::TableSamplePeriod(QWidget * parent):
    QDialog(parent),mainLayout(new QVBoxLayout),mPeriodList(new QComboBox),
    mOkBtn(new QPushButton(tr("确定"))),mCancelBtn(new QPushButton(tr("取消")))
{
    QStringList periods;
    periods << QStringLiteral("300ms")<< QStringLiteral("600ms")<<  QStringLiteral("900ms")
                <<QStringLiteral("1.5s")<< QStringLiteral("3s") << QStringLiteral("6s")<< QStringLiteral("9s")
                << QStringLiteral("30s")<< QStringLiteral("1m") << QStringLiteral("10m")
                << QStringLiteral("30m") << QStringLiteral("1h") << tr("自定义");
    mPeriodList->addItems(periods);
    mPeriodList->setEditable(false);
    mPeriodList->setInsertPolicy(QComboBox::InsertAlphabetically);//每次自定义的项不作为新项插入
    mPeriodList->setCurrentIndex(6); // 开启的话默认9s记录1次

    QLabel * info = new QLabel(tr("选择日志周期: "));
    info->setBuddy(mPeriodList);
    QHBoxLayout * top = new QHBoxLayout;
    top->addWidget(info);
    top->addWidget(mPeriodList);

    QHBoxLayout * bottom = new QHBoxLayout;
    bottom->addStretch();
    bottom->addWidget(mOkBtn);
    bottom->addWidget(mCancelBtn);

    mainLayout->addLayout(top);
    mainLayout->addLayout(bottom);
    connect(mOkBtn,&QPushButton::clicked,this,[=]{
        QString period = mPeriodList->currentText();
        period = checkCustomItem(period);
        //qDebug()<<"current period = "<<period;
        emitPeriod(period);
        accept();
    });
    connect(mCancelBtn,&QPushButton::clicked,this,[=]{reject();});
    setWindowIcon(QIcon(":/images/tablelog.png"));
    setFont(QFont("Times New Roman",12));
    resize(QSize(400,120));
    setLayout(mainLayout);
}

QString TableSamplePeriod::checkCustomItem(QString period)
{
    if (period == tr("自定义"))
    {
        QString custom = showSelectUnit(); // 获取自定义的采样时间
        if (!custom.isEmpty() &&mPeriodList->findText(custom) < 0) // 如果没找到返回-1,说明不存在这个自定义的时间
            mPeriodList->insertItem(mPeriodList->count()-1,custom);//把这个项插进去,位置是倒数第2项
        mPeriodList->setCurrentText(custom); //这很重要,这样用户再次点开显示上次设置的自定义时间
        period = custom;
    }
    return period;
}

void TableSamplePeriod::emitPeriod(QString period)
{
    QString value;
    if (period.endsWith("ms",Qt::CaseInsensitive)){
        value = period.remove("ms",Qt::CaseInsensitive);
        quint32 ms = value.toUInt();//ms只能输入>350的int或double
        if (ms == 0)
        {
            double val = value.toDouble();
            ms = qRound(val); // 直接取整即可
        }
        //qDebug()<<ms<<"ms";
        mPeriod.ms = ms;mPeriod.s = 0;mPeriod.m = 0;mPeriod.h = 0;
        emit selectedPeriod(ms);
    }
   else if (period.endsWith("s",Qt::CaseInsensitive)) {
           value = period.remove("s",Qt::CaseInsensitive);
           quint32 s = value.toUInt(); // 输入>0.35的int或者double
           if (s == 0) // 说明是浮点数
           {
               double val = value.toDouble();
               // 单位s的浮点数不能直接取整,误差过大
               quint32 ms = qRound(val * 1000); // 转为ms传递
               //qDebug()<<ms<<"ms/s";
               mPeriod.ms = ms;mPeriod.s = 0;mPeriod.m = 0;mPeriod.h = 0;
               emit selectedPeriod(ms);
           }
           else {
               //qDebug()<<s<<"s";
               mPeriod.ms = 0;mPeriod.s = s;mPeriod.m = 0;mPeriod.h = 0;
               emit selectedPeriod(0,s);
           }
   }
   else if (period.endsWith("m",Qt::CaseInsensitive))
   {
       value = period.remove("m",Qt::CaseInsensitive);
       quint32 m = value.toUInt(); // 输入可以是[0.01,+)
       if (m == 0)// 说明是浮点数
       {
           double val = value.toDouble();
           // 如果是0.01m=0.6s取整就是1s误差很大; 0.5m=30s,设定≥0.5m取整导致的损失忽略不计
           if (val < 0.5) //临界值0.5m=30s=30000ms,即<30000ms使用ms传递
           {
               quint32 ms = qRound(val * 60000); // 转为ms传递
               qDebug()<<ms<<"ms/m";
               mPeriod.ms = ms;mPeriod.s = 0;mPeriod.m = 0;mPeriod.h = 0;
               emit selectedPeriod(ms);
           }
           else {
               quint32 s = qRound(val * 60); // 转为s传递
               //qDebug()<<s<<"s/m";
               mPeriod.ms = 0;mPeriod.s = s;mPeriod.m = 0;mPeriod.h = 0;
               emit selectedPeriod(0,s);
           }
       }
       else {
           //qDebug()<<m<<"m";
           mPeriod.ms = 0;mPeriod.s = 0;mPeriod.m = m;mPeriod.h = 0;
           emit selectedPeriod(0,0,m);
       }
   }
   else if (period.endsWith("h",Qt::CaseInsensitive))
   {
       value = period.remove("h",Qt::CaseInsensitive);
       quint32 h = value.toUInt();
       if (h == 0)
       {
           double val = value.toDouble(); // 0.01h=0.6m=36s,全部使用s来传递,取整损失忽略不计
           quint32 s = qRound(val * 3600);
           //qDebug()<<s<<"s/h";
           mPeriod.ms = 0;mPeriod.s = s;mPeriod.m = 0;mPeriod.h = 0;
           emit selectedPeriod(0,s);
       }
       else {
           //qDebug()<<h<<"h";
           mPeriod.ms = 0;mPeriod.s = 0;mPeriod.m = 0;mPeriod.h = h;
           emit selectedPeriod(0,0,0,h);
       }
   }
}

QString TableSamplePeriod::showSelectUnit()
{
     QDialog * dlg = new QDialog;
     QGridLayout * layout = new QGridLayout;
     QLabel * label1= new QLabel(tr("周期单位: "));
     QComboBox * unitList =  new QComboBox;
     QStringList units;
     units <<"ms"<<"s"<<"m"<<"h";
     unitList->addItems(units);
     QLabel * label2 = new QLabel(tr("输入: "));
     QLineEdit * line = new QLineEdit;
     QDoubleValidator * validator = new QDoubleValidator(0.0,10000.0,2);//2位小数
     line->setValidator(validator);

     QPushButton * okbtn = new QPushButton(tr("确定"));
     QPushButton * cancelbtn = new QPushButton(tr("取消"));
     connect(cancelbtn,SIGNAL(clicked()),dlg,SLOT(reject()));
     connect(okbtn,&QPushButton::clicked,this,[=]{dlg->accept();});

     layout->addWidget(label1,0,0);
     layout->addWidget(unitList,0,1);
     layout->addWidget(label2,1,0);
     layout->addWidget(line,1,1);
     layout->addWidget(okbtn,2,0);
     layout->addWidget(cancelbtn,2,1);

     dlg->setLayout(layout);
     dlg->setFont(QFont("Times New Roman",12));
     dlg->setWindowIcon(QIcon(":/images/tablelogunit.png"));
     dlg->resize(300,200);

     QString unit = "";
     int ret = dlg->exec();
     if (ret ==QDialog::Accepted)
     {
            double input = line->text().toDouble();
            double mul = input / 300.; // 判断浮点数是否为300.0浮点数的倍数
            if (mul != static_cast<quint32>(mul)) {//如果不是取整后不会相等
                QMessageBox::warning(dlg,tr("警告"),tr("推荐300ms的整数倍日志周期,否则将圆整处理不会按照指定的时间记录!"));
            }
            //qDebug()<<"input = "<<input <<" mul = " << mul;

            if (unitList->currentIndex() == 0){ // ms
                 if (input - 300.0< 0.0) // 不支持300ms以下
                 {
                     QMessageBox::critical(dlg,tr("错误"),tr("不支持小于300ms的日志周期!"));
                     return unit;
                 }
                 //qDebug()<<"here "<<QString("%1ms").arg(QString::number(input));
                 return QString("%1ms").arg(QString::number(input));
            }
            else if (unitList->currentIndex() == 1){ // 0.35s
                if (input - 0.3< 0.0) // 不支持0.3s以下
                {
                    QMessageBox::critical(dlg,tr("错误"),tr("不支持小于0.3s的日志周期!"));
                    return unit;
                }
                return QString("%1s").arg(QString::number(input));
            }
            else if (unitList->currentIndex() == 2) { // 最小0.01min=0.01*60=0.6s>0.35s是支持的
                return QString("%1m").arg(QString::number(input));
            }
            else if (unitList->currentIndex() == 3) {// 0.01h = 0.01 * 3600=36s
                return QString("%1h").arg(QString::number(input));
            }
     }
     delete  dlg;
     return unit;
}

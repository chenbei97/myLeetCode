#include "../../inc/flow/scanvesselsummary.h"

ScanVesselSummary::ScanVesselSummary(QWidget *parent) : GradientHiddenWidget(parent)
{
    mCountdown = new Label;
    mCountdown->setAlignment(Qt::AlignLeft);
    mPannel = new QTextEdit;
    mPannel->setReadOnly(true);
    mPannel->setFrameShape(QTextEdit::NoFrame);
    mPattern = new Pattern;
    mPattern->toggleState(Pattern::GroupState);
    header->setText(tr("实验配置信息总结"));
    mainlay->addLayout(toplay());
    mainlay->addWidget(mPannel);
    mainlay->addWidget(mPattern);
}

QHBoxLayout* ScanVesselSummary::toplay()
{
    auto lay = new QHBoxLayout;
    mCheckBox = new QCheckBox(tr("是否保存为常用设置?"));
    mCheckBox->setChecked(false);
    mNameEdit = new LineEdit;
    mNameEdit->setToolTip(tr("请给本配置设定一个名称,方便下次调用"));
    mNameEdit->hide();
    lay->addWidget(mCountdown);
    lay->addWidget(mCheckBox);
    lay->addSpacing(10);
    lay->addWidget(mNameEdit);
    lay->addStretch();

    connect(mCheckBox,&QCheckBox::stateChanged,this,[=](int state){
        state==Qt::Checked? mNameEdit->show():mNameEdit->hide();
    });
    return  lay;
}

void ScanVesselSummary::translate(const ScanConfigData &d)
{
    data = d;
    mPannel->clear();
    mPannel->append(tr("<strong><font color = #75FA8D>成像模式:</font></strong> %1").arg(d.channel));
    mPannel->append(tr("<strong><font color = #75FA8D>物镜倍数:</font></strong> %1").arg(d.objective));
    mPannel->append(tr("<strong><font color = #75FA8D>视野数量:</font></strong> %1").arg(d.view));
    mPannel->append(tr("<strong><font color = #75FA8D>孔径尺寸:</font></strong> %1").arg(scanWellsize()));
    mPannel->append(tr("<strong><font color = #75FA8D>扫描轨迹:</font></strong> \n%1").arg(scanTrajectory()));
    mPannel->append(tr("<strong><font color = #75FA8D>分析类型:</font></strong> %1").arg(d.analysis_type));
    mPannel->append(tr("<strong><font color = #75FA8D>分析定义:</font></strong> %1").arg(d.analysis_definition));
    mPannel->append(tr("<strong><font color = #75FA8D>分析笔记:</font></strong> %1").arg(d.analysis_notes));
    mPannel->append(tr("<strong><font color = #75FA8D>光谱参数1:</font></strong> %1%").arg(d.analysis_spec_1));
    mPannel->append(tr("<strong><font color = #75FA8D>光谱参数2:</font></strong> %1%").arg(d.analysis_spec_2));
    mPannel->append(tr("<strong><font color = #75FA8D>实验类型:</font></strong> %1").arg(d.experiment_type));
    mPannel->append(tr("<strong><font color = #75FA8D>实验人员:</font></strong> %1").arg(d.experiment_person));
    mPannel->append(tr("<strong><font color = #75FA8D>实验名称:</font></strong> %1").arg(d.experiment_name));
    mPannel->append(tr("<strong><font color = #75FA8D>实验细胞:</font></strong> %1").arg(d.experiment_celltype));
    mPannel->append(tr("<strong><font color = #75FA8D>实验描述:</font></strong> %1").arg(d.experiment_description));
    if (!d.is_schedule) {
        mPannel->append(tr("<strong><font color = #75FA8D>扫描类型:</font></strong> 立即扫描"));
        mPannel->append(tr("<strong><font color = #75FA8D>扫描时间:</font></strong> %1 hours  %2 minutes  %3 seconds").arg((double)d.once_total_time/3600.)
                        .arg((double)d.once_total_time/60.).arg(d.once_total_time));
        mPannel->append(tr("<strong><font color = #75FA8D>间隔时间:</font></strong> %1 hours  %2 minutes  %3 seconds").arg((double)d.once_duration_time/3600.)
                        .arg((double)d.once_duration_time/60.).arg(d.once_duration_time));
        mPannel->append(tr("<strong><font color = #75FA8D>扫描次数:</font></strong> %1").arg(d.once_total_count));
        mCountdown->hide();
        timer.stop();
    } else {
        mPannel->append(tr("<strong><font color = #75FA8D>扫描类型:</font></strong> 计划扫描"));
        mPannel->append(tr("<strong><font color = #75FA8D>开始时间:</font> <font color = red>%1</font></strong>").arg(d.schedule_start_datetime.toString("yyyy/MM/dd hh::mm")));
        mPannel->append(tr("<strong><font color = #75FA8D>结束时间:</font></strong> %1").arg(d.schedule_end_datetime.toString("yyyy/MM/dd hh::mm")));
        mPannel->append(tr("<strong><font color = #75FA8D>扫描时间:</font></strong> %1 hours  %2 minutes  %3 seconds").arg((double)d.schedule_total_time/3600.)
                        .arg((double)d.schedule_total_time/60.).arg(d.schedule_total_time));
        mPannel->append(tr("<strong><font color = #75FA8D>间隔时间:</font></strong> %1 hours  %2 minutes  %3 seconds").arg((double)d.schedule_duration_time/3600.)
                        .arg((double)d.schedule_duration_time/60.).arg(d.schedule_duration_time));
        mPannel->append(tr("<strong><font color = #75FA8D>扫描次数:</font></strong> %1").arg(d.schedule_total_count));

        connect(&timer,&QTimer::timeout,this,[&]{
            auto num = QDateTime::currentDateTime().secsTo(d.schedule_start_datetime);
            if (num>0)
                mCountdown->setText(tr("倒计时: %1 seconds").arg(num));
            else  {
                mCountdown->setText(tr("倒计时: 实验已启动!"));
                timer.stop();
            }
        });
        mCountdown->show();
        timer.start(1000);

        // 不使用这种方法,滚动条总是会被下拉或者上拉体验不好,使用单独的Label设置
        //mPannel->append(tr("倒计时: %1 seconds").arg(QDateTime::currentDateTime().secsTo(d.schedule_start_datetime)));
//        connect(&timer,&QTimer::timeout,this,[&]{
//            auto k = QDateTime::currentDateTime().secsTo(d.schedule_start_datetime);
//            auto text = mPannel->toPlainText();
//            auto idx = text.lastIndexOf(':');
//            auto c = text.count() - idx-2; // 不能删除冒号和冒号后边的空格,c=11
//            text.chop(c);
//            text += QString("%1 seconds").arg(k);
//            mPannel->clear();
//            mPannel->setText(text);
//            mPannel->moveCursor(QTextCursor::End);//移动光标到最后一行
//        });

    }


}

QString ScanVesselSummary::scanWellsize() const
{
    QString r = "";
    switch (data.wellsize) {
        case 6 : r ="6";mPattern->setPatternSize(2,3);break;
        case 24 : r ="24";mPattern->setPatternSize(4,5);break;
        case 96 : r ="96";mPattern->setPatternSize(8,12);break;
        case 384 : r ="384";mPattern->setPatternSize(16,24);break;
        default:break;
    }
    return  r;
}

QString ScanVesselSummary::scanTrajectory()
{
    LOG<<"groups => "<<data.groupNames;
   // LOG<<"group pointlists = > "<<data.groupPointLists;
    //LOG<<"group namelists = > "<<data.groupNameLists;
    Q_ASSERT(data.groupPointLists.count() == data.groupNameLists.count()); // 这里不能连等
    Q_ASSERT(data.groupNameLists.count() == data.groupNames.count());//要分开设定

    auto gc = data.groupNames.count();
    mPattern->setGroupColors(getClassicColors(gc));
    QString all = tr("\n");
    for(int i = 0; i < gc;++i) {
            all +="\t"+data.groupNames.at(i)+":\t";
            auto ppos  = data.groupPointLists.at(i);
            auto pname = data.groupNameLists.at(i);
            for(int j = 0; j < ppos.count(); ++j) {
                  auto pos = ppos.at(j);
                  auto name = pname.at(j);
                  all += tr("[%1,%2,%3,%4] =>").arg(QChar(pos.x()+65)).arg(pos.y()+1).arg(name).arg(j+1);
            }
            all.chop(2);
            all+="\n";
            mPattern->setGroupPoint(data.groupPointLists.at((i)),i);
    }

    return all;
}

QString ScanVesselSummary::flag() const
{// saveToSql调用后才有意义,定义这个函数是为了rollback使用
    // 能够拿到保存时唯一的flag,也就是saveToSql内对savetime的赋值
    return data.save_time.toString(ExperConfigTableFields.other_fields.datetime_num);
}

bool ScanVesselSummary::saveToSql()
{
    emit started();
    data.save_time = QDateTime::currentDateTime(); // 保存之前赋值
    // 第1张表是主表
    bool r1 = saveExperConfigToSql(data.valuesForSql());
    // 第2张表是组的点轨迹表
    bool r2 = saveGroupPointConfigToSql(data.groupValuesForSql());

    if (!(r1 && r2))
        QMessageBox::critical(this,tr("错误"),tr("保存配置到数据库失败!"));
    //else QMessageBox::information(this,tr("消息"),tr("保存配置到数据库成功!"));
    return r1&&r2;
}

bool ScanVesselSummary::saveToJson()
{
    if (!mCheckBox->isChecked())
        return true;
    auto name = mNameEdit->text().simplified();
    if (name.isEmpty()) {
        QMessageBox::critical(this,tr("错误"),tr("请给要保存的配置命名!"));
        return false;
    }
    // 下方将所有配置写入json文件,name是保存的文件名称
    bool r  = saveExperConfigToJson(name,data.valuesForJson(),this);
    if (!r)
        QMessageBox::critical(this,tr("错误"),tr("保存配置到Json文件失败!"));
    //else QMessageBox::information(this,tr("消息"),tr("保存配置到Json文件成功!"));
    return r;
}

bool ScanVesselSummary::sendToSocket()
{
    //LOG<<data.valuesForSocket();
    bool r = sendExperConfigToSocket(data.valuesForSocket());
    if (!r)
        QMessageBox::critical(this,tr("错误"),tr("执行启动命令错误![%1]").arg(TcpLoaderPointer->lastError()));
    emit finished();
    return r;
}


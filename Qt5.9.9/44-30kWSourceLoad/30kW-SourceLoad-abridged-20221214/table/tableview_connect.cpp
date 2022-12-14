#include <table/tableview.h>

void TableView::initConnections()
{
     initActConnections();

     // mainwindow's mainWorkMode emit = > mainSetting => mTableView => mTableSizeDlg
     connect(this,&TableView::workModeChanged,mTableSizeDlg,&TableSizeDialog::workModeChanged);

    connect(this,static_cast<void (TableView::*)(const QList<QByteArray>&)>(&TableView::log),
            this,[=](const QList<QByteArray>& logdata){
            if (!mLogEnabled) return; // 没有启用日志记录什么也不做
           // if (mTable->row() > 10000) return; // 不要再插

            QStringList log;
            log << logdata[0];
            // 这里要注意,插入的数据log = datetime + V +A + W + R
            // 要和mTableSizeDlg选择的字段匹配即mTableSizeDlg->header().headerField; 适当进行选择插入何种数据
            QList<TableSizeDialog::Field> fields = mTableSizeDlg->header().headerField;
            TableSizeDialog::Field field;
            foreach(field,fields){
                switch (field) {
                        case TableSizeDialog::Field::SrcVol: log<<logdata[1];break;
                        case TableSizeDialog::Field::SrcCurr: log<<logdata[2];break;
                        case TableSizeDialog::Field::SrcPow: log<<logdata[3];break;
                        case TableSizeDialog::Field::SrcRes: log<<logdata[4];break;
                        case TableSizeDialog::Field::LoadVol: log<<logdata[1];break;
                        case TableSizeDialog::Field::LoadCurr: log<<logdata[2];break;
                        case TableSizeDialog::Field::LoadPow: log<<logdata[3];break;
                        case TableSizeDialog::Field::LoadRes: log<<logdata[4];break;
                }
            }
            qDebug()<<"logdata = "<<log;
            mTable->insertRow(log);
    });

     connect(mTable,static_cast<void (Table::*)(const QModelIndex&)>(&Table::cellCurrentIndex),this,
             [=](const QModelIndex&idx){ // 来自Table选择模型提供的有效单元格位置
             QString text = tr("位置: ( %1, %2 )").arg(idx.row()+1).arg(idx.column()+1);
             mCellLoc->setText(text);
             updateCellTextFont(idx);//使用tab/→也能显示动作的checked状态
     });

     connect(mTable,static_cast<void (Table::*)(const QString&)>(&Table::cellCurrentContent),this,
             [=](const QString&content){ // 来自Table选择模型提供的有效单元格位置
             QString text = tr("文本: %1").arg(content);
             mCellContent->setText(text);
     });

     connect(mTableView,static_cast<void (QTableView::*)(const QModelIndex&)>(&QTableView::clicked),this,
             [=](const QModelIndex& index){updateCellTextFont(index);}); // 让动作的checked状态和单元格的状态保持一致
 //    connect(mTableView,static_cast<void (QTableView::*)(const QModelIndex&)>(&QTableView::doubleClicked),this,
 //            [=](const QModelIndex& index){updateCellTextFont(index);}); // 双击和按压可以不用,区别不大
 //    connect(mTableView,static_cast<void (QTableView::*)(const QModelIndex&)>(&QTableView::pressed),this,
 //            [=](const QModelIndex& index){updateCellTextFont(index);});

     connect(mTableSizeDlg,&TableSizeDialog::customTableNotImport,this,[=]{
          // 如果是自定义表格且不启用文本导入的,获取对话框的行列和表头信息
         mTable->reset(mTableSizeDlg->row(),mTableSizeDlg->col());//重置行列数在前
         mTable->setHeader(mTableSizeDlg->header().headerString); // 重置表头在后,否则reset会清除掉表头
         setActColEnabled(true); // 普通表格功能使能列的3个动作 append/insert/remove
         mLogEnabled = false;
     });

     connect(mTableSizeDlg,static_cast<void (TableSizeDialog::*)(QStringList&)>(&TableSizeDialog::customTableUseImport),
             this,[=](QStringList&content){// 自定义表格且启用文本导入
         mTable->importTable(content);
         setActColEnabled(true);
         mLogEnabled = false;
     });

     connect(mTableSizeDlg,&TableSizeDialog::unCustomTable,this,[=]{
          // 启用保存历史功能,不是自定义表格
         QStringList header;
         header <<tr("时间"); // 第1列总是默认的时间字段
         header << mTableSizeDlg->header().headerString;
         mTable->reset(0,header.size());//重置行列数,这里的行数不重要,列数和表头项数一致,行数为0是日志从0行开始
         mTable->setHeader(header);
         setActColEnabled(false); // 禁用列的3个动作
         mLogEnabled = true; // 启用日志记录
     });
}

void TableView::initActConnections()
{
    connect(ActAppendRow,&QAction::triggered,this,[=]{mTable->appendRow();});
    connect(ActAppendCol,&QAction::triggered,mTable,&Table::appendCol);
    connect(ActInsertRow,&QAction::triggered,this,[=]{mTable->insertRow();});
    connect(ActInsertCol,&QAction::triggered,mTable,&Table::insertCol);
    connect(ActRemoveRow,&QAction::triggered,mTable,&Table::removeRow);
    connect(ActRemoveCol,&QAction::triggered,mTable,&Table::removeCol);

    //信号函数参数必须≥槽函数参数,所以无参信号不能直接连接有参槽函数,这里用匿名函数解决
    connect(ActSetAlignLeft,&QAction::triggered,this,[=]{ // 没有再次点击对齐会取消对齐的行为
            mCellFont.align = Table::AlignType::Left;// 左对齐再次点击是左对齐
            mTable->setAlign(mCellFont.align);
    });
    connect(ActSetAlignCenter,&QAction::triggered,this,[=]{
            mCellFont.align = Table::AlignType::Center; // 居中对齐再次点击还是居中对齐
            mTable->setAlign(mCellFont.align);
    });
    connect(ActSetAlignRight,&QAction::triggered,this,[=]{
            mCellFont.align = Table::AlignType::Right; // 右对齐再次点击是右对齐
            mTable->setAlign(mCellFont.align);
    });

    connect(ActSetBold,&QAction::triggered,this,[=]{ // 加粗和斜体有取消效果
            mCellFont.bold=!mCellFont.bold;
            mTable->setBold(mCellFont.bold);// 再次点击会取消加粗
    });
    connect(ActSetItalic,&QAction::triggered,this,[=]{
            mCellFont.italic=!mCellFont.italic;
            mTable->setItalic(mCellFont.italic);// 再次点击会取消斜体
    });

    connect(ActClearTable,&QAction::triggered,mTable,&Table::clearConcurrent);

    connect(ActConfigTable,&QAction::triggered,this,[=]{
        mTableSizeDlg->setCurrentSize(mTable->row(),mTable->col());//size对话框的文本显示和当前表格行列数一致
        mTableSizeDlg->exec();
    });

    connect(ActImportTxt,&QAction::triggered,mTable,&Table::importTxtConcurrent);
    connect(ActExportTxt,&QAction::triggered,mTable,&Table::exportTxtConcurrent);
    connect(ActImportCsv,&QAction::triggered,mTable,&Table::importCsvConcurrent);
    connect(ActExportCsv,&QAction::triggered,mTable,&Table::exportCsvConcurrent);

    connect(ActSetColor,&QAction::triggered,this,[=]{
            QPalette palette;
            palette.setColor(QPalette::Text,mCellFont.mForeColor);
            palette.setColor(QPalette::Background,mCellFont.mBackColor);
            TableColorDialog * dlg = new TableColorDialog(palette); // 传递初始颜色/或者上次设置过的颜色
            int ret = dlg->exec();
            if (ret == QDialog::Accepted)
            {
                  mCellFont.mForeColor = dlg->foregroundColor();//更新选中的新颜色
                  mCellFont.mBackColor = dlg->backgroundColor();
                  // 同时把颜色传递给mTable,内部去更新选中单元格的颜色
                  mTable->setColor(mCellFont.mForeColor,mCellFont.mBackColor);
            }
            delete dlg;
    });

    connect(ActSetSamplePeriod,&QAction::triggered,this,[=]{
         int ret = mTableSPDlg->exec();
         if (ret == QDialog::Accepted)
         {
             // accept后mTableSPDlg的信号selectedPeriod发送出来,mPeriod已被设置,这里直接转发
             emit selectedPeriod(mTableSPDlg->mPeriod.ms,mTableSPDlg->mPeriod.s,
                                 mTableSPDlg->mPeriod.m,mTableSPDlg->mPeriod.h);
         }
         // 或者无需mPeriod,直接连接mTableSPDlg和this的2个selectedPeriod信号也可以
    });

    // 多个动作的同一信号执行相似的槽函数,可以考虑信号映射器,信号不能带参数
    QList<QAction*> actList;
    actList <<ActAppendRow <<ActAppendCol << ActInsertRow << ActInsertCol
                <<ActRemoveRow <<ActRemoveCol << ActSetAlignLeft << ActSetAlignCenter
               << ActSetAlignRight << ActSetBold << ActSetItalic << ActClearTable << ActSetColor
               << ActImportTxt<< ActExportTxt << ActImportCsv<<ActExportCsv << ActConfigTable << ActSetSamplePeriod;
    QAction * act;
    QSignalMapper * signalMapper = new QSignalMapper(this);
    foreach(act,actList) {
            connect(act, SIGNAL(hovered()), signalMapper, SLOT(map()));
            signalMapper->setMapping(act,act->text()); // 绑定的文本映射关系
    }
    connect(signalMapper, static_cast<void (QSignalMapper::*)(const QString&)>(&QSignalMapper::mapped),
            this, [=](const QString& text){ QString t = tr("工具提示: %1").arg(text); mToolTip->setText(t);
    });
}


void TableView::updateCellTextFont(const QModelIndex &index)
{
    QStandardItem * item = mTable->takeItem(index); // 拿到这个单元格的指针
    ActSetBold->setChecked(item->font().bold()); // 让动作的状态和当前结果一致
    ActSetItalic->setChecked(item->font().italic());
    switch (item->textAlignment()) { // 动作使用分组,可以不手动实现互斥效果
//        case Qt::AlignLeft | Qt::AlignVCenter: ActSetAlignLeft->setChecked(true);
//            ActSetAlignCenter->setChecked(false);ActSetAlignRight->setChecked(false);break;
//        case Qt::AlignCenter:ActSetAlignCenter->setChecked(true);
//            ActSetAlignLeft->setChecked(false);ActSetAlignRight->setChecked(false);break;
//        case Qt::AlignRight | Qt::AlignVCenter:ActSetAlignRight->setChecked(true);
//            ActSetAlignLeft->setChecked(false);ActSetAlignCenter->setChecked(false);break;
//        default: break;
        case Qt::AlignLeft | Qt::AlignVCenter: ActSetAlignLeft->setChecked(true);break;
        case Qt::AlignCenter:ActSetAlignCenter->setChecked(true);break;
        case Qt::AlignRight | Qt::AlignVCenter:ActSetAlignRight->setChecked(true);break;
        default: break;
    }
}


void TableView::setActColEnabled(bool checked)
{
    ActAppendCol->setEnabled(checked);// 控制列 添加-插入-删除动作的使能,在自定义字段时禁用
    ActInsertCol->setEnabled(checked);
    ActRemoveCol->setEnabled(checked);
}

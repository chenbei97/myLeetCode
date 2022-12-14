#include <table/tablesizedialog.h>

TableSizeDialog::TableSizeDialog(QWidget * parent):QDialog(parent)
{
        mainLayout = new QGridLayout;

        QLabel * mRowLabel = new QLabel(tr("行: "));
        QLabel * mColLabel = new QLabel(tr("列: "));
        mRowEdit = new QLineEdit;
        mColEdit = new QLineEdit;
        QIntValidator *validator = new QIntValidator(1,10000); // 用指针才起作用
        mRowEdit->setValidator(validator);
        mColEdit->setValidator(validator);
        QLabel * mHeaderLabel = new QLabel(tr("表头: "));
        mHeaderEdit = new QLineEdit(tr("A,B,C,或不输入(默认1,2,3)"));

        QLabel * mWorkModeLabel = new QLabel(tr("工作模式: "));
        QRadioButton * cvRbn = new QRadioButton(tr("恒压模式"));
        QRadioButton * ccRbn = new QRadioButton(tr("恒流模式"));
        cvRbn->setChecked(true); // 默认CV
        cvRbn->setEnabled(false); // 只读,只能外部改变
        ccRbn->setEnabled(false);

        mOkBtn = new QPushButton(tr("确定"));
        mCancelBtn = new QPushButton(tr("取消"));
        mRow = -1;
        mCol = -1;

        mSourceFields = new QListWidget;
        addFields(cvRbn->isChecked(),mSourceFields);
        mLoadFields = new QListWidget;
        addFields(ccRbn->isChecked(),mLoadFields);

        // 主布局的第1个GroupBox: 默认只启用普通的表格功能,不能保存历史数据,那么可以自定义表格
        QGroupBox * sizeBox = new QGroupBox(tr("自定义表格"));
        QGridLayout * sizeLay = new QGridLayout;
        sizeLay->addWidget(mRowLabel,0,0);
        sizeLay->addWidget(mRowEdit,0,1);
        sizeLay->addWidget(mColLabel,1,0);
        sizeLay->addWidget(mColEdit,1,1);
        sizeLay->addWidget(mHeaderLabel,2,0);
        sizeLay->addWidget(mHeaderEdit,2,1);
        sizeBox->setCheckable(true);
        sizeBox->setChecked(true); // 启用
        sizeBox->setLayout(sizeLay);

        // 主布局的第2个GroupBox: 多行文本导入表格
        QGroupBox * importBox = new QGroupBox(tr("文本导入"));
        QVBoxLayout * importLay = new QVBoxLayout;
        QString importTxt = tr("1. 如果不启用文本导入,必须在自定义表格设置行列和表头,"
                               "表头必须以逗号隔开,个数必须和列数一致,例如'A,B,C,D',或者不输入默认'1,2,3,4...'表头设置.\n"
                               "2. 使用文本导入功能就不要再设置表格行列数和表头,自定义表格内的功能无效.\n"
                               "3. 粘贴的文本要求带有表头否则会解析错误,同时每列务必用空格隔开(space,tab)或者逗号(,)隔开,每行用换行符隔开!\n"
                               "4. 这里的文本导入功能实际就是表格窗口中导入Txt/Csv的功能,只是提供了一个编辑框的功能更方便!\n");
        QPlainTextEdit * txtEdit = new QPlainTextEdit(importTxt);
        QLabel * isImportLabel = new QLabel(tr("是否启用文本导入?"));
        QCheckBox * isImport = new QCheckBox;
        connect(isImport,static_cast<void (QCheckBox::*)(bool)>(&QCheckBox::clicked),this,[=](bool checked){
             mRowEdit->setEnabled(!checked); //这里设置的表格行列和表头无效,不允许编辑,直接在plaintext定义
             mColEdit->setEnabled(!checked);
             mHeaderEdit->setEnabled(!checked);
             checked?txtEdit->clear():txtEdit->setPlainText(importTxt);
        });
        isImport->setChecked(false);
        QHBoxLayout * isImportLay = new QHBoxLayout;
        isImportLay->addStretch();
        isImportLay->addWidget(isImportLabel);
        isImportLay->addWidget(isImport);
        importLay->addWidget(txtEdit);
        importLay->addLayout(isImportLay);
        importBox->setLayout(importLay);
        importBox->setCheckable(true);

        // 主布局的第3个GroupBox: 有2个QListWidget,其中1个依据工作模式不可用
        QGroupBox * fieldBox = new QGroupBox(tr("启用字段保存"));
        QHBoxLayout * fieldLay = new QHBoxLayout;
        fieldLay->addWidget(mSourceFields);
        fieldLay->addWidget(mLoadFields);
        fieldBox->setCheckable(true);
        fieldBox->setChecked(false); // 不启用
        fieldBox->setLayout(fieldLay);

        // 让3个groupbox勾选互斥,sizeBox和importBox保持一致
        connect(sizeBox,static_cast<void (QGroupBox::*)(bool)>(&QGroupBox::clicked),
                this,[=](bool checked){fieldBox->setChecked(!checked); importBox->setChecked(checked);});
        connect(fieldBox,static_cast<void (QGroupBox::*)(bool)>(&QGroupBox::clicked),
                this,[=](bool checked){sizeBox->setChecked(!checked); importBox->setChecked(!checked);});

        // 主布局的第4个GroupBox: 附加说明信息,显示当前工作模式(只读)以及确定和取消按钮
        QGroupBox * modeBox = new QGroupBox(tr("附加信息"));
        QHBoxLayout * modeLay1 = new QHBoxLayout;
        QHBoxLayout * modeLay2 = new QHBoxLayout;
        QVBoxLayout * modeLay = new QVBoxLayout;
        QPlainTextEdit * infoEdit = new QPlainTextEdit(tr("提示信息:\n"
                                                          "1. 工作模式在主窗口进行设置,这里只是展示状态,默认恒压模式.\n"
                                                          "2. 可以勾选'自定义表格'也可以勾选'启用字段保存',二者只能选取其一.\n"
                                                          "3. 如果勾选了'自定义表格',说明只使用表格的一般功能,也就是纯粹的Excel功能.\n"
                                                          "4. 如果勾选了'启用字段保存',可以勾选当前工作模式允许的保存字段,例如恒压模式下默认勾选4个源字段,"
                                                          "不可以勾选载字段.此时表格的列数自动确定,请不要再改动.然后主窗口启用后台记录历史数据功能,"
                                                          "就会在USB/TCP功能开启后自动保存历史查询数据!\n"
                                                          "5. 勾选了'启用字段保存',则日期时间字段默认第1列,不可改动.\n"));
        infoEdit->setReadOnly(true);
        modeLay1->addWidget(mWorkModeLabel);

        QButtonGroup * rbnGroup = new QButtonGroup;
        rbnGroup->setExclusive(true);//默认是独占
        rbnGroup->addButton(cvRbn,0);
        rbnGroup->addButton(ccRbn,1);// 按说可以让2个rbn自动互斥,但这里没实现不知道为什么

        modeLay1->addWidget(cvRbn);
        modeLay1->addWidget(ccRbn);
        //modeLay1->addWidget(rbnGroup);//rbnGroup不显示为可视界面不能被添加
        modeLay2->addStretch();
        modeLay2->addWidget(mOkBtn);
        modeLay2->addWidget(mCancelBtn);
        modeLay->addLayout(modeLay1);
        modeLay->addWidget(infoEdit);
        modeLay->addLayout(modeLay2);
        modeBox->setLayout(modeLay);

        connect(this,static_cast<void (TableSizeDialog::*)(WORKMODE)>(&TableSizeDialog::workModeChanged),
                this,[=](WORKMODE mode){// mainwindow's monitorSetting emit = > mainSetting => mTableView => mTableSizeDlg
                bool checked = mode == WORKMODE::CV; //工作模式是mainwindow确定的,默认CV
                cvRbn->setChecked(checked);
                ccRbn->setChecked(!checked);//ccRbn没能实现自动互斥,只能加上这行代码手动实现
        });
        connect(mOkBtn,&QPushButton::clicked,this,[=]{
            mHeader.headerString.clear(); // 实现清除掉,否则下次会累积
            mHeader.headerField.clear();
            if (sizeBox->isChecked()) // 如果是自定义表格的功能
            {
                    if (!isImport->isChecked()) // 但不启用文本导入
                    {
                            QString text1 = mRowEdit->text().simplified();
                            QString text2 = mColEdit->text().simplified();
                            QString text3 = mHeaderEdit->text().simplified(); // 逗号隔开的
                            if (text1.isEmpty() || text2.isEmpty()) return;
                            mRow = text1.toUInt();// row(),col(),header()把信息带出去
                            mCol = text2.toUInt();
                            if (!text3.isEmpty()) mHeader.headerString = text3.split(',',QString::SkipEmptyParts); // 去掉空格
                            else for(int i = 1; i <=mCol; ++i) mHeader.headerString<<QString::number(i); // 如果没有输入,则默认1,2,3,...col
                            //qDebug()<<mHeader;//"A", "B", "C", "D"
                            if (mCol != mHeader.headerString.size()){
                                QMessageBox::critical(this,tr("错误"),tr("表头项数和列数不匹配,请重新输入!"));
                                mHeaderEdit->clear();
                                return;
                            }
                            emit customTableNotImport();//告知外部是自定义但不使用文本导入的情况
                    }
                    else { // 启用文本导入
                            // 粘贴的文本用空格或者逗号隔开均可
                            QStringList content = txtEdit->toPlainText().split('\n',QString::SkipEmptyParts);
                            emit customTableUseImport(content);
                    }
            }
            else { // 启用保存字段的功能
                    bool checked = cvRbn->isChecked();
                    QListWidgetItem * item;
                    if (checked){ // 是CV模式
                        for(int r = 0; r < mSourceFields->count(); ++r)
                        {
                            item = mSourceFields->item(r);
                            if (item->checkState() == Qt::Checked) // 被勾选的源字段
                            {
                                mHeader.headerString<<item->text(); // 作为表头
                                int fieldIdx = item->data(1).toInt(); // item存储的数据是Field转为int,这里变为int
                                mHeader.headerField << Field(fieldIdx);
                            }
                        }
                    }
                    else { // 是CC模式
                        for(int r = 0; r < mLoadFields->count(); ++r)
                        {
                            item = mLoadFields->item(r);
                            if (item->checkState() == Qt::Checked) // 被勾选的载字段
                            {
                                mHeader.headerString<<item->text(); // 作为表头
                                int fieldIdx = item->data(1).toInt(); // item存储的数据是Field转为int,这里变为int
                                mHeader.headerField << Field(fieldIdx);
                            }
                        }
                    }
                    emit unCustomTable();
            }
            accept();
        });
        connect(mCancelBtn,&QPushButton::clicked,this,&QDialog::reject);

        mainLayout->addWidget(sizeBox,0,0);
        mainLayout->addWidget(importBox,0,1);
        mainLayout->addWidget(fieldBox,1,0);
        mainLayout->addWidget(modeBox,1,1);
        mainLayout->setColumnStretch(0,2); // 第1列和第2列的宽度比例3:2
        mainLayout->setColumnStretch(1,3);
        setLayout(mainLayout);

        setWindowIcon(QIcon(":/images/tableview.png"));
        setFont(QFont("Times New Roman",12));
        //setFixedSize(QSize(1050,650));
        resize(QSize(1050,650));
}

int TableSizeDialog::row() const
{
        return mRow;
}

int TableSizeDialog::col() const
{
        return mCol;
}

TableSizeDialog::LogField TableSizeDialog::header() const
{
    return mHeader;
}

void TableSizeDialog::setCurrentSize(int row, int col)
{
    mRowEdit->setText(QString::number(row));
    mColEdit->setText(QString::number(col));
}

void TableSizeDialog::addFields(bool checked,QListWidget * listwidget)
{
    listwidget->setEnabled(checked);
    QStringList headers;
    QList<Field> fields;
    headers<<tr("源电压")<<tr("源电流")<<tr("源功率")<<tr("源内阻");
    fields << Field::SrcVol << Field::SrcCurr << Field::SrcPow << Field::SrcRes;
    if (!checked)
    {
        headers.clear();
        headers<<tr("载电压")<<tr("载电流")<<tr("载功率")<<tr("载内阻");
        fields.clear();
        fields << Field::LoadVol << Field::LoadCurr << Field::LoadPow << Field::LoadRes;
    }

    QListWidgetItem * item;
    for(int i = 0 ; i < headers.size(); ++i)
    {
        item = new QListWidgetItem(headers.at(i),listwidget);
        item->setTextAlignment(Qt::AlignLeft);
        item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        item->setCheckState(Qt::Checked);
        item->setData(1,static_cast<int>(fields.at(i))); // 存储隐藏的数据信息,作为游标
    }
}

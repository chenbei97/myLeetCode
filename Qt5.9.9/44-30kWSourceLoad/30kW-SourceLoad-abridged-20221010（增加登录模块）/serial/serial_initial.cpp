#include <serial/serial_config.h>

void SerialConfig::initUI()
{
      this->initPortInformation();
      this->initPortConfig();
      mainLayout = new QGridLayout(this);
      mainLayout->addWidget(PortInformation,0,0,1,1);
      mainLayout->addWidget(PortConfig,0,1,1,1);
}

void SerialConfig::initPortInformation()
{
        PortInformation = new QGroupBox(tr("串口信息"));
        AvailPortsCombo = new QComboBox; // 有效串口
        PortNameLabel = new QLabel(tr("串口名称："));
        PortLocationLabel = new QLabel(tr("串口位置："));
        PortDescriptionLabel = new QLabel(tr("串口描述："));
        PortManufacturerLabel = new QLabel(tr("制造商："));
        PortVendorLabel = new QLabel(tr("供应商："));
        PortIdentifierLabel = new QLabel(tr("产品编号："));

        QVBoxLayout * PortLabelsLayout = new QVBoxLayout;
        PortLabelsLayout->addWidget(PortNameLabel);
        PortLabelsLayout->addWidget(PortLocationLabel);
        PortLabelsLayout->addWidget(PortDescriptionLabel);
        PortLabelsLayout->addWidget(PortManufacturerLabel);
        PortLabelsLayout->addWidget(PortVendorLabel);
        PortLabelsLayout->addWidget(PortIdentifierLabel);
        QVBoxLayout * PortInfomationLayout = new QVBoxLayout;
        PortInfomationLayout->addWidget(AvailPortsCombo);
        PortInfomationLayout->addLayout(PortLabelsLayout);
        PortInformation->setLayout(PortInfomationLayout);

         // 初始化有效串口及其信息
        QString name; // 串口名称
        QString location; // 串口位置
        QString description; // 描述信息
        QString manufacturer; // 制造商
        quint16 vendor; // 供应商
        quint16 identifier; // 产品编号
        const auto infos = QSerialPortInfo::availablePorts(); // 可用串口

        for (const QSerialPortInfo &info : infos)
        {
              QStringList  informations;
              name = info.portName();
              location = info.systemLocation();
              description = info.description();
              manufacturer = info.manufacturer();
              vendor = info.vendorIdentifier();
              identifier = info.productIdentifier();

              informations << name << location
                   << (!description.isEmpty() ? description : blankString)
                   << (!manufacturer.isEmpty() ? manufacturer : blankString)
                   << (vendor ? QString::number(info.vendorIdentifier(), 16) : blankString)
                   << (identifier ? QString::number(info.productIdentifier(), 16) : blankString);

              AvailPortsCombo->addItem(name,informations); // 把串口名称和对应的所有信息一起存进去便于切换串口时展示信息
        }

      on_PortChanged(0); // 初始化的时候需要先执行1次
}

void SerialConfig::initPortConfig()
{
        PortConfig = new QGroupBox(tr("串口配置"));
        PortBaudRateLabel = new QLabel(tr("波特率："));
        PortParityLabel = new QLabel(tr("奇偶位："));
        PortDataBitLabel = new QLabel(tr("数据位："));
        PortStopBitLabel = new QLabel(tr("停止位："));
        PortFlowControlLabel = new QLabel(tr("流控制："));

        PortBaudRateCombo = new QComboBox;
        PortParityCombo = new QComboBox;
        PortDataBitCombo = new QComboBox;
        PortStopBitCombo = new QComboBox;
        PortFlowControlCombo = new QComboBox;

        okBtn = new QPushButton(tr("确定"));

        QGridLayout * layout = new QGridLayout;
        layout->addWidget(PortBaudRateLabel,0,0);
        layout->addWidget(PortBaudRateCombo,0,1);
        layout->addWidget(PortParityLabel,1,0);
        layout->addWidget(PortParityCombo,1,1);
        layout->addWidget(PortDataBitLabel,2,0);
        layout->addWidget(PortDataBitCombo,2,1);
        layout->addWidget(PortStopBitLabel,3,0);
        layout->addWidget(PortStopBitCombo,3,1);
        layout->addWidget(PortFlowControlLabel,4,0);
        layout->addWidget(PortFlowControlCombo,4,1);
        layout->setRowStretch(5,0); // 空列
        layout->addWidget(okBtn,5,1);
        PortConfig->setLayout(layout);

         // 波特率
        QList<qint32> baudrates = QSerialPortInfo::standardBaudRates();
        QStringList stringBaudrates;
        foreach (const quint32& rate, baudrates)
                    stringBaudrates << QString::number(rate,10);
        PortBaudRateCombo->addItems(stringBaudrates);
        PortBaudRateCombo->addItem(tr("自定义")); // 支持自定义波特率
        PortBaudRateCombo->setEditable(false); // 默认不可编辑除非选择了自定义
        PortBaudRateCombo->setInsertPolicy(QComboBox::NoInsert); // 用户自定义的值不会作为新项插入
        PortBaudRateCombo->setCurrentIndex(6); // 对应9600的位置
        PortBaudRateCombo->setToolTip(tr("请注意,自定义波特率只支持[0,4000000]的范围!"));

        // 数据位
        PortDataBitCombo->addItem(QStringLiteral("5"), QSerialPort::Data5); // 存储到指定userData下
        PortDataBitCombo->addItem(QStringLiteral("6"), QSerialPort::Data6);
        PortDataBitCombo->addItem(QStringLiteral("7"), QSerialPort::Data7);
        PortDataBitCombo->addItem(QStringLiteral("8"), QSerialPort::Data8);
        PortDataBitCombo->setCurrentIndex(3); // 默认是Data8

        // 校验位
        PortParityCombo->addItem(tr("None"), QSerialPort::NoParity);// 存储到指定userData下
        PortParityCombo->addItem(tr("Even"), QSerialPort::EvenParity);
        PortParityCombo->addItem(tr("Odd"), QSerialPort::OddParity);
        PortParityCombo->addItem(tr("Mark"), QSerialPort::MarkParity);
        PortParityCombo->addItem(tr("Space"), QSerialPort::SpaceParity);

        // 停止位
        PortStopBitCombo->addItem(QStringLiteral("1"), QSerialPort::OneStop);// // 存储到指定userData下
        #ifdef Q_OS_WIN // 此类型的停止位只支持window平台
        PortStopBitCombo->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
        #endif
        PortStopBitCombo->addItem(QStringLiteral("2"), QSerialPort::TwoStop);
        PortStopBitCombo->setToolTip(tr("请注意,1.5只支持Windows平台!"));

        // 流控制
        PortFlowControlCombo->addItem(tr("None"), QSerialPort::NoFlowControl);
        PortFlowControlCombo->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
        PortFlowControlCombo->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}




QToolButton：
	QToolButton可以关联QAction，QAction可以关联槽函数
		QToolButton与QAction的联系是setDefaultAction()函数
		QAction和槽函数的联系就像信号的槽函数的关系那样，可以借助命名规则也可以借助connect
	QToolButton可以在UI的toolBar设计，然后拖动动作栏的动作到toolBar实现关联
	QToolButton可以动态被添加进toolBar，需要借助addWidget函数，它还具备添加分隔符和动作函数
		ui->toolBar->addWidget(toolbtn);
		ui->toolBar->addSeparator();
		ui->toolBar->addAction(ui->action); // 把ui已设计过的QAction添加进来
	QToolButton可以联系1个动作的triggered()信号,这个动作可以关联另1个动作的trigger()信号
	QToolButton需要关注的枚举类型：enum ToolButtonPopupMode {DelayedPopup,MenuButtonPopup,InstantPopup};
		MenuButtonPopup模式将会让工具按钮显示一个特殊箭头，指示存在菜单，但是按钮本身也可以联系1个默认动作
		InstantPopup模式点击按钮时立即显示菜单,没有默认的动作，即此模式下不会触发按钮自身联系的动作
		DelayedPopup模式按住工具按钮一段时间后(超时取决于样式，请参阅 QStyle::SH_ToolButton_PopupDelay)，将显示菜单
QMenu：
	 QMenu创建的每个下拉选项其实就是一个QAction，只不过不需要手动关联，直接绑定
	 QMenu可以在UI界面设计，每个菜单选项新建下拉选项时动作一栏就会自动增加QAction
	 QMenu可以动态设计，涉及的核心函数就是addAction，也就是菜单可以添加多个QAction对象
		QMenu * menu = new QMenu(this);
		menu.addAction(ui->action1);
		menu.addAction(ui->action2);
		menu.addAction(ui->action3);
	QMenu对象可以被QToolButton添加，前提是此工具按钮为菜单栏弹出模式
		toolbtn->setPopupMode(QToolButton::MenuButtonPopup); // 菜单弹出模式
		toolbtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon); // 文字图标布局
		toolbtn->setDefaultAction(ui->actSelPopMenu); // 设置默认动作,即此菜单
		toolbtn->->setMenu(menu); // 整体添加菜单


#include "mainwindow.h"
#include "ui_mainwindow.h"

// 判断mdiarea是否存在激活的窗口,没有返回空指针
MyTextEdit* MainWindow::activateTextWindow()
{
     MyTextEdit * w = Q_NULLPTR;
     if (QMdiSubWindow * win = ui->mdiArea->activeSubWindow())
         w = qobject_cast<MyTextEdit*>(win->widget()); // 把多文档子窗口类型的内部小部件MyTextEdit返回
      return w;
}

// 查找是否存在指定名称的子窗口
QMdiSubWindow *MainWindow::findChildWnd(const QString &docName)
{
    QString canonicalFilePath = QFileInfo(docName).canonicalFilePath();
    foreach (QMdiSubWindow *wnd, ui->mdiArea->subWindowList())
    {
        MyTextEdit *childwnd = qobject_cast<MyTextEdit *>(wnd->widget());
        if (childwnd->mCurDocPath == canonicalFilePath) return wnd;
    }
    return 0;
}

void MainWindow::addSubWindowActForWindowMenu()
{
      // 根据当前窗口的数量给窗口菜单添加对应的动作,这样点击每个动作就让对应的窗口成为激活状态
    //首先清空原【窗口】菜单，然后再添加各菜单项
    ui->menuWindow->clear();
    ui->menuWindow->addAction(ui->actClose);
    ui->menuWindow->addAction(ui->actCloseAll);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->actTile);
    ui->menuWindow->addAction(ui->actCascade);
    ui->menuWindow->addSeparator();
    ui->menuWindow->addAction(ui->actNext);
    ui->menuWindow->addAction(ui->actPrevious);

    // 获取mdiarea的所有子窗口列表
    QList<QMdiSubWindow *> wnds = ui->mdiArea->subWindowList();
    if (!wnds.isEmpty()) ui->menuWindow->addSeparator();//如果有活动子窗口先加入1个分隔条

    //遍历各个子窗口，显示所有当前已打开的文档子窗口项
    for (int i = 0; i < wnds.size(); ++i)
    {
        // 获取每个窗口的中心部件
        MyTextEdit *childwnd = qobject_cast<MyTextEdit *>(wnds.at(i)->widget());
        QString menuitem_text;
        if (i < 9) // 8个窗口及以内
        {
            menuitem_text = tr("&%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        } else {
            menuitem_text = tr("%1 %2").arg(i + 1).arg(childwnd->getCurDocName());
        }

        QAction *menuitem_act = ui->menuWindow->addAction(menuitem_text); //添加子窗口菜单项,动作名称：xx文档
        menuitem_act->setCheckable(true); // 设置动作类型是可选
        menuitem_act->setChecked(childwnd == activateTextWindow());//将当前活动的子窗口设为勾选状态

        //关联菜单项的触发信号到信号映射器的map()槽，该槽会发送mapped(QWidget*)信号
        // 而mapped(QWidget*)信号和setActiveSubWindow(QWidget*))函数绑定
        // 所有子窗口菜单动作都执行的同1个槽函数,节省代码
        connect(menuitem_act, SIGNAL(triggered()), mSignalMapper, SLOT(map()));

        //将菜单项与相应的窗口部件进行映射，在发送mapped()信号时就会以这个窗口部件为参数
        mSignalMapper->setMapping(menuitem_act, wnds.at(i)); // 设定QMdiSubWindow*作为不同动作的独特映射
    }
    setFormatMenuActEnabled(true);//使格式菜单下的功能可用
}

#include "customDialog.h"
#include "ui_customDialog.h"

// 4个工具栏动作的槽函数

// 1. 启动设置表格行列数的对话框(模态对话框)
void customDialog::on_actTab_SetSize_triggered()
{
      this->sizeDialog = new tableSizeDialog; // 注意这里并不传递父窗口指针
      this->initialize_sizeDialog_connection(); // 关联信号,可以实现在对话框改变行列数时表格也有对应的显示但是需要确认才是真的设置
      Qt::WindowFlags flags = this->sizeDialog->windowFlags();
      this->sizeDialog->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint); //给对话框外观设置额外的属性,固定大小

      // 数据交互过程
      // 把数据模型的行列数属性显示在对话框上,主窗口获取信息=>对话框显示
      int oldRow = theModel->rowCount(); int oldColumn = theModel->columnCount();
      this->sizeDialog->setRowColumn(oldRow,oldColumn);

      int ret = this->sizeDialog->exec(); // exec会进入事件循环等待结果,模态对话框使用exec
      // 在tableSizeDialog.cpp内定义了只有2个结果,根据确定和取消发出accpet()和reject()函数,反馈exec()的结果对应Accepted和Rejected
      if (ret == QDialog::Accepted) // 如果是Accepted,对话框关闭,但只是隐藏不是真正的删除
      {
            // 把对话框输入的行列数传递给数据模型,对话框获取信息=>数据模型保存
            int cols = this->sizeDialog->columnCount();
            int rows = this->sizeDialog->rowCount();
            theModel->setColumnCount(cols);
            theModel->setRowCount(rows);
      }
      else { // 如果拒绝了,因为对话框设置的单元格的变化导致的数据模型变化要恢复
              theModel->setRowCount(oldRow);
              theModel->setColumnCount(oldColumn);
      }
      delete this->sizeDialog; // 表格行列数设置的对话框关闭后不会删除内存,这里手动删除内存
}

// 2. 启动设置表格标题的对话框(模态对话框)
void customDialog::on_actTab_SetHeader_triggered()
{
    // 注意,此对话框虽然也是模态对话框,但是和设置表格行列数的对话框不同
    // 本对话框只创建1次,可以多次调用,退出对话框只是暂时隐藏,主窗口析构时才会是否本对话框指向的内存
    if (this->headerDialog == nullptr) // 安全检查
        this->headerDialog = new tableHeaderDialog(this);// 注意这里传递父窗口指针

    this->initialize_headerDialog_connection(); // 初始化信号连接

    // 由于本对话框只是隐藏,所以当主窗口的tableview变化时,对话框的显示会不一致
    // 为了保持一致,获取tableview的数据模型的底层数据来重新初始化对话框的listview
    if (this->headerDialog->getHeader().count() != this->theModel->columnCount())
    {
          QStringList headers;
          for (int i = 0; i < theModel->columnCount(); ++i) // 访问标题的每列
          {
                QString header = theModel->headerData(i,Qt::Horizontal,Qt::DisplayRole).toString();
                headers.append(header);
          }
          // 主窗口的数据模型=>对话框的listview进行交互
          this->headerDialog->setHeader(headers);
    }

    int ret = this->headerDialog->exec(); // 模态对话框

    if (ret == QDialog::Accepted)
    {
          // 对话框的listview => 主窗口的数据模型进行交互
          QStringList headers = this->headerDialog->getHeader();
          this->theModel->setHorizontalHeaderLabels(headers); // tableview设置水平标题
    }
}

// 3. 启动设置表格单元格内容的对话框(非模态对话框)
void customDialog::on_actTab_Locate_triggered()
{
      if (this->itemDialog == nullptr) // 注意必须是同一份窗口,否则下方设置动作禁止没有效果
          this->itemDialog = new tableItemDialog(this); // 注意这里传递父窗口指针

      this->initialize_itemDialog_connection();

      // ui->actTab_Locate->setEnabled(false); // 和下方函数的代码一样
      this->setTableItemEnable(false); // 禁止再次点击创建对话框

      this->itemDialog->setAttribute(Qt::WA_DeleteOnClose); // 传递标识让窗口关闭后删除对象

      Qt::WindowFlags flags = this->itemDialog->windowFlags();
      this->itemDialog->setWindowFlags(flags | Qt::WindowStaysOnTopHint); // 保持在顶部显示

      // 主窗口=>对话框进行交互,也就是说对话框显示的行列数至少得是主窗口已有的那么大
      this->itemDialog->setSpinRange(theModel->rowCount(),theModel->columnCount()); // 这里不用从(1,1)计算,返回的就是真实行列数
      // 当前鼠标指向的单元格能传递给对话框当前单元格显示
      QModelIndex index = this->theSelection->currentIndex(); // 当前鼠标指向的单元格索引
      if (index.isValid())
          this->itemDialog->setSpinValue(index.row()+1,index.column()+1);// 注意从(1,1)计算,返回的行列数是索引值不是真实值

      this->itemDialog->show(); // 非模态对话框直接显示
}

// 4. 退出主窗口
void customDialog::on_actFile_Quit_triggered()
{
    // this->close(); ui界面已经关联了此槽函数
}

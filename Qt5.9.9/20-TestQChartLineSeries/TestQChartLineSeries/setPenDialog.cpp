#include "setPenDialog.h"
#include "ui_setPenDialog.h"
#include    <QColorDialog>

// 若MSVC 编译版本错误，修改 msvc-version.conf 文件
// 解决MSVC编译时，界面汉字乱码的问题
#if _MSC_VER >= 1600     //MSVC2015>1899,    MSVC_VER= 14.0
#pragma execution_character_set("utf-8")
#endif

setPenDialog::setPenDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::setPenDialog)
{
        ui->setupUi(this);
        // pen的线型设置,默认SolidLine
        ui->comboPenStyle->clear();
        ui->comboPenStyle->addItem("NoPen",0);
        ui->comboPenStyle->addItem("SolidLine",1);
        ui->comboPenStyle->addItem("DashLine",2);
        ui->comboPenStyle->addItem("DotLine",3);
        ui->comboPenStyle->addItem("DashDotLine",4);
        ui->comboPenStyle->addItem("DashDotDotLine",5);
        ui->comboPenStyle->addItem("CustomDashLine",6);
        ui->comboPenStyle->setCurrentIndex(1);
}

setPenDialog::~setPenDialog()
{
  delete ui;
}

// 1. 设置pen后,需要同步更新界面的状态
void setPenDialog::setPen(QPen pen)
{
    this->m_pen=pen; // 保存设置的结果
    ui->spinWidth->setValue(pen.width()); //同步线宽
    int i=static_cast<int>(pen.style());  //枚举类型转换为整型
    ui->comboPenStyle->setCurrentIndex(i);// 同步线型
    QColor  color=pen.color();
    ui->btnColor->setAutoFillBackground(true); //设置颜色按钮颜色全部填充
    QString str=QString::asprintf("background-color: rgb(%d, %d, %d);",
                                  color.red(),color.green(),color.blue());
    ui->btnColor->setStyleSheet(str);//同步颜色表
}

// 2. 获取pen的属性,先把对话框的属性同步到私有属性保存
QPen setPenDialog::getPen()
{
    m_pen.setStyle(Qt::PenStyle(ui->comboPenStyle->currentIndex()));// 线型
    m_pen.setWidth(ui->spinWidth->value()); //线宽
    QColor  color;
    color=ui->btnColor->palette().color(QPalette::Button); // 同步按钮角色的颜色
    m_pen.setColor(color);
    return  m_pen;
}

// 3. 颜色选择对话按钮的响应槽函数设置pen的color属性
void setPenDialog::on_btnColor_clicked()
{
    QColor  color=QColorDialog::getColor();
    if (color.isValid())
    { //用样式表设置QPushButton的背景色
        QString str=QString::asprintf("background-color: rgb(%d, %d, %d);",
                                      color.red(),color.green(),color.blue());
        ui->btnColor->setStyleSheet(str);
    }
}

// 4.静态函数获取pen的属性
QPen setPenDialog::getPen(QPen iniPen,bool &ok)
{ //静态函数，获取QPen
    setPenDialog *Dlg=new setPenDialog; //创建一个本例自定义的对话框
    Dlg->setPen(iniPen); //设置初始化的QPen保存到m_pem

    QPen    pen; // 新的pen
    int ret=Dlg->exec(); //弹出对话框
    if (ret==QDialog::Accepted)
    {
        pen=Dlg->getPen(); //获取对话框设置的pen属性
        ok=true;    }
    else
    {
        pen=iniPen;//原先的不变
        ok=false;   }

    delete  Dlg; //删除对话框对象
    return  pen; //返回设置的QPen对象
}

#include "TestQChartDrawAllCharts.h"
#include "ui_TestQChartDrawAllCharts.h"

TestQChartDrawAllCharts::TestQChartDrawAllCharts(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::TestQChartDrawAllCharts)
{
      ui->setupUi(this);
      this->resize(1800,800);
      this->theModel = new QStandardItemModel(iniDataRowCount,fixedColumnCount,this); //数据模型
      ui->tableView->setModel(theModel); //设置数据模型
      this->initData();//初始化数据
      this->statisticalData();//统计数据
      // 数据模型的 itemChanged信号与自定义的槽函数关联，用于自动计算平均分
      connect(this->theModel,SIGNAL(itemChanged(QStandardItem *)),this,SLOT(on_itemChanged(QStandardItem *)));

      this->initBarChart();
      this->initStackBarChart();
      this->initPercentBarChart();
      this->initPieChart();
      this->initScatterChart();
}

TestQChartDrawAllCharts::~TestQChartDrawAllCharts()
{
    delete ui;
}

// 1. 初始化数据
void TestQChartDrawAllCharts::initData()
{
    QStringList     headerList;
    headerList<<"姓名"<<"数学"<<"语文"<<"英语"<<"平均分";
    this->theModel->setHorizontalHeaderLabels(headerList); //设置表头文字

    qsrand(QTime::currentTime().second());//随机数种子
    for (int i=0;i<theModel->rowCount();i++) // 每行
    {
        // 姓名列
        QString studName=QString::asprintf("学生%2d",i+1);
        QStandardItem*  aItem=new QStandardItem(studName);//创建item
        aItem->setTextAlignment(Qt::AlignHCenter);
        theModel->setItem(i,colNoName,aItem); //设置item

        // 数学、语文、英语列(1,2,3)
        qreal sumScore=0;
        for (int j=colNoMath;j<=colNoEnglish;j++)
        { //不包含最后一列
            qreal score=50.0+(qrand() % 50);//随机数
            sumScore+=score;

            aItem=new QStandardItem(QString::asprintf("%.0f",score));//创建 item
            aItem->setTextAlignment(Qt::AlignHCenter);
            theModel->setItem(i,j,aItem); //为模型的某个行列位置设置Item
        }

        // 平均分列(4)
        aItem=new QStandardItem(QString::asprintf("%.1f",sumScore/3));//创建平均分item
        aItem->setTextAlignment(Qt::AlignHCenter);
        aItem->setFlags(aItem->flags() & (!Qt::ItemIsEditable));//平均分不允许编辑
        theModel->setItem(i,colNoAverage,aItem); //平均分
    }
}

// 2. 统计数据
void TestQChartDrawAllCharts::statisticalData()
{
    int cnt50,cnt60,cnt70,cnt80,cnt90; // 5个分数档次

    qreal   sumV,minV,maxV; // 总分、最低分和最高分
    qreal   val;
    QTreeWidgetItem *item; //节点

    int i,j;
    for(i=colNoMath;i<=colNoAverage;i++) // 数学、语文、英语、平局对4列分别进行统计
    {
        sumV=0; // 某一科的所有学生总得分
        cnt50=0;
        cnt60=0;
        cnt70=0;
        cnt80=0;
        cnt90=0;

        for(j=0;j<theModel->rowCount();j++) // 针对某一列,所有学生的统计
        {
            val=theModel->item(j,i)->text().toDouble(); // 获取该行该列的分数

            if (j==0) // 统计的第1个学生成绩作为最小值和最大值
            {
                minV=val;
                maxV=val;
            }
            if (val<minV) // 后面的学生只需要和目前的最小最大值比较即可
                minV=val;
            if (val>maxV)
                maxV=val;

            sumV+=val;

            if (val<60) // 统计分数段人数
                cnt50++;
            else if ((val>=60) && (val<70))
                cnt60++;
            else if ((val>=70) && (val<80))
                cnt70++;
            else if ((val>=80) && (val<90))
                cnt80++;
            else
                cnt90++;
        }

        // 某一列的学生统计完以后,把各分数段人数、平均、最低分、最高分
        // 写入到对应行的位置,使用topLevelItem获取顶层项(因为列已经固定,获取行数即可)
        item=ui->treeWidget->topLevelItem(0); //<60 ,第0行,第j列
        item->setText(i,QString::number(cnt50));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(1); //60
        item->setText(i,QString::number(cnt60));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(2); //70
        item->setText(i,QString::number(cnt70));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(3); //80
        item->setText(i,QString::number(cnt80));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(4); //90
        item->setText(i,QString::number(cnt90));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(5); //average
        item->setText(i,QString::number(sumV/theModel->rowCount()));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(6); //max
        item->setText(i,QString::number(maxV));
        item->setTextAlignment(i,Qt::AlignHCenter);

        item=ui->treeWidget->topLevelItem(7); //min
        item->setText(i,QString::number(minV));
        item->setTextAlignment(i,Qt::AlignHCenter);
    }
}

// 3. 数据模型的 itemChanged信号与自定义的槽函数关联，用于自动计算平均分
void TestQChartDrawAllCharts::on_itemChanged(QStandardItem * item)
{
    if ((item->column()<colNoMath) || (item->column()>colNoEnglish))
          return; //如果被修改的item不是数学、语文、英语,就退出
    int rowNo=item->row(); //获取数据的行编号
    qreal  sum=0;
    QStandardItem   *aItem;
    for (int i=colNoMath;i<=colNoEnglish;i++)
    { //获取三个分数的和
        aItem=theModel->item(rowNo,i);
        sum+=aItem->text().toDouble();
    }
    qreal avg=sum/3; //计算平均分
    aItem=theModel->item(rowNo,colNoAverage); //获取平均分数据的item
    aItem->setText(QString::asprintf("%.1f",avg)); //更新平均分数据
}

// 4. 曲线和图例标记进行关联
void TestQChartDrawAllCharts::on_chartBarLegendMarkerClicked()
{
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());

    switch (marker->type())
    {
        case QLegendMarker::LegendMarkerTypeXY:
        {
            marker->series()->setVisible(!marker->series()->isVisible()); // 相反操作
            marker->setVisible(true);
            break;
        }

        case QLegendMarker::LegendMarkerTypeBar:
        { //bar不好处理, barset不能被隐藏，只能take，但是无法恢复
            marker->series()->setVisible(!marker->series()->isVisible());
            marker->setVisible(true);
            break;
        }
        case QLegendMarker::LegendMarkerTypePie:
        {
            marker->series()->setVisible(!marker->series()->isVisible());
            marker->setVisible(true);
            break;
        }
        default:
            break;
    }
}

// 5. 鼠标点击饼图分块时弹出的槽函数
void TestQChartDrawAllCharts::on_PieSliceHighlight(bool show)
{
    // 关联hovered()信号,动态设置setExploded()效果
    QPieSlice *slice;
    slice=(QPieSlice *)sender();
    slice->setExploded(show);
}

// 6. 用于设置饼图的holeSize
void TestQChartDrawAllCharts::on_spinHoleSize_valueChanged(double arg1)
{
    QPieSeries  *series;
    series=(QPieSeries*)ui->chartViewPie->chart()->series().at(0);
    series->setHoleSize(arg1);
}

// 7. 用于设置饼图的PieSize
void TestQChartDrawAllCharts::on_spinPieSize_valueChanged(double arg1)
{
      QPieSeries  *series;
      series=(QPieSeries*)ui->chartViewPie->chart()->series().at(0);
      series->setPieSize(arg1);
}

// 8. 用于设置饼图的主题
void TestQChartDrawAllCharts::on_cBoxTheme_currentIndexChanged(int index)
{
    ui->chartViewPie->chart()->setTheme(QChart::ChartTheme(index));
}

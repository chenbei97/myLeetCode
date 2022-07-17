#include "TestDataStream.h"
#include "ui_TestDataStream.h"
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QDebug>

// 1. 保存stm文件
void TestDataStream::on_actSave_triggered()
{
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        QString aFileName=QFileDialog::getSaveFileName(this,tr("选择保存文件"),currPath.path(),
                     "Qt预定义编码数据文件(*.stm)");

        if (aFileName.isEmpty())
            return;

       if  (this->saveStmFile(aFileName)) //保存为流数据文件
           QMessageBox::information(this,"提示消息","文件已经成功保存!");
}

// 2. 打开stm文件
void TestDataStream::on_actOpen_triggered()
{
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),currPath.path(),
                     "流数据文件(*.stm)");

        if (aFileName.isEmpty())
            return;

        if  (this->openStmFile(aFileName)) //保存为流数据文件
             QMessageBox::information(this,"提示消息","文件已经打开!");

        this->initialize_toolbar_enable(true); // 此时表格和模型有了数据可以保存为任何类型txt,stm和dat,也可以使用文本显示动作了
}

// 3. 保存dat文件
void TestDataStream::on_actSaveBin_triggered()
{
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        //调用打开文件对话框选择一个文件
        QString aFileName=QFileDialog::getSaveFileName(this,tr("选择保存文件"),currPath.path(),
                                                       "二进制数据文件(*.dat)");
        if (aFileName.isEmpty())
            return;

        if  (this->saveDatFile(aFileName)) //保存为流数据文件
            QMessageBox::information(this,"提示消息","文件已经成功保存!");
}

// 4. 打开dat文件
void TestDataStream::on_actOpenBin_triggered()
{
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),currPath.path(),
                                                       "二进制数据文件(*.dat)");
        if (aFileName.isEmpty())
            return;

        if  (this->openDatFile(aFileName)) //保存为流数据文件
            QMessageBox::information(this,"提示消息","文件已经打开!");

        this->initialize_toolbar_enable(true); // 此时表格和模型有了数据可以保存为任何类型txt,stm和dat,也可以使用文本显示动作了
}

// 5. 保存txt文件
void TestDataStream::on_actSaveTxt_triggered()
{
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        // 打开文本对话框
        QString aFileName=QFileDialog::getSaveFileName(this,tr("Select File"),currPath.path(),
                     "txt(*.txt);;all files(*.*)");
        if (aFileName.isEmpty())
            return;

        QFile aFile(aFileName);
        if (!(aFile.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)))
            return;

        QTextStream aStream(&aFile);
        aStream.setAutoDetectUnicode(true);
        QStandardItem   *aItem;
        int i,j;
        QString str;

        //1. 读取数据模型的标题内容
        for (i=0;i<this->theModel->columnCount();i++)
        {
            aItem=this->theModel->horizontalHeaderItem(i);
            str=str+aItem->text()+"\t";  //使用Tab作为分隔符
        }
        aStream<<str<<"\n";  //换行

        // 2. 读取数据模型的数据内容
        for ( i=0;i<this->theModel->rowCount();i++) // 行
        {
            str="";
            for( j=0;j<this->theModel->columnCount()-1;j++) // 列
            {
                aItem=this->theModel->item(i,j);
                str=str+aItem->text()+QString::asprintf("\t");
            }

            aItem=this->theModel->item(i,j); //最后1列单独设置
            if (aItem->checkState()==Qt::Checked)
                str=str+"true";
            else
                str=str+"false";
             aStream<<str<<"\n";
        }
}

// 6. 打开txt文件
void TestDataStream::on_actOpenTxt_triggered()
{

         // (1) 从文本文件读取内容
        QDir currPath = QDir::current();
        currPath.cdUp(); // 从debug目录回到上级目录
        currPath.cd("15-TestQDataStream"); // 进入工作文件夹

        QString aFileName=QFileDialog::getOpenFileName(this,tr("打开一个文件"),currPath.path(),
                     "文本文件(*.txt)");

        if (aFileName.isEmpty())
            return;

        QFile aFile(aFileName);
        QStringList aFileContent;//用于存储读取的文本
        if (aFile.open(QIODevice::ReadOnly | QIODevice::Text ))
        {
             QMessageBox::information(this,"提示消息","文件已经打开!");
             QTextStream aStream(&aFile); //文本流
             aStream.setAutoDetectUnicode(true);
             while (!aStream.atEnd()) //文本流没读完就继续
             {
                 QString str=aStream.readLine();//读取1行
                 aFileContent.append(str); //并保存1行
             }
             aFile.close();//关闭
        }
        else return;

        // (2) 读取的文本内容去初始化表格
        int rowCnt=aFileContent.count(); //文本行数
        this->theModel->setRowCount(rowCnt-1); // 标题行占据1行,所以设置表格实际行数-1

        // 1. 设置标题行
        QString header=aFileContent.at(0);//at访问第1行
        QStringList headerList=header.split(QRegExp("\\t+"),QString::SkipEmptyParts);// 把该行分割成多个列标题
        this->theModel->setHorizontalHeaderLabels(headerList);// 设置分割好的标题

        // 2. 设置数据行
         int j;
         QStandardItem   *aItem;
        for (int i=1;i<rowCnt;i++) //从第2行开始
        {
                QString aLineText=aFileContent.at(i); //第i行分隔
                QStringList tmpList=aLineText.split(QRegExp("\\t+"),QString::SkipEmptyParts); // 每行的所有列分开

                // 最后1列单独设置,这里设置第1-5列
                for (j=0;j<FixedColumnCount-1;j++)
                {
                    aItem=new QStandardItem(tmpList.at(j));// 每个列是1个项
                    this->theModel->setItem(i-1,j,aItem); //设置该项
                }

                 // 第6列是逻辑列,单独设置
                aItem=new QStandardItem(headerList.at(j));
                aItem->setCheckable(true);
                if (tmpList.at(j)=="0" || tmpList.at(j)=="false") // 是0为不选中
                    aItem->setCheckState(Qt::Unchecked);
                else if (tmpList.at(j)=="1" || tmpList.at(j)=="true")
                    aItem->setCheckState(Qt::Checked); // 1为选中
                this->theModel->setItem(i-1,j,aItem);
        }

        this->initialize_toolbar_enable(true); // 此时表格和模型有了数据可以保存为任何类型txt,stm和dat,也可以使用文本显示动作了
}

// 7. 保存stm文件实际调用的函数
bool TestDataStream::saveStmFile(QString &aFileName)
{
        QFile aFile(aFileName);  //以文件方式读出
        if (!(aFile.open(QIODevice::WriteOnly | QIODevice::Truncate)))
                return false;

        QDataStream aStream(&aFile);
        aStream.setVersion(QDataStream::Qt_5_9); //设置版本号,写入和读取的版本号要兼容

        qint16  rowCount=theModel->rowCount(); // 获取数据模型行数
        qint16  colCount=theModel->columnCount(); //获取数据模型列数

        // 1. 保存表格行列数
        aStream<<rowCount; //写入文件流,行数
        aStream<<colCount;//写入文件流,列数

        // 2. 保存表头文字
        for (int i=0;i<theModel->columnCount();i++)
        {
            QString str=theModel->horizontalHeaderItem(i)->text();//获取表头文字
            aStream<<str; //QString写入文件流,Qt预定义编码方式
        }

        // 3. 保存数据区文字
        for (int i=0;i<theModel->rowCount();i++)
        {
                QStandardItem* aItem=theModel->item(i,0); //测深
                qint16 ceShen=aItem->data(Qt::DisplayRole).toInt();
                aStream<<ceShen;// 写入文件流，qint16

                aItem=theModel->item(i,1); //垂深
                qreal chuiShen=aItem->data(Qt::DisplayRole).toFloat();
                aStream<<chuiShen;//写入文件流， qreal

                aItem=theModel->item(i,2); //方位
                qreal fangWei=aItem->data(Qt::DisplayRole).toFloat();
                aStream<<fangWei;//写入文件流， qreal

                aItem=theModel->item(i,3); //位移
                qreal weiYi=aItem->data(Qt::DisplayRole).toFloat();
                aStream<<weiYi;//写入文件流， qreal

                aItem=theModel->item(i,4); //固井质量
                QString zhiLiang=aItem->data(Qt::DisplayRole).toString();
                aStream<<zhiLiang;// 写入文件流，QString

                aItem=theModel->item(i,5); //测井取样
                bool quYang=(aItem->checkState()==Qt::Checked);
                aStream<<quYang;// 写入文件流，bool
        }
        aFile.close();
        return true;
}

// 8. 打开stm文件实际调用的函数
bool TestDataStream::openStmFile(QString &aFileName)
{
        QFile aFile(aFileName);  //以文件方式读出
            if (!(aFile.open(QIODevice::ReadOnly)))
            return false;

        QDataStream aStream(&aFile); //用文本流读取文件
        aStream.setVersion(QDataStream::Qt_5_9); //设置流文件版本号,和保存stm要一致

        // 1. 读取表格行列数
        qint16  rowCount,colCount;
        aStream>>rowCount; //读取行数
        aStream>>colCount; //列数
        this->resetTable(rowCount); //读取到行列数后立刻调整

        // 2. 读取表头
        QString str;
        for (int i=0;i<colCount;i++)
            aStream>>str;  //读取表头字符串

        // 3. 读取数据区文字
        qint16  ceShen;
        qreal  chuiShen;
        qreal  fangWei;
        qreal  weiYi;
        QString  zhiLiang;
        bool    quYang;
        QStandardItem   *aItem;
        QModelIndex index;

        for (int i=0;i<rowCount;i++)
        {
                aStream>>ceShen;//读取测深, qint16
                index=theModel->index(i,0);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(ceShen,Qt::DisplayRole);

                aStream>>chuiShen;//垂深,qreal
                index=theModel->index(i,1);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(chuiShen,Qt::DisplayRole);

                aStream>>fangWei;//方位,qreal
                index=theModel->index(i,2);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(fangWei,Qt::DisplayRole);

                aStream>>weiYi;//位移,qreal
                index=theModel->index(i,3);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(weiYi,Qt::DisplayRole);

                aStream>>zhiLiang;//固井质量,QString
                index=theModel->index(i,4);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(zhiLiang,Qt::DisplayRole);

                aStream>>quYang;//bool
                index=theModel->index(i,5);
                aItem=theModel->itemFromIndex(index);
                if (quYang) aItem->setCheckState(Qt::Checked);
                else aItem->setCheckState(Qt::Unchecked);
        }
        aFile.close();
        return true;
}

// 9. 保存dat文件实际调用的函数
bool TestDataStream::saveDatFile(QString &aFileName)
{
        // QFile + QDataStream 读取文本文件和保存二进制文件
        QFile aFile(aFileName);  // 使用QFile绑定该文件
        if (!(aFile.open(QIODevice::WriteOnly))) // 只写方式打开
            return false;

        QDataStream aStream(&aFile); //用文本流读取文件
        // aStream.setVersion(QDataStream::Qt_5_9); //无需设置数据流的版本
        aStream.setByteOrder(QDataStream::LittleEndian);// 设置字节序为最低有效字节优先(windows平台)
        // aStream.setByteOrder(QDataStream::BigEndian);//QDataStream::LittleEndian最高有效字节在前(默认)

        qint16  rowCount=theModel->rowCount(); // 获取模型数据保存的行数
        qint16  colCount=theModel->columnCount();// 获取模型数据保存的列数

        // int QDataStream::writeRawData(const char *s, int len);
        // 将 s 中的 len 个字节写入流。返回实际写入的字节数，错误时返回 -1

        // 1. 首先保存表格的行数和列数
        aStream.writeRawData((char *)&rowCount,sizeof(qint16)); //写入文件流
        aStream.writeRawData((char *)&colCount,sizeof(qint16));//写入文件流

        // 2. 保存表头文字
        QByteArray  btArray;
        QStandardItem   *aItem;
        for (int i=0;i<theModel->columnCount();i++) // 遍历表头标题(列数)
        {
            aItem=theModel->horizontalHeaderItem(i); //获取表头的每个列item
            QString str=aItem->text(); //获取表头文字

             btArray=str.toUtf8(); //转换为UTF-8的字符数组
            // btArray = str.toLocal8Bit(); // 转换为字符串的本地 8 位表示形式也可以,但是读取的时候要保持一致
            aStream.writeBytes(btArray,btArray.length()); //写入文件流,长度quint32型,然后是字符串内容
            // aStream.writeRawData(btArray,btArray.length());//对于字符串,应使用writeBytes()函数
        }

        // 3. 保存数据区文字
        qint8   yes=1,no=0; //分别代表逻辑值 true和false
        for (int i=0;i<theModel->rowCount();i++) // 遍历每行
        {
            // 每行都有6个数据,测深、垂深、方位、位移、固井质量和测井取样(逻辑值)
            aItem=theModel->item(i,0); //测深
            qint16 ceShen=aItem->data(Qt::DisplayRole).toInt();//qint16类型
            aStream.writeRawData((char *)&ceShen,sizeof(qint16));//写入文件流

            aItem=theModel->item(i,1); //垂深
            qreal chuiShen=aItem->data(Qt::DisplayRole).toFloat();//qreal 类型
            aStream.writeRawData((char *)&chuiShen,sizeof(qreal));//写入文件流

            aItem=theModel->item(i,2); //方位
            qreal fangWei=aItem->data(Qt::DisplayRole).toFloat();
            aStream.writeRawData((char *)&fangWei,sizeof(qreal));

            aItem=theModel->item(i,3); //位移
            qreal weiYi=aItem->data(Qt::DisplayRole).toFloat();
            aStream.writeRawData((char *)&weiYi,sizeof(qreal));

            aItem=theModel->item(i,4); //固井质量
            QString zhiLiang=aItem->data(Qt::DisplayRole).toString();
            btArray=zhiLiang.toUtf8();
            aStream.writeBytes(btArray,btArray.length()); //写入长度,uint,然后是字符串

            aItem=theModel->item(i,5); //测井取样(逻辑值)
            bool quYang=(aItem->checkState()==Qt::Checked); //true or false
            if (quYang)
                aStream.writeRawData((char *)&yes,sizeof(qint8));
            else
                aStream.writeRawData((char *)&no,sizeof(qint8));
        }

        aFile.close();
        return true;
}

// 10. 打开dat文件实际调用的函数
bool TestDataStream::openDatFile(QString &aFileName)
{
    /*
            根据dat文件保存的数据含义顺序来读取dat文件
            qint16  rowCount  行数
            qint16  colCount    列数
            QByteArray btArray (长度,表头文字) ×列数(6)
            qint16,qreal,qreal,qreal,QString,bool (测深,垂深,方位,位移,固井质量和测井取样) ×行数
    */

        QFile aFile(aFileName);  //QFile绑定文件
        if (!(aFile.open(QIODevice::ReadOnly))) // 只读打开
            return false;

        QDataStream aStream(&aFile); //用文本流读取文件
        // aStream.setVersion(QDataStream::Qt_5_9); //不必设置数据流的版本
        aStream.setByteOrder(QDataStream::LittleEndian); // 和保存dat文件一致,字节序为最低有效字节优先
        // aStream.setByteOrder(QDataStream::BigEndian);

        // 1. 先读取表格行列数
        qint16  rowCount,colCount;
        aStream.readRawData((char *)&rowCount, sizeof(qint16));
        aStream.readRawData((char *)&colCount, sizeof(qint16));
        this->resetTable(rowCount); // 根据读取到的立刻调整tableView

        // 2. 读取表头文字
        char *buf;
        uint strLen;  //也就是quint32(别名)
        for (int i=0;i<colCount;i++)
        {
              aStream.readBytes(buf,strLen);//同时读取字符串长度,和字符串内容
               // 和保存时用的编码保持一致
              QString str=QString::fromUtf8(buf,strLen); //可处理汉字,str读到的标题文字没有使用,因为表头不需要重新调整
              Q_UNUSED(str);
        }

        // 3. 读取数据区数据
        QStandardItem   *aItem;
        QModelIndex index;
        // 读取到的数据保存到以下变量,这些变量被setData函数使用
        qint16  ceShen;
        qreal  chuiShen;
        qreal  fangWei;
        qreal  weiYi;
        QString  zhiLiang;
        qint8   quYang;

        for (int i=0;i<rowCount;i++)
        {
                aStream.readRawData((char *)&ceShen, sizeof(qint16)); //测深
                index=theModel->index(i,0);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(ceShen,Qt::DisplayRole);

                aStream.readRawData((char *)&chuiShen, sizeof(qreal)); //垂深
                index=theModel->index(i,1);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(chuiShen,Qt::DisplayRole);

                aStream.readRawData((char *)&fangWei, sizeof(qreal)); //方位
                index=theModel->index(i,2);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(fangWei,Qt::DisplayRole);

                aStream.readRawData((char *)&weiYi, sizeof(qreal)); //位移
                index=theModel->index(i,3);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(weiYi,Qt::DisplayRole);

                aStream.readBytes(buf,strLen);//固井质量
                zhiLiang=QString::fromUtf8(buf,strLen); // 和保存时用的编码保持一致
                index=theModel->index(i,4);
                aItem=theModel->itemFromIndex(index);
                aItem->setData(zhiLiang,Qt::DisplayRole);

                aStream.readRawData((char *)&quYang, sizeof(qint8)); //测井取样
                index=theModel->index(i,5);
                aItem=theModel->itemFromIndex(index);
                if (quYang==1) aItem->setCheckState(Qt::Checked);
                else aItem->setCheckState(Qt::Unchecked);
        }

        aFile.close();
        return true;
}

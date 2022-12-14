#include <csv/csvexport.h>

void CSVExport::writeTable(const QString & text) // 私有函数,给文本流写入数据
{
    QString fileName = QFileDialog::getSaveFileName(Q_NULLPTR, tr("CSV文件"), mWorkDir,tr("*.csv"));
    if (fileName.isEmpty()) {
        QMessageBox::information(Q_NULLPTR,tr("消息"),tr("取消导出CSV文件!"));
        return;
    }
    QFile outFile(fileName);
    outFile.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text);
    QTextStream ts(&outFile);
    ts.setCodec("gbk"); // 这里要设置好gbk即可
    ts << text;
    //QByteArray bytes = text.toLocal8Bit();
    //ts<< bytes;  //传字节,导出那里解析回字节似乎不行,所以就用上边方法就行
    outFile.close();
    QMessageBox::information(Q_NULLPTR,tr("消息"),tr("成功导出CSV文件!"));
}

void CSVExport::exportCsv()
{
     // error()函数返回0或1,返回0说明对话框选择了ignore,否则说明选择了apply,仍然执行
     if (mTableHeader.isEmpty() && mTableContent.isEmpty())
     {
          if (error(ErrorCode::Empty)) writeTable(""); // 什么也不写入
          return;
     }

     if (mTableHeader.isEmpty()) // 表头是空的,那么内容一定不为空
     {
         if(error(ErrorCode::EmptyHeader)) writeTable(mTableContent); // 把内容写入
         return;
     }

     if (mTableContent.isEmpty()) // 内容是空的,那么表头不为空
     {
         if(error(ErrorCode::EmptyContent)) writeTable(mTableHeader);// 把表头写入
         return;
     }

     // 到这里说明都不为空
     writeTable(mTableHeader+mTableContent);  // 把表头和内容写入
}

QString CSVExport::importCsv()
{
        // 提供函数导入外部的csv,获取文本用于其他用处
        QString fileName = QFileDialog::getOpenFileName(Q_NULLPTR, tr("CSV文件"), mWorkDir,tr("*.csv"));
        if (fileName.isEmpty()) {
            QMessageBox::information(Q_NULLPTR,tr("消息"),tr("取消导入CSV文件!"));
            return "";
        }
        QFile outFile(fileName);
        outFile.open( QIODevice::ReadOnly );
        QTextStream ts(&outFile);
        ts.setAutoDetectUnicode(true); // 导入设置好gbk,这2行不设置也没事
        ts.setCodec(QTextCodec::codecForName("gbk")); //这里得用gbk,和txt不同
//        while (!ts.atEnd())
//        {
//            QString line = ts.readLine();
//        }
        QString content = ts.readAll();
        outFile.close();
        //qDebug()<<content; // 如果这里导出的是乱码可能是csv源文件存在问题
        // 考虑将破损的csv文件另存一份csv文件会自动整理好格式,再导入就不会乱码
        return content;
}

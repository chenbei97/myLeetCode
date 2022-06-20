#%%
# -*- coding UTF-8 -*-
'''
@Project : MyProjects
@File : mySignDialog.py
@Author : chenbei
@Date : 2021/3/6 11:11
'''
import sys
import os
from PyQt5.QtWidgets import  QDialog,QApplication
from PyQt5.QtGui import QPalette,QPixmap,QBrush
from PyQt5.QtCore import pyqtSlot,pyqtSignal
from MyPlatform import signDialog
class mySignDialog(QDialog):
    signState = pyqtSignal(bool,bool)
    def __init__(self,parent=None):
        super().__init__(parent)
        self.ui = signDialog.Ui_signDialog()
        self.ui.setupUi(self)
        # 设置背景图片的操作
        palette = QPalette()
        path = os.getcwd() + "//lover.jpg"
        # print(path)
        pix = QPixmap(path)
        pix.scaled(self.width(),self.height())
        palette.setBrush(QPalette.Background, QBrush(pix))
        self.setPalette(palette)
        self.show()
    def checkUsernameIsTrue(self):
        if self.ui.username.text() == "cb" :
            return True
        else:
            return False
    def checkPasswordIsTrue(self):
        if self.ui.password.text() == "cb" :
            return True
        else:
            return False
    def __del__(self):
        self.close()
    @pyqtSlot()
    def on_sure_Button_clicked(self):
        self.signState.emit(self.checkPasswordIsTrue(), self.checkUsernameIsTrue())
        #print(self.checkPasswordIsTrue(), self.checkUsernameIsTrue())
if __name__ == '__main__':

    app = QApplication(sys.argv)
    form = mySignDialog ()
    sys.exit(app.exec_())
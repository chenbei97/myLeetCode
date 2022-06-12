#%%
# -*- coding UTF-8 -*-
'''
@Project : MyProjects
@File : mySignWindow.py
@Author : chenbei
@Date : 2021/3/5 20:51
'''

import sys
import os
from PyQt5.QtWidgets import (QLineEdit,QMainWindow ,QApplication)
from PyQt5.QtCore import pyqtSlot,pyqtSignal
from PyQt5.QtGui import QPalette,QPixmap,QBrush
from MyPlatform import signWindow
class mySignWindow(QMainWindow):
    signState = pyqtSignal(bool,bool)
    def __init__(self,parent=None):
        super().__init__(parent)
        self.ui = signWindow.Ui_signIn_MainWindow()
        self.ui.setupUi(self)
        self.ui.password.setEchoMode(QLineEdit.Password)
        self.ui.username.setEchoMode(QLineEdit.Password)

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
        if self.ui.username.text() == "null" :
            return True
        else:
            return False
    def checkPasswordIsTrue(self):
        if self.ui.password.text() == "1998" :
            return True
        else:
            return False
    def __del__(self):
        self.close()
    @pyqtSlot()
    def on_sure_Button_clicked(self):
        self.signState.emit(self.checkPasswordIsTrue(), self.checkUsernameIsTrue())
if __name__ == '__main__':

    app = QApplication(sys.argv)
    form = mySignWindow ()
    sys.exit(app.exec_())
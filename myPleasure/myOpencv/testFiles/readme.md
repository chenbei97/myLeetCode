# 务必阅读本VSCode配置Opencv的步骤

## CSDN的答案不靠谱

## 如果VS Studio配置Opencv

可以在这个笔记doc中的第4章，第4.5节找到答案。

[https://github.com/chenbei97/myLeetCode/imageProcessingV3.docx](https://github.com/chenbei97/myLeetCode/blob/main/imageProcessingV3.docx)

## 配置Git、Mingw

可在这个md文档找到答案，并给出了VsCode配置C++和Python的方法。

[https://github.com/chenbei97/ComputerVision/markdown/配置环境相关/Git和Vscode配置.md](https://github.com/chenbei97/ComputerVision/blob/main/markdown/配置环境相关/Git和Vscode配置.md)

本人的Mingw的路径就在C盘。

```
C:\msys64
```

记得要把bin、include文件夹都加入环境变量。

```
C:\msys64\mingw64\bin
C:\msys64\mingw64\include
```

## 现在VsCode开始配置Opencv

这个过程参考知乎的答案。

[如何优雅地在你的Vscode上使用opencv（C++接口，Windows篇，实则踩坑经历） - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/402378383?utm_source=wechat_session&utm_medium=social&utm_oi=1173235761410818048&utm_campaign=shareopn)

答案提供好了Opencv编译好的版本，下载地址在下方。

[opencv编译好的版本](https://gitee.com/kirigaya/opencv_built_by_gcc_on_-windows)

或者见

现在要做的事，下载的文件有lib、include、bin。把里边的内容直接复制到上边Mingw的对应文件夹中。


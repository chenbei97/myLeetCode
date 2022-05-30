准备工作
1. vscode 应用拓展下载clang-format
然后全局settings.json写入字段:
// 针对clang-format的设置
"editor.formatOnSave": true,
"clang-format.executable": "${workspaceRoot}", // ${cwd} or ${workspaceRoot} or ${env.VAR} or "/absolute/path/to/clang-format"

cd cmakeExercises\static_analysis\clang

clang-format -style=llvm -dump-config > .clang-format

支持7种代码格式
LLVM A style complying with the LLVM coding standards
Google A style complying with Google’s C++ style guide
Chromium A style complying with Chromium’s style guide
Mozilla A style complying with Mozilla’s style guide
WebKit A style complying with WebKit’s style guide
Microsoft A style complying with Microsoft’s style guide
GNU A style complying with the GNU coding standards

经过核实，了解到需要先安装clang++，配置好vscode 的clang-format
觉得有些麻烦，所以这块内容先不弄了，但是本readme.txt保留，也许以后会用

参考链接：
clang官网及其发布文档：
https://clang.llvm.org/get_started.html
https://clang.llvm.org/docs/ClangFormatStyleOptions.html
clang-format vscode：
https://blog.csdn.net/u012294613/article/details/124663820
https://blog.csdn.net/shenmingxueIT/article/details/122125191
https://github.com/xaverh/vscode-clang-format-provider
cmake例子：
https://github.com/ttroy50/cmake-examples/tree/master/04-static-analysis/clang-format

相应的clang-analyzer也是不再说明，参见：
https://github.com/ttroy50/cmake-examples/tree/master/04-static-analysis/clang-analyzer

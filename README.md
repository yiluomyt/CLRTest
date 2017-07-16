# CLRTest
Demo about C++ using C# dll

项目Trianlge来自于[Trianlge.NET](https://github.com/eppz/Triangle.NET)

## Demo 1
CSharpDLL生成了一个简单的C#类库

CLRTest是一个使用了CLR开关的CLI/C++程序

1. 使用#using指令包含C#的dll文件
1. 用^标识托管对象
1. 用gcnew创建托管对象
1. 托管对象的使用类似于指针

## Demo 2
给出了一个在非托管C++中调用C#库的解决方法

简单思路：使用CLI/C++封装对C#库的操作，生成一个中间DLL，然后在非托管C++中调用中间DLL。

### 一些碰到的问题
1. C++在导出函数时，会对函数名进行修饰，其后果就是在调用时很难直接确定函数入口。

    解决方法：

    * 包含导出函数的头文件
    * 添加静态链接库

    ```
    #pragma comment(lib, "../x64/Debug/usingTriangle.lib")
    #include"../usingTriangle/usingTriangle.h"
    ```
    在加载DLL之后，即可调用导出的C++函数。

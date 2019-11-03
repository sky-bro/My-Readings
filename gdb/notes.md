* 显示gdb版本信息 gdb中输入show version
* 显示版权信息：show copying
* 启动时不显示提示信息：启动时`gdb -q`
* 退出时不显示提示信息：`set confirm off`
* 输出信息较多时，不暂停，全部输出：`set pagination off` 或者 `set height 0`
* `info functions`列出所有函数名称（支持正则 `info functions thre*`）
* `s` 默认情况下会进入带调试信息的函数，不会进入不带调试信息的函数
  * `set step-mode on`后就不会跳过没有调试信息的函数，之后可以使用调试汇编程序的方法调试函数
* 退出正在调试的函数：
  * `finish`运行到函数返回
  * `return val` 直接在当前位置返回 返回值位val
* 直接执行函数：`call func()` 或者 `print func()`
* 显示堆栈信息：`i frame`
* 寄存器：`i reg`
* 反汇编函数：`disassemble func`
* 尾调用堆栈信息（不懂！）
* 选择函数堆栈帧：`frame number`，最内层是0
* 向上或向下切换堆栈帧：`up number`, `down number`
* 对namespace Foo中的foo函数设置断点：`b Foo::foo`
* 对匿名空间中的bar函数设置断点：`b (anonymous namespace)::bar`
* 在程序地址上打断点：`b *address` （在调试汇编程序或没有调试信息时使用）
* 在程序入口打断点：当调试没有调试信息(`strip a.out`)的程序时，直接运行start是没有效果的
  * 可以先通过readelf (`readelf -h a.out`)或者进入gdb后使用info files获得入口地址
  * 然后在程序地址上打断点`b *address`
* 文件行号上打断点：`b linenum`，也可以显示指定文件`b file:linenum` (会匹配所有子目录下的文件)，弊端是如果改变了源程序，断点就不是你想要的了
* 保存已经设置的断点
  * `save breakpoints file-name-to-save`
  * `source file-name-to-save`
* 设置临时断点（只生效一次）：`tbreak (缩写tb)`
* 设置条件断点：`break ... if cond`
* 忽略断点：`ignore bnum count`忽略编号位bnum的断点count次，只有第count+1次触发才会让程序终端
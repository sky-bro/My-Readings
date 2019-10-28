## Google Hack

- 搜索存在敏感信息的网站：`filetype:php intitle:管理登录`
- 搜索Discuz论坛主机：`intext:Powered by Discuz`

## Nmap

* 许多插件，可以用来：检测SQL注射、网页爬行、数据库密码检测
* Nmap脚本引擎：`--script` `.nse` http://nmap.org/nsedoc

## DirBuster

* 探测Web目录结构和隐藏的敏感文件
* 其它类似工具：。。

## 指纹识别

* 针对计算机或计算机系统的某些服务的指纹识别
* 特征库

## Burp Suite

* 插件

## AWVS

* 自动化Web应用程序安全测试工具

## AppScan

## SQL 注入

### 分类

#### 数字型

* ASP、PHP等弱类型语言中常见

* ```
  http://www.xxser.com/test.php?id=8' // 出错
  http://www.xxser.com/test.php?id=8 and 1=1 // 执行正常，返回数据与原始无差异
  http://www.xxser.com/test.php?id=8 and 1=2 // 执行正常，无法查询出数据，因为1=2始终为假
  ```

* 在数据库查询时，数字加引号一般也是合法的，只不过在查询条件为数字时一般不会加单引号

#### 字符型

* 数字型与字符型最大区别在于前者不需要单引号闭合，而后者一般需要使用单引号来闭合
* 关键在于如何闭合SQL语句以及注释多余的代码

### 常见数据库注入

* 对数据库注入，无非是利用数据库获取更多数据或者更大权限
  * 查询数据
  * 读写文件
  * 执行命令

### Blind SQL Injection

* ask the DB true of false questions
  * content based
  * time based
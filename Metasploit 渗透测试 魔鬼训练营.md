## 第1章 魔鬼训练营——初识Metasploit

* **渗透测试**就是一种通过模拟恶意攻击者的技术与方法，挫败目标系统安全控制措施，取得访问控制权限，并发现具备业务影响后果安全隐患的一种安全测试与评估方式

* 渗透测试分类

  * 黑盒测试（外部测试）：一无所知
  * 白盒测试（内部测试）：所有知识
  * 灰盒测试：两种组合

* 渗透测试过程环节

  * [PTES](http://www.pentest-standard.org/)渗透测试执行标准是由安全界多家领军企业技术专家所共同发起的，具体包括以下7个阶段

  1. 前期交互阶段：确定渗透测试范围、目标、限制条件以及服务合同细节
  2. 情报搜集阶段：
  3. 威胁建模阶段：
  4. 漏洞分析阶段：
  5. 渗透攻击阶段：
  6. 后渗透攻击阶段：
  7. 报告阶段：

* 安全漏洞声明周期

  * 周期中，从安全漏洞被发现到厂商发布补丁程序用于修补该漏洞之前的这段器件，被安全社区普遍地称为”**0day**“
  * 100%成功率且可以躲避检测，因此”0day“的安全漏洞和对应的渗透代码对于黑客社区具有很高的价值
  * 典型包括7个部分

  1. 安全漏洞研究与挖掘
  2. 渗透代码开发与测试
  3. 安全漏洞和渗透代码在封闭团队中流传
  4. 安全漏洞和渗透代码开始扩散
  5. 恶意程序出现并开始传播
  6. 渗透代码/恶意程序大规模传播并危害互联网
  7. 渗透攻击代码/攻击工具/恶意程序逐渐消亡

* 渗透测试神器Metasploit

  * 在黑客圈里混，不学好英语是不行的
  * 诞生与发展
    * 2003年10月HD Moore发布了他的第一个基于Perl语言的Metasploit版本，当时一共集成了11个渗透攻击模块

* Metasploit结构剖析

  * 体系结构
    * 基础库文件中提供了核心框架和一些基础功能的支持
    * 实现渗透测试功能的主体代码以模块化方式组织，按用途分为6类
    * 插件机制支持将外部安全工具集成到框架中
    * 通过用户接口与功能程序提供给渗透测试者和安全研究人员进行使用

* 安装Metasploit

  * msfgui
  * **msfconsole**
  * msfcli

## 第2章 赛宁 VS. 定V——渗透测试实验环境

* 渗透测试实验环境拓扑结构

* 攻击机环境

  * Back Track

* 靶机环境

  1. OWASP BWA(Broken Web Apps)靶机镜像
  2. Linux Metasploitable靶机镜像
  3. Win2K3 Metasploitable靶机镜像
     * Metasploit最主要的渗透攻击模块还是集中在Windows环境，但windows系统和上层大多软件属于商业软件
  4. WinXP Metasploitable靶机镜像

* 分析环境

  1. Wireshark 网络抓包与协议分析
  2. IDA Pro 逆向工程分析工具
  3. OllyDbg 动态调试工具
  4. Tamper Data & Hackbar Web应用分析辅助插件
  5. OWASP WebScarab
  6. **Burp Suite**

* **渗透测试实验环境搭建**

  * 网络环境配置

  * 虚拟机镜像配置

    * 按照介绍先后，因为先后次序会影响到DHCP分配的IP地址
    * 当然也可以按照我们的IP地址表进行手工分配

    1. 配置Back Track攻击机环境
    2. 配置靶机与分析机环境

## 第3章 揭开“战争迷雾”——情报搜集技术

* 渗透测试中情报搜集环节需要完成两项重要任务

  * 通过信息搜集工作，确定渗透测试目标的范围
  * 通过情报信息搜集，发现渗透目标的安全漏洞与脆弱点，为后续的渗透攻击提供基础

* 信息搜集工作可以通过手工进行，也可以利用一些自动化的工具，这些自动化的工具通常称为“**扫描器**”

* 外围信息搜集

  * 又称为：**公开渠道**信息搜集

  * 通过DNS和IP地址挖掘目标网络信息

    * 如果关于测试目标的信息只有一个域名或者IP地址，那么接下来可以做些什么呢？

    1. whois域名注册信息查询
    2. nslookup与dig域名查询
       * 两工具功能类似，都可以查询指定域名对应IP地址
       * dig可以从该域名的官方DNS服务器上查到精确的权威解答，而nslookup只会得到DNS解析服务器保存在Cache中的非权威解答
       * dig命令更灵活，可以指定使用哪台DNS进行查询，同时采用dig命令将会触发DNS向官方权威DNS进行一次递归查询，以获得权威解答
       * `dig @<DNS> <target_domain>`
    3. IP2Location地理位置查询
       * 由IP地址查询地理位置的方法称为IP2Location
       * 一些网站提供了IP到地理位置的查询服务，如**GeoIP**，可以在https://www.maxmind.com上使用该服务
    4. netcraft提供的信息查询服务
       * [查询子域名](https://searchdns.netcraft.com/)
       * 用netcraft网站还能够获取一些关于网站和服务器更为详细的信息（地理位置、域名服务器地址、服务器操作系统类型、服务器运行状况等）——**Netcraft Extension**
    5. **IP2Domain**反查域名
       * 一台物理服务器上面可能运行多个虚拟主机，这些虚拟主机具有不同的域名，但通常公用一个IP地址
       * http://www.ip-adress.com/reverse_ip/ 废柴？
       * 7c.com

  * 通过搜索引擎进行信息搜集

    1. Google Hacking技术
       * Google中包含了互联网上在线Web网站的海量数据，且提供了多种**高级搜索功能**
       * 《Google Hacking for Penetration Testers》
       * 《Google Hacking DataBase》 [GHDB](https://www.exploit-db.com/google-hacking-database)
       * SiteDigger
       * Search Diggity
    2. 搜索网站的目录结构
       * Google中输入`parent directory site:testfire.net`, （现在无效了，看不到bank目录）
       * 类似工作也可以借助Metasploit中的brute_dirs、dir_listing、dir_scanner等辅助auxiliary模块来完成
       * 一些网站还会在根目录放置一个名为robots.txt的文件——爬虫规则，而其指出的文件与目录常常是渗透测试者最关注的攻击目标。若发现，应对它给予足够的关注
    3. 检索特定类型的文件：xls...
       * `site:testfire.net filetype:xls`
    4. 搜索网站中的Email地址
       * Metasploit中一个辅助模块`search_email_collector`可以进行有针对性的邮件地址搜集
    5. 搜索易存在SQL注入点的页面
       * 如网站登录页面：`site:testfire.net inurl:login`

* 主机探测与端口扫描

* 服务扫描与查点

* 网络漏洞扫描
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

  * 活跃主机扫描

    * ICMP Ping命令
      * Ping(Packet Internet Grope)是一个用于测试网络连接的程序
      * 会发送一个ICMP echo请求消息给目的主机，并报告应答情况
    * Metasploit的主机发现模块
      * Metasploit中提供了一些辅助模块可用于活跃主机的发现，位于`modules/auxiliary/scanner/discovery`下
      * 主要有：arp_sweep、ipv6_multicast_ping、ipv6_neighbor、ipv6_neighbor_router_advertisement、udp_probe、udp_sweep
      * arp_sweep使用ARP请求枚举本地局域网中的所有活跃主机，智能探测同一子网中的活跃主机，对于远程网络，可以使用更为强大的Nmap扫描器进行探测
      * udp_sweep通过发送UDP数据包探查指定主机是否活跃，并发现主机上的UDP服务
    * 使用Nmap进行主机探测
      * 目标网络哪些主机存活，哪些服务开放，甚至知道网络中使用了何种防火墙设备等
      * 不使用任何选项下，Nmap会使用与Ping命令一样的机制，向目标网络发送ICMP的echo请求，同时会测试目标系统的80和443端口是否打开
      * 如果是在Internet环境中，Ping扫描发送的ICMP数据包通常无法穿透Internet上的网络边界（通常是被防火墙设备过滤了）
      * `nmap -sn 10.10.10.0/24` 仅探测存活主机，不对开放的TCP端口进行扫描
      * `nmap -PU 10.10.10.0/24` 通过对开放的UDP端口进行探测以确定存活的主机，类似udp_sweep辅助模块

  * 操作系统辨识

    * 使用`-O`选项让Nmap对目标操作系统进行识别
    * `nmap -A`可以获取更详细的服务和操作系统信息

  * 端口扫描与服务类型探测

    * 常见的端口扫描技术有以下几类

      1. TCP Connect 结果最精确，速度最慢，也会被扫描主机记录到日志，容易暴露
      2. TCP SYN 利用了TCP协议栈的一些特性，更加快速隐蔽
      3. TCP ACK 同上
      4. TCP FIN 同上
      5. TCP IDLE (more advanced)

    * Metasploit中的端口扫描器

      * `search portscan`
      * ack: 通过ACK扫描的方式对防火墙上未被屏蔽的端口进行探测
      * ftpbounce: 通过FTP bounce攻击的原理对TCP服务进行枚举，一些新的FTP服务器软件能很好防范该攻击，但一些旧的Solaris及FreeBSD系统的FTP服务中此类攻击方式仍能够被利用
      * **syn**: 使用发送TCP SYN标志的方式探测开放的端口，一般推荐：因其扫描速度较快、结果准确且不容易被对方察觉
      * tcp: 使用完整的tcp连接，最准确，但速度较慢
      * xmas: 一种更为隐秘的扫描方式，通过发送FIN、PSH和URG标志，能够躲避一些高级的TCP标记监测器的过滤

    * Nmap的端口扫描功能

      * 大部分扫描器会对所有的端口分为open或close两种类型，而Nmap对端口状态的分析粒度更加细致
      * open、closed、filtered、unfiltered、open|filtered、closed|filtered

      1. open: 一个应用程序正在此端口上进行监听，以接收来自TCP、UDP或SCTP协议的数据
      2. closed: 关闭的端口指的是**主机已响应**，但没有应用程序监听的端口
      3. filtered: 指Nmap不能确认端口是否开放，但根据响应数据猜测该端口可能被防火墙等设备过滤
      4. unfiltered: 仅在使用ACK扫描时，Nmap无法确定端口是否开放，会归为此类，可使用其它类型扫描（如Window扫描，SYN扫描，FIN扫描）进一步确认端口的信息

    * 使用Nmap探测更详细的服务信息

      * `nmap -sV -Pn 10.10.10.129`

  * Back Track 5 的 Autoscan 功能

  * 探测扫描结果分析

  * <table>
        <thead>
          <tr>
            <th>主机</th>
            <th>操作系统</th>
            <th>主要的开放端口</th>
            <th>对应服务版本</th>
          </tr>
        </thead>
        <tbody>
          <tr>
            <td rowspan="7">网站服务器(10.10.10.129)</td>
            <td rowspan="7">Linux 2.6.X(Ubuntu)</td>
            <td>SSH(22)</td>
            <td>OpenSSH 5.3p1</td>
          </tr>
          <tr>
            <td>HTTP(80)</td>
            <td>Apache httpd 2.2.14</td>
          </tr>
          <tr>
            <td>netbios-ssn(139)</td>
            <td>Samba smbd3.X</td>
          </tr>
          <tr>
            <td>Imap(143)</td>
            <td>Courier Imapd(released 2008)</td>
          </tr>
          <tr>
            <td>netbios-ssn(445)</td>
            <td>Samba smbd3.X</td>
          </tr>
          <tr>
            <td>commplex-link(5001)</td>
            <td>Oracle VM Manager</td>
          </tr>
          <tr>
            <td>HTTP(8080)</td>
            <td>Apache Tomcat/Coyte JSP engine 1.1</td>
          </tr>
          <tr>
            <td rowspan="15">后台服务器(10.10.10.130)</td>
            <td rowspan="15">Microsoft Windows XP|2003</td>
            <td>FTP(21)</td>
            <td>Microsoft ftpd</td>
          </tr>
          <tr>
            <td>HTTP(80)</td>
            <td>Microsoft IIS httpd 6.0</td>
          </tr>
          <tr>
            <td>MSRPC(135)</td>
            <td>Microsoft Windows RPC</td>
          </tr>
          <tr>
            <td>netbios-ssn(139)</td>
            <td>空</td>
          </tr>
          <tr>
            <td>Microsoft-ds(445)</td>
            <td>Microsoft Windows 2003 or 2008 microsoft-ds</td>
          </tr>
          <tr>
            <td>multiling-http(777)</td>
            <td>未知</td>
          </tr>
          <tr>
            <td>MSRPC(1025)</td>
            <td>Microsoft Windows RPC</td>
          </tr>
          <tr>
            <td>MSRPC(1026)</td>
            <td>Microsoft Windows RPC</td>
          </tr>
          <tr>
            <td>MSRPC(1027)</td>
            <td>Microsoft Windows RPC</td>
          </tr>
          <tr>
            <td>MSRPC(1031)</td>
            <td>Microsoft Windows RPC</td>
          </tr>
          <tr>
            <td>oracle-tns(1521)</td>
            <td>Oracle TNS Listener 10.2.0.1.0(for 32-bit Windows)</td>
          </tr>
          <tr>
            <td>HTTP(6002)</td>
            <td>SafeNet Sentinel License Monitor httpd 7.3</td>
          </tr>
          <tr>
            <td>afs3-callback(7001)</td>
            <td>未知</td>
          </tr>
          <tr>
            <td>HTTP(7002)</td>
            <td>SafeNet Sentinel Keys License Monitor httpd 1.0(Java Console)</td>
          </tr>
          <tr>
            <td>HTTP(8099)</td>
            <td>Microsoft IIS httpd 6.0</td>
          </tr>
          <tr>
            <td rowspan="8">网关服务器(10.10.10.254)</td>
            <td rowspan="8">Unix, Linux</td>
            <td>FTP(21)</td>
            <td>vsftpd 2.2.2</td>
          </tr>
          <tr>
            <td>SSH(22)</td>
            <td>OpenSSH 5.3p1</td>
          </tr>
          <tr>
            <td>HTTP(80)</td>
            <td>Apache httpd 2.2.14</td>
          </tr>
          <tr>
            <td>netbios-ssn(139)</td>
            <td>Samba smbd3.X</td>
          </tr>
          <tr>
            <td>Imap(143)</td>
            <td>Courier Imapd(released 2008)</td>
          </tr>
          <tr>
            <td>netbios-ssn(445)</td>
            <td>Samba smbd3.X</td>
          </tr>
          <tr>
            <td>ovm-manager(5001)</td>
            <td>Oracle VM Manager</td>
          </tr>
          <tr>
            <td>HTTP(8080)</td>
            <td>Apache Tomcat/Coyte JSP engine 1.1</td>
          </tr>
        </tbody>
      </table>

* 服务扫描与查点

  * 确定开放端口后，通常会对相应端口上所运行服务的信息进行更深入的挖掘，通常称为**服务查点**
  * Metasploit的Scanner辅助模块中，有很多用于服务扫描和查点的工具，**常**以`[service_name]_version`和`[service_name]_login`命名
    * `[service_name]_version`可用于遍历网络中包含了某种服务的主机，并进一步确定服务的版本
    * `[service_name]_login`可对某种服务进行口令探测攻击
    * 例如，`http_version`可用于查找网络中的web服务器，并确定服务器的版本号，`http_login`可用于对需要身份认证的http协议应用进行口令探测

  1. 常见的网络服务扫描
     * Telnet服务扫描
       * 历史悠久但先天缺乏安全性，渐渐被SSH协议代替
       * 价格昂贵、使用寿命更长的大型交换机仍可能使用，而此类交换机在网络中的位置一般来说都非常重要
       * 渗透进入一个网络时，不妨扫描一下是否有主机或设备开启了Telnet服务，为下一步进行网络嗅探或口令猜测做好准备
       * `auxiliary/scanner/telnet/telnet_version`
     * SSH服务扫描
       * 如果没有做其他的安全增强配置（如限制管理员登录的IP地址），只要获取服务器的登录口令，就可以使用SSH客户端登录服务器
       * `auxiliaty/scanner/ssh/ssh_version`
     * Oracle数据库服务查点
       * `auxiliary/scanner/oracle/tnslsnr_version`
       * `mssql_ping` 模块查找网络中的Microsoft SQL Server
     * 开放代理探测与利用
       * 隐藏网络身份的技术有很多，使用代理服务器(Proxy)、VPN等，但最简单和最常见的还是使用代理服务器
       * Metasploit提供了open_proxy模块，能更加方便地获取免费的HTTP代理服务器地址
       * 比开放代理更保险的隐藏攻击源方法是利用开放的或者自主架设的VPN服务
       * 使用这些VPN可以采用加密方式转发路由你的渗透测试数据包，而无需单行你的攻击发起源被跟踪到
       * ？Proxy & VPN: difference
  2. 口令猜测与嗅探
     * SSH服务口令猜测
       * `auxiliary/scanner/ssh/ssh_login`
     * psnuffle口令嗅探
       * 是目前Metasploit中唯一用于口令嗅探的工具，功能不算强大，但非常实用
       * 实际渗透测试过程中，只有在得到能够接入对方网络的初识访问点之后，才能够方便地实用Metasploit中的psnuffle模块进行口令嗅探
       * 如果条件允许的话，推荐在接入网络整个过程中都要保持嗅探器的运行，以增加截获口令的可能性
       * `auxiliary/sniffer/psnuffle`

* 网络漏洞扫描（通过开放服务的漏洞利用，取得服务器的控制权）

  * 漏洞扫描原理与漏洞扫描器
    * **网络漏洞扫描**指的是利用一些自动化的工具来发现网络上各类主机设备的安全漏洞。这些自动化的工具通常被称为**漏洞扫描器**
    * 分**黑盒**扫描与**白盒**扫描
    * 漏洞扫描器一般会附带一个用于识别主机漏洞的**特征库**，并定期对特征库进行更新
  * OpenVAS漏洞扫描器
    * 类似Nessus的综合型漏洞扫描器
    * Nessus曾经是业内开源漏洞扫描工具的标准，在其商业化不再开放源代码后，它的原始项目中分支出OpenVAS开源项目
    * OpenVAS已成为当前最好用的开源漏洞扫描工具
    * 使用NVT（Network Vulnerability Test）脚本对多种远程系统（Windows、Linux、Unix以及Web程序等）的安全问题进行检测
    * 开发维护一套免费的NVT库
  * 查找特定服务漏洞
    * 
  * 漏洞扫描结果分析

* 渗透测试信息数据库与共享

  * 使用渗透测试信息数据库的有事
  * Metasploit的数据库支持

## 第4章 Web应用渗透技术

* Web应用攻击的主要类型
  1. SQL注入攻击
     * 普通注入：根据后台数据库提示有价值的错误信息，可以轻松地进行注入活动
     * 盲注：难度交大，但渗透测试中经常遇到，有经验的管理员在给出错误页面时，没有提供详细的错误信息，攻击者需要运用脚本通过仅有的判断信息对表中每一个字段进行探测，从而实现注入的技术
  2. 跨站脚本XSS: Cross-Site Scripting
     * 存储型XSS：攻击脚本能永久存储在目标服务器数据库或文件中，多见于论坛和博客等Web站点，在发帖时，将恶意脚本连同正常的信息一起注入帖子内容中
     * **反射型XSS**：非持久型的XSS，具有一次性的特点，通过邮件等方式将恶意链接发给受害者，当受害者点击链接时，注入脚本连接到攻击者准备好的服务器某个恶意文件上，然后服务器将注入的文件“反射”到受害者的浏览器上，从而该浏览器执行了这段恶意文件
     * DOM型XSS：它利用了客户端浏览器对请求的网页进行DOM渲染。例如
       * `http://www.some.site/page.html?default=<script>....</script>`
  3. 跨站伪造请求CSRF: Cross-Site Request Forgery
     * 属于XSS漏洞的一种衍生，基本原理是，攻击者利用XSS注入的方式注入一段脚本，当受害者点击浏览器运行该段脚本时，脚本伪造受害者发送了一个合法请求。例如注入如下HTML代码
     * `<img src="http://www.boc.cn/transfer.do?toAct=123456&money=10000">`
     * 浏览器在请求这个地址时同时会附带表示其身份的Cookie信息，就好像受害者自己发送的一样
  4. 会话认证管理缺陷
  5. 安全误配置
  6. 不安全密码存储
     * 敏感资料未加密
     * 使用自己开发的未经证明的算法
     * 持续使用强度不足的算法
     * 未经程序处理的key，以及将key存储在不受保护的地方
  7. 不安全的对象参考Insecure Direct Object References
     * 攻击者利用Web系统本身的文档读取功能，任意存取系统的某一份文档或资料
  8. 限制URL访问失败Failure to Restrict URL Access
  9. 缺乏传输层保护
     * 没有使用SSL/TLS等保护机制，导致数据和Session ID可能被监听到
     * 同时，过期或不正确的证书也可能被使用
  10. 未验证的重定向和跳转Unvalidated Redirects and Forwards
      * 非常容易利用的弱点，攻击者一般会通过未验证重定向页面诱使受害者点击，从而获取密码或其它敏感数据
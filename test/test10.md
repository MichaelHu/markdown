@s
## 享受写文档的乐趣

hudamin 2014-08-22

@s data-transition="zoom"
### 文档的作用

1. 写文档于己是一种`总结和梳理`
2. 写文档与他是一种`知识分享和传承`

@s data-transition="fade"
### 什么会影响我们写文档的体验

1. `排版`：缩进、段落、字号、字体、颜色、源码、图片、链接等
2. `显示面积`：强制换行、均匀分布，太不像代码了
    <img src="./img/line-wrap.png">
@s
3. `接口文档`：`字处理软件`输出的接口文档很不友好
    * 小尾巴，拼写纠正，输入纠正，非等宽字体。—— `太智能了，不见得好啊`
        <img src="./img/code-in-word.png">
    * 图文混排，没法直接拷贝
        <img src="./img/code-in-word-2.png">
    
@s
2. `更新`：如何保证让他人总能看到最新版的文档？

    `甲`：那个接口貌似不能用，帮忙看下

    `乙`：好的，我看下，稍等

    `乙`：我这能用啊，你怎么调的？

    `甲`：@＃@＃¥¥＊&&…………（（&……％＃

    `乙`：你的文档太老了，两月前我就更新了，你去下一个

    `甲`：.....

@s
3. `分享`：U盘？邮件？

@s
### 技术、技术相关人员怎么写文档

1. `写代码`的方式来写文档：纯文本，格式化
2. `管理代码`的方式来管理文档：方便diff
3. 拥抱`云服务`

@s
### HTML格式Web文档

@s
### 怎么写HTML文档？
1. 手写？FE都看着头疼
    <img title="HTML手写" src="./img/write-in-html.png">
2. 编辑工具转存？前提是你还得自己排版


@s
### 我们希望的方式
1. 不直接写HTML标签
2. 纯文本，格式简单
3. 输出为HTML文档
4. 支持主题随意切换

@s
### markdown
1. `JOHN GRUBER`发明，帮助简单快速编写web文档
2. 特定格式书写`纯文本`文档：使用`特殊字符和缩进`，通过工具就可以`转换`成美观的HTML文档
3. 解析器有很多，除了JOHN GRUBER提供的`Perl`解析器外，互联网上还有很多其他版本的，
    比如`Python`版本、`Nodejs`版本、`java`版本、`C`版本等等
4. 新闻文档平台使用的markdown解析器是我前段时间开发的一个基于`lex-yacc`的编译型C解析器

@s
### 如何使用markdown写web文档

@s
### 例子1：标题＋段落

@s
## 一级标题
前言：段落一文本
### 二级标题
段落二文本
#### 三级标题
段落三文本

@s
`写法`：
    # 一级标题
    前言：段落一文本
    ## 二级标题
    段落二文本
    ### 三级标题
    段落三文本

@s
### 例子2：标题＋段落＋代码
@s
#### 以下是一段C代码
简介C代码功能
    int i = 0;
    for(;i<10;i++){
        printf("%d",i);
    }
总结段落

@s
`写法`：

    ### 以下是一段C代码
    简介C代码功能
        int i = 0;
        for(;i<10;i++){
            printf("%d",i);
        }
    总结段落
@s
### 例子3: 多级列表
* `新闻PC端`
    1. 频道
        * 首页
        * 国内
        * 互联网
        * ...
    2. 百家
        * 首页
        * 争鸣
        * 作家页
        * ...
* `新闻无线端`
    1. WEB端
        * WEBAPP
            * Phone WEBAPP
                1. 新闻WEBAPP
                2. 框版本WEBAPP
                3. 阿拉丁正文
                4. ...
            * iPad WEBAPP
                1. 新闻WEBAPP
                2. 阿拉丁正文
        * WAP
            * WML
            * 触屏版
    2. 客户端
        * Android客户端
        * iOS客户端
            1. iPhone/iPod客户端
            2. iPad客户端
@s
`写法`：
    * `新闻PC端`
        1. 频道
            * 首页
            * 国内
            * 互联网
            * ...
        2. 百家
            * 首页
            * 争鸣
            * 作家页
            * ...
    * `新闻无线端`
        1. WEB端
            * WEBAPP
                * Phone WEBAPP
                    1. 新闻WEBAPP
                    2. 框版本WEBAPP
                    3. 阿拉丁正文
                    4. ...
                * iPad WEBAPP
                    1. 新闻WEBAPP
                    2. 阿拉丁正文
            * WAP
                * WML
                * 触屏版
        2. 客户端
            * Android客户端
            * iOS客户端
                1. iPhone/iPod客户端
                2. iPad客户端

@s
### 编写注意事项
1. 纯文本编辑器，ultraEdit, notepad++, editplus, webstorm, vim等，`不要用`word
2. 保存编码：`UTF-8`
3. 文件扩展名：`.md`

@s
### 如何使用百度新闻文档平台 
1. 浏览器访问：`http://db-news-fe2.vm.baidu.com:8520/docs/`
3. SVN，建立自己的子目录：`http://db-news-fe2.vm.baidu.com:8520/svn/newsdocs`
4. 本地预览
        > markdown xxx.md
3. 编辑`index.md`，添加你的文档到首页

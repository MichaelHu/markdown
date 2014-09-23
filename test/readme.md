# markdown_pro说明

## 1. 前言

markdown是基于lex-yacc (flex-bison)编写的C解析器，其解析的语法是<a href="http://daringfireball.net/projects/markdown/" target="_blank">markdown语法</a>的一个子集。

提供了两个版本：
* markdown，提供块级元素解析和內联级元素解析
* markdown_pro，只提供块级元素解析，内联级元素只提供code解析

使用场景：
* markdown，适用于严格进行字符转义的文档
* markdown_pro，适用于绝大部分编写随意的文档

## 2. 标签支持能力

1. 支持的元素：
    * 主要针对块级元素进行解析，包含p, h1-h6, ul, ol, blockquote 
    * 內联元素只处理了code 

2. 常规markdown內联元素的支持不包含在此实现中，原因是基于lex & yacc对语法的严格要求，不适合markdown语法的随意性，会出现非常多的syntax error，而error handling很不容易实现。
    比如內联元素a, img等，编写时，直接写其HTML格式，如下：

        <a href="url">
            title
        </a>
        <img src="url">

3. 支持多级嵌套列表

4. 支持嵌套代码段

6. 其他HTML标签，直接编写，如：

        <table><tr><td>1</td></tr></table>
        <script type="text/javascript" src="./markdown.js"></script>

## 3. 语法说明 

### 3.1 h1-h6

语法：

    # h1 text 
    ## h2 text
    ### h3 text
    #### h4 text
    ##### h5 text
    ###### h6 text

会产生以下输出：

    <h1>h1 text</h1>
    <h2>h2 text</h2>
    <h3>h3 text</h3>
    <h4>h4 text</h4>
    <h5>h5 text</h5>
    <h6>h6 text</h6>

### 3.2 常规段落

语法：

    段落1文本
    段落1文本

    空行开启新的段落
    段落2文本
    段落2文本

会产生以下输出：

    <p>段落1文本
    段落1文本</p>
    <p>空行开启新的段落
    段落2文本
    段落2文本</p>

### 3.3 列表

* 3.3.1 有序列表
    有序列表由`*`开始，后接至少一个空格，再接文本 

    语法（有序列表）：

        1. 列表第一项
        2. 列表第二项

    会产生以下输出：

        <ol><li>列表第一项</li>
        <li>列表第二项</li></ol>

* 3.3.2 无序列表
    无序列表有`数字.`开始，后接至少一个空格，再接文本

    语法（无序列表）：

        * 无序列表第一项
        * 无序列表第二项

    会产生以下输出：

        <ul><li>无序列表第一项</li>
        <li>无序列表第二项</li></ul>

* 3.3.3 嵌套列表
    在上级列表的基础上，再次缩进四个空格或者一个制表符 

    语法（嵌套列表）：

        * 无序列表第一项
            1. 嵌套有序列表第一项
            2. 嵌套有序列表第二项
        * 无序列表第二项
            1. 嵌套有序列表第一项
            2. 嵌套有序列表第二项

    会产生以下输出：

        <ul><li>无序列表第一项<ol><li>嵌套有序列表第一项</li>
        <li>嵌套有序列表第二项</li></ol>
        </li>
        <li>无序列表第二项<ol><li>嵌套有序列表第一项</li>
        <li>嵌套有序列表第二项</li></ol>
        </li></ul> 

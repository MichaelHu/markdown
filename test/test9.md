`允许直接编写html标签`，如果希望html标签直接输出而不做任何处理，需要满足以下条件：
1. 每行的第一列开始写标签
2. 所有内容都在一行内完成
如下所示：

    <table><tr><td>1</td><td>2</td></tr><tr><td>3</td><td>4</td></tr></table>

    <style>body{background-color: #999;}</style>

    <script>console.log(12345);for(var i = 0; i<10; i++){console.log(i);}</script>

    <script type="text/javascript" src="http://wap.baidu.com/static/news/webapp/console/console_fd94d87.js"></script>

<table>
<tr><td>1</td><td>2</td></tr>
<tr><td>3</td><td>4</td></tr>
</table>

<style>body{background-color: #999;}</style>

<script>console.log(12345);for(var i = 0; i<10; i++){console.log(i);}</script>

<script type="text/javascript" src="http://wap.baidu.com/static/news/webapp/console/console_fd94d87.js"></script>

如果要将无序列表包含在div标签内：

    <div>
    * unordered list item 1
    * unordered list item 2
    </div>

<div>
* unordered list item 1
* unordered list item 2
</div>


* `下载地址`：<a href="/docs/hudamin/markdown/download/markdown_preview.tar.gz">markdown_preview_tar.gz</a>
* `部署以及使用方法`：
    1. `Windows`：
        1. 下载以后解包至`C:\markdown_preview`
        2. 将`C:\markdown_preview\markdown.bat`拷贝至`C:\WINDOWS\system32`
        3. 使用方式：
                markdown.bat FILENAME 
        4. 按以上方式解包，即可正常使用。如果需要自己更换目录，则需要修改markdown.bat对应路径

    2. `Mac`:
        1. 下载以后解包至某一本地目录，例如`DIR/markdown_preview` 
        2. 修改`DIR/markdown_previw/markdown.sh`，将
                MARKDOWNCMD=/Users/hudamin/projects/git/git-myscripts/markdown/bin/preview/markdown.out
                ROOT=/Users/hudamin/projects/git/git-myscripts/markdown/bin/preview
            修改成：
                MARKDOWNCMD=DIR/markdown_preview/markdown.out
                ROOT=DIR/markdown_preview
        3. 将`DIR/markdown_preview/markdown.sh`拷贝成`~/bin/markdown`
        4. 设置`可执行权限`： `chmod +x markdown`
        5. 使用方式：
                markdown FILENAME 


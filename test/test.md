@s
# h1 text
## h2 text
### h3 text
#### h4 text
##### h5 text
###### h6 text

this is H1
==========

@s
this is H2
----------



The only restrictions are that block-level HTML elements — e.g. <div>, <table>, <pre>, <p>, etc. — must be separated from surrounding content by blank lines, and the start and end tags of the block should not be indented with tabs or spaces. Markdown is smart enough not to add extra \(unwanted\) <p> tags around HTML block-level tags.


@s
\*literal asterisks\*


@s
## backslash escapes

    \   backslash
    `   backtick
    *   asterisk
    _   underscore
    {}  curly braces
    []  square brackets
    ()  parentheses
    #   hash mark
    +   plus sign
    -   minus sign (hyphen)
    .   dot
    !   exclamation mark



@s
<table>
<tr>
<td>Foo</td>
</tr>
</table>

@s
*emphasis*

<div>*emphasis*</div>

@s
## <span>header</span>

* <a href="url">text</a>
* <img src="url">

@s
&lt;
&amp;

http://images.google.com/images?num=30&amp;q=larry\+bird

4 < 5

@s
"  \n"  => <br />

> This is a blockquote with two paragraphs. Lorem ipsum dolor sit amet,
> consectetuer adipiscing elit. Aliquam hendrerit mi posuere lectus.
> Vestibulum enim wisi, viverra nec, fringilla in, laoreet vitae, risus.
> 
> Donec sit amet nisl. Aliquam semper ipsum sit amet velit. Suspendisse
> id sem consectetuer libero luctus adipiscing.



@s
> This is the first level of quoting.
>
> > This is nested blockquote.
>
> Back to the first level.



@s
> ## This is a header.
> 
> 1.   This is the first list item.
> 2.   This is the second list item.
> 
> Here's some example code:
> 
>     return shell_exec\("echo $input | $markdown_script"\);


@s
*   Red
*   Green
*   Blue


@s
+   Red
+   Green
+   Blue


-   Red
-   Green
-   Blue


@s
1.  Bird
2.  McHale
3.  Parish


1.  Bird
1.  McHale
1.  Parish


@s
3. Bird
1. McHale
8. Parish




@s
*   Bird

*   Magic




@s
1.  This is a list item with two paragraphs. Lorem ipsum dolor
    sit amet, consectetuer adipiscing elit. Aliquam hendrerit
    mi posuere lectus.

    Vestibulum enim wisi, viverra nec, fringilla in, laoreet
    vitae, risus. Donec sit amet nisl. Aliquam semper ipsum
    sit amet velit.

2.  Suspendisse id sem consectetuer libero luctus adipiscing.






@s
*   This is a list item with two paragraphs.

    This is the second paragraph in the list item. You're
only required to indent the first line. Lorem ipsum dolor
sit amet, consectetuer adipiscing elit.

*   Another item in the same list.







@s
blockquote within a list item, the blockquote’s > delimiters need to be indented:

*   A list item with a blockquote:

    > This is a blockquote
    > inside a list item.






@s
*   A list item with a code block:

        <code goes here>





@s
This is a normal paragraph:

    This is a code block.




@s
<p>This is a normal paragraph:</p>

<pre><code>This is a code block.
</code></pre>






@s
Here is an example of AppleScript:

    tell application "Foo"
        beep
    end tell




@s
<p>Here is an example of AppleScript:</p>

<pre><code>tell application "Foo"
    beep
end tell
</code></pre>




@s
    <div class="footer">
        &copy; 2004 Foo Corporation
    </div>



@s
<pre><code>&lt;div class="footer"&gt;
    &amp;copy; 2004 Foo Corporation
&lt;/div&gt;
</code></pre>



@s
Regular Markdown syntax is not processed within code blocks. E.g., asterisks are just literal asterisks within a code block.


@s
## to be implemented

<hr />

    * * *

    ***

    *****

    - - -

    ---------------------------------------




@s
This is [an example](http://example.com/ "Title") inline link.

[This link](http://example.net/) has no title attribute.



@s
<p>This is <a href="http://example.com/" title="Title">
an example</a> inline link.</p>

<p><a href="http://example.net/">This link</a> has no
title attribute.</p>




@s
## to be implemented

    This is [an example][id] reference-style link.
    This is [an example] [id] reference-style link.

    [id]: http://example.com/  "Optional Title Here"




@s
    [foo]: http://example.com/  "Optional Title Here"
    [foo]: http://example.com/  'Optional Title Here'
    [foo]: http://example.com/  (Optional Title Here)


    [id]: http://example.com/longish/path/to/resource/here
        "Optional Title Here"




@s
    [Google][]

    [Google]: http://google.com/






@s
*single asterisks*

_single underscores_

**double asterisks**

__double underscores__





@s
<em>single asterisks</em>

<em>single underscores</em>

<strong>double asterisks</strong>

<strong>double underscores</strong>





@s
un*frigging*believable




@s
\*this text is surrounded by literal asterisks\*




@s
Use the `printf()` function.


    <p>Use the <code>printf()</code> function.</p>


``There is a literal backtick (`) here.``

    <p><code>There is a literal backtick (`) here.</code></p>






@s
A single backtick in a code span: `` ` ``

A backtick-delimited string in a code span: `` `foo` ``


    <p>A single backtick in a code span: <code>`</code></p>

    <p>A backtick-delimited string in a code span: <code>`foo`</code></p>







@s
Please don't use any `<blink>` tags.


<p>Please don't use any <code>&lt;blink&gt;</code> tags.</p>






@s
`&#8212;` is the decimal-encoded equivalent of `&mdash;`.


<p><code>&amp;#8212;</code> is the decimal-encoded
equivalent of <code>&amp;mdash;</code>.</p>




@s
inline images:

![Alt text](/path/to/img.jpg)
![Alt text](/path/to/img.jpg "Optional title")


@s
reference images:

## to be implemented

    ![Alt text][id]

    [id]: url/to/image  "Optional title attribute"




@s
<http://example.com/>

<a href="http://example.com/">http://example.com/</a>




@s
<address@example.com>

<a href="&#x6D;&#x61;i&#x6C;&#x74;&#x6F;:&#x61;&#x64;&#x64;&#x72;&#x65;
&#115;&#115;&#64;&#101;&#120;&#x61;&#109;&#x70;&#x6C;e&#x2E;&#99;&#111;
&#109;">&#x61;&#x64;&#x64;&#x72;&#x65;&#115;&#115;&#64;&#101;&#120;&#x61;
&#109;&#x70;&#x6C;e&#x2E;&#99;&#111;&#109;</a>





















@s
## to be implemented

    a / b;
    // comment
    var c = a / 5;
    ////////
    /^\s+|\s+$/.test("   hello, world!   ");
    a/b/c




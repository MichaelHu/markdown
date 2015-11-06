#!/bin/bash

REVEAL=""

if [ "reveal" == "$1" ] ; then
    REVEAL="_reveal"
fi

find . -type f \
    -regex "\..*\.md" \
    -exec sh build-markdown.sh {} $REVEAL \;

find . -type f -regex "\..*\.md\.html" \
    | sed -E 's/^.+$/<a href="&" target="_blank">&<\/a><br>/g' \
    | cat ./tpl/header.tpl.html - ./tpl/footer.tpl.html  \
    > test_index.txt.md.html

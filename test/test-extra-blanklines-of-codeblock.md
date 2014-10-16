# C语言的可变参数列表

## header files

    #include <stdarg.h>





## examples

    char *str_format(char *format, ...){
        char *_str = NULL;
        va_list args;

        _str = (char *)malloc(1000000);
        va_start(args, format);
        vsprintf(_str, format, args);
        va_end(args);
        return _str;
    }


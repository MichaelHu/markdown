executable file on windows can be built by Cgywin + MinGW

1. MinGW，include gcc
2. Cgywin, include Linux Shell, bison, flex, make, etc.
3. UnixTools can not be used as Cgywin
4. if error "make: cc not be found": 
        cd $MINGW/bin
        cp gcc cc


#set pagination off
set logging file gdb.log
set logging on

file uosc

# main.cpp
break main.cpp:34
break main.cpp:35
break main.cpp:51
break main.cpp:52
break main.cpp:67

# graphics.cpp
break graphics.cpp:33
break graphics.cpp:57
break graphics.cpp:61

# config.cpp
break config.cpp:19

run

set logging off
quit
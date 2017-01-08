# passwd
This tool is a binary for Windows that will help you check the passwd information in linux.

## build
* This tool was developed as a visual studio 2015 professional and was developed to support at least visual studio 2010.

## usage
* passwd.exe [file_path]

### example
```
C:\test>passwd.exe C:\Users\Owner\Desktop\passwd
[user] : root
[password] : x
[uid] : 0
[gid] : 0
[extra] : root
[homedir] : /root
[shell] : /bin/bash

[user] : daemon
[password] : x
[uid] : 1
[gid] : 1
[extra] : daemon
[homedir] : /usr/sbin
[shell] : /usr/sbin/nologin

[user] : bin
[password] : x
[uid] : 2
[gid] : 2
[extra] : bin
[homedir] : /bin
[shell] : /usr/sbin/nologin

[user] : noye
[password] : x
[uid] : 1000
[gid] : 1000
[extra] : Noye,,,
[homedir] : /home/noye
[shell] : /bin/bash
```

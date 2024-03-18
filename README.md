# Embedded Microprocessor Systems Lab. Spring, 2024.
 # Qt5 install (tx2):(should be installed already next time)
    sudo apt-get install qt5-default
# copy dir to tx2:
    scp -r <dir>nvidia@<IP>:~
# after copy to tx2 
    cd <file dir>
    qmake
    make  
# TODO
 find how to set Image throught QIcon

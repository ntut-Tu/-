# Embedded Microprocessor Systems Lab. Spring, 2024.
## lab  要創自己獨立的 Branch 不要 push 到 Main Branch 


## 為什麼需要驅動?

減少用戶空間直接接觸到硬體

 ## 驅動運作原理
 
![003](https://github.com/ntut-Tu/Embedded-Microprocessor-Systems-Lab.-Spring-2024./assets/160988691/fd0170dc-265c-4ee1-aa7f-0c9c49e11c42)

## 注意!!!

記得確認/dev/demo  的文件類型

    ls -l /dev/demo

確認是否c開頭，不是的話

    cd ~
    sudo rm /dev/demo
    mknod /dev/demo c 60 0
   
## 清除dmesg的垃圾訊息

    sudo dmesg -C

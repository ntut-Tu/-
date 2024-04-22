# Embedded Microprocessor Systems Lab. Spring, 2024.
## lab  要創自己獨立的 Branch 不要 push 到 Main Branch 


## Linux 指令

https://dylan237.github.io/linux-basic.html

 * 創資料夾

    mkdir (-p) Name

-p:直接建立多層的資料夾

 * 移除檔案

    rm (-r)(-f) fileName

-r 刪除資料夾

-f 強制刪除 ,-rf=資料夾連同檔案刪除

 * 顯示目錄
   
    ls (-a)(-l)(-R) (DIR)

-a 顯示隱藏檔案

-l 詳細資料 （權限、日期）

-R 顯示包含子資料夾

DIR 沒有，默認當前目錄

    pwd

顯示當前路徑

 * 本地複製
  
    cp (-rpfis) Target

-r 整個資料夾包含內容複製

-p 連同檔案本身屬性、權限複製

-f 強制覆蓋

-i 會詢問是否覆蓋

-s 複製成捷徑

 * 移動或重新命名

    mv (-bvf) Target1 Target2 (move)

    mv (-bvf) ./Target1 ./Target2 (rename)

-b 備份後再移動

-v 移動後顯示做了什麼

-f 強制移動

 * 尋找

    find (從哪搜尋) (-name)|(-iname) <Target in string form>

-name 名字一定要相同

-iname 大小寫皆可

還可以透過特定檔案屬性搜尋，詳見網站

 * 列印檔案內容

    cat (-nbsE) Target1 (>|>>) Target2

-n 對輸出的每row編號

-b 同n但空白行不編號

-s 連續空行合併

-E 每row結尾+$

">" 修改

">>" 追加修改

 * 印出一行

    echo 




## makefile 介紹

https://hackmd.io/@sysprog/SySTMXPvl

## node.js child process 介紹

https://medium.com/wenchin-rolls-around/node-js-%E7%9A%84%E5%AD%90%E7%A8%8B%E5%BA%8F%E6%A8%A1%E7%B5%84-child-process-196529aacfdd
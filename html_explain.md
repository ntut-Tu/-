### HTML 教學：

這份文件是一個 HTML 文件，讓我們來一步步解釋每個部分：

#### 文件型態宣告（DOCTYPE）：
```html
<!DOCTYPE html>
```
這行代碼宣告了 HTML 文件的類型。

#### HTML 開始標籤：
```html
<html>
```
這表示 HTML 文件的開始。

#### head 標籤：
```html
<head>
    <title>LED Control</title>
    <style>
        /* CSS 样式 */
    </style>
</head>
```
在 head 標籤中包含了文件的標題（title）和樣式表（style）。

#### body 標籤：
```html
<body>
    <!-- 此處為文件的主體內容 -->
</body>
```
body 標籤內包含了整個文件的主要內容。

#### 容器 div 元素：
```html
<div class="container">
    <!-- 內容 -->
</div>
```
div 元素是 HTML 中用來劃分和組織內容的一種容器。

#### 標題標籤（h1、h2）：
```html
<h1>LED Switch Frequency</h1>
<h2>LED Ctrl</h2>
```
h1 和 h2 標籤用來定義標題，h1 為一級標題，h2 為二級標題。

#### 表單（form）：
```html
<form>
    <!-- 表單內容 -->
</form>
```
form 元素用來創建 HTML 表單，以便用戶輸入資料。

#### 輸入框（input）：
```html
<input type="checkbox" id="LED1" name="LED1"> LED 1
```
input 元素用來創建不同類型的輸入框，這裡是一個勾選框（checkbox）。

#### 標籤（label）：
```html
<label for="LEDcheckbox1">
    <input type="checkbox" id="LED1" name="LED1"> LED 1
</label>
```
label 元素用來定義輸入框的標籤，通常與 input 元素配合使用。

#### 按鈕（button）：
```html
<button onclick="sendCtrlMode()">Submit</button>
```
button 元素用來創建按鈕，onclick 事件指定了按鈕被點擊時要執行的 JavaScript 函式。

#### 腳本（script）：
```html
<script>
    // JavaScript 代碼
</script>
```
script 元素用來嵌入 JavaScript 代碼，用於實現交互功能。

這些是文件中常見的 HTML 元素，它們用於創建和組織網頁的不同部分。

當然，讓我們來解釋 JavaScript 部分的代碼：

#### JavaScript 事件監聽器（Event Listeners）：
```javascript
// 获取ON和OFF checkbox元素
const onCheckbox = document.getElementById('ON');
const offCheckbox = document.getElementById('OFF');

// 当ON checkbox被点击时
onCheckbox.addEventListener('click', function () {
    // 如果ON checkbox被选中，取消OFF checkbox的选中状态
    if (onCheckbox.checked) {
        offCheckbox.checked = false;
    }
});

// 当OFF checkbox被点击时
offCheckbox.addEventListener('click', function () {
    // 如果OFF checkbox被选中，取消ON checkbox的选中状态
    if (offCheckbox.checked) {
        onCheckbox.checked = false;
    }
});
```
這段代碼添加了事件監聽器，當 ON 或 OFF checkbox 被點擊時，它們會觸發對應的事件處理函式。如果 ON checkbox 被選中，則會取消 OFF checkbox 的選中狀態；反之亦然。

#### JavaScript 函式（Functions）：
```javascript
function sendCtrlMode() {
    // JavaScript 函式代碼
}

function sendShineMode() {
    // JavaScript 函式代碼
}
```
這兩個函式分別是處理「提交」和「Shine_Mode」按鈕點擊事件的 JavaScript 函式。它們負責構建請求並發送到伺服器。

#### XMLHttpRequest 物件：
```javascript
var xhr = new XMLHttpRequest();
```
XMLHttpRequest 物件用於與伺服器進行通信，發送 HTTP 請求和接收 HTTP 響應。

#### 請求配置和發送：
```javascript
xhr.open("GET", requestUrl, true);
xhr.send();
```
這裡使用 XMLHttpRequest 物件的 open 方法配置請求，然後使用 send 方法發送請求到伺服器。

這些是 JavaScript 部分的一些關鍵概念和代碼片段，它們用於實現與用戶交互和伺服器通信的功能。

好的，讓我更詳細地解釋這兩個 JavaScript 函式的功能：

#### sendCtrlMode 函式：
```javascript
function sendCtrlMode() {
    // 创建一个 XMLHttpRequest 对象
    var xhr = new XMLHttpRequest();
    const onCheckbox = document.getElementById('ON');
    const offCheckbox = document.getElementById('OFF');

    // 配置请求
    if (onCheckbox.checked) {
        baseUrl = "/ToCtrlMode/ON/";
    } else if (offCheckbox.checked) {
        baseUrl = "/ToCtrlMode/OFF/";
    }
    var ledSelection = '';

    // 检查每个 LED 复选框是否被选中，如果选中则添加到 LED 选择字符串中
    if (document.getElementById('LED1').checked) {
        ledSelection += "LED1/";
    }
    if (document.getElementById('LED2').checked) {
        ledSelection += "LED2/";
    }
    if (document.getElementById('LED3').checked) {
        ledSelection += "LED3/";
    }
    if (document.getElementById('LED4').checked) {
        ledSelection += "LED4/";
    }

    // 构建完整的请求 URL
    var requestUrl = baseUrl + ledSelection;

    // 如果至少选中了一个 LED，则发送请求
    if (ledSelection !== '') {
        xhr.open("GET", requestUrl, true);
        
        // 当请求完成时的处理函数
        xhr.onload = function () {
            if (xhr.status == 200) {
                // 如果请求成功，将服务器返回的信息显示在网页上
                document.getElementById("response").innerHTML = xhr.responseText;
            }
        };
        // 发送请求
        xhr.send();
    }
}
```
這個函式的作用是根據用戶在網頁上的操作，構建並發送一個 HTTP 請求到伺服器。首先，它創建了一個 XMLHttpRequest 對象，然後根據用戶選擇的 LED 和模式構建請求的 URL。最後，它發送這個請求到伺服器，並在請求完成後將伺服器返回的響應顯示在網頁上。

#### sendShineMode 函式：
```javascript
function sendShineMode() {
    // 建立一个 XMLHttpRequest 物件
    var xhr = new XMLHttpRequest();

    // 配置请求
    //xhr.open("GET", "http://localhost:3000/ToShineMode", true);


    // 如果 ShineMode 被点击并且 text 不为空，则在 "/ToShineMode" 后面加上 "/text"
    var textValue = document.getElementById("Shine_Times").value;
    if (textValue.trim() !== '') {
        xhr.open("GET", "/ToShineMode/" + textValue, true);
    }
    // 当请求完成时的处理函数
    xhr.onload = function () {
        if (xhr.status == 400) {
            // 如果请求成功，将服务器返回的信息显示在网页上
            document.getElementById("response").innerHTML = xhr.responseText;
        }
    };
    // 发送请求
    xhr.send();
}
```
這個函式的作用是根據用戶在網頁上的操作，構建並發送一個 HTTP 請求到伺服器。它首先創建了一個 XMLHttpRequest 對象，然後構建請求的 URL，根據用戶輸入的 Shine 次數。最後，它發送這個請求到伺服器，並在請求完成後將伺服器返回的響應顯示在網頁上。

這兩個函式都用於與伺服器進行通信，並根據用戶的操作動態生成請求的內容。
# HTML 2

## 图像（接上一篇）

*前排提醒：属性名称不分大小写，但属性值大小写敏感。*

### 水平线

1. `<hr>`：水平线，用于分隔内容。

```html
<hr>
```

2. `<hr>`标签可以设置属性，如`width`、`size`、`color`，`align`等。

```html
<hr width="50%" size="3" color="red">
```

width对应的是页面宽度的百分之多少

### 改变背景图

在body标签中设置`background-image`属性即可。

```html
<body background="image.jpg">
```

## 补充的文本标签

加粗线 <b>
下划线 <u>
删除线 <del> <s>
斜体 <i>


代码实现

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <b>前端</b>
    <i>联系</i>
    <p>邮箱：<EMAIL></p>
    <del>微信：lyx2019</del>
    <br>
    <u>手机：13812345678</u>
    <br>
    <s>QQ：123456789</s>
</body>
</html>
```

### 表格标签

1. `<table>`：表格标签，用于创建表格。
2. `<tr>`：表格行标签，用于创建表格的行。
3. `<td>`：表格单元格标签，用于创建表格的单元格。
4. `<th>`：表格标题标签，用于创建表格的标题。

```html
<table>
    <tr>
        <th>姓名</th>
        <th>年龄</th>
        <th>性别</th>
    </tr>
    <tr>
        <td>张三</td>
        <td>20</td>
        <td>男</td>
    </tr>
    <tr>
        <td>25</td>
        <td>女</td>
    </tr>
</table>
```

代码实现

```html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>表格标签</title>
</head>
<body>
    <table border="1">
        <tr>
            <th>姓名</th>
            <th>年龄</th>
            <th>性别</th>
        </tr>
        <tr>
            <td>张三</td>
            <td>20</td>
            <td>男</td>
        </tr>
        <tr>
            <td>25</td>
            <td>女</td>
        </tr>
    </table>
</body>
</html>
```

表格标签还有border属性，可以设置边框的宽度。

## 网页中的链接

链接又叫超级链接，是构成网页的基本元素。

链接的目标可以是多种样式的，可以是一个网页，一个图片，一个邮件地址，一个应用程序。

### 链接的语法

```html
<a href="目标地址">链接描点对象</a>
```

- `href`：表示链接的目标地址，可以是网页地址，也可以是邮件地址。
- `链接描点对象`：可以是文本，也可以是图像。

*点击`链接描点对象`后，将会跳转到`目标地址`*

### 链接的种类

#### 基本文字链接

最初文字上的超链接是蓝色，浏览过后会变成紫色。

```html
<a href="http://www.baidu.com">百度</a>
```

代码实现

```html
<!DOCTYPE html>
<html>
    <head>
        <title>基本文字链接</title>
    </head>
    <body>
        你也可以直接把链接插入到文字中去。
        比如这样，打开<a href="https://www.baidu.com">百度</a>
            <br>
        <p>
            这样插入了一个百度的链接
        </p>
            <a href="http://www.baidu.com">百度</a>
    </body>
</html>
```

文字链接不是链接到的东西是文字，是以文字作为载体来链接到我们想要去的目标上去

#### 图像链接

链接的基本方法和文字没有区别
在引入`<a href="目标地址">`和`</a>`中插入`<img scr="图片的地址">`

代码实现

```html
<!DOCTYPE>
<html>
    <head>
        <title>
            插入图片链接
        <title>
    <head>
    <body>
        <h1>下面是图片的链接<h1>
            <a href="1.html">
                <img src="img/1.png">
            </a>
        <h1>点击图片链接就会跳转到想要去的地方<h1>
    </body>
<html>
```

如果图像不是正规矩形的就会出现边框，去除边框可以在代码中添加“broad=0”
例如

```html
<img src="img/1.png" border=0>
```

*border是img标签中的*。

#### 链接邮箱地址

在`<a>`标签中可以链接电子邮件和邮箱地址。通过网址让使用者和设计者联系的最方便的方式

可以直接留下电子邮箱，但更加倾向于把邮箱链接到页面内容当中，

```html
<a href="mailto=2077880746@qq.com">我的邮箱</a>
```

这样单击这里就可以自动打开邮件客户端，并且自动填上收件人

*如果浏览者的浏览器也没有安装客户端，则会给使用者带来很大的麻烦*。

### 在同一页面中查找信息

可以链接到当前页面的指定位置，主要用于导航

需要使用`<a>`中id属性来确定路径。

几个步骤

1. 确定链接的瞄点对象

`<a href=#...></a>`

2. 在页面中设定出链接的目标,使用id属性

`<a id= >`

代码实现

```html
<!DOCTYPE>
<html>
    <head>
        <title>查找页面的内容
        </title>
    <head>
    <body>
        <h1><a id="top">目录</a><h1>
        <ul>
            <li><a href="#1">第一节</a></li>
            <li><a href="#2">第二节</a></li>
            <li><a href="#3">第三节</a></li>
        </ul>
        <br><br><br><br><br><br>
        <h3><a id="1">第一节内容</a><h3>
            <p>
                假装这里有一些内容
            </p>
        <h3><a id="top">返回目录</a><h3>
            <h3><a id="2">第二节内容</a><h3>
            <p>
                假装这里有一些内容
            </p>
        <h3><a id="top">返回目录</a><h3>
            <h3><a id="3">第二节内容</a><h3>
            <p>
                假装这里有一些内容
            </p>
        <h3><a id="top">返回目录</a><h3>
            <br><br><br>
    </body>
</html>
```

### 提高链接的友好度

使用新颖的方法来改变链接的状态

#### 美观连接的状态

首先搞明白链接都有哪些状态

1. 链接还没有被选中时
2. 链接被选中时
3. 鼠标滑过链接时
4. 链接被访问之后

其中我们有link，alink，vlink属性来修改

link：修改链接没有访问的时候的文本颜色
alink：修改链接被选中的文本颜色
vlink：修改链接被访问之后的文本颜色

```html
<!--通过标签属性修改文本链接的颜色-->
<!DOCTYPE>
<html>
    <head>
        <title>
            通过标签属性修改文本链接的颜色
        <title>
    </head>
    <body link=teal alink=red vlink=sliver>
        <h2>通过标签属性修改文本链接的颜色</h2>
        <br>
            <a href="后退.html">注意文本颜色前后变化</a>
        <br>
    </body>
</html>
```

这个时候链接到了一个后退的html文件上，在body标签上定义了三种状态的链接

这是使用html标签属性来实现的功能，事实上这种就方法不值得推荐，更好的方法应该时基于css

除了结构性的`<p>`,`<body>`无法取代，在表现性的作用下，应该习惯于避免使用标签属性的方法。而且css可以包含更多的属性修改，实现自由度更大的修饰。

#### 热点区域的链接

热点区域的定义：一个图像的某一个区域。
比如在地图上一点，点击即可进入到连接到的界面

这需要我们使用一个`<map>`标签来定义热点区域，然后使用`<area>`标签来定义热点区域的链接

```html
<!DOCTYPE>
<html>
    <head>
        <title>
            热点区域的链接
        <title>
    </head>
    <body>
        <h2>热点区域的链接</h2>
        <br>
        <img src="img/map.jpg" usemap="#map">
        <map name="map">
            <area shape="circle" coords="300,300,50" href="#"/>
        </map>
        <br>
    </body>
</html>
```

这个例子中，我们定义了一个热点区域，使用了`<img>`标签的`usemap`属性来引用热点区域的名称，然后使用`<area>`标签定义了两个热点区域，一个是矩形，一个是圆形。

href属性定义了点击热点区域后跳转到的链接，这里我们使用`#`表示当前页面。

#### 在新窗口页面上显示链接窗口

有时候我们希望链接到其他页面时，在新窗口页面上显示，而不是在当前页面打开。

```html
<a href="http://www.baidu.com" target="_blank">百度</a>
```

target="_blank"属性可以实现在新窗口页面上显示。

## 网页中的表单

- 表单的工作原理是用户输入数据，然后服务器接收数据，处理数据，然后返回结果。

从技术概念上，表单时操作form对象的，对象是一种基本的数据类型

### script标签

- `<script>`标签用于包含客户端脚本，可以用来实现动态效果，比如动画，表单验证，AJAX，JavaScript。

- `<script>`标签可以嵌入到`<head>`标签中，也可以嵌入到`<body>`标签中。

- `<script>`标签可以包含JavaScript代码，也可以包含外部JavaScript文件。

javascript代码可以直接写在标签中，也可以写在外部文件中，然后通过src属性引入。

```html
<script>
    // 这里是JavaScript代码
</script>

<script src="js/script.js"></script>
```

1. 外部JavaScript文件

外部JavaScript文件可以是`.js`文件，也可以是`.js.php`文件，`.js.asp`文件，`.js.jsp`文件等。

```html
<script src="js/script.js"></script>
```

这样就可以在外部JavaScript文件中定义JavaScript代码，然后通过src属性引入到页面中。

2. 内联JavaScript代码

```html
<script>
    // 这里是JavaScript代码
</script>
```

### 创建表单

和普通的html文件一样，通过form标签创建，有一些常用的属性，比如name，action，method等。

name属性：表单的名称

action属性：表单提交的目标地址，通过form标签定义的表单，必须要action属性才能将数据提交出去

method属性：表单提交的方式，可以是get，post，put，delete等。

其中get的安全性较差，所有表单的信息都会直接呈现在地址栏中，而post除了可见的处理脚本外，其他的东西都可以隐藏

常见的表单元素

```html
<form name="myForm" action="submit.php" method="post">
```

代码解析：这里定义了一个myform的表单，其中action属性指定了提交的目标地址为submit.php，method属性指定了提交的方式为post。

```html
<form action="submit.php" method="post">
    <label for="name">姓名：</label>
    <input type="text" id="name" name="name"><br><br>
    <label for="email">邮箱：</label>
    <input type="email" id="email" name="email"><br><br>
    <label for="message">留言：</label>
    <textarea id="message" name="message"></textarea><br><br>
    <input type="submit" value="提交">
</form>
```

表单域是用户输入数据的地方，表单域相当于用户给程序下达命令。
常见的指令有：文本输入框，密码输入框，邮箱输入框，多行文本输入框，提交按钮。

### 通过表单展示不一样的页面

#### input标签

常见的属性有name,type,value,size,maxlengh等


type属性可以指定表单域的类型，常见的类型有text，password，email，checkbox，radio，submit，reset，file等。


### text文本框的样式表单

单行文本框又将文本框，是一种最常见的一类表单元素，让用户输入一些简单的内容，如用户名等

```html
<label for="username">用户名：</label>
<input type="text" id="username" name="username" placeholder="请输入用户名"><br><br>
```

代码解析：这里定义了一个用户名的文本框，其中placeholder属性可以设置提示信息，当用户点击文本框时，提示信息会消失。

```html
<label for="password">密码：</label>
<input type="password" id="password" name="password" placeholder="请输入密码"><br><br>
```

代码解析：这里定义了一个密码的文本框，其中type属性指定了密码类型，输入的字符会被替换成圆点。

```html
<label for="email">邮箱：</label>
<input type="email" id="email" name="email" placeholder="请输入邮箱"><br><br>
```

代码解析：这里定义了一个邮箱的文本框，其中type属性指定了邮箱类型，输入的字符会被自动验证。

```html
<label for="message">留言：</label>
<textarea id="message" name="message" placeholder="请输入留言"></textarea><br><br>
```

代码解析：这里定义了一个多行文本框，其中type属性指定了多行文本类型，可以输入多行文本。

```html
<label for="gender">性别：</label>
<input type="radio" id="male" name="gender" value="male">
<label for="male">男</label>
<input type="radio" id="female" name="gender" value="female">
<label for="female">女</label><br><br>
```

代码解析：这里定义了一个性别的单选框，其中type属性指定了单选类型，value属性指定了单选按钮的值。

```html
<label for="interest">兴趣：</label>
<input type="checkbox" id="reading" name="interest" value="reading">
<label for="reading">阅读</label>
<input type="checkbox" id="swimming" name="interest" value="swimming">
<label for="swimming">游泳</label>
<input type="checkbox" id="running" name="interest" value="running">
<label for="running">跑步</label><br><br>
```

代码解析：这里定义了一个兴趣的多选框，其中type属性指定了多选类型，value属性指定了多选按钮的值。

```html
<label for="file">上传文件：</label>
<input type="file" id="file" name="file"><br><br>
```

代码解析：这里定义了一个上传文件的按钮，其中type属性指定了文件类型。

#### select标签

select标签可以用来创建下拉列表，常见的属性有name,size,multiple等

```html
    <option value="japan">日本</option>
</select><br><br>
```


代码解析：这里定义了一个下拉列表，其中option标签定义了选项，value属性指定了选项的值。

```html
    <option value="japan">日本</option>
</select><br><br>
```


代码解析：这里定义了一个下拉列表，其中option标签定义了选项，value属性指定了选项的值。


```html
    <option value="japan">日本</option>
</select><br><br>
```


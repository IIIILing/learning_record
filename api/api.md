# API

## cookie

cookie是浏览器一种本地储存的方式，可以用来保存用户信息，比如用户名、密码、购物车、浏览记录等。

特点：

1. 保存在浏览器上，不参与到服务器的通信过程。
2. 大小限制为4KB左右。
3. 生命周期为浏览器会话期间，关闭浏览器则失效。

cookie的属性：

1. name：cookie的名称。
2. value：cookie的值。
在请求中以键值对的形式出现，形式为

```
Cookie: <name>=<value>; <name>=<value>;...
```

生命周期：

1. Permanent cookie：
设置Expires或Max-Age属性，
前者是绝对时间的形式，后者是设置时间+offset的形式，同时设置以maxage为准

Max-Age=0：删除cookie
Max-Age=n：n秒后过期
Max-Age=复数的时候，立即删除cookie

Expires=date：date到期时间，到期后删除cookie
2. Sessioncookie：设置过期时间后，cookie在浏览器关闭后失效。

注意：

* 同一域名下，不同路径的cookie可以共享，不同域名下，cookie不共享。
* cookie的作用域是路径，不同路径的cookie互不影响。
* cookie的大小限制为4KB左右，过多的cookie会影响性能。
* cookie的安全性依赖于加密传输。

## 限制访问

cookie只是存在于客户端本地的一段文本信息，本身十分不安全，为了提高cookie的安全性，可以采用以下方式限制访问：

1. 设置HttpOnly属性：

一般来说，cookie是通过http请求和设置的，在一个请求头中携带Header

Set-Cookie就让浏览器自动设置好cookie，已经设置过的cookie会被写到在cookie中发送/返回

这个过程管理全部由浏览器完成，但是前端也可以主动访问并设置cookie，比如js可以通过document访问这个页面

浏览器提供httpOnly属性，可以防止js访问cookie，这样可以防止cookie被盗用，但是也会带来一些限制，比如不能通过js设置cookie的domain和path属性，不能设置cookie的过期时间等。

```
Set-Cookie: name=value; HttpOnly
```

但是这样并不能完全防止js访问cookie，因为js可以直接通过document.cookie访问到cookie，所以还需要配合其他方式来限制访问。

## cookie的作用范围

几乎所有的网页都使用了cookie，浏览器需要区分不同网站设置的cookie

Domian和Path属性都可以限制cookie所属的网站，浏览器只会讲数条cookie发送个符合限制的网站的请求中。

domain限制了cookie所属的域名，浏览器会默认匹配一下的所有的子域名，例如这是了domain=example.com，那么浏览器会把example.com、www.example.com、mail.example.com等都匹配到。

如果不限制domain属性。那么浏览器会将请求的target作为domain属性，并且不会匹配子域名，所以不主动设置domain，对cookie的使用反而更加严格

```
Set-Cookie: name=value; Domain=example.com; Path=/
```

path限制了cookie所属的路径，不设置path路线，则默认为/。
path不论是否主动设置，都可以匹配到所有的子路径

我们主导可以有name重复的cookie，浏览器以domain+path来设置cookie的作用范围，在一个范围内（也就是domain和path的字面量相同）的那么是唯一的，但是不同的范围内，可以有重复的cookie

## 安全性

cookie的安全性依赖于加密传输，但是由于cookie本身的不安全性，所以cookie的安全性也不完全可靠。

* 加密传输：

cookie的传输过程是明文传输，所以需要加密传输，比如https。

* 防止跨站请求伪造（CSRF）攻击：

CSRF攻击是指攻击者通过伪装成受害者的浏览器，向网站发送恶意请求，从而盗取用户信息，比如银行转账

可能是这样发生的，我们在网站A.com上获取了用户的cookie，西施如果网站B.com向A发送了一条请求，其符合我们之前的所有的限制条件（范围限制），所以就会带着该cookie来进行秦秋访问，如果B.com利用这一点向A发送恶意请求，那么就可能盗取用户信息。

简单介绍跨域和跨站的区别

### 站site和域domain

站site的概念，一般由域名来区别
一般的域名服务商售卖xxx.com.cn这样的二级域名，所以我们将二级域名相同的网站成为same site，二级域名不同网站的二级域名成为cross site

域origin的概念，一般由协议+域名+端口号来区别，比如https://www.example.com:8080，只有两个网站的schema、host和port都相同，那么他们才是同一个域。

如果我们假设*同源网站*一般属于同一所有者，那么基本上统战之内不会发生上述攻击，并且可能期望共享cookie，因此浏览器对cookie做了一个site级别的限制

samesite属性分不同的级别，strict、lax、none，strict是默认值，lax和none是非严格限制，可以共享cookie，但是不能跨域，strict是严格限制，不能共享cookie，不能跨域，任何cookie都不会被懈怠，意思是说从A.com向B.com发送请求是不会携带任何cookie的

这样非常安全但是会很不方便

比如我们分享的是一个github链接，但是跳转之后用户发现自己是未登录状态，必须重新刷新发送cookie才能刷新出登录内容

因此就需要lax模式来将一部分秦秋从限制中移除，其中就有<a>标识，这样跳转链接中就不会因为跨站而被限制cookie

none则是完全不进行samesite限制，为了基本的安全保障，只设置了secure
(通过https传输)的cookie可以被设置成samesite=none，这样就可以跨域共享cookie了，但是也会带来一些安全问题，比如cookie被窃取，所以一般不建议使用none模式

具体的浏览器怎么处理secure其扭曲就不一定，Safari会直接将cookie设置成strict，Chrome和Firefox则是默认的lax模式，但是都可以设置secure属性来加密传输

### 同源策略

同源策略是浏览器的安全策略，限制了不同源的文档或脚本如何进行交互。

同源策略限制了不同源的文档或脚本不能读取对方的cookie，防止CSRF攻击。

同源策略是浏览器的一种安全机制，它是为了防止跨站请求伪造（Cross-site Request Forgery，CSRF）攻击而提出的。

防止CSRF攻击的方法：

1. 验证码：

验证码是一种常用的防止CSRF攻击的方法，验证码是由网站生成的随机字符，用户需要填写验证码才能提交表单。

2. 同源策略：

同源策略是浏览器的安全策略，限制了不同源的文档或脚本如何进行交互。

同源策略限制了不同源的文档或脚本不能读取对方的cookie，防止CSRF攻击。

* 限制cookie的使用：

除了上面提到的限制访问，还可以设置一些限制，比如设置HttpOnly属性，设置过期时间，设置作用范围等。

设置HttpOnly属性，可以防止js访问cookie，设置过期时间，可以防止cookie过期，设置作用范围可以限制cookie的使用范围。    

## 参考

[https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Cookies](https://developer.mozilla.org/zh-CN/docs/Web/HTTP/Cookies)  
[https://www.ruanyifeng.com/blog/2019/09/cookie-and-session.html](https://www.ruanyifeng.com/blog/2019/09/cookie-and-session.html)  
[https://www.cnblogs.com/liu-yao/p/10472282.html](https://www.cnblogs.com/liu-yao/p/10472282.html)  
[https://www.jianshu.com/p/a3d57d5d5d9d](https://www.jianshu.com/p/a3d57d5d5d9d)  

## CORS

跨域资源共享（Cross-Origin Resource Sharing，CORS）是一种机制，它使用额外的HTTP头来告诉浏览器，让运行在一个 origin (domain) 上的Web应用被允许访问来自不同源服务器上的指定的资源。

浏览器内有很多内置资源，比如页面 dom, localStorage, cookie 等等等等。如果让任何网站都能访问这些资源是很危险的。​
我们之前已经说明过跨站 cookie 共享可能产生的 CSRF 问题。相似的还有 XFS，这是一种因为共享 dom 产生的问题，攻击者可以用 inline frame (常见用途是页面内嵌其他网页，比如嵌一个地图) 伪造成一个其他的网页，并且访问目标网站的 dom，之后攻击者就可以监听到目标网站的几乎所有动作。如果目标网站是一个银行网站，就有可能被监听到密码之类的信息。

CORS 即是为了应对这种问题。CORS 可以限定一个请求的来源和可以访问的资源。上面说的 CSRF、XFS 等等问题，可以通过 CORS，从服务器端限制请求来源，直接拒绝来源不明的请求，从而免去大多数攻击风险。​
​
严谨来说，是浏览器限制了跨域请求，CORS 不是 “限制” 的规则，反而是在限制下进行 “共享” 的规则。​

## 实现流程
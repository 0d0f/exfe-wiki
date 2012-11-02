JavaScript编程规范（Ver1.0）

Product documentation
2012-03-13

　　*一、总则：*

　　Any violation to the guide is allowed if it enhances readability.
　　因为了提高代码可读性而违反本编程规范的行为都是被允许的。

　　下面这段话摘自《Code Conventions for the JavaScript Programming Language》，我认为说得非常好，拿来做为总则吧，本规范除符合EXFE私有JS架构部分外，其它部分基本来自对这篇文章的摘要及整理。http://javascript.crockford.com/code.html

软件的长期价值直接源于其编码质量。在它的整个生命周期里，一个程序可能会被许多人阅读或修改。如果一个程序可以清晰的展现出它的结构和特征，那就能减少在以后对其进行修改时出错的可能性。
编程规范可以帮助程序员们增加程序的健壮性。所有的 JavaScript 代码都是暴露给公众的。所以我们更应该保证其质量。保持整洁很重要。
　　*二、JavaScript的文件：*
　　1、除非针对特定的需求，大部分的JavaScript 程序应独立保存在独立的JS文件中。
　　2、JavaScript 代码不应该被包含在 HTML 文件中，除非这是段特定只属于此部分的代码。在 HTML 中的JavaScript代码会明显增加文件大小，而且也不能对其进行缓存和压缩。
　　3、<script src=filename.js>应尽量放到 body 的最后面。这样可以减少因为载入脚本而造成其他页面内容载入也被延迟的问题。

　　*三、缩进：*
　　缩百单位为四个空格，应尽量避免使用Tab来缩进。

　　*四、注释：*
　　为了增强代码的可读性以及可维护性，鼓励并要求尽量多写注释。

 /*
     * Get the cookie according to the given name
     * @name, the name of the cookie
     * @return Cookie value
     */
    util.getCookie = function(name) {
        var arr = document.cookie.match(new RegExp("(^| )"+name+"=([^;]*)(;|$)"));
        if(arr != null){ //if cookie exists
            return unescape(arr[2]);
        }
        return null;
    };
　　*五、变量声明：*
　　1、将变量声明语句放在函数的前面。
　　2、最好把每个变量的声明语句单独放到一行，并加上注释说明。
　　3、尽量减少全局变量的使用，不要让局部变量覆盖全局变量。

var headElementObject = document.getElementsByTagName('head')[0];
　　*六、函数声明：*
　　1、所有的函数在使用前都要进行声明。
　　2、如果函数是匿名函数,则在function和“(”(左括号)之间应有一个空格。如果省略了空格，可能会让人感觉函数名叫作 function。

　　*七、命名规则：*
　　1、变量名应由26个大小写字母(A..Z,a..z),10个数字(0..9),和_(下划线)组成。避免使用国际化字符(如中文)
　　2、不要把_(下划线)作为变量名的第一个字符。它有时用来表示私有变量,但实际上JavaScript并没提供私有变量的功能。如果私有变量很重要, 那么使用私有成员的形式。应避免使用这种容易让人误解的命名习惯。
　　3、大多数的变量名和方法命应以小写字母开头。
　　4、必须与new共同使用的构造函数名应以大写字母开头。当new被省略时JavaScript不会有任何编译错误或运行错误抛出。忘记加new时会让不好的事情发生(比如被当成一般的函数)，所以大写构造函数名是我们来尽量避免这种情况发生的唯一办法。
　　5、全局变量应该全部大写。（JavaScript没有宏或者常量，所以不会因此造成误会）
　　6、所有的模块应该符合0d0f命名空间规则。如/apps/CrossEdit.js，则应该为它创建一个命名空间：odof.apps.cross.edit。

var moduleNameSpace = "odof.apps.cross.edit";
var ns = odof.util.initNameSpace(moduleNameSpace);

//调用方法使用实例：
odof.apps.cross.edit.postData();
　　*八、建议：*
　　1、使用{}代替new Object()，使用[]代替new Array()。
　　2、避免使用“,”(逗号)操作符，除非在特定的for 语句的控制部分。(不包括那些被用在对象定义、数组定义、var语句、和参数列表中的逗号分隔符。)
　　3、在JavaScript中块没有域。只有函数有域。不要使用块，除非在复合语句中。
　　4、使用===和!==操作符会相对好点。==和!=操作符会进行类型强制转换。 特别是，不要将==用于与错值比较（false/null/undefined/“”/0/NaN）。
　　5、eval是JavaScript中最容易被滥用的方法。避免使用它。eval有别名。不要使用Function构造器。不要给setTimeout或者setInterval传递字符串参数。

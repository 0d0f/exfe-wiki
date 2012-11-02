EXFE用户登录部分技术文档

Product documentation
2012-03-13

前言：由于登录部分是目前为止绑定事件最多，逻辑也相对比较复杂的部分，为了后续维护的方便，写下此文档。

一、流程图（略，见产品文档 #1AM72# ）

二、技术上涉及到的文件：
　　1、/static/js/user/UserStatus.js（前端逻辑控制文件，命名空间：odof.user.status）
　　2、/static/js/user/UserIdentification.js（前端DOM控制文件，命名空间：odof.user.identification）
　　3、 /static/js/exlibs/ExDialog.js（前端弹出对话框控制文件，非重点。odof.exlibs.ExDialog）
　　4、/controllers/SActions.php（服务器端逻辑控制文件）

三、前端逻辑：

　　1、检查是否登录：
　　当前端页面加载完成之后，JS会去检查用户是否登录，若已经登录则直接显示用户于页面的右上角。若没有登录，则右上角显示Sign in按钮并且绑定弹出登录框事件，当用户点击时，生成登录框并且弹出（见本节第二部分：用户登录及注册操作）。

jQuery(document).ready(function(){
    odof.user.status.checkUserLogin();
});
　　调用checkUserLogin()方法进行是否登录检查时，URL被转发到/s/checkUserLogin即SActions的doCheckUserLogin方法中，服务器接收到请求返回JSON串（如下）：

{ "cross_num" : 7,
  "crosses" : [{ "begin_at" : "2011-11-18 10:00:00",
        "id" : "q1i",
        "sort" : "upcoming",
        "timestamp" : 1321581600,
        "title" : "Meet handaoliang" 
      }],
  "user_avatar" : "c09bb8a95c3346f8117fa88ccfcd5b2a.jpg",
  "user_name" : "handaoliang",
  "user_status" : 1
}
　　若成功返回，则执行：odof.user.status.showLoginStatus()，将DOM元素的控制权交给showLoginStatus方法。同时检查是否有回调，如果前端调用时设置了回调，则执行回调函数。

　　2、用户登录及注册操作：
　　当用户处于未登录状态时，showLoginStatus生成Sign in按钮并且执行绑定，当JavaScript事件检测到用户点击Sign in按钮，即执行 odof.user.status.doShowLoginDialog()方法，调用identification的showdialog()方法，生成登录框的DOM（String）。考虑到适用不同的环境及需求，showdialog定义了三个参数：dialogBoxID, callBackFunc, userIdentity，其中：
　　dialogBoxID：对话框ID，如果存在，则会把对话框放在该元素中。否则以弹窗的形式呈现。
　　callBackFunc：回调函数，如果存在，则会在检测用户是否登录之后调用。
　　userIdentity：用户的identity，如果存在，则需要检测当前identity是否存在。

　　登录框调用odof.user.identification.showdialog生成，showdialog的参数reg表示是初始化成注册框。代码示例如下：

        var html = odof.user.identification.showdialog("reg");
        if(typeof callBackFunc != "undefined"){
            ns.callBackFunc = callBackFunc;
        }       

        if(typeof dialogBoxID != "undefined" && typeof dialogBoxID == "string"){
            document.getElementById(dialogBoxID).innerHTML = html;
        }else{              
            odof.exlibs.ExDialog.initialize("identification", html);
            var dialogBoxID = "identification_dialog";
        }
　　当登录框生成之后，需要绑定一系列事实，以实现登录框的交互操作。其中包括检测上一次是否登录成功，如果上一次登录成功，则取到上一次登录的identity，显示到identity登录框：

var lastIdentity = odof.util.getCookie('last_identity');
if(lastIdentity){
    ......
}
　　如果传入了identity，那么要检测是注册还是登录。

if(typeof userIdentity != "undefined" && userIdentity != ""){
    odof.user.identification.identityInputBoxActions(userIdentity);
}
　　identity及password输入框的事件，通过odof.user.identification.bindDialogEvent方法来绑定，其中，identity输入框绑定onkeyup事件，password输入框绑定onfocus事件。在 identityInputBoxActions方法中，会根据用户的输入用Ajax去服务器端检测当前输入的identity是否存在，存在与不存在分别对应于登录和注册操作。

jQuery('#identity').keyup(function() {
    ns.identityInputBoxActions();
});
jQuery('#identification_pwd').focus(function() {
    ns.identityInputBoxActions();
});
　　当用户提交当前Form时，通过odof.user.identification.bindDialogEvent方法绑定的onSubmit事件会去检查当前输入的identity/password/display name是否有效，如果有效，则进行相应的与服务器端的交互操作，无效则显示警告。

jQuery('#identificationform').submit(function() {
      ......
}
　　3、用户重置密码操作：
　　针对不同的需求，用户重置密码的操作可能会被要求显示不同的对话框，加上找回密码操作与其它部分无十分密切的关联操作的特性，因此与注册登录窗口一样，这一部分的代码单独生成，开发人员通过调用 odof.user.status.doShowResetPwdDialog()可生成重置密码窗口。
　　doShowResetPwdDialog有两个参数：
　　resetPwdCID：重置密码对话框的ContainerID，如果不存在，则弹框。
　　actions：操作类型，允许的参数为resetpwd/setpwd，默认为resetpwd，其中resetpwd是正常的重置密码流程，setpwd则是针对Cross页面，当用户第一次点击邀请的链接进来时使用，此时需要传入cross_id以及cross_token，以决定能否执行更改密码操作。

if(typeof actions == "undefined"){
    actions = "resetpwd";
}

var postData = {
    jrand:Math.round(Math.random()*10000000000),
    u_pwd:userPassword,
    u_dname:userDisplayName,
    u_token:userToken
};
if(actions == "setpwd"){
    postData = {
        jrand:Math.round(Math.random()*10000000000),
        u_pwd:userPassword,
        u_dname:userDisplayName,
        c_id:cross_id,
        c_token:token
    };
}
jQuery.ajax({
    type: "POST",
    url: site_url+"/s/resetPassword?act="+actions
    ......
});
　　当然actions也决定了返回的链接，当actions为setpwd时，返回的是Cross页面，否则则跳转到Profile页面。

if(actions == "setpwd") {
    window.location.href="/!"+JSONData.cross_id;
} else{
    window.location.href="/s/profile";
}
　　4、发送验证邮件窗口：
　　通过odof.user.status.doShowVerificationDialog显示发送验证邮件窗口，同样，这个窗口可以写到页面上，也可以以弹出的窗口显示，这取决于是否传入一个dialogContainerID，如果传入了，则显示在页面，否则以弹窗的方式显示。同时需要传入用户的identity用以显示到页面上。发送邮件的的对话框也是通过odof.user.identification.showdialog()方法生成。

　　5、发送激邮件和验证邮件：
　　由于发送邮件在前端的操作是一样的，区分只在于后端的动作，因此前端JavaScript中写成了一个方法即：odof.user.status..doSendEmail()，前端开发只要传入identity以及actions即可。

ns.doSendEmail = function(userIdentity, doActions){
    var actionURI = site_url+"/s/sendActiveEmail";
    if(typeof doActions != "undefined" && doActions == 'verification'){
        actionURI = site_url+"/s/SendVerification";
    }
    ......
}

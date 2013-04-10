# iOS Developer: Certificates, Identifiers & Profiles
##概述
iOS开发采用证书管理，凡是注册帐号并在有效期内，都可以申请证书。    
[管理网站入口](https://developer.apple.com/account/overview.action) 

这里涉及到几个概念：证书(Certificate)、标示(Identifier)、设备(Devices)和Provisioning Profile。

###证书(Certificate)
证书是一对公私钥匙，根据用途分为iOS开发证书、iOS部署证书、iOS APNs开发证书和iOS APNs部署证书。

证书申请方式是由本地工具keychain产生请求文件CertificateSigningRequest.certSigningRequest，将这个文件提交到管理网站，经过team批准之后，生成对应的证书，包含签过名公钥。下载证书并导入回keychain。由于申请的时候私钥和对应信息已经保存在本地，因此导入后公钥和私钥会自动配对显示在keychain的证书栏目里面。

要注意：
服务器上下载的只是公钥，私钥在请求的机器上。因此更换机器／用户帐号应当导出全部证书（包含私钥）进行迁移，仅有公钥无法正常使用。
如果证书（只有公钥）已经存在于keychain里，这时导入证书（公钥＋私钥）会失败，删除原有的证书（只有公钥）再导入即可。

原则上team的每个成员都有一个自己的证书，这样就可以在真机上调试。
不同的证书应当用不同的请求文件请求，以避免有相同的私钥。

###标示(Identifier)
标示用来区分app，不同app应该有不同的标示。在同一台手机上，若已经存在相同标示的app会被按照替换升级的方式而不是全新安装。
在开发的时候，标示也同时被用来匹配证书的，因此更改app标示会导致可用的证书出现变化。
xcode也会帮忙自动管理一个用*通配的标示。

###设备(Device)
设备就是iOS开发、测试设备的串号，可以通过iTunes的界面获取，也可以在连接手机后，xcode organizer来直接添加为开发机器。

###Provisioning Profile
翻译没有想好，这个profile的作用是：指定哪些人（证书）、哪些机器允许参与开发和测试（真机运行），并且限制了对应的app（Identifier）。

这里有几点延伸
当人员调整、机器增减，都会影响profile，因此这个profile会经常更新。
证书（只有公钥）和Profile可以通过xcode organizer进行同步，因此大部分时候不需要单独下载，更新后刷新一下即可。
结合内置的标示和证书信息，可以在项目中根据项目里面的标示选择匹配的证书。
为了开发方便，xcode还会产生一个包含通配标示的Profile，方便开发人员临时增加项目调试代码，因此自建的开发Profile应当包含项目具体标示而不是通配标示

## 查找问题
这篇[SO回答](http://stackoverflow.com/questions/8424017/xcode-could-not-find-a-valid-private-key-certificate-pair-for-this-profile-in-yo)包含的7个步骤保证了能够重设完整的环境，结合上面的解释来自己解决问题：


1. Delete your Certificates: Open the Application called Keychain Access on your Mac (You can hit the keys command + space bar on your keyboard to bring Spotlight and type Keychain Access to launch it). Then select login on the upper left list and Certificates on the lower left list, you will delete only the Certificates starting with the words "iPhone Developer" or "iPhone Distribution".

2. You need to revoke the old certificates by logging into your Apple iOS Developer's account and going to the Provisioning Portal and then to the Certificates option on the left menu. Then locate your Developer Certificate and click on the link located at the right that reads "Revoke".

3. Go back to the Keychain Access Application on you Mac, click on the menu bar the following menus: "Keychain Access" -> "Certificate Assistant" -> "Request a Certificate from a Certificate Authority". Just enter you email if needed and modify the option that says "Request is:" selecting the option "save to disk"... a dialog will ask you where do you want to save a CSR file wich is normally called "CertificateSigningRequest.certSigningRequest".

4. Go back to the online Provision Portal and create a new Certificate uploading the file you just generated on the same option where your old Certificates were before.

5. After a minute or so... you will see under the Certificates list that you can now Download you new certificate and that you can also download a WWDR intermediate certificate (See the links under the certificate list). Download them and give them to your Keychain Access by double-clicking them.

6. You will have to go to the Provisioning Portal menu option called Provisioning where you will see all your App's Development Provisioning Profiles. You will have to click the link "Edit"->"Modify" at the right and verify that the Certificate is checked.

7. Finally, just close "XCode 4". When you re-open it, go to the menu "Window" -> "Organizer". Because the Organizer reads the certificates from you keychain, they should be there already. Next time you plug your devices just click on Provisioning and make sure the old certificates are gone and the new certificate is on.

##目前项目的遗留问题
* 发布证书私钥和dm的开发证书私钥相同    
  造成问题：dm的开发用户会被自动激活，违反每人使用自己证书的原则。    
  解决办法：开发用的Provisioning Profile应当排除dm。

* 项目的证书指定选择    
  造成问题：不同人工作环境的证书不同，因此工程文件会互相冲突，导致反复提交。   
  解决办法：通过Provisioning Profile的正确配置，工程选自动选择，让xcode自己选择对应的证书进行操作。    
  
## 迁移
方法1 从xcode Organizer的Teams中导出全部证书（含私钥），导入到新机器后，点右下刷新，用apple id登陆后，会得到最新的Provisioning Profile。    
方法2 到keychain里面选择对应的证书导出，到新机器上逐一导入。这里需要注意的是，只需要导出带私钥的证书，仅有公钥的证书可以通过xcode organizer刷新的方式取回。
BOT流程
=======

Email
-----

 - 邮件发到x@exfe.com

 	- 邮件含有text/calendar的ics附件

 	 	- ics的UID已经有对应的cross id

 	 		根据ics文件内容更新对应的cross信息，邮件内正文作为conversation发送。邮件全文保存到s3，并将连接附到conversation的内容。

 	 	- ics的UID没有对应的cross id

 	 		根据ics文件内容创建新的cross，邮件正文附加到description后面。邮件全文保存到s3，并将连接附到description。

 	- 邮件不包含text/calendar的ics附件

 	 	将邮件的subject作为title，正文作为description，所有邮件地址（to，from，cc里除了x@exfe.com的地址）作为参与者，创建cross。

 - 邮件发到x+ennnn@exfe.com/x+cnnnn@exfe.com/x+nnnn@exfe.com

 	- nnnn为已经存在的exfee id（ennnn）或者cross id（cnnnn/nnnn）

 		邮件内正文作为conversation发送。邮件全文保存到s3，并将连接附到conversation的内容。

 	- nnnn无效（不是有效的exfee id或者cross id）

 		发送帮助邮件

 - 其余情况

 	发送帮助邮件
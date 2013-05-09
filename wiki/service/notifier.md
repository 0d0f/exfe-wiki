# 通知服务

## 说明

拼合通知用的文字，并下发给recipient。

假设service架设在127.0.0.1的23333端口。

 - cross相关服务

    - 邀请

        接口地址：

            http://127.0.0.1:23333/v3/notifier/cross/invitation

        POST内容：

            {
                "to": {...}, // recipient 对象，要发送给的 recipient
                "cross": {...}, // cross 对象，被发送者所在 cross
                "by": {...}, // identity 对象，邀请触发者
            }
 
    - 摘要

        接口地址：

            http://127.0.0.1:23333/v3/notifier/cross/digest

        POST内容：

            [{
                "to": {...}, // recipient 对象，要发送给的 recipient
                "cross_id": nnn, // cross id，被发送者所在 cross 的 id
                "updated_at": "YYYY-MM-DD HH:MM:SS" // cross 更新的时间
            }, {...}, ... // 同上
            ]

    - 更新
    
        接口地址：

            http://127.0.0.1:23333/v3/notifier/cross/summary

        POST内容：

            [{
                "to": {...}, // recipient 对象，要发送给的 recipient
                "cross": {...}, // cross 对象，被发送者所在 cross 的最新信息
                "old_cross": {...}, // cross 对象，被发送者所在 cross 被更新前的信息
                "by": {...}, // identity 对象，邀请触发者 
            }, {...}, ... // 同上
            ]

 - user相关服务

    - 欢迎
    
        接口地址：

            http://127.0.0.1:23333/v3/notifier/user/welcome

        POST内容：

            {
                "to": {...}, // recipient 对象，要发送给的 recipient
                "need_verify": true/false // 是否要对用户进行验证
            }

    - 验证
    
        接口地址：

            http://127.0.0.1:23333/v3/notifier/user/verify

        POST内容：

            {
                "to": {...}, // recipient 对象，要发送给的 recipient
                "user_name": "..." // 进行操作的用户名
            }

    - 重置密码
    
        接口地址：

            http://127.0.0.1:23333/v3/notifier/user/reset

        POST内容：

            {
                "to": {...}, // recipient 对象，要发送给的 recipient
                "user_name": "..." // 进行操作的用户名
            }

 -  exfee相关服务

    - 对话
    
        接口地址：

            http://127.0.0.1:23333/v3/notifier/exfee/conversation

        POST内容：

            [{
                "to": {...}, // recipient 对象，要发送给的 recipient
                "post": {...}, // post 对象
            }, {...}, ... // 同上
            ]
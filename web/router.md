Web Front-End Route
-------------------

## Routes & Resources

基础规范、约定

### 约定


    Path               Action(#)    Used for

    /posts             index        display a list
    /posts/:id         show         display a item
    /posts/new         new          creating a item
    /posts/:id/edit    edit         editing a item


### index


    /


### sign in 登录


    /signin


### sign out 登出


    /signout


### users


    /users                                      to /users#index                             as /:identity_id

    /users/:identity_id                         to /users/:identity_id#show                 as /:identity_id

    /users/:identity_id/setpassword

    /users/:identity_id/fogotpassword

    /users/:identity_id/preferences

    /users/:identity_id/preferences/edit

    ...


###

### crosses


    /crosses                                    to /crosses#index

    /crosses/new                                to /crosses#new                             as /gather

    /crosses/:cross_id                          to /crosses#show                            as /!cross_id

    /crosses/:cross_id/edit                     to /crosses/:cross_id#edit

    /crosses/:cross_id/widget                   to /crosses/:cross_id/widget#show           as /!cross_id/widget

    /crosses/:cross_id/map

    /crosses/:cross_id/date

    /crosses/:cross_id/routex

    /crosses/:cross_id/pollx

    /crosses/:cross_id/pollx/new

    /crosses/:cross_id/pollx/:poll_id                                                       as /!cross_id/pollx/:poll_id

    /crosses/:cross_id/pollx/:poll_id/edit

    ...

### Go to app


    # 打开app
    /toapp

    # 强制更新本地`user-token`
    /toapp?authenticate


### Wechat


    # about routex
    /wechat/aboutroutex


### invalid


    /invalid


### 404


    /404


### 500


    /500


## Debug Mode

    # enable debug
    ?debug=(on|true)

    # disable debug
    ?debug=(off|false)

## Links
* [Old Routes](https://docs.google.com/a/exfe.com/document/d/1oIaFPUDBgrGyQ1wHXxv3bOAzqVL2K3Xpc3FjDKRLh40/)
* [URI scheme](http://en.wikipedia.org/wiki/URI_scheme)
* [IPhone URL Schemes](http://wiki.akosma.com/IPhone_URL_Schemes)

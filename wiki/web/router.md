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


### sign up 注册


    /signup


### sign in 登录


    /login


### logout 登出


    /logout


### users


    /users                                      to /users#index                             as /:username

    /users/:username                            to /users/:username#show                    as /:username

    /users/:username/setpassword

    /users/:username/fogotpassword

    /users/:username/preferences

    /users/:username/preferences/edit

    ...


###

### crosses


    /crosses                                    to /crosses#index

    /crosses/new                                to /crosses#new                             as /gather

    /crosses/:cross_id                          to /crosses#show                            as /!cross_id

    /crosses/:cross_id/edit                     to /crosses/:cross_id#edit

    /crosses/:cross_id/widgets                  to /crosses/:cross_id/widgets#show          as /!cross_id/widgets

    /crosses/:cross_id/map

    /crosses/:cross_id/date

    /crosses/:cross_id/routex

    /crosses/:cross_id/votex

    /crosses/:cross_id/votex/new

    /crosses/:cross_id/votex/:vote_id                                                       as /!cross_id/vote_id

    /crosses/:cross_id/votex/:vote_id/edit

    ...


### invalid


    /invalid


### 404


    /404


### 500


    /500


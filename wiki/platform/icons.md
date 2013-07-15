# Icons

    author: Leask Huang
    created date: 2013-07-15
    updated date: 2013-07-15


## Map Mark
* endpoint: /v3/icons/mapmark
* QUERY args:
    - content: [str:length <= 2] // OPTIONAL / default: P
    - color: [str: blue | red] // OPTIONAL / default: blue
* returns:
    - 200: [bin:image/png]
    - 404
* example:

    #!bash
    $ http 'http://api.panda.0d0f.com/v3/icons/mapmark'
    / - \
    | P |
     \ /
    $ http 'http://api.panda.0d0f.com/v3/icons/mapmark?content=喵&color=red'
    / - \
    | 喵|
     \ /

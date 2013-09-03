# App Folder Notes

## 结构

    App Sandbox
    -- <AppName>.app
    -- Documents
       -- Inbox
          -- ...
       -- ...
    -- Library
       -- Application Support
          -- FlurryFiles
             -- ...
          -- users
             -- default.exfe
                -- user.sqlite
             -- user_233.exfe
                -- exfeInfo.plist
                -- user.sqlite
                -- ...
       -- Caches
          -- <BundleIdentifier>
             -- exfe.sqlite
          -- DataDiskCache
             -- ...
          -- Snapshots
             -- ...
          -- images
             -- ...
       -- Cookies
          -- ...
       -- FlurryFiles
          -- ...
       -- Preferences
          -- <BundleIdentifier>.plist 
          -- com.apple.PeoplePicker.plist
          -- ...
    -- tmp
       -- ...

## 图片缓存
* Library/Caches/images/

## 应用数据
* Library/Preferences/&lt;BundleIdentifier>.plist
* Library/Application Support/&lt;BundleIdentifier>/
* Library/Application Support/&lt;BundleIdentifier>/exfe.sqlite

应用数据包含用户未登录的时候需要的配置数据、有效时间长于用户登陆登出的数据。
比如push token、曾经的登陆过的帐号等。

## 用户数据
* Library/Application Support/users/user\_&lt;ID>.exfe/exfeInfo.plist
* Library/Application Support/users/user\_&lt;ID>.exfe/user.sqlite

如果user.plist文件被删除了，或者某个字段符合某个条件，那么这个用户的数据是可以删除的

## 作废用户数据：
* 删除exfeInfo.plist
* 下次启动的时候删除不包含“exfeInfo.plist”的Library/Application Support/users/*.exfe 所有文件夹
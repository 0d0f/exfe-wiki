Mnemosyne 记忆女神之青春
------------------------
> author: cfd   
> date  : 2013-01-18T19:09:42 UTC+0800

## 前端规划

### 功能

#### Data Controller
  * `DataController` Class
  * Struct
  * APIs
    - `getPhotos()` 获取图片数据

#### Rect 排版形状 (第一阶段，只支持矩形)
  * `Rect` Class
  * Struct

        :::javascript
        {
          "x": int,
          "y": int,
          "width": int,
          "height": int,
          "stroke": string,
          "stroke-width": int
        }

  * Note: 遵循 SVG 定义,描述

#### G Group Container
  * `G` Class
  * Struct

        :::javascript
        {
          "x": int,
          "y": int,
          "width": int,
          "height": int

        }

#### Layout Box 对 Box 进行排版
  * `LayoutBox` Class
  * Struct

        :::javascript
        {
        }

  * APIs

#### Layout Engine 排版引擎
  * `Typesetting` Class
  * Struct

        :::javascript
        {
          "layouts": {
            "1": [],
            "2": [],
            "3": [],
            "4": [],
            "5": []
            //...
          }
        }


  * APIs
    - `typeset()` 排版
    - `order()` 排序
    - `random()` 生产随机数
    - `getLayout(photo_numbers)` 根据图片数, 随机获取图片排版结构

#### Smart Resize

#### Photo Item 图片对象
  * `PhotoItem` Class
  * Struct

        :::javascript
        {}

  * APIs
    - `generateHTML()` 生产 HTML 结构
    - `addAttrs()` 给 Photo-Item DOM 添加属性
    - `removeAttrs()` 删除 Photo-Item DOM 属性


## Roadmap 开发周期



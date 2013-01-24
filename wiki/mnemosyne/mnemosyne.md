Mnemosyne 记忆女神之青春
------------------------
> author: cfd   
> date  : 2013-01-18T19:09:42 UTC+0800

## 结构模型
  - Data Controller 负责数据交互
    * get photos

  - Layout Engine 排版引擎，负责对数据进行排版
    * Typesetting 排版
    * models
        * PhotoItem 图片
        * Layout 模板
        * Rect 矩形
        * G 群组

  - View 视图
    * 负责对排版内容，进行渲染
    * events bind
    * smart resize 智能检测 window size

## Roadmap 开发周期
  * 2013-01-21 ~ 2013-01-25
    1. Rect (矩形) 结构、方法, 第一阶段只支持矩形
    2. G (群组) 结构、方法
    3. shapeFactory 简单工厂模式
    4. layout 结构定义
    5. Typesetting 排版模型、功能，第一阶段只实现简单排版方法, 只支持二级排版
    6. html + css 结构
    7. 模拟数据，简单 Demo

  * 2013-01-27 ~ 2013-02-01
    1. 监听 window.resize，重新排版内容
    2. events 绑定，第一阶段，只支持 Desktop
    3. 图片浏览交互
    4. navbar 导航栏
    5. 根据设计稿，修改 html css 结构

  * 2013-02-4 ~ 2013-02-07
    2. 数据交互
    3. 添加身份，分享图片
    4. 根据 source, identity, etc... 分类筛选

  * 2013-02-18 ~ 2013-02-22
    1. 适配 iPad
    2. Mobile events 绑定
    3. 提升体验, 第一阶段不追究特酷效果

  * 2013-02-25 ~ 2013-03-01
    1. 测试 优化


## 前端规划

### 功能

#### Data Controller
  * `DataController` Object
  * Struct
  * API
    - `getPhotos()` 获取图片数据

#### Layout Engine 排版引擎
  * `Typesetting` Class
  * Struct
  * API
    - `typeset()` 排版
    - `sort()` 排序
    - `random()` 生产随机数
    - `getLayout(photo_numbers)` 根据图片数, 随机获取图片排版结构


##### Rect 排版形状 (第一阶段，只支持矩形)
  * `Rect` Class
  * Struct

        :::javascript
        {
          "id": int,
          "type": "Rect",
          "x": [int/floa],
          "y": [int/float],
          "width": [int/float],
          "height": [int/float],
        }

  * Note: 遵循 SVG rect-tag 定义,描述

##### cellFactory
  * `cellFactory` 简单工厂模式

##### G Group Container
  * `G` Class, 对图形进行分组
  * Struct

        :::javascript
        {
          "id": int,
          "type": "G",
          "group_name": "xyz",
          "cells": [
            { "type": "Rect" ... },
            { "type": "Circle" ... }
            ...
           ]
           ...
        }

        :::javascript
        // sample:
        {
          "id" 233,
          "type": "G",
          "group_name": "233喵",
          "cells": [
            { "type": "Rect", "x": 0, "y": 0, "width": 1, "height": 1 },
            { "type": "Circle", "cx": 50, "cy": 50, "r": 30 }
          ]
        }

  * API
    - `append()` 添加 element
  * Note: 遵循 SVG g-tag 定义,描述


#### View

##### Smart Resize

##### Photo Item 图片对象
  * `PhotoItem` Class
  * Struct

        :::javascript
        {}

  * API
    - `generateHTML()` 生产 HTML 结构
    - `addAttrs()` 给 Photo-Item DOM 添加属性
    - `removeAttrs()` 删除 Photo-Item DOM 属性

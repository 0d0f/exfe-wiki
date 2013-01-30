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

  * 2013-01-31 ~ 2013-02-08
    1. GUI / UX
      - 墙样式调整
      - 大图入场动画
      - 大图出场动画
      - 大图切换动画

    2. Optimization
      - HTML + CSS 结构
      - 排版引擎数据结构，排版引擎算法，二维 => 一维

    3. Others
      - 初始Group模板

  * 2013-02-18 ~ 2013-02-22
    * Features
      - API数据层
      - 嵌入·X·页
      - 事件绑定调控

  * 2013-02-25 ~ 2013-03-01
    * Features
      - 1 地图
      - 2 模板最佳适应尺寸
      - 3 Like/Emotion？

    * GUI / UX
      - 0 启动入场动画
      - 1 Animation 调优
      - 1 Pad重力感应
      - 2 时间线：算法、交互、样式、3D效果

    * Optimization
      - 2 CSS3 3D GPU 加速
      - 2 根据当前所看大图, 滚动背景wall
      - 3 墙边界弹性滚动
      - 3 窗口尺寸缩放时动画流畅

    * Others
      - 1 照片座标定位计算函数

  * Next
      - Cell 后期支持更多属性描述, 圆 多边形等
      - 启用 Worker 处理复杂计算
          - 导航栏数据变化重绘
          - cell属性变化遍历赋值
          - 多组图片分步加载，内存调度
      - 评论
      - 连拍图组展示交互
      - 模板cell样式自定义

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
          "name": "xyz",
          "aspect_ratio": 3 / 4, // `width / height` = 9 / 16 or = .75
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
          "name": "233喵",
          "aspect_ratio": 3 / 4,
          "cells": [
            { "type": "Rect", "x": 0, "y": 0, "width": 1, "height": 1 },
            { "type": "Circle", "cx": .5, "cy": .5, "r": .5 }
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

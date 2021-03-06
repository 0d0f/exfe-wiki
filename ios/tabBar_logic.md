# TabBar 逻辑
tabBar 上的 widget 对应的 tabBarItem 会携带显示信息：default(也属于 visible), visible 或 hidden。

## 展现流程
对于展现 tabBar 会有三种情况：一般流程、跳转进入（cross 本地存在）、跳转进入（cross 本地没有）。

- 对于第一种情况，tabBar 会以 default 作为显示内容；
- 第二种情况，无视要跳转的 widget 对应 tabBarItem  的显示类型，直接认为是 visible；
- 第三种情况，需要现有一个空白的加载状态，加载完后再按照第二种情况的逻辑。

## TabBar 状态
TabBar 存在两种状态：收起、展开

### 收起状态时，可以做的操作：

- tap: 点击后进入展开状态；
- swipe: 滑动后，如果 visible 的 tabBarItem 只有一个，就进入展开状态（草案），大于一个时，会在 visible 的 tabBarItem 间循环跳转(0->1->2->0...)；

### 展开状态时，可以做的操作：

- tap：点击某个 tabBarItem 会选中对应的 viewController；
- pan：如果存在 hidden 的 tabBarItem，那么就可以向左拉出；

## 交互细节 & 可优化内容（草案）

- pan 时拉出的 tabBarItem 不能显示半个；
- 在展开状态时，快速向右 pan 或者 向右 pan 到一定程度（eg. 已经滑入 50％？）时，切换到收起状态；
- 在状态切换时，被选中的 tabBarItem 应该在层次上更考上，浮起，动画结束后，再落下；
- 保持 tabBarItem 顺序不变；

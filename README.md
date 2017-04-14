* # POJ
##  计算几何题目列表
* POJ 1031 Fence 计算视角，要注意角度覆盖大于2*PI的情况
* POJ 1039 Pipe 用叉积判断方向的经典题。枚举两凸点，先计算过这两点能否出左口，若可以再计算最右能到到多远。
* POJ 1066 Treasure Hunt 正方形区域中有n条线段，求从边界到某点最少穿过几条线段。黑书练习题。可BFS，还有更简洁的方法。
* POJ 1070 Deformed Wheel 二维点旋转问题，中间确定旋转位置时用到二分。
* POJ 1092 Farmland 对每个点，将和它相连的边按逆时针排序，这样对每条边可找到相临的下一条边。
* POJ 1106 Transmitters 扫描线问题
* POJ 1113 Wall 凸包入门题
* POJ 1118 Lining Up 判断最多多少2D点共线,和2780 3512遥相呼应
* POJ 1127 Jack Straws 线段相交测试，传递闭包。
* POJ 1133 Stars 带scaling的2D点旋转问题.基本思想是枚举。注意有星座中心对称的情况，要判重
* POJ 1151 Atlantis x方向离散化,y方向扫描线
* POJ 1225 STRICTLY INSCRIBED SIMILAR TRIANGLES 枚举两点所在的边，二分找第三的位置，并判断是否合法。注意：数据中角度有负值
* POJ 1228 Grandpa's Estate n个点是否能唯一确定一个凸包。和凸包边上的点数有关。
* POJ 1259 The Picnic http://hi.baidu.com/xh176233756/blog/item/58fb9f19fac6c04d43a9addd.html
* POJ 1263 Reflections 核心内容是判断有向线段关于某直线的镜像（可取两点算镜像）和直线与圆的交点(方法很多，我是自备模板，囧……)
* POJ 1265 Area 面积(累计叉积和),边上的点(gcd(dx, dy)), 内部的点(peak定理)
* POJ 1266 Cover an Arc 精度题。确定圆心、半径，通过圆弧的两端点和圆的上下左右四个顶点判断覆盖矩形的边界.注:(int)(-1.5) = -1
* POJ 1269 Intersecting Lines 判断斜率和截距，求直线交点
* POJ 1271 Nice Milk 半平面交+dfs,直接枚举哪些边是否蘸复杂度大，dfs快而优美
* POJ 1279 Art Gallery 半平面交入门题
* POJ 1294 Not Too Convex Hull 动态规划，用dp[i][j][k],表示从i逆时针到j用k根皮筋的最小面积,注意for()中加一些范围的优化
* POJ 1319 Pipe Fitters 注意每行只能容纳一根管子时skew的处理方法
* POJ 1347 Triangle 没想到好的方法，硬枚举，情况很多，很头疼
* POJ 1361 JaWs 先算垂直下降的落点，判断是左滑还是右滑，注意精度，WA n多次
* POJ 1371 Tin Cutter 每次从平面上切下一块矩形，求最后平面上有多少洞。离散化+floodfill。
* POJ 1375 Intervals 计算极角，排序，扫描线
* POJ 1379 Run Away 貌似三角剖分，尚不会。可模拟退火水过。
* POJ 1389 Area of Simple Polygons 同1151
* POJ 1408 Fishnet 算出各个交叉点，再一次算面积，没什么要注意的
* POJ 1410 Intersection 有退化情况
* POJ 1418 Viva Confetti 找出哪些点是可见的。可以O(n^3)判断。1.圆周上某一点未被覆盖的圆可见 2.两圆相交且交点未被第三圆遮住时,以上两圆可见。3. 2中交点下面的第一个圆可见。这三种讨论可覆盖所有可见的情况。
* POJ 1428 Hermes' Colony 由于分叉点不一定在给的点上，所以不是简单的最小生成树。三个点时分叉点就是三角形费马点，四个点时分叉点有两个。我的做法是随机调整（传说中的爬山法？）精度问题很费解，不知道随机调整怎么写比较好，试了很多次才AC
* POJ 1434 Fill the Cisterns! 二分高度，判断。
* POJ 1444 Parallelepiped walk dfs模拟走各个面的过程，注意一个面不要走多次。
* POJ 1471 Triangles 这个不算几何题，囧...
* POJ 1473 There's Treasure Everywhere! 模拟即可
* POJ 1474 Video Surveillance 多边形的核是否存在。半平面交。
* POJ 1494 Sunrise 精度极烦人，反三角函数看来很不可靠
* POJ 1499 Supercomputer Selection, The Sequel 将三棱柱拆成一个三棱锥和一个四棱锥求体积，死活不能AC，不知为何（另外题意极痤，强烈BS）
* POJ 1500 Polygonal Puzzle 枚举和各个多边形各个顶点对应时误差有多大。
* POJ 1514 Metal Cutting 8！的枚举
* POJ 1518 Problem Bee 坐标转化
* POJ 1536 Trains
* POJ 1556 The Doors DP
* POJ 1569 Myacm Triangles
* POJ 1584 A Round Peg in a Ground Hole
* POJ 1586 Three Sides Make a Triangle
* POJ 1605 Horse Shoe Scoring
* POJ 1610 Quad Trees
* POJ 1623 Squadtrees
* POJ 1624 This Takes the Cake
* POJ 1645 BSP Trees
* POJ 1654 Area
* POJ 1660 Princess FroG
* POJ 1673 EXOCENTER OF A TRIANGLE
* POJ 1685 Color Tunnels
* POJ 1687 Buggy Sat
* POJ 1688 Dolphin Pool
* POJ 1693 Counting Rectangles
* POJ 1696 Space Ant
* POJ 1727 Advanced Causal Measurements (ACM)
* POJ 1755 三维线性规划的可行性判定。可化简为二维的，然后半平面交吧。注意这是将很大的图形映射到很小的区域上。
* POJ 1758 Frontier
* POJ 1765 November Rain
* POJ 1774 Fold Paper Strips
* POJ 1803 Box Art
* POJ 1810 Covering
* POJ 1813 Overlapped Shapes
* POJ 1819 Disks
* POJ 1834 线段处理
* POJ 1843 Shire
* POJ 1851 Map
* POJ 1871 Bullet Hole
* POJ 1873 The Fortified Forest
* POJ 1875 Robot
* POJ 1877 Flooded!
* POJ 1881 Sail Race
* POJ 1899 Farmer Bill's Problem
* POJ 1902 Illumination
* POJ 1912 A highway and the seven dwarfs
* POJ 1921 Paper Cut
* POJ 1927 Area in Triangle
* POJ 1931 Biometrics
* POJ 1937 Balanced Food
* POJ 1939 Diplomatic License
* POJ 1940 Polygon Programming with Ease
* POJ 1956 Pumps and Pipes
* POJ 1971 Parallelogram Counting
* POJ 1981 Circle and Points
* POJ 1982 Water Tank
* POJ 2007 Scrambled Polygon
* POJ 2012 Triangle Cuts
* POJ 2016 Ink Blots
* POJ 2026 As the Crow Flies
* POJ 2031 Building a Space Station MST
* POJ 2036 I Conduit!
* POJ 2043 Area of Polygons
* POJ 2048 Monster Trap
* POJ 2053 Square
* POJ 2066 Minimax Triangulation
* POJ 2069 Super Star
* POJ 2074 Line of Sight
* POJ 2079 Triangle
* POJ 2087 Petanque
* POJ 2098 Ellipse
* POJ 2130 Jogging
* POJ 2149 Inherit the Spheres
* POJ 2150 Crossing Prisms
* POJ 2164 Find the Border
* POJ 2165 Gunman
* POJ 2172 Bricks
* POJ 2177 Ghost Busters
* POJ 2187 Beauty Contest 最远点对。旋转卡壳。
* POJ 2284 That Nice Euler Circuit
* POJ 2318 n条线分一条形区域为n+1个子区域，k个点，求每个区域内有多少点。二分。
* POJ 2398 同2318。数据规模较小。
* POJ 2420 多边形费马点。随机化贪心。
* POJ 2451 很直白的半平面交。注意效率（N<=20000）。
* POJ 2540 猜点，类似猜数字，每次提示更近了还是更远了，怀疑庄家使诈。半平面交判断可行性。
* POJ 2606 同1118。数据规模较小，可O(n^3)枚举。
* POJ 2621 Parallelepiped
* POJ 2622 Convex hull
* POJ 2653 平面上放了n条线段，求没有被其他线段压住的有那些。暴力也要注意题目的细节。
* POJ 2686 Traveling by Stagecoach
* POJ 2687 Earth Observation with a Mobile Robot Team
* POJ 2693 同1981。数据规模很小。
* POJ 2747 Shy Polygons
* POJ 2780 同1118。对偶变换+hash，注意对偶平面上平行线的处理。
* POJ 2826 两线段（看成木板吧）最多能接多少水。注意水是怎么落下的。
* POJ 2839 Convex Hull and Triangle
* POJ 2932 Coneology
* POJ 2954 Triangle
* POJ 3011 Secrets in Shadows
* POJ 3129 How I Wonder What You Are!
* POJ 3130 How I Mathematician Wonder What You Are!
* POJ 3135 Polygons on the Grid
* POJ 3148 平面上每个网格被多边形覆盖的面积。这个应该叫梯形剖分？
* POJ 3304 是否存在一条线段L使所有线段的投影在L上有交集。问题等价于……
* POJ 3334 Connected Gheeves
* POJ 3335 Rotating Scoreboard
* POJ 3347 Kadj Squares
* POJ 3348 凸包面积。模板。
* POJ 3384 Feng Shui
* POJ 3407 Brookebond s'en va en guerre...
* POJ 3410 Split convex polygon
* POJ 3449 几种集合体相交的判断。输入输入格式很恶心。
* POJ 3512 同1118。对偶变换+hash，注意对偶平面上平行线的处理。
* POJ 3525 凸多边形内离边界最远点。二分，半平面交。还有更快的方法。
* POJ 3549 平面上n个圆，不能走出圆从一点走到另一点的最短路。求关键点，建图，求最短路。
* POJ 3608 求两凸包距离。旋转卡壳。
* POJ 3743 一圆被n条直线切成很多份，求其面积最大的一份的面积。算交点，建图，求面积（参考1092）。

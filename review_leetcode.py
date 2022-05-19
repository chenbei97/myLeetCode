'''
Author: chenbei
Date: 2022-05-17 08:24:16
LastEditTime: 2022-05-18 14:13:52
Description: review leetCode
FilePath: \myLeetCode\review_leetcode.py
Signature: A boy without dreams
'''
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# 1.两数之和
def twoSums(nums,target):
    '''
        题目要求找到2个数字之和为target,如果找到就返回索引,输入数组不一定是有序的
        使用哈希表实现,遍历数组,当前数字为num作为key,idx作为val
        如果target-num在哈希表的索引里这就说明存在这样的数字
        那么[idx,hash[target-num]]就是想要的结果
        如果不存在,先把当前的[num,idx]对插入hash,这样可以保证一次遍历
    '''
    n = len(nums)
    hash = {}
    for idx, num in enumerate(nums):
        if target-num in hash:
            return [hash[target-num],idx]
        hash[num] = idx
    return []
# 2.买卖股票I
def sellStocksI(prices):
    '''
        输入的prices[i]代表每一天的价格,要求找到某天买入和后边某天卖出产生的最大利润
        可以设定初始最大利润为0,历史最低价格为inf,然后遍历每个价格
        如果价格低于当前的历史最低价格就更新它,然后用当前的价格减去历史最低价格获得的利润
        和之前能获得的最大利润比较,如果有更大的利润就可以更新最大利润
        遍历数组结束就可以获取历史价格最低点和利润了
    '''
    maxProfit, minPrice = 0, int(1e9)
    for price in prices:
        minPrice = min(minPrice,price)
        maxProfit = max(maxProfit,price-minPrice)
    return maxProfit
# 3.买卖股票II
def sellStocksII(prices):
    '''
        第I题要求只能买一次然后卖出找出最大利润,本题可以多次买入然后多次卖出
        但是要求买入以后只能继续持有或者卖出,任何时候不能持有2只及以上的股票
        允许当天买入并且当天卖出,虽然这样做好像毫无意义
        本题不使用动态规划而使用贪心算法,比较好记思路
        贪心算法就是只要后一天比前一天的价格高就有的赚,那么这部分利润就可以累计
        但是这只是单纯的计算可能的最大利润,事实上也确实是最大利润,但是不反应实际的交易过程
    '''
    maxProfit = 0
    for i in range(len(prices)-1):
        maxProfit += max(0,prices[i+1]-prices[i]) # 注意要有的赚所以和0比较
    return maxProfit
# 4.颜色分类
def colorClassify(colors):
    '''
        输入的数字只有0,1,2,表示3种颜色,要求相同元素相邻且按照0,1,2颜色进行排列
        注意要求原地排序,同时不能使用库的sort函数
        思路是:定义2个索引指针,初始化指向0索引,要求指针指向的元素分别是0和1
        遍历颜色数组,如果遇见了1就换到前边,让p1指针前进,否则遇见了0就换到前边,让p0指针前进
        这样有几种可能:
        1.最开始可能是if语句先执行,这样p1前进后它前边的元素是1,但是p0也暂时指向了这个1元素
        若下次遍历执行的是else语句,即颜色是0的情况,这个0就会被换到p0的位置,那么p1之前的元素变成了0,但是1已经交换出去了
        这个1元素要交换回来,即与此时已前进的p1指针进行交换,然后p1指针再前进1位
        2.也可能先执行的是else语句再执行if语句,先执行else语句0被换到前边后,p0和p1都会前进
        下次无论是继续执行else还是先执行if还是都不执行,不会影响到之前的结果
        3.如果一开始if,else都没执行说明碰到的是2,等待着1.和2.的情况即可,2会被交换出去的,因为p0,p1指针没有移动
    '''
    # 定义2个索引指针,其中p0要求指向元素0,p1指向元素1,初始时暂时都指向0元素
    p0,p1 = 0,0
    for idx in range(len(colors)):
        color = colors[idx] 
        if color == 1: 
            # 如果if语句先执行,1被换到p1的位置
            # 如果else语句先执行,p0之前的元素已变为0,p1也已前进1位,故再执行if语句不会影响之前的元素
            colors[idx],colors[p1] = colors[p1],colors[idx]
            p1 += 1
        elif color == 0:
            # 如果if语句先执行,p1前边的元素已经是1,此时p0<p1,p0指向的元素很可能是1
            # 这样再执行elif语句就会把p0指向的1元素交换出去到idx的位置

            # 如果if语句没有先执行,先执行的else语句,上一轮p0和p1已经前进1位不会对之前元素有影响
            colors[idx],colors[p0] = colors[p0],colors[idx]
            
            # 如果是先if后else的情况,要多一步判断
            if p0<p1: # 此时colors[idx]可能是1,虽然它在p0的前边,但它不应该在p1的后面,所以还要与p1交换
                colors[idx],colors[p1] = colors[p1],colors[idx]
            p1 += 1
            p0 += 1
# 5.k个最近的距离点
def kNearestPoints(points,k):
    # 指定排序方法即可,按照x^2+y^2进行排序
    method = lambda point:point[0]*point[0]+point[1]*point[1]
    points.sort(key=method)
    return points[:k]
# 6.每日温度
def dailyTemperature(nums):
    '''
        要求计算每日温度要过多少天才能升温,如果后面没有更高的温度用0代替
        返回一个数组,每个元素表示当日要过多少天升温
        思路是维护一个记录温度索引的栈,答案列表事先赋予初值0,长度和温度数组相同
        初始时栈为空不满足while循环条件,条件是栈不为空且当前的温度比之前栈顶的温度高
    '''
    ans = [0 for _ in nums]
    idxStack = []
    for idx in range(len(nums)):
        currTemperature = nums[idx]
        while len(idxStack) and currTemperature>nums[idxStack[-1]]:
            lastIdx = idxStack.pop(-1) # 弹出上个栈顶温度对应的索引
            ans[lastIdx] = idx - lastIdx # idx的温度比lastIdx温度高,这个索引差值作为ans[lastIdx]的值
        idxStack.append(idx) # 不满足条件就先入栈
    return ans
# 7.三数之和
def threeSum(nums):
    '''
        找到3个数和为0的所有答案
        可以先将数组排序,然后第1重循环从[0,n-1]遍历,注意如果连续的2个数是相同的就会导致重复
        由于固定的第1个元素first是从0开始,所以first>0时且nums[first]==nums[first-1]时认为重复,跳过循环
        继续,第2重循环也是如此,从[first+1,n-1]遍历,second>first时且nums[second]==nums[second-1]时认为重复,跳过
        第3重循环当然也可以这样做,但是时间复杂度明显高了起来
        
        考虑第1个元素first固定,第2个元素second也固定,第3个元素third在最右侧时此时判断first+second+third与0的关系
        如果大于0,说明满足条件的third只可能出现在左侧,因为数组已经有序,那么third向数组首端前移即可
        如果third退到和second相等说明不存在=0的组合,break即可,如果过程中有这样的组合将其追加进答案列表
        要注意的是:third指针要在第2重循环之前定义,因为固定了first,每轮second=first+1都要更新third为n-1
    '''
    n = len(nums)
    ans = []
    nums.sort()
    for first in range(n):
        if (first > 0) and (nums[first]==nums[first-1]): # first>0是避免first-1越界,和first-1相等意味着重复
            continue
        third = n-1 # 因为随着first不同,second也是不同,third在不同的second中都要重置为n-1
        for second in range(first+1,n): # second=first+1与second=first相等意味着重复
            if (second >first+1) and (nums[second]==nums[second-1]):
                continue
            while (second < third) and (nums[first]+nums[second]+nums[third]>0): # 由于已经有序,third只能减小才可能=0
                third -= 1
            if third == second:
                break  # 本轮second再也找不到合适的third了,break进入下一轮的second,2重循环被终止
            if nums[first]+nums[second]+nums[third] == 0:
                ans.append([nums[first],nums[second],nums[third]])
    return ans
# 8.两数相加
def addTwoNumbers(l1:ListNode,l2:ListNode):
    '''
        2个链表的元素相加,得到一个新的链表可以表示这个相加值
        例如 2->4->3 + 5->6->4 = 342+654=807
        需要注意的是低位元素在链首,高位元素在链尾
        思路:难点在于考虑进位问题和链表长度不同时如何处理,进位要注意的时当前2个节点的求和要对10取除数
        除数去和下一轮的2个节点参与计算,初始进位值为0,链表长度不同时高位只需要原封不动保留即可
        
        使用while遍历,只要任意一个链表的节点不为空就执行,然后取出节点值(也要判断是否为None再取)
        之后计算除数和余数,除数用于下一轮计算,余数作为构建节点的值,构建完新节点后next指针也要向前移动
        l1,l2当然也要继续向前移动,但是要注意因为while的循环条件,l1和l2很有可能已经是None,所以事先判断再取next
    '''
    dumpy = ListNode()
    next = dumpy
    carry = 0 # 初始进位值为0
    while l1 or l2 : # 只要有不为空的节点
        val_1 = l1.val if l1 else 0 # 取出2个值
        val_2 = l2.val if l2 else 0 
        next.next = ListNode((val_1+val_2+carry)%10) # 构建新节点,是2个值+进位之和对10的余数
        carry = (val_1+val_2+carry) // 10 # carry是上一轮的来的进位,初始为0,注意carry先被参与余数运算而不是除数
        next = next.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    # while结束后,carry可能会不为0,如果不为0说明高位进1了
    if carry:
        next.next = ListNode(carry)
    return dumpy.next
# 9.二分查找
def binarySearch(nums,target):
    '''
        要求输入数组事先有序
        然后定义2个指针left,right分别指向开头和结尾,即0和n-1
        取left,right的中间位置mid,如果nums[mid]就是要寻找的target直接返回mid
        如果nums[mid]>target,说明target处于[0,mid-1]之间,让right从n-1变为mid-1
        否则nums[mid]<target,说明target处于[mid+1,n-1]之间,让left从0变为mid+1
        left≠right时循环就继续
    '''
    left,right = 0,len(nums)-1
    while left != right:
        mid = (left+right) // 2
        if nums[mid] == target: 
            return mid
        elif nums[mid] > target: # [0,mid-1]
            right = mid - 1
        else: left = mid + 1 # [mid+1,n-1]
    return -1
# 10.冒泡排序
def bubbleSort(nums):
    '''
        稳定排序,最坏和平均时间复杂度O(n^2),最好时间复杂度O(n)
        原理是两两交换,总是把更大的元素交换到前边
        从第1个元素开始固定,然后这一轮会依次从第2个元素直到最后1个元素与nums[0]进行比较
            只要比nums[0]小就换到前边,本轮结束,nums[0]就已经是最小的元素
        然后从第2个元素开始固定,同理可以让nums[1]是最小的元素
        以此类推,为了避免越界,直到倒数第2个元素固定,只有nums[n-2]和nums[n-1]进行比较,循环结束
    '''
    n = len(nums)
    for i in range(n-1): # 避免j越界
        for j in range(i+1,n) : # nums[i]固定,nums[j++]总是和nums[i]比较,如果更小就交换到前边
            if nums[i]>nums[j]:
                nums[i],nums[j]=nums[j],nums[i]
    return nums        
# 11.计数排序
def countSort(nums):
    '''
        平均复杂度是nlog2n,稳定性排序
        思路是,先两两比较元素,控制变量从i=1,2..,n-1,控制变量j从j=0,1,..i
        元素更大的在名次数组对应位置+1,例如nums[i]>nums[j]就在rank[i]+1
        得到名次数组之后,rank[i]≠i,只要rank[i]=i就可以实现有序
        所以遍历每个元素nums[i],当前元素nums[i]的排名可以找到,也就是rank[i]
        如果rank[i]≠i说明排名没有按照顺序,而rank[i]对应的元素是nums[rank[i]]
        将这2个元素交换,同时名次数组也交换,即rank[i]和rank[rank[i]]进行交换
        遍历结束后,rank[i]=i,nums也已经有序
    '''
    n = len(nums)
    rank = [0] * n
    for i in range(1,n):
        for j in range(i):
            if nums[i]>nums[j] : rank[i]+=1
            else: rank[j]+=1
    for i in range(n): # 遍历每个元素
        while rank[i] != i: # 有序的元素应当满足排名rank[i]=i
            r = rank[i] # rank[i]对应的元素是nums[rank[i]],把它换到现在的nums[i]即可实现rank[i]=i
            nums[i],nums[r]=nums[r],nums[i]
            rank[i],rank[r]=rank[r],rank[i] # 排名也要交换
    return nums
if __name__ == '__main__':
    print(twoSums([3,2,4],6)) # [1,2]
    print(threeSum([-1,0,1,2,-1,-4])) # [[-1, -1, 2], [-1, 0, 1]]
    print(sellStocksI([7,1,5,3,6,4])) # 5
    print(sellStocksII([7,1,5,3,6,4])) # 7
    print(kNearestPoints([[1,1],[3,4],[-3,4],[5,5],[3,7],[10,6]],3)) # [[1, 1], [3, 4], [-3, 4]]
    print(dailyTemperature([73,74,75,71,69,72,76,73]))
    print(binarySearch([1,3,4,6,7,9,12,14,15,16,17,18,20,23,35,78,88,100],17)) # 10
    print(bubbleSort([5,4,3,2,1])) # [1, 2, 3, 4, 5]
    print(countSort([5,4,3,2,1])) # [1, 2, 3, 4, 5]

    colors = [2,0,2,1,1,0]
    colorClassify(colors)
    print(colors) # [0,0,1,1,2,2]

    root1 = ListNode(2)
    root1.next = ListNode(4)
    root1.next.next = ListNode(3)
    root2 = ListNode(5)
    root2.next = ListNode(6)
    root2.next.next = ListNode(4)
    ans = addTwoNumbers(root1,root2)
    while ans:
        print(ans.val,end=" ")
        ans = ans.next # 7 0 8  342+465=807

    
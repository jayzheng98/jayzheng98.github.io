---
layout: archive
title: "Online Programming"
collection: notes
permalink: /notes/OP
author_profile: false
---

<!-- GFM-TOC -->
* Categories
    * [1. Recursion (DFS)](#recursion-dfs)
    * [2. Mathematics](#mathematics)
    * [3. Hash](#hash)
    * [4. Sort](#sort)
    * [5. DP](#dp)
    * [6. Linked List](#linked-list)
    * [7. Binary Tree](#binary-tree)
    * [8. Stack & Queue](#stack--queue)
    * [9. Others](#others)
<!-- GFM-TOC -->

## Recursion (DFS)
### BM56 Full arrangement of numbers with duplicates (有重复项数字的全排列) 
**1.** Using *macro definition* to realize exchange: `#define swap (x,y,t) (t = x, x = y, y = t)` 

**2.** Solution:

```c
int count=0;
char *tmp, *rec;
char *out[];
void dfs(char* s, int i, int len){
    if (i == len) {      // End condition
        strcpy(out[count++],tmp);
        return;
    }
    for (int j = 0; j < len; j++) {
        if (j > 0 && s[j] == s[j - 1] && rec[j - 1] == 0)
            continue;    // Sorting can put the same numbers together so that you can skip them here
        if (rec[j] == 0) {
            rec[j] = 1;
            tmp[i] = s[j];
            dfs(s, i + 1, len);
            rec[j] = 0;
        }
    }
}
int main(){
    …
    scanf("%s",s);
    qsort(s,strlen(s),sizeof(char),cmp);    // Sorting is the key! The "cmp" function is omitted here
    dfs(s,0,strlen(s));
    …  
}
```

### HJ43 Labyrinth problem (迷宫问题)
**1.** A template for such problem:

```c
void dfs(int n, int m){
    maze[n][m]=1;               // Mark this position has been passed
    k++;
    if(n==row-1 && m==col-1){   // End condition
        …;
        return;
    }
    if(n+1<row && !maze[n+1][m])  dfs(n+1,m);
    if(m+1<col && !maze[n][m+1])  dfs(n,m+1);
    if(n-1>=0 && !maze[n-1][m])   dfs(n-1,m);
    if(m-1>=0 && !maze[n][m-1])   dfs(n,m-1);
    k--;
    maze[n][m]=0;   // Restore step and mark (Whether backtracking is needed depends on the actual situation)
}
```
**2.** If the entrance is not unique, use *for loops* (usually 2) in the main func to traverse all the entrances.
 - **BM57 Number of islands** needs to use loops to find 1 to define the entrance of an island. Every time we pass in a position in an island, 0 should be set first, but it cannot be restored to 1 after passing out! Otherwise, we would enter the same island multiple times during the loops.

### HJ67 & HJ89 24-point game (24点游戏)
**1.** Use array "rec" to mark whether the number is used to achieve the full arrangement：

```c
for(int j=0;j<4;j++){
    if(rec[j]==0){
        rec[j]=1;
        //dfs(in,i+1,calc);
        dfs(in,i+1,calc+in[j]);
        dfs(in,i+1,calc-in[j]);
        dfs(in,i+1,calc*in[j]);
        dfs(in,i+1,calc/in[j]);
        rec[j]=0;
    }
 }
```
**2.** The end condition for the requirement to output the formula: ("i" starts from 0)

```c
char* formu[9];      // Because input has the value of 10, a two-dimensional array is needed
if (i == 4) {
    if (calc == 24) {
        if (!strcmp(formu[0], "+")) {      // Elements in array are no longer "char" but "string"
            flag = 1;
            for (int l = 1; l < k; l++) {  // Skip the first operator
                printf("%s", formu[l]); 
            }
       }
    }
    return;
}
```

### HJ71 String wildcard (字符串通配符)
**1.** A confusible point in C:
  - Elements in an array defined by *malloc*, can be accessed with "\*a++", but cannot be assigned with it. ("++" will change the position of the pointer)
  - Elements in an array defined by *a[n]*, cannot be accessed and assigned with \*a++.
  - Elements in arrays defined in both ways above can be accessed and assigned with \*(a+i).
**2.** Solution:

```c
bool match(char* str, char* str1) {
    if (*str == '\0' && *str1 == '\0')     // End at the same time, return true
        return true;
    if (*str == '\0' || *str1 == '\0')     // One ends first, return false
        return false;
    if (*str == *str1 || abs(*str - *str1) == 32) {
        return match(str + 1, str1 + 1);
    }
    else if (*str == '?' && (isdigit(*str1) || isalpha(*str1))){
        return match(str + 1, str1 + 1);
    } 
    else if (*str == '*' && (isdigit(*str1) || isalpha(*str1))) {
        while (*str == '*') {              // Multiple "*" are equivalent to one "*"
            str++;
        }
        str--;
        return match(str + 1, str1) || match(str + 1, str1 + 1) || match(str, str1 + 1); 
        // 0 matched: str+1, str1 fixed; 1 matched: str+1, str1+1; Multiple matched: str fixed, str+1
    }
    return false;
}
```

## Mathematics
### HJ50 Arithemetic (四则运算)
**1.** Solution:

```c
int i;
int calc(char* in, int len) {
    char flag = '+';
    int stack[40];
    int tmp = 0, out = 0, top=-1;
    while (i < len) {
        tmp = 0;
        if(in[i]=='-')
            flag=in[i++];
        if (in[i] == '{' || in[i] == '[' || in[i] == '('){
            i++;
            tmp = calc(in, len);
        }
        while (in[i] >= '0' && in[i] <= '9') {
            tmp = tmp * 10 + in[i] - '0';
            i++;
        }
        switch (flag) {
            case '+': stack[++top] = tmp; break;
            case '-': stack[++top] = -tmp; break;
            case '*': stack[top] *= tmp; break;
            case '/': stack[top] /= tmp; break;
        }
        if (in[i] == '}' || in[i] == ']' || in[i] == ')') {
            i++;
            break;
        }
        flag = in[i++];
    }
    for (int j = 0; j <= top; j++) {
        out += stack[j];
    }
    return out;
}
```
 
### HJ82 Decompose true fraction into Egyptian fractions (埃及分数分解)
**Description:** For example, 8/11 = 1/2 + 1/5 + 1/55 + 1/110

**1.** Solution:

```c
while(scanf("%lld%c%lld", &fz, &slash, &fm)!=EOF){  // Use "scanf" to directly change "char" into "int"
     while(fz!=1){
         if(fm%fz==0){
             fm/=fz;
             break;
         }
         long long x=fm/fz;
         long long y=fm%fz;
         printf("1/%lld+",x+1);
         fz-=y;
         fm*=x+1;
     }
     printf("1/%lld\n",fm);
}
```

### HJ107 Calculate cube root (求解立方根)
**1.** Output the *float* variable with specified number of decimals, like 2: `printf("%.2f", i);`

### HJ108 Find the least common multiple (求最小公倍数)
**1.** Find the greatest common divisor of "a" and "b": `int gcd(int a, int b){   return b == 0 ? a : gcd(b, a%b); }`
 
**2.** The least common multiple = (a\*b) / gcd(a,b)

### JZ14 Cut a rope (剪绳子)
**Description:** For example, when the length of the rope is 8, we cut it into three sections with lengths of 2, 3, 3 to get the maximum product 18

**1.** "N" divided by "M" and rounded up: `int res = (N - 1) / M + 1;`

## Hash
### BM90 Minimum window substring(最小覆盖子串)
**1.** Solution:

```c
char* minWindow(char* S, char* T ) {
    int lens=strlen(S), lent=strlen(T), out=lens+1, l=0, r=0, k=0;
    char* hash=calloc(128, sizeof(char));
    for(int i=0;i<lent;i++){
        hash[T[i]]++;
    }
    while(r<lens){
        if(hash[S[r]]>0)
            lent--;         // 1 matched
        hash[S[r]]--;
        r++;
        while(!lent){       // All matched, narrow the left bound (at this time in "hash", only values of the characters to be matched are 0, others are negative)
            if(out>r-l){
                out=r-l;    // Record length "r-l" and start position "l" of the substring
                k=l;
            }
            if(map[S[l]]==0)
                lent++;     // This an element that needs to be included, which means narrowing is completed. So we can end the "while(!lent)"
            hash[S[l]]++;
            l++;
        }
    }
    if(out==lens+1)        // Matching is incomplete
        return "";
    S[k+out]='\0';         // End the string and prepare for the "return"
    return &S[k];
}
```

### HJ27 查找兄弟单词
**1.** 判断hash表加减后是否为零可以比较两个顺序不同的字符串所有元素是否相同：

```c
for(int i=0;i<len;i++){
   hash[word[i]]++;
   hash[sample[i]]--;
}
```

## Sort
### BM20 数组中的逆序对
**1.** Solution: Merge sort

```c
static long P = 0;
static int tmp[100000];
void merge(int* arr, int* tmp, int l, int mid, int r) {
    int ll = l, rr = mid + 1, k = 0;
    while (ll <= mid && rr <= r) {
        if (arr[ll] < arr[rr])
            tmp[k++] = arr[ll++];
        else {
            P += (mid - ll + 1);  //计算个数要+1
            P %= 1000000007;      //如果只是一般的归并排序，则不需要这两步
            tmp[k++] = arr[rr++];
        }
    }
    while (ll <= mid) {
        tmp[k++] = arr[ll++];
    }
    while (rr <= r) {
        tmp[k++] = arr[rr++];
    }
    for (int i = l; i <= r; i++){
        arr[i] = *(tmp++);       //形参指针指向的数组会跟着改变
    } 
}
void mergesort(int* arr, int l, int r) {
    int mid = (l + r) / 2;
    if (l < r) {                 // 只剩一个元素时结束
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, tmp, l, mid, r);
    }
}
int InversePairs(int* data, int dataLen ) {
    mergesort(data, 0, dataLen - 1);
    return P;
}
```

### BM54 三数之和 （这道题的思想可能经常用到）
**1.** Solution:

```c
int** threeSum(int* num, int numLen) {
    qsort(num, numLen, sizeof(int), cmp);
    int** arr = calloc(300, sizeof(int*));
    int k = 0;
    for (int i = 0; i < numLen - 2; i++) {
        int *pre = &num[i+1], *end = &num[numLen - 1];
        while (pre < end) {
            if (num[i] + *pre + *end == 0) {
                arr[k] = calloc(3, sizeof(int));
                arr[k][0] = num[i];
                arr[k][1] = *pre;
                arr[k][2] = *end;
                k++;
                while (*pre == *(pre + 1))
                    pre++;
                pre++;
                while (*end == *(end - 1))
                    end--;
                end--;
            } 
            else if (num[i] + *pre + *end > 0)
                end--;
            else
                pre++;
        }
        while (num[i] == num[i+1]) 
            i++;
    }
    return arr;
}
```

### HJ26 字符串排序
**1.** 按字母顺序不区分大小，从字符串中提取字母放入新数组中：

```c
for (char j = 'A'; j <= 'Z'; j++) {
   for (int i = 0; i < strlen(input); i++) {
       if (input[i] == j || input[i] - 32 == j)
           character[index++] = input[i];
   }
}
```

## DP
### HJ16 购物单  N元钱买商品（主件、附件1、附件2），计算最大满意度
**1.** 将附件、主件的价格和满意度分别存入对应的二维数组（q是对应的主件编号）：

```c
for (int i = 1; i <= m; i++) {
      int v, p, q;
      scanf("%d %d %d", &v, &p, &q);
      if (!q) {                          //主
          val[i][0] = v;  wei[i][0] = v * p;
      } 
      else if (val[q][1] == 0) {        //附1
          val[q][1] = v;  wei[q][1] = v * p;
      } 
      else {                            //附2
          val[q][2] = v;  wei[q][2] = v * p;
      }
}
```
**2.** 状态转移4种情况（主、主附1、主附2、主附1附2）：

`dp[j]=Max(dp[j], wei[i][0] + dp[j - val[i][0]]);    //买了这个商品剩下的钱能买到的满意度`

### HJ24 合唱队  最少出队多少人构成山字形身高队形
**1.** 以i为中心分别从左到右和从右到左找两边的最长上升子序列，最后记得多减一个！

### HJ32 密码截取  最长回文字符串
**1.** i遍历所有长度，若j到k为回文串则dp置1。状态转移3种情况（奇、偶、边界）：

```c
for(int i=0;i<len;i++){
     for(int j=0;j<len-i;j++){
         int k=j+i;
         if(!i)
            dp[j][k]=1;
         else if (i==1 && in[j]==in[k])
            dp[j][k]=1;
         else if(dp[j+1][k-1] && in[j]==in[k])
            dp[j][k]=1;
         if(dp[j][k])
            max=fmax(max,i+1);      //注意长度的话i要加1
     }
 }
```

## Linked List
### BM2 链表内指定区间反转
**1.** 养成用一个空头结点记录链表的好习惯（遇到首尾节点反转时不会出错）

```c
while(n-m){ // pre和cur位置不移动，相当于不停地把new插到pre和cur之间
     new=cur->next;
     cur->next=new->next;
     new->next=pre->next;
     pre->next=new;
     n--;
}
```

### BM9 删除链表的倒数第n个节点
**1.** 快指针先走n步，然后快慢指针一起出发实现对倒数第n的定位

### HJ48 从单向链表中删除指定值的节点
**1.** 定义：

```c
typedef struct LinkNode{
    int val;
    struct LinkNode* next;
}LinkNode;
```
**2.** 创建一个节点：
`LinkNode* p=malloc(sizeof(LinkNode));`

## Binary Tree
## BM26 二叉树层序遍历
**1.** 前序遍历的变种，分层存放前序遍历的结果。递归参数要传递层数，输出数组也变二维

```c
void levelorder(int level, struct TreeNode* root, int** out, int** rs){
    if(root==NULL)
        return;
    if(level>=k){
        out[level]=calloc(100, sizeof(int));
        k++;
    }
    int* i=&out[level][(*rs)[level]];
    *i++=root->val;
    (*rs)[level]++;
    levelorder(level+1, root->left, out, rs);
    levelorder(level+1, root->right, out, rs);
}
```

### BM36 判断是不是平衡二叉树
**1.** 求树的高度：

```c
int depth(TreeNode *root) {
    if (!root) return 0;
    int ldep = depth(root->left);
    int rdep = depth(root->right);
    return fmax(ldep, rdep) + 1;
}
```

### BM40 重建二叉树
**1.** Solution:

```c
struct TreeNode* recur(int* xianxu, int* zhongxu, int Len){
    if(!Len)
        return NULL;
    struct TreeNode* out=calloc(Len, sizeof(struct TreeNode));
    out->val=xianxu[0];
    int i=0;
    for(;i<Len;i++){
        if(zhongxu[i]==xianxu[0])
            break;
    }
    int newxxl[i+1], newxxr[Len-i], newzxl[i+1], newzxr[Len-i];
    for(int j=0;j<i;j++){
        newxxl[j]=xianxu[j+1];
        newzxl[j]=zhongxu[j];
    }
    for(int j=0;j+i+1<Len;j++){
        newxxr[j]=xianxu[j+i+1];
        newzxr[j]=zhongxu[j+i+1];
    }
    out->left=recur(newxxl, newzxl, i);
    out->right=recur(newxxr, newzxr, Len-i-1);
    return out; 
}
```

## Stack & Queue
### BM45 滑动窗口的最大值
**1.** 队列比较适合于滑动窗口的维护（实际上就是一个有双指针的数组），定义：

```c
typedef struct queue{
    int data[MAX];
    int head;          //在左边
    int tail;
}Queue;
```
**2.** Create with： `Queue q;`

## Others
## HJ30 字符串合并处理
**1.** switch()语句小技巧：

```c
case 'a':                                // 将执行和后一句一样的内容
case 'A': in[i]='5'; break;
```

### HJ33 整数与IP地址间的转换
**1.** 十进制转八位二进制：

```c
void DeciToBina(int n, char* out) {
    int length=0;
    char a[8];
    while (n>=2) {
        a[length++] = (n % 2) + '0';     //将除2得到的余数装入数组中
        n = n / 2;
    }
    a[length++] = (n % 2) + '0';         //存储最后一个余数
    while(length<8){
        a[length++]='0';
    }
    for (int i = length - 1, k=0; i >= 0; i--){  
        out[k++] = a[i];                 //将余数从下往上输出
    }
}
```
**2.** IP地址转32位二进制

```c
int ipToBina(char* in, char* out){
    int tmp=0, count=0, c=0;
    char* ip[4];
    for(int j=0;j<=strlen(in);j++){
        if(in[j]!='.' && in[j]>='0' && in[j]<='9')
            tmp=tmp*10 + in[j]-'0';
        else if(in[j]=='.' || j==strlen(in)){
            ip[count]=calloc(8, sizeof(char));
            DeciToBina(tmp, ip[count++]);
            tmp=0;
        }
        else               //其他特殊字符
            return 1;
    }
    for(int a=0;a<4;a++){
        for(int b=0;b<8;b++){
            out[c++]= ip[a][b];
        }
    }
    return 0;
}
```

### HJ77 火车进站
**1.** 字典序：转换成字符串后用qsort+strcmp实现，cmp：
- char arr\[n]\[m] :      `return strcmp((char*)a, (char*)b);`
- char** arr=calloc(…) :  `return strcmp(*(char**)a, *(char**)b);`

### HJ94 记票统计
**1.** 可以用getchar()丢弃一个不需要的输入字符！

### JZ15 二进制中1的个数
**1.** Treat the *complement* of a negative number as the *true form* to obtain its corresponding positive number:

`unsigned int tmp = (unsigned int) n;`

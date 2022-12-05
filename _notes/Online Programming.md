---
layout: archive
title: "Online Programming"
collection: notes
permalink: /notes/OP
author_profile: false
---

<a name="top"></a>

<!-- 
* Categories
    * [Introduction](#introduction)
    * [1. Recursion (DFS)](#recursion-dfs)
    * [2. Mathematics](#mathematics)
    * [3. Hash](#hash)
    * [4. Sorting](#sorting)
    * [5. DP](#dp)
    * [6. Linked List](#linked-list)
    * [7. Binary Tree](#binary-tree)
    * [8. Stack & Queue](#stack--queue)
    * [9. Others](#others)
 -->

<br>

# Introduction
<hr>

**1.** At first, I practiced my online programming on the well-known [Leetcode](https://leetcode.com/). However, I found some paid functions on Leetcode, such as *Debug* and *spell check*, are free on [Nowcoder](https://www.nowcoder.com/), so I mainly use Nowcoder to train my programming now

**2.** The reason why I choose *C* for online programming is that *C* is relatively rudimentary and does not have many powerful built-in functions that *Python* and *C++* have. So programming with *C* allows me to have a more comprehensive and in-depth understanding of data structure & algorithm

<br>

# Recursion (DFS)
<hr>

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
<br>

# Mathematics
<hr>

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
 
**2.** The least common multiple: `(a*b) / gcd(a,b)`

### JZ14 Cut a rope (剪绳子)
**Description:** For example, when the length of the rope is 8, we cut it into three sections with lengths of 2, 3, 3 to get the maximum product 18

**1.** "N" divided by "M" and rounded up: `int res = (N - 1) / M + 1;`

<br>

# Hash
<hr>

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
            lent--;          // 1 matched
        hash[S[r]]--;
        r++;
        while(!lent){        // All matched, narrow the left bound (at this time in "hash", only values of the characters to be matched are 0, others are negative)
            if(out>r-l){
                out=r-l;     // Record length "r-l" and start position "l" of the substring
                k=l;
            }
            if(map[S[l]]==0)
                lent++;      // This is an element that needs to be included, which means narrowing is completed. So we can end the "while(!lent)"
            hash[S[l]]++;
            l++;
        }
    }
    if(out==lens+1)          // Matching is incomplete
        return "";
    S[k+out]='\0';           // End the string and prepare for the "return"
    return &S[k];
}
```

### HJ27 Find sibling words (查找兄弟单词)
**Description:** Define the sibling of a word as a word that can be generated by exchanging the letters in the word any times but without adding, deleting or modifying letters

**1.** By judging whether a value in *hash* is zero after "++" and "--", you can know whether all elements of two strings with different orders are the same:

```c
for(int i=0;i<len;i++){
   hash[word[i]]++;
   hash[sample[i]]--;
}
```
<br>

# Sorting
<hr>

### BM20 Inverse pairs in an array (数组中的逆序对)
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
            P += (mid - ll + 1);
            P %= 1000000007;        // Surely these 2 steps are not needed in the normal template of merge sort
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
        arr[i] = *(tmp++);          // Array "data" pointed by the formal parameter pointer "arr" will change accordingly
    } 
}
void mergesort(int* arr, int l, int r) {
    int mid = (l + r) / 2;
    if (l < r) {
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

### BM54 Three sum (三数之和) 
**Description:** Find all triples in an array that meet "a+b+c=0"

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

### HJ26 String sort (字符串排序)
**1.** Extract letters from a string in alphabetical order (case-insensitive) and put them into a new array:

```c
for (char j = 'A'; j <= 'Z'; j++) {
   for (int i = 0; i < strlen(input); i++) {
       if (input[i] == j || input[i] - 32 == j)
           character[index++] = input[i];
   }
}
```
<br>

# DP
<hr>

### HJ16 Shopping list (购物单)
**Description:** There are 3 kinds of goods: main part, accessory 1 and 2, accessories must be purchased after the corresponding main part. Known the price and satisfaction of each product, calculate the maximum satisfaction we can get with money N

**1.** Store the price and satisfaction of accessories and main parts into the corresponding 2D array (q is the number of corresponding main part):

```c
for (int i = 1; i <= m; i++) {
      int v, p, q;
      scanf("%d %d %d", &v, &p, &q);
      if (!q) {                          // main part
          val[i][0] = v;  wei[i][0] = v * p;
      } 
      else if (val[q][1] == 0) {        // accessory 1
          val[q][1] = v;  wei[q][1] = v * p;
      } 
      else {                            // accessory 2
          val[q][2] = v;  wei[q][2] = v * p;
      }
}
```
**2.** 4 cases of state transfer:
 - Buy main part
 - Buy main part & accessory 1
 - Buy main part & accessory 2
 - Buy main part & accessory 1 & accessory 2

```c
for (int i = 1; i <= m; i++) {
    for (int j = N; j >= 0; j--) {
        if (val[i][0] <= j) {
            dp[j] = Max(dp[j],
                        wei[i][0] + dp[j - val[i][0]]);  // Buy this one "wei[i][0]+dp[j-val[i][0]]" or not "dp[j]"
        }
        if (val[i][1] && (val[i][0] + val[i][1]) <= j) {
            dp[j] = Max(dp[j], 
                        wei[i][0] + wei[i][1] + dp[j - val[i][0] - val[i][1]]);
        }
        if (val[i][2] && (val[i][0] + val[i][2]) <= j) {
            dp[j] = Max(dp[j],
                        wei[i][0] + wei[i][2] + dp[j - val[i][0] - val[i][2]]);
        }
        if (val[i][2] && (val[i][0] + val[i][1] + val[i][2]) <= j) {
            dp[j] = Max(dp[j],
                        wei[i][0] + wei[i][1] + wei[i][2] + dp[j - val[i][0] - val[i][1] - val[i][2]]);
        }
    }
}
```

### HJ24 Chorus (合唱队)
**Description:** Calculate the minimum number of people to leave to form a mountain shaped (eg. 1 3 6 3 2) height formation in a team with N members

**1.** Solution: Take "i" as the center to find the longest ascending subsequence on both sides from → and ← respectively:

```c
int chorus(int *h, int N) {
    int max = 0;
    int l[N], r[N];
    for (int i = 0; i < N; i++) {
        l[i]=1; r[i]=1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i] && l[i] < l[j] + 1) 
                l[i] = l[j] + 1;
        }
    }
    for (int i = N-2; i >=0; i--) {
        for (int j = N-1; j > i; j--) {
            if (h[j] < h[i] && r[i] < r[j] + 1) 
                r[i] = r[j] + 1;
        }
    }
    for(int i = 0; i < N; i++){
        int tmp=r[i]+l[i]-1;       // Notice the central person "i" was counted twice
        if(tmp>max)
            max=tmp;
    }
    printf("%d\n",(N-max));
    return 0;
}
```

### HJ32 Get password (密码截取)
**Description:** Get the longest palindrome substring

**1.** Solution: Traverse all values of length through "i". If string\[j-k\] is a palindrome, set dp[j][k] to 1

**2.** 3 cases of state transfer:
 - In the middle of a palindrome with even length
 - In the middle of a palindrome with odd length
 - In the boundary of a former palindrome

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
            max=fmax(max, i+1);      // length = i+1
     }
 }
```
<br>

# Linked List
<hr>

### BM2 Reverse between specified range in linked list (链表内指定区间反转)
**1.** Develop the habit of using a null node to indicate the linked list (In case the first and last node need to be reversed)

**2.** Solution: The position of "pre" and "cur" actually don't change, and constantly insert "new" between "pre" and "cur"
```c
while(n-m){ 
     new=cur->next;
     cur->next=new->next;
     new->next=pre->next;
     pre->next=new;
     n--;
}
```

### BM9 Remove the nth node from the bottom of a linked list (删除链表的倒数第n个节点)
**1.** Solution: The *fast pointer* moves n steps first, then the *slow pointer* starts. When the fast pointer points to *NULL*, the slow pointer points to the nth node from the bottom of the linked list.

### HJ48 Remove the specified node from a one-way linked list (从单向链表中删除指定值的节点)
**1.** Definition of the node：

```c
typedef struct LinkNode{
    int val;
    struct LinkNode* next;
}LinkNode;
```
**2.** Create a node：
`LinkNode* p=malloc(sizeof(LinkNode));`

**3.** If the head node of the linked list is unknown, use the value of targeted node's next node to cover the value of targeted node, and then remove its next node

<br>

# Binary Tree
<hr>

## BM26 Binary tree level order traversal (二叉树层序遍历)
**1.** It is a variation of *preorder traversal*, that is, the results of preorder traversal are stored hierarchically

```c
static int k=0;
void levelorder(struct TreeNode* root, int level, int** out, int* arrlevel){  // Recursive parameters need to include the current level of the tree
    if(root == NULL)
        return;
    if(level>=k){
        out[level]=calloc(1000,sizeof(int));                                  // The output array also becomes two-dimensional
        k++;
    }

    out[level][arrlevel[level]++]=root->val;
    levelorder(root->left, level+1, out, arrlevel);
    levelorder(root->right, level+1, out, arrlevel);
}
```

### BM36 Balanced Binary Tree (判断是不是平衡二叉树)
**1.** Calculate the depth of a tree:

```c
int depth(TreeNode *root) {
    if (!root) 
        return 0;
    int ldep = depth(root->left);
    int rdep = depth(root->right);
    return fmax(ldep, rdep) + 1;
}
```

### BM40 Reconstruct binary tree (重建二叉树)
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
<br>

# Stack & Queue
<hr>

### BM45 Maximum in sliding window (滑动窗口的最大值)
**1.** The queue is quite suitable for the maintenance of sliding window (A queue actually is an array with 2 pointers)

**2.** Definition of the queue:

```c
typedef struct queue{
    int data[MAX];
    int head;
    int tail;
}Queue;
```
**3.** Create a queue： `Queue q;`

<br>

# Others
<hr>

## HJ30 String merging (字符串合并处理)
**1.** Tips of *switch()*: 

```c
case 'a':                           // It will execute the same as the next "case" 
case 'A': in[i]='5'; break;
```

### HJ33 Conversion between integer and IP address (整数与IP地址间的转换)
**1.** Convert decimal to binary (8-bit):

```c
void DeciToBina(int n, int* out) {
    int length=0;
    int a[8];
    while (n>0) {
        a[length++] = (n % 2);
        n = n / 2;
    }
    while(length<8){
        a[length++]=0;              // Fill with "0"
    }
    for (int i = length - 1, k=0; i >= 0; i--){  
        out[k++] = a[i];            // Output the remainders in reverse order
    }
}
```
**2.** Convert IP address to binary (32-bit):

```c
void IPToBina(char* in, int* out){
    int tmp=0, count=0, c=0;
    int* ip[4];
    for(int j=0;j<=strlen(in);j++){
        if(in[j]!='.' && isdigit(in[j]))
            tmp=tmp*10 + in[j]-'0';
        else if(in[j]=='.' || j==strlen(in)){
            ip[count]=calloc(8, sizeof(int));
            DeciToBina(tmp, ip[count++]);
            tmp=0;
        }
    }
    for(int a=0;a<4;a++){
        for(int b=0;b<8;b++){
            out[c++]= ip[a][b];
        }
    }
}
```

### HJ77 Trains pull in (火车进站)
**Description:** Enter a line of positive integers to be *pushed*, output all schemes of *popping* in dictionary order

**1.** Dictionary order: Achieved by *qsort* and *strcmp*
- char arr\[n]\[m] :      `return strcmp((char*)a, (char*)b);`
- char** arr=calloc(…) :  `return strcmp(*(char**)a, *(char**)b);`

### HJ94 Count of votes (记票统计)
**1.** Tips: Use *getchar()* to drop a unneeded character from the input

### JZ15 Number of "1" in the binary number (二进制中1的个数)
**1.** Treat the *complement* of a negative number as the *true form* to obtain its corresponding positive number:

`unsigned int tmp = (unsigned int) n;`

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>

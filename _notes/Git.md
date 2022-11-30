---
title: "Git"
collection: notes
permalink: /notes/Git
author_profile: false
---

<!-- GFM-TOC -->
* Chapters 
    * [Statement](#statement)
    * [1. Common commands](#common-commands)
    * [2. Centralized & Distributed](#centralized--distributed)
    * [3. Central Server](#central-server)
    * [4. 工作流](#工作流)
    * [5. 分支实现](#分支实现)
    * [6. 冲突](#冲突)
    * [7. 储藏（Stashing）](#储藏stashing)
<!-- GFM-TOC -->

<br>

# Statement
<hr>

Some of the content and pictures in this article are excerpted from the [CS-Notes](https://github.com/CyC2018/CS-Notes/blob/master/notes/Git.md). If there is infringement, please inform to delete

<br>

# Common commands
<hr>

<div align="center">
   
| Command | Object | Description |
|:--------|:-------:|:--------:|
|git add | filename |  #将文件加到暂存区域|
|git commit -m | filename | #将暂存区域的文件提交到git仓库|
||||
|git commit --amend | | #修改最后一次提交（shift+zz退出，q!不保存退出）|
|git mv | original new |  #修改文件名|
|git rm | filename |  #删除工作目录和暂存区的文件（不同的话不会删除，加-f强制删）|
|git rm --cached | filename |  #只删除暂存区的文件|
||||
|git status|||
|git log | | #查看提交记录|
|git reflog ||  #（cmd窗口关掉后）查看每个版本号|
||||
|git reset | 版本号 |  #将该版本回滚到暂存区域|
|git reset | HEAD~n |  #将HEAD指针移动到前n个对象上并将该对象回滚到暂存区域|
|git reset --soft | HEAD~n |  #仅移动HEAD指针|
|git reset --hard | HAED~n |  #比默认的多了“将暂存区域文件还原到工作目录”（覆盖掉源码）|
||||
|git diff | | #比较工作目录和暂存区的文件|
|git diff | 版本号 |  #比较工作目录和仓库的文件|
|git diff | 版本号1 版本号2 |  #比较仓库中的两个文件|
|git diff --cached | 版本号 |  #比较暂存区和仓库的文件#只有仓库中的文件才有版本号，这样就理清关系了~|
||||
|git branch | 分支名 |  #创建分支|
|git checkout | 分支名 | #切换分支|
|git merge | 分支名 |  #合并分支|
|git branch -d | 分支名 |  #删除分支|

</div>

<br>

# Centralized & Distributed
<hr>

**1.** Git is a distributed version control system, while SVN is centralized

<div align="center"> <img width="600" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git1.png?raw=true"/> </div><br>

**2.** Comparison between centralized and distributed: 

<div align="center">
   
|  | Centralized | Distributed |
|:--------|:-------:|:--------:|
| The copy of code | only the central server | everyone's computer |
| Work without central server | × | √ |
| Networking required | √ | × |
| Create and merge | slow (copy a complete code) | fast |
   
</div>

<br>

# Central Server
<hr>

**1.** The central server is used to exchange the changes of each user. Git can work without it, but the central server can run continuously which makes exchanges easier

**2.** For example, the [Github](https://github.com/) is a central server
<br>

# 工作流

新建一个仓库之后，当前目录就成为了工作区，工作区下有一个隐藏目录 .git，它属于 Git 的版本库。

Git 的版本库有一个称为 Stage 的暂存区以及最后的 History 版本库，History 存储所有分支信息，使用一个 HEAD 指针指向当前分支。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208195941661.png"/> </div><br>

- git add files 把文件的修改添加到暂存区
- git commit 把暂存区的修改提交到当前分支，提交之后暂存区就被清空了
- git reset -- files 使用当前分支上的修改覆盖暂存区，用来撤销最后一次 git add files
- git checkout -- files 使用暂存区的修改覆盖工作目录，用来撤销本地修改

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208200014395.png"/> </div><br>

可以跳过暂存区域直接从分支中取出修改，或者直接提交修改到分支中。

- git commit -a 直接把所有文件的修改添加到暂存区然后执行提交
- git checkout HEAD -- files 取出最后一次修改，可以用来进行回滚操作

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208200543923.png"/> </div><br>

## 分支实现

使用指针将每个提交连接成一条时间线，HEAD 指针指向当前分支指针。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203219927.png"/> </div><br>

新建分支是新建一个指针指向时间线的最后一个节点，并让 HEAD 指针指向新分支，表示新分支成为当前分支。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203142527.png"/> </div><br>

每次提交只会让当前分支指针向前移动，而其它分支指针不会移动。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203112400.png"/> </div><br>

合并分支也只需要改变指针即可。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203010540.png"/> </div><br>

## 冲突

当两个分支都对同一个文件的同一行进行了修改，在分支合并时就会产生冲突。

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203034705.png"/> </div><br>

Git 会使用 \<\<\<\<\<\<\< ，======= ，\>\>\>\>\>\>\> 标记出不同分支的内容，只需要把不同分支中冲突部分修改成一样就能解决冲突。

```
<<<<<<< HEAD
Creating a new branch is quick & simple.
=======
Creating a new branch is quick AND simple.
>>>>>>> feature1
```

## Fast forward

"快进式合并"（fast-farward merge），会直接将 master 分支指向合并的分支，这种模式下进行分支合并会丢失分支信息，也就不能在分支历史上看出分支信息。

可以在合并时加上 --no-ff 参数来禁用 Fast forward 模式，并且加上 -m 参数让合并时产生一个新的 commit。

```
$ git merge --no-ff -m "merge with no-ff" dev
```

<div align="center"> <img src="https://cs-notes-1256109796.cos.ap-guangzhou.myqcloud.com/image-20191208203639712.png"/> </div><br>

## 储藏（Stashing）

在一个分支上操作之后，如果还没有将修改提交到分支上，此时进行切换分支，那么另一个分支上也能看到新的修改。这是因为所有分支都共用一个工作区的缘故。

可以使用 git stash 将当前分支的修改储藏起来，此时当前工作区的所有修改都会被存到栈中，也就是说当前工作区是干净的，没有任何未提交的修改。此时就可以安全的切换到其它分支上了。

```
$ git stash
Saved working directory and index state \ "WIP on master: 049d078 added the index file"
HEAD is now at 049d078 added the index file (To restore them type "git stash apply")
```

该功能可以用于 bug 分支的实现。如果当前正在 dev 分支上进行开发，但是此时 master 上有个 bug 需要修复，但是 dev 分支上的开发还未完成，不想立即提交。在新建 bug 分支并切换到 bug 分支之前就需要使用 git stash 将 dev 分支的未提交修改储藏起来。

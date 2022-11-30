---
permalink: /notes/git
title: "Git"
author_profile: false
redirect_from: 
  - /git/
---

<!-- GFM-TOC -->
* Chapters 
    * [Statement](#statement)
    * [1. Common commands](#common-commands)
    * [2. Centralized & Distributed](#centralized--distributed)
    * [3. Central Server](#central-server)
    * [4. Workflow](#workflow)
    * [5. Branch](#branch)
    * [6. Conflict](#conflict)
    * [7. Stashing](#stashing)
<!-- GFM-TOC -->

<br>

# Statement
<hr>

Some of the content and pictures in this article are excerpted from the [CS-Notes](https://github.com/CyC2018/CS-Notes/blob/master/notes/Git.md). If there is infringement, please inform to delete

<br>

# Common commands
<hr>
   
| Command | Object | Description |
|:--------|:-------:|:--------:|
|git add | filename | Add files to the staging area |
|git commit -m | filename | Submit files in staging area to the repository |
|git commit --amend | | Modify the last submission (use "shift+zz" to exit; use "q!" to exit without saving) |
|git mv | original  new | Modify the name of a file |
|git rm | filename | Delete files in both working directory and staging area (use "-f" to force delete) |
|git rm --cached | filename | Delete files in the staging area only |
||||
|git pull||Fetch from and integrate with another repository or a local branch|
|git push||Update remote refs along with associated objects|
||||
|git log | | View submission logs |
|git reflog || Show referentiable history versions |
||||
|git reset | version | Roll back the version to the staging area |
|git reset | HEAD~n | Move the HEAD pointer to the first "n" objects and roll back the objects to staging area |
|git reset --soft | HEAD~n | Move the HEAD pointer to the first "n" objects only |
|git reset --hard | HAED~n | Further restore the staging area files to working directory (overwrite the source code) |
||||
|git diff | | Compare files in working directory and staging area |
|git diff | version | Compare files in working directory and repository |
|git diff | version1  version2 | Compare 2 files in a repository |
|git diff --cached | version | Compare files in staging area and repository (only files in repository have "version") |
||||
|git branch | branch name | Create a branch |
|git checkout | branch name | Switch to a branch |
|git merge | branch name | Merge changes from another branch|
|git branch -d | branch name |  Delete a branch | 

* See more from the [cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)
<br>

# Centralized & Distributed
<hr>

**1.** Git is a distributed version control system, while SVN is centralized

<div align="center"> <img width="600" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git1.png?raw=true"/> </div><br>

**2.** Comparison between centralized and distributed: 
   
|  | Centralized | Distributed |
|:--------|:-------:|:--------:|
| The copy of code | only the central server | everyone's computer |
| Work without central server | × | √ |
| Networking required | √ | × |
| Create and merge | slow (copy a complete code) | fast |

<br>

# Central Server
<hr>

**1.** The central server is used to exchange the changes of each user. Git can work without it, but the central server can run continuously which makes exchanges easier

**2.** For example, the [Github](https://github.com/) is a central server
<br>

# Workflow
<hr>

新建一个仓库之后，当前目录就成为了工作区，工作区下有一个隐藏目录 .git，它属于 Git 的版本库。

Git 的版本库有一个称为 Stage 的暂存区以及最后的 History 版本库，History 存储所有分支信息，使用一个 HEAD 指针指向当前分支。

<div align="center"> <img width="850" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git2.png?raw=true"/> </div><br>
<br>

# Branch
<hr>

使用指针将每个提交连接成一条时间线，HEAD 指针指向当前分支指针。

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git3.png?raw=true"/> </div><br>

新建分支是新建一个指针指向时间线的最后一个节点，并让 HEAD 指针指向新分支，表示新分支成为当前分支。

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git4.png?raw=true"/> </div><br>

每次提交只会让当前分支指针向前移动，而其它分支指针不会移动。

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git5.png?raw=true"/> </div><br>

合并分支也只需要改变指针即可。

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git6.png?raw=true"/> </div><br>
<br>

# Conflict
<hr>

当两个分支都对同一个文件的同一行进行了修改，在分支合并时就会产生冲突。

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git7.png?raw=true"/> </div><br>

Git 会使用 \<\<\<\<\<\<\< ，======= ，\>\>\>\>\>\>\> 标记出不同分支的内容，只需要把不同分支中冲突部分修改成一样就能解决冲突。

```
<<<<<<< HEAD
Creating a new branch is quick & simple.
=======
Creating a new branch is quick AND simple.
>>>>>>> feature1
```
<br>

# Stashing
<hr>

在一个分支上操作之后，如果还没有将修改提交到分支上，此时进行切换分支，那么另一个分支上也能看到新的修改。这是因为所有分支都共用一个工作区的缘故。

可以使用 git stash 将当前分支的修改储藏起来，此时当前工作区的所有修改都会被存到栈中，也就是说当前工作区是干净的，没有任何未提交的修改。此时就可以安全的切换到其它分支上了。

```
$ git stash
Saved working directory and index state \ "WIP on master: 049d078 added the index file"
HEAD is now at 049d078 added the index file (To restore them type "git stash apply")
```

该功能可以用于 bug 分支的实现。如果当前正在 dev 分支上进行开发，但是此时 master 上有个 bug 需要修复，但是 dev 分支上的开发还未完成，不想立即提交。在新建 bug 分支并切换到 bug 分支之前就需要使用 git stash 将 dev 分支的未提交修改储藏起来。

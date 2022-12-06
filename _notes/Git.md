---
layout: single
collection: notes
permalink: /notes/git
title: "Git"
author_profile: false
toc: true
toc_label: "Contents"
---

<a name="top"></a>

<!-- 
* Chapters 
    * [Statement](#statement)
    * [1. Common Commands](#common-commands)
    * [2. Centralized & Distributed](#centralized--distributed)
    * [3. Central Server](#central-server)
    * [4. Workflow](#workflow)
    * [5. Branch](#branch)
    * [6. Conflict](#conflict)
    * [7. Stashing](#stashing)
-->

<br>

# Statement
<hr>

Some of the content and pictures in this article are excerpted from the [CS-Notes](https://github.com/CyC2018/CS-Notes/blob/master/notes/Git.md). If there is infringement, please inform to delete

<br>

# Common Commands
<hr><br>

**1. Table**

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

**2. See more from the [cheat sheet](https://education.github.com/git-cheat-sheet-education.pdf)**

<br>

# Centralized & Distributed
<hr>

**1.** Git is a distributed version control system, while SVN is centralized

<div align="center"> <img width="600" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git1.png?raw=true"/> </div><br>

**2.** Comparison between centralized and distributed: 
   
|  | Centralized | Distributed |
|:--------|:-------:|:--------:|
| The copy of code | Only the central server | Everyone's computer |
| Work without central server | × | √ |
| Networking required | √ | × |
| Create and merge | Slow (copy a complete code) | Fast |

<br>

# Central Server
<hr>

**1.** The central server is used to exchange the changes of each user. Git can work without it, but the central server can run continuously which makes exchanges easier
 - *For example, the [Github](https://github.com/) is a central server*

<br>

# Workflow
<hr>

**1.** After creating a new repository, the current directory becomes the workspace

**2.** There is a hidden directory ".git" in the workspace, which belongs to the Git version library
 - *The Git version library includes a staging area called "Stage" and the latest "History" version library. "History" stores all branches' information and uses a HEAD pointer to point to the current branch*

<div align="center"> <img width="850" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git2.png?raw=true"/> </div><br>
<br>

# Branch
<hr>

**1. Implement**
 - *Use the pointer to connect each submission into a timeline, and the HEAD pointer points to the current branch pointer*

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git3.png?raw=true"/> </div><br>

**2. New**
 - *Create a new pointer to the last node of the timeline, and make the HEAD pointer point to the new branch, indicating that the new branch becomes the current branch*

<div align="center"> <img width="300" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git4.png?raw=true"/> </div><br>

**3. Commit**
 - *Each commit will only move the current branch pointer forward, while other pointers stay fixed*

<div align="center"> <img width="360" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git5.png?raw=true"/> </div><br>

**4. Merge**
 - *Simply change the pointer*

<div align="center"> <img width="360" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git6.png?raw=true"/> </div><br>
<br>

# Conflict
<hr>

**1.** When two branches modify the same line of the same file, conflicts will occur during merging:

<div align="center"> <img width="360" src="https://github.com/jayzheng98/jayzheng98.github.io/blob/master/images/git7.png?raw=true"/> </div><br>

**2.** Git will use "\<\<\<\<\<\<\<, =======, \>\>\>\>\>\>\>" to identify contents of different branches. We only need to modify the conflicting parts to be the same to resolve the conflict

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

**1.** After operating on a branch, switch to another branch before the changes are committed, the changes can also be seen on the other branch. This is because all branches share a same workspace

**2.** We can use `git stash` to store the changes of the current branch
 - *At this time, all the changes of the current workspace will be stored in the stack to keep the current workspace clean. As there are no uncommitted changes, we can safely switch to other branches*

```
$ git stash
Saved working directory and index state \ "WIP on master: 049d078 added the index file"
HEAD is now at 049d078 added the index file (To restore them type "git stash apply")
```

**3.** Stashing can be used to implement the "bug branch"
 - *If you are currently developing on the "dev branch", but there is a bug on the "master branch", and the development on the "dev branch" is incomplete to be submitted immediately. Before creating and switching to a new bug branch, you need to use `git stash` to store the uncommitted changes of "dev branch"*

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>

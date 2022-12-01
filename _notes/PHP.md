---
layout: archive
title: "PHP"
collection: notes
permalink: /notes/php
author_profile: false
---

<a name="top"></a>

<!-- GFM-TOC -->
* Chapters
    * [1. Basic](#chapt1-basic)
    * [2. Output](#chapt2-output)
    * [3. Type of Data](#chapt3-type-of-data)
    * [4. Grammar](#chapt4-grammar)
    * [5. Database](#chapt5-database)
    * [6. Superglobal Variable](#chapt6-superglobal-variable)
    * [7. Binary Tree](#chapt7-binary-tree)
    * [8. New Feature of PHP8](#chapt8-new-feature-of-php8)
    * [9. Exercise](#chapt9-exercise)
<!-- GFM-TOC -->

<br>

# Chapt.1 Basic
<hr>

**1.** PHP files can contain "html", "CSS" and "JavaScript" code

| Code    | Description |
|:-------:|:--------:|
| `<?php ... ?>` | Tags for PHP code |
| `;` `{}` | Statement terminators |
| `//` `/*...*/` | Annotations |
| `$s` | Define a variable "s" |
| `=` | Assignment Operator |

<br>

# Chapt.2 Output
<hr>

**1.** PHP use `echo` and `print` to output contents:

```php
<?php
    echo 111,222;   // Multiple
    echo '<hr>';
    print 111;      // Single
    echo '<hr>';
    $a_zzy = 'Variable name cannot begin with a number and there cannot be spaces after the $';
    echo $a_zzy;
?>
```
<br>

# Chapt.3 Type of Data
<hr>

**1.** Integer, float, boolean, null and string

```php
<?php
    $x = true;
    var_dump($x);        // "var_dump()" can print the type of a variable
    echo '<hr>';
    $y = -123;
    var_dump($y);
    echo '<hr>';
    $f = 3.1415;
    var_dump($f);
    echo '<hr>';
    $s1 = '我是';        // One Chinese character is three characters long
    var_dump($s1);
    echo '<hr>';
    $s2 = 'my name is Jay';
    var_dump($s2);
    echo '<hr>';
    $s3 = "$s1 zzy";     // " can parse variable content, while ' cannot
    var_dump($s3);
    echo '<hr>';
    $n = null;
    var_dump($n);
?>
```
**2.** Array

```php
<?php
    $arr1 = array(                           // or use "[]"
        'ouyang',
        'miejue'
    ); 
    echo $arr1[1],'<hr>';
    
    $arr2 = [
        'ouyang' => '欧阳',
        '西门吹雪',
        '东方不败'
    ];
    echo $arr2['ouyang'],'<hr>';            // Custom array subscript
    print_r($arr2);                         // Output the whole array
    echo '<hr>';
    $s1 = 'I am';
    echo $s1.$arr2[1], '她叫', $arr1[1];    // "." and "," have the same effect
```
**3.** Multidimensional array

```php
    $MultiD_arr = array(
        array(
            'ouyang'
        ),
        array(
            'miejue'
        ),
        array(
            'ximen',
            'kungfu'=>[
                'PHP',
                'Python',
                'C++']
         )
    );
    print_r($MultiD_arr);                  // Arrays of different dimensions can be nested together
    echo '<hr>';
    echo 'I can use'.$MultiD_arr[2]['kungfu'][1].', and am learning'.$MultiD_arr[2]['kungfu'][0];  // Access elements in multi-D array
```
**4.** Loops in array

```php
    foreach($arr2 as $k=>$v){             // key "k" and value "v"
        echo $v, $k;
        echo '<hr>';
    } 
    foreach($MultiD_arr as $k=>$v){       // It proves that we'd better not to define a mixed-dimensional array
        foreach($v as $vv){
            echo $vv;
        }
    } 
?>
```
**5.** Constant

```
<?php
    define('HOST','127.0.0.1');   // Definition method 1
    echo HOST;
    const NAME = 'PHP website';     // Definition method 2
    echo NAME;
?>
```

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>

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
    * [1. Basic Info](#chapt1-basic-info)
    * [2. Output](#chapt2-output)
    * [3. Type of Data](#chapt3-type-of-data)
    * [4. Grammar](#chapt4-grammar)
    * [5. Database](#chapt5-database)
    * [6. Superglobal Variable](#chapt6-superglobal-variable)
    * [7. Class and Object](#chapt7-class-and-object)
    * [8. New Feature of PHP8](#chapt8-new-feature-of-php8)
    * [9. Exercise](#chapt9-exercise)
<!-- GFM-TOC -->

<br>

# Chapt.1 Basic Info
<hr>

**1.** PHP files can include "html", "CSS" and "JavaScript" code

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
    $y = -123;
    var_dump($y);
    $f = 3.1415;
    var_dump($f);
    $s1 = '我是';        // The length of 1 Chinese character == 3 en characters
    var_dump($s1);
    $s2 = 'my name is Jay';
    var_dump($s2);
    $s3 = "$s1 zzy";     // " can parse variable content, while ' cannot
    var_dump($s3);
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
    echo $s1.$arr1[1], '她叫', $arr2[1];    // "." and "," have the same effect
```
**3.** Multidimensional array (Try not to exceed 3 dimensions)

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

```php
<?php
    define('HOST', '127.0.0.1');      // Definition method 1
    echo HOST;
    const NAME = 'PHP website';       // Definition method 2
    echo NAME;
?>
```
<br>

# Chapt.4 Grammar
<hr>

**1.** Conditional statements

```php
<?php
    // "?" and ":"
    $str1 = 'ouyang';
    echo $str1 ? 'I am ouyang' : 'Unknown'; 
    
    // "if", "elseif" and "else"
    $str2 = '';
    $str3 = '1';
    if($str2){
        echo 'I have content';
    }
    elseif($str3){
        echo "I have".$str3;
    }
    else{
        echo 'Both are null';
    }
    
    // "switch"
    switch($str1){
        case 'ouyang': 
            echo 'I am ouyang';
            break;
        case 'miejue':
            echo 'I am miejue';
            break;
        default:
            echo $str1;
    }
    
    // PHP8 has "match()" to match and output in the form of key&value
    $str4 = 'zzy';
    echo match($str4){         // Exact match (while "switch" is not). For example, character number and integer number will be distinguished 
        'hht' => 'Haotian He',
        'zzy' => 'Zhongyi Zheng',
        'wj' => 'Jing Wang'
    };
?>
```
**2.** Built-in functions

```php
<?php
    $ouyang = 'OUYANG';
    echo strtolower($ouyang);          // Convert to lowercase
    
    $miejue = 'miejueshitai';
    echo strtoupper($miejue);          // Convert to uppercase
    
    $php = 'ouyang, miejue, ximen';
    print_r ( explode(',', $php) );    // Divide string into array by ","
    
    $ximen = 'ximen';
    echo md5($ximen);                  // Use "md5" to encrypt string
    
    $arr = ['ouyang', 'ximen', 'tianpeng'];
    echo count($arr);                  // Counting the number of elements
    
    echo implode(',',$arr);            // Combine array into string by ","
    
    echo in_array('tianpeng', $arr);   // Query the giving content
    
    array_pop($arr);                   // Delete the last element
    print_r($arr);
?>
```
**3.** Custom functions

```php
<?php
    $num2 = 13;        
    function num($num1, $num2){
        //global $num2;                //Use "global" to call global variables in functions
        return $num1 * $num2;
    }
    echo num(12, 11);
?>
```
**4.** Operators

| Operator | Description |
|:-------:|:--------:|
| + | Add |
| - | Subtract |
| * | Multiply |
| / | Divide |
| % | Modular |
| ++ | Same as in C |
| -- | Same as in C |
| == | Equal to |
| != | Not equal to |
| >= | Greater than or equal to |
| <= | less than or equal to |
| === | Identically equal to |
| !== | Not identically equal to |
| and | Logic and |
| or | Logic or |
| xor | Logic xor |
| ! | Logic not |

<br>

```php
<?php
    var_dump( 100 === 100 );
    echo '<hr>';
    var_dump( true === 'true' );   // "(Not) Identically equal to" compare not only values but also data types
?>
```
**5.** Loops
 
```php
<?php
    // "while"
    $int = 1;
    while($int < 10){
        echo $int;
        $int++;
    }
    $int = 1;
    
    // "do...while"
    do {
        echo $int;
        $int++;
    }while($int < 10);
    
    // "for"
    $int1 = 1;
    for($int1; $int1<10; $int1++){
        if($int1 == 5){
            echo '5';
        }
        else{
            echo $int1;
        }
    }
 ?>
 ```
 <br>

# Chapt.5 Database
<hr>

**1.** PHP could operate databases through the "PDO (PHP Data Object)":

```php
<?php
    $pdo = new PDO('mysql:host=localhost;dbname=blog', 'root', 'root');   // PDO($dsn, $username, $password)
    //var_dump($pdo);
    $stmt = $pdo->prepare('select * from article');                       // "->" calls the property of the class
    $stmt->execute();
    $arr = $stmt->fetchAll();
    print_r($arr);
?>
```
**2.** Instruction about the "Mysql" database please refer to [here](https://jayzheng98.github.io/notes/mysql)

<br>

# Chapt.6 Superglobal Variable
<hr>

**1.** Superglobal variables can be used across pages. For example, they can be used directly in "test2.php" though created in "test.php"

| Superglobal variable | Description |
|:-------:|:--------:|
| `$_GET` | Receive the value in the url, which is displayed after "?" |
| `$_POST` | Receive the value in the url, but not be displayed |
| `$_COOKIE` | Be used to identify users and stored in client browsers |
| `$_SESSION` | Be used to store "sessions" and stored in servers |
| `$_REQUEST` | Include the value of "get", "post" and "cookie" |
| `$GLOBALS` | A global combined array that includes all variables |

<br>

```php
<?php
    // print_r($GLOBALS);     
    setcookie('user','admin'); 
    print_r($_COOKIE);
    echo '<hr>';
    session_save_path("D:/");
    session_start(); 
    $_SESSION['user'] = 'admin';
    print_r($_SESSION);
?>
```
```html
<html>
  <head>
    <meta charset="utf-8" />
    <title>PHP website</title>
  </head>
  <body>
    <form action="" method="post"> 
      lecturer: <input type="text" name="name" /> School:
      <input type="text" name="school" />
      <input type="submit" value="submit" />
    </form>
  </body>
</html>
```
<br>

# Chapt.7 Class and Object
<hr>



<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>

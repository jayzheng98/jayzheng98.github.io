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
    $arr1 = array(                           // Or use "[]"
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
    foreach($arr2 as $k=>$v){             // Key "k" and value "v"
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
    echo match($str4){          // Exact match (while "switch" is not). For example, character number and integer number will be distinguished 
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
    echo strtolower($ouyang);           // Convert to lowercase
    
    $miejue = 'miejueshitai';
    echo strtoupper($miejue);           // Convert to uppercase
    
    $php = 'ouyang, miejue, ximen';
    print_r ( explode(',', $php) );     // Divide string into array by ","
     
    $ximen = 'ximen';
    echo md5($ximen);                   // Use "md5" to encrypt string
    
    $arr = ['ouyang', 'ximen', 'tianpeng'];
    echo count($arr);                   // Counting the number of elements
    echo implode(',',$arr);             // Combine array into string by "," 
    echo in_array('tianpeng', $arr);    // Query the giving content
    array_pop($arr);                    // Delete the last element
    print_r($arr);
?>
```
**3.** Custom functions

```php
<?php
    $num2 = 13;        
    function num($num1, $num2){
        //global $num2;                 //Use "global" to call global variables in functions
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
| `$_GET` | Receive the value in the URL, which is displayed after "?" |
| `$_POST` | Receive the value in the URL, but not be displayed |
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

**1.** Three characteristics:
 - **Inheritance**: Allows an object of one type to obtain the attributes and methods of an object of another type (the parent class cannot use the contents of the child class)
 - **Encapsulation**: Abstracts an object into a class. Each class implements protection mechanisms for its own attributes and methods
 - **Polymorphism**: Refers to that an entity has multiple forms at the same time, which is mainly embodied in the inheritance of the class (inherit first and then rewrite)

**2.** Class attribute and class method
```php
<?php 
    class Teacher{
        // Class attribute (variable)
        public $name = 'ouyang';                       // "public" (default): visible within class, outside class and in subclasses 
        protected $school = 'SWJTU';                   // "protected": visible within class and subclasses, but invisible outside class
        private $id_num;                               // "private": visible only within class, invisible in subclasses and outside class
        
        // Method
        public function fun1(){
            echo 'Name：miejue, School: SCU<hr/>';   // Try not to use "echo" but "return" in class
        }
        public function fun2(){
            return 'Name：miejue, School: SCU<hr/>';
        }
        public function fun3(){                        // Use pseudo variable "$this" to refer to the variable of current class
            return 'Name:'.$this->name.', School: '.$this->school.', ID Number: '.$this->id_num.'<hr/>'; 
        }
        public function fun4(){            
            return $this->fun3();                      // Use pseudo variable "$this" to refer to the method of current class
        }
        
        // Magic methods (Only record "__construct" and "__destruct" here)
        public function __construct($name, $school, $id_num){   // "__construct" is executed when instantiating
            $this->name = $name;
            $this->school = $school;
            $this->id_num = $id_num;
        }
        public function __destruct(){                          // "__destruct" is automatically executed after the class execution
            echo 'Class executed, ready to be destructed<hr/>';
        }
    }
```    
**3.** Inheritance and polymorphism

```php
    class PHPteacher extends Teacher{       // Inherit the class "Teacher" defined above
        public function fun5(){
            return $this->school;
        }
        public function fun6(){
            return $this->id_num;
        }
        public function fun1(){
            return 'I am rewritten here to embody the Polymorphism<hr/>';
        }
    }
    
    // Some tests
    $ximen = new Teacher('ximen','SCU','5101061998');
    print_r($ximen);
    echo '<hr/>';
    echo $ximen->name;
    echo '<hr/>';
    echo $ximen->fun3();
    
    $ouyang = new PHPteacher('ouyang','SWJTU','5101051997');
    print_r($ouyang);
    echo '<hr/>';
    echo $ouyang->id_num;                 // Cannot access "id_num" (private)
    echo '<hr/>';
    echo $ouyang->fun5();                 // Can access "school" (protected)
    echo $ouyang->fun6();                 // Still cannot access "id_num"    
    echo $ouyang->fun3();
    echo $ouyang->fun1();
?>
```
**4.** Abstract class
 - Abstract class cannot be instantiated but only inherited
 - Abstract methods (no func body) in abstract class need to be rewritten in subclass

```php
<?php
    abstract class Teacher1 {             // Notice that there is no "abstract attribute"
        protected $name;
        private $school;
 
        public function __construct($name, $school) {
            $this->name = $name;
            $this->school = $school;
        }
        public function fun1() {
            return 'Name: ' . $this->name . ', School: ' . $this->school .'<hr/>';
        }
        abstract public function fun2();
    }

    class PHPTeacher1 extends Teacher1 {
        public function fun3() {
            return $this->fun1();
        }
        public function fun2() {
            return 'I am the rewritten method after inheriting <hr/>';
        }
    }

    $obj = new PHPTeacher1('ximen', 'SCU');
    echo $obj->fun2();
    echo $obj->fun3();
?>
```
**5.** Interface
- Interface is a special kind of abstract class, and its methods are all abstract

```php
<?php
    interface file{
        public function noTF($param);     // Don't need to use the "abstract" keyword, but end its methods with ";"
        public function noZY($param);
    }
    class Teacher2 implements file {      // Use "implements" to implement an interface
        protected $name;
        private $school;
        public $noTF;
        public $noZY;

        public function __construct($name, $school) {
            $this->name = $name;
            $this->school = $school;
        }
        public function noTF($param) {
            $this->noTF = $param;
        }
        public function noZY($param) {
            $this->noZY = $param;
        }
        public function fun1() {
            return 'I am' . $this->name . ', ' . $this->noTF . $this->noZY;
        }
    }

    $obj = new Teacher2('ouyang', 'SWJTU');
    $obj->noTF('I didn't conduct corporal punishment on students, ');
    $obj->noZY('I didn't assign any homework');
    echo $obj->fun1();
?>
```
**6.** Namespace
 - It is used to solve the naming conflict of global members, drawing on the idea of file directory (different directories can have files with the same name)
 - The namespace must be written at the beginning of the program
 - Except for variables, the rest members cannot be directly accessed across namespaces

```php
<?php
    namespace one;
        const NAME = 'Constant of miejue <hr/>';
        function php(){
                return 'Function of miejue <hr/>';
        }
        class phpcn{
                public function fun(){
                        return 'Class of miejue <hr/>';
                }
        }
        
        // Access in namespace one
        echo php();  
        echo \two\php();       
        echo \one\three\php();
        use \one\three as t;        // Use sub-namspace "one\three" and rename it with "as"
        echo t\php();

    namespace two;
        const NAME = 'Constant of ximen <hr/>';
        function php(){
                return 'Function of ximen <hr/>';
        }
        class phpcn{
                public function fun(){
                        return 'Class of ximen <hr/>';
                }
        }

    namespace one\three;           // Sub-namespace
        const NAME = 'Constant of ouyang <hr/>';
        function php(){
                return 'Function of ouyang <hr/>';
        }
        class phpcn{
                public function fun(){
                        return 'Class of ouyang <hr/>';
                }
        }
?>
```
<br>

# Chapt.8 New Feature of PHP8
<hr>

**New feature 1**: JIT compiler
 - JIT (Just In Time) compiler can greatly improve the performance of PHP
 - JIT compiler will be integrated into PHP as an extension. The "Opcache extension" is used to directly convert some *opcodes* into *cpu instructions* at runtime
 - JIT is valid only when "Opcache" is enabled

**New feature 2**: You can assign variables with default values when calling functions
 - PHP7

```php
function test($a,$b=0,$c=0,$d=0){
    echo $a;
    echo '<hr/>';
    echo $b;
    echo '<hr/>';
    echo $c;
    echo '<hr/>';
    echo $d;
}

test(10,20,30,40);
```
 - PHP8

```php
function test($a,$b=0,$c=0,$d=0){
    echo $a;
    echo '<hr/>';
    echo $b;
    echo '<hr/>';
    echo $c;
    echo '<hr/>';
    echo $d;
}

test(10,20,d:30,c:40);
```
**New feature 3**: You can define and initialize attributes in the constructor at the same time

```php
public function __construct(public $name, public $school, public $id_num){}
```

<div align="right"><a class="top-link hide" href="#top"><font size="6"><b>↑</b></font></a></div>

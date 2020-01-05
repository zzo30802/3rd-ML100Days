<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8" />
        <title>The english word book</title>
    </head>
    <body>
    
    <!--登入MySQL伺服器-->
    <?php
    $servername = "localhost";
    $username = "root";
    $password = "usbw";
    
    //mysqli指令查詢(MySQLi Procedural) : https://www.runoob.com/php/php-ref-mysqli.html
    // Create connection
    $conn = mysqli_connect($servername, $username, $password);
    //設定server的字體，否則會亂碼
    mysqli_set_charset($conn, "utf8");
    // Check connection
    if (!$conn){
        die("Connection faild: ". mysqli_connect_error());
    }
    
    // Create database，並且確認資料庫自否已經存在
    $dbname_create = $_POST['select_create_database'];
    if (mysqli_select_db($conn, $dbname_create) == True){
        echo "資料庫 $dbname_create 已存在";
    } else {
        $sql = "CREATE DATABASE $dbname_create";
        if (mysqli_query($conn, $sql)){
            echo "Database created successfully";
        }else {
            "Error creating database: ".mysqli_connect_error();
        }
    }

    if(!isset($dbname_create)){
        echo '{"success": false}';
    } else {
        echo '{"success": True}';
    }
    
    

    //select_create_table
    $word_positive = $_POST['word_positive'];
    $word_negative = $_POST['word_negative'];
    $sql1 = "INSERT INTO toeic (word_positive, word_negative) VALUES ('$word_positive','$word_negative')";
    if ($conn->query($sql1) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql1 . "<br>" . $conn->error;
    }

    mysqli_close($conn)
    ?>
    </body>
</html>
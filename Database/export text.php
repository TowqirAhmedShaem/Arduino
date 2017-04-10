<?php get_header(); ?>
  <body>

<?php
$servername = "localhost";
$username = "id1303442_wp_55bd5273f841065b84fdc8ac423cc9fe";
$password = "c7aeae161ac5e9e0a5a0a5ebdd183bdff0a2b5c9";
$dbname = "id1303442_wp_55bd5273f841065b84fdc8ac423cc9fe";

// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);

if($conn)
{
	echo "Shaem Successful"."<br>";
}
else 
{
	echo "Shaem Faile"."<br>";
}

//$sql = "SELECT id, firstname, lastname FROM MyGuests";
//$sql  = 'SELECT *  FROM `registration` WHERE `template` = 02';
//$var=1;
$sql = "SELECT id, name, template, date, mobilenumber FROM attendance ";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    // output data of each row
	
    while($row = mysqli_fetch_assoc($result)) {
        echo  "ID: " . $row["id"]."Name: " . $row["name"]."Template No :" .$row["template"]."Mobile No : " .$row["mobilenumber"] ."Date :" .$row["date"]  ."<br>";
    }
} else {
    echo "0 results";
}

mysqli_close($conn);
?>


<?php get_footer(); ?>
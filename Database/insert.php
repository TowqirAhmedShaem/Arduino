<!DOCTYPE html>
<html>
<head>
<title>APECE  attendance management system</title>
</head>
<body>

<h1 style="color:blue;" >	Applied Physics, Electronics and Communication Engineering</h1>  
<h1 style="text-align:center;" >	University of Chittagong</h1>  
<img src="http://www.w3schools.com/images/w3schools_green.jpg" width="104" height="142">
<?php
	get_header();
?>
  <body>
<?php
$servername = "localhost";
$username = "id1303442_wp_55bd5273f841065b84fdc8ac423cc9fe";
$password = "c7aeae161ac5e9e0a5a0a5ebdd183bdff0a2b5c9";
$dbname = "id1303442_wp_55bd5273f841065b84fdc8ac423cc9fe";

// Create connection
$conn=mysqli_connect($servername, $username, $password, $dbname);

$var=$_GET['var'];
//$var=1;

$sql2 = "SELECT id, name, template, date, mobilenumber FROM registration WHERE template = '".$var."' ";
$resource=mysqli_query($conn,$sql2);
$getData=mysqli_fetch_array($resource);
$id=$getData['id'];
$name=$getData['name'];
$date=$getData['date'];
$mobilenumber=$getData['mobilenumber'];

$sql = "INSERT INTO `attendance` (`id`, `name`, `template`, `date`, `mobilenumber`) VALUES ('".$id."', '".$name."', '".$var."', '".$date."', '".$mobilenumber."' );";
$data=mysqli_query($conn,$sql);
if($data)
{
	echo "Success";
}
else
{
	echo "Failed!";
}

get_footer();

?>

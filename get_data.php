<?php
date_default_timezone_set("Asia/Kolkata");
$con = mysqli_connect('localhost','iotagri1_smart','2r%4jdD8','iotagri1_smart');
$sql = "select * from bulbs_data";
$result=mysqli_query($con,$sql);
$row=mysqli_fetch_assoc($result);
echo '?ID='.str_replace('(Manual)','',$row['motor']).'$';
?>



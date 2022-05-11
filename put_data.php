<?php
////////////////////////////////////////////////////
$con = mysqli_connect('localhost','iotagri1_smart','2r%4jdD8','iotagri1_smart');
////////////////////////////////////////////////////
if(!empty($_REQUEST))
{
$temp = @$_REQUEST['temp'];
$hum = @$_REQUEST['hum'];
$mos = @$_REQUEST['mos'];

$query = "INSERT INTO `sens` (`temp`, `hum`, `mos`)
 VALUES ('".$temp."', '".$hum."', '".$mos."')";
mysqli_query($con,$query);
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
if($temp >= 50)
{
$to      = 'myakaprakash@gmail.com';
$subject = ' HIGH TEMPERATURE ALERT';
$message = 'Temp='.$temp;
$message .= "Deg   Filed TEMPERATURE Alert."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

$to      = '2018011239.mahamudul@ug.sharda.ac.in';
$subject = ' HIGH TEMPERATURE ALERT';
$message = 'Temp='.$temp;
$message .= "Deg   Filed TEMPERATURE Alert."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

}
////////////////////////////////////////////////////////////////////////
if($hum >= 45)
{
$to      = 'myakaprakash@gmail.com';
$subject = ' HIGH HUMIDITY ALERT';
$message = 'HUMIDITY='.$hum;
$message .= "Filed HUMIDITY Alert."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

$to      = '2018011239.mahamudul@ug.sharda.ac.in';
$subject = ' HIGH HUMIDITY ALERT';
$message = 'HUMIDITY='.$hum;
$message .= "Filed HUMIDITY Alert."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

}
////////////////////////////////////////////////////////////////////////
if($mos >= 200)
{
$to      = 'myakaprakash@gmail.com';
$subject = ' SOIL MOISTURE ALERT';
$message = 'MOISTURE Detected AT FEILD';
$message .= "MOTOR PUMP OFF."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

$to      = '2018011239.mahamudul@ug.sharda.ac.in';
$subject = ' SOIL MOISTURE ALERT';
$message = 'MOISTURE Detected AT FEILD';
$message .= "MOTOR PUMP OFF."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

}
////////////////////////////////////////////////////////////////////////
if($mos <= 100)
{
$to      = 'myakaprakash@gmail.com';
$subject = ' NO SOIL MOISTURE ';
$message = 'NO MOISTURE Detected AT FEILD';
$message .= "MOTOR PUMP ON."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

$to      = '2018011239.mahamudul@ug.sharda.ac.in';
$subject = ' NO SOIL MOISTURE ';
$message = 'NO MOISTURE Detected AT FEILD';
$message .= "MOTOR PUMP ON."."\r\n";
$message .= "https://iotagriculture.in/iot_agrimnr/index.php"."\r\n";
$headers = 'From: iotwaterq@gmail.com' . "\r\n" .
    'Reply-To: iotwaterq@gmail.com' . "\r\n" .
    'X-Mailer: PHP/' . phpversion();
mail($to, $subject, $message, $headers);

}
////////////////////////////////////////////////////////////////////////
}
?>

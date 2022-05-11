<?php
date_default_timezone_set("Asia/Kolkata");
$con = mysqli_connect('localhost','iotagri1_smart','2r%4jdD8','iotagri1_smart');
$sql = "SELECT * FROM sens ORDER BY createdat DESC";
$result=mysqli_query($con,$sql);
$row=mysqli_fetch_assoc($result);
?>

<div class="row" style="margin-top: 5px">
			<div class="col-md-3"  style="margin-top: 5px; margin-left:50px;">
				<center><span class="label label-danger">Temperature Sensor</span></center>
				<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>

    
<?php 
if($row['temp'] >='1' AND $row['temp'] <='10.99' )
echo '<td width="14%"><img src="images/therm-10.jpg" width="94" height="292"></td>';

if($row['temp'] >='11' AND $row['temp'] <='20.99' )
echo '<td width="14%"><img src="images/therm-20.jpg" width="94" height="292"></td>';

if($row['temp'] >='21' AND $row['temp'] <='30.99' )
echo  '<td width="14%"><img src="images/therm-30.jpg" width="94" height="292"></td>';

if($row['temp'] >='31' AND $row['temp'] <='40.99' )
echo '<td width="14%"><img src="images/therm-40.jpg" width="94" height="292"></td>';

if($row['temp'] >='41' AND $row['temp'] <='50.99' )
echo '<td width="14%"><img src="images/therm-50.jpg" width="94" height="292"></td>';

if($row['temp'] >='51' AND $row['temp'] <='60.99' )
echo '<td width="14%"><img src="images/therm-60.jpg" width="94" height="292"></td>';

if($row['temp'] >='61' AND $row['temp'] <='70' )
echo '<td width="14%"><img src="images/therm-70.jpg" width="94" height="292"></td>';

if($row['temp'] >='71' AND $row['temp'] <='80' )
echo '<td width="14%"><img src="images/therm-80.jpg" width="94" height="292"></td>';

if($row['temp'] >='81' AND $row['temp'] <='90' )
echo '<td width="14%"><img src="images/therm-90.jpg" width="94" height="292"></td>';

if($row['temp'] >='91' AND $row['temp'] <='100' )
echo '<td width="14%"><img src="images/therm-100.jpg" width="94" height="292"></td>';

if($row['temp'] >='101' AND $row['temp'] <='110' )
echo '<td width="14%"><img src="images/therm-110.jpg" width="94" height="292"></td>';

if($row['temp'] >='111' AND $row['temp'] <='120' )
echo '<td width="14%"><img src="images/therm-120.jpg" width="94" height="292"></td>';

if($row['temp'] >='121' AND $row['temp'] <='130' )
echo '<td width="14%"><img src="images/therm-130.jpg" width="94" height="292"></td>';
?>

<td width="70"><table width="80%" border="0" align="center" cellpadding="0" cellspacing="0">
<tr>
<td>
<h1>
<?php echo $row['temp']; ?>
<sup><small>o</small></sup></h1>
</td>
</tr>
<tr>
<td>
Date &amp; Time:
<?php echo $row['createdat']; ?>
</td>
</tr>
</table></td>
</tr>
</table>
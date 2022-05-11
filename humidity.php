<?php
date_default_timezone_set("Asia/Kolkata");
$con = mysqli_connect('localhost','iotagri1_smart','2r%4jdD8','iotagri1_smart');
$sql = "SELECT * FROM sens ORDER BY createdat DESC";
$result=mysqli_query($con,$sql);
$row=mysqli_fetch_assoc($result);
?>

<div class="row" style="margin-top: 5px"> </div>
    <div class="col-md-3" style="margin-left:5px; margin-top:5px;">
				<center><span class="label label-danger">Soil Humidity Sensor</span></center>
				<table width="100%" border="0" cellspacing="0" cellpadding="0">
<tr>
<td><img src="images/humidity.png" width="150" height="170"></td>
<td width="70%"><table width="80%" border="0" align="center" cellpadding="0" cellspacing="0">
			</div>
			
<tr>
<td>
<h1>
<?php echo $row['hum']; ?>
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
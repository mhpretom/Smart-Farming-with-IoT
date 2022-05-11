<?php
date_default_timezone_set("Asia/Kolkata");
$con = mysqli_connect('localhost','iotagri1_smart','2r%4jdD8','iotagri1_smart');
$sql = "select * from bulbs_data";
$result=mysqli_query($con,$sql);
$row=mysqli_fetch_assoc($result);
?>



<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="refresh" content="3" />
    <title>svs</title>
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <script src="js/jquery.min.js"></script>
      <script src="js/bootstrap.min.js"></script>
    <style>
	  .motor-holder
    	{
    		width: 180px;
    		margin: 10px auto;
    		cursor: pointer;
    	}
    	.bulb-holder
    	{
    		width: 120px;
    		margin: 10px auto;
    		cursor: pointer;
    	}
    	 .fan-holder
    	{
    		width: 192px;
    		margin: 5px auto;
    		cursor: pointer;
    	}
    	.bulb-holder h3
    	{
    		text-align: center;	
    	}
    </style>
  </head>
  <body>
   	<div class="container">
   		
		<div class="row" style="margin-top: 20px">
        <div class="col-md-3">
				<center><span class="label label-danger">Submercible Pump-1</span></center>
				<div id="motor-holder" class="motor-holder">
					<?php 
						if($row['motor'] =='ON' OR $row['motor'] =='ON(Manual)' )
							echo '<img src="images/water_pouring.gif" height="200">';
						else
							echo '<img src="images/water_pump.jpg" height="200">';
							
						if($row['motor'] =='ON(Manual)')
							echo '<br><span class="label label-primary">AUTOMATIC ON</span>';
						
						if($row['motor'] =='OFF(Manual)')
							echo '<br><span class="label label-primary">AUTOMATIC OFF</span>';
							
					?>
				</div>
			</div>
				
			
			
			
            
        </div>
   	</div>   
   	<script>
	$('#motor-holder').click(function(){
   			$.ajax({
	  		  type: "POST",
			  url: "toggle_bulb.php",
			  data: { "mot" : "motor", "rand" : Math.floor(Math.random()*11)},
			  success: function(data, textStatus, jqXHR)
				    {
						//alert(this.data + "," + this.url);
				      	if(data=="motorON")
				      	{
				      		$('#motor-holder').empty();
				      		$('#motor-holder').html('<img src="images/water_pouring.gif" height="200">');
				      	}
				      	else
				      	{
				      		$('#motor-holder').empty();
				      		$('#motor-holder').html('<img src="images/water_pump.jpg" height="200">');
				      	}
				    },
			});
   		});
   		
		
   	</script>
  </body>
</html>
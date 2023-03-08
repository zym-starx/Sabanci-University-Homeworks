<!DOCTYPE html>
<html>
<head>
	<title>Add Nurse</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
	<b>Add Nurse<b>
	<br> <br>

<?php
	include "listnurses.php";
?>
	<br><br>
	Please enter the information of the patient:
	<br>
	<form action="addnurse2.php" method ="POST"><br>
		<input type="text" name="name" placeholder="Type nurse's name"><br><br>
		<input type="text" name="area" placeholder="Type nurse's area"><br>
		<button>Submit</button>
		<br>
	</form>
</div>

<br><br><br>
<div align="left">
	<form action= "nurse.php">
			<button class = "gfg" type="submit">
				Nurses main page
			</button>
	</form>
</div>


</body>
</html>

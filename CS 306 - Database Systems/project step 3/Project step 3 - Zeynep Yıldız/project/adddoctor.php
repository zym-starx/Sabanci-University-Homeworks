<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
	<title>Add Doctor</title>
	
</head>

<body>
<div align="left">
<b>Add Doctor<b>
<br> <br>

<?php
include "listdoctors.php";
?>
<br><br>
Please enter the information of the new doctor:
<br>
<form action="adddoctor2.php" method ="POST"><br>
	<input type="text" name="name" placeholder="Type doctor's name"><br><br>
	<input type="text" name="area" placeholder="Type doctor's area"><br>
	<button>Submit</button>
	<br>
</form>
</div>

<div align="right">
<form action="doctor.php">
        <button class = "gfg" type="submit">
            Doctors main page
        </button>
</form>
</div>


</body>
</html>

<!DOCTYPE html>
<html>
<head>
	<title>Add Patient</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>Add Patient<b>
<br> <br>

<?php
include "listpatients.php";
?>
<br><br>
Please enter the information of the patient:
<br>
<form action="addpatient2.php" method ="POST"><br>
	<input type="text" name="name" placeholder="Type patient's name"><br><br>
	<input type="integer" name="age" placeholder="Type patient's age"><br>
	<button>Submit</button>
	<br>
</form>
</div>

<div align="right">
<form action= "patient.php">
        <button class = "gfg" type="submit">
            Patients main page
        </button>
</form>
</div>


</body>
</html>

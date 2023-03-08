<!DOCTYPE html>
<html>
<head>
	<title>Add Medical Record</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>Add Patient<b>
<br> <br>

<?php
include "config.php";
?>
<br><br>
Please enter the information of the patient's medical record:
<br>
<form action="addmedrecord2.php" method ="POST"><br>
	<input type="text" name="dis" placeholder="Type patient's disease"><br><br>
	<input type="text" name="med" placeholder="Type prescribed medicine"><br><br>
    <input type="hidden" name="id"><br><br>
	<button>Submit</button>
	<br><br>
</form>
</div>

<div align="right">
<form action= "selectinfopat.php">
        <button class = "gfg" type="submit">
            Go back
        </button>
</form>
</div>


</body>
</html>

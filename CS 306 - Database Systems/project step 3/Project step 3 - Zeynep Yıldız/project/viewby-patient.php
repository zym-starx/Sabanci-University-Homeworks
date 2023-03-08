<!DOCTYPE html>
<html>
<head>
	<title>View Patient</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>Select Patient<b>
<br> <br>

<?php
include "listpatients.php";
?>

<form action="viewby-p.php" method="POST">
<select name="ages">

<?php

$sql_command = "SELECT DISTINCT page FROM patient";
$myresult = mysqli_query($db, $sql_command);

while($id_rows = mysqli_fetch_assoc($myresult))
{
	$id = $id_rows['page'];
	echo "<option value=$id>".$id."</option>";
}

?>
</select>

<button>SHOW</button>
</form>
</div>

<br><br><br>
<div align="left">
<form action="patient.php">
        <button class = "gfg" type="submit">
            Patients main page
        </button>
</form>
</div>

</body>
</html>
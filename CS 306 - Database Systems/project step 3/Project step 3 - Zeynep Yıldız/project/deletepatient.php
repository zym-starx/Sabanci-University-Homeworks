<!DOCTYPE html>
<html>
<head>
	<title>Delete Patient</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>Delete Patient<b>
<br> <br>

<?php
include "listpatients.php";
?>

<form action="deletepatient2.php" method="POST">
<select name="ids">

<?php

$sql_command = "SELECT pid FROM patient";

$myresult = mysqli_query($db, $sql_command);

while($id_rows = mysqli_fetch_assoc($myresult))
{
	$id = $id_rows['pid'];
	echo "<option value=$id>".$id."</option>";
}

?>
</select>

<button>DELETE</button>
</form>
</div>

<div align="right">
<form action="patient.php">
        <button class = "gfg" type="submit">
            Patient main page
        </button>
</form>
</div>

</body>
</html>
<!DOCTYPE html>
<html>
<head>
	<title>View Nurses</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>View Patients<b>
<br> <br>

<?php
include "listnurses.php";
?>

<form action="viewby-n.php" method="POST">
<select name="areas">

<?php

$sql_command = "SELECT DISTINCT area FROM nurse";
$myresult = mysqli_query($db, $sql_command);

while($area_rows = mysqli_fetch_assoc($myresult))
{
	$area = $area_rows['area'];
	echo "<option value=$area>".$area."</option>";
}

?>
</select>

<button>SHOW</button>
</form>
</div>

<br><br><br>
<div align="left">
<form action="nurse.php">
        <button class = "gfg" type="submit">
            Nurse main page
        </button>
</form>
</div>

</body>
</html>
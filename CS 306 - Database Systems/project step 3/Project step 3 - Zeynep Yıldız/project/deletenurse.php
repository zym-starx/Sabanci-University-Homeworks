<!DOCTYPE html>
<html>
<head>
	<title>Delete Nurse</title>
	<link rel="stylesheet" href="style.css">
</head>

<body>
<div align="left">
<b>Delete Nurse<b>
<br> <br>

<?php
include "listnurses.php";
?>

<form action="deletenurse2.php" method="POST">
<select name="ids">

<?php
$sql_command = "SELECT nid FROM nurse";

$myresult = mysqli_query($db, $sql_command);

while($id_rows = mysqli_fetch_assoc($myresult))
{
	$id = $id_rows['nid'];
	echo "<option value=$id>".$id."</option>";
}
?>

</select>
<button>DELETE</button>
</form>


</div>

<div align="right">
<form action="nurse.php">
        <button class = "gfg" type="submit">
            Nurse main page
        </button>
</form>
</div>

</body>
</html>
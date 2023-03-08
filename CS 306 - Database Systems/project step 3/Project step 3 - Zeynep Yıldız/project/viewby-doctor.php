<!DOCTYPE html>
<html>
<head>
    <link rel="stylesheet" href="style.css">
	<title>View Doctors</title>
</head>

<body>
<div align="left">
<b>View Doctors<b>
<br> <br>

<form action="viewby-d.php" method="POST">
<select name="areas">

<?php
include "config.php";
$sql_command = "SELECT DISTINCT darea FROM doctor";
$myresult = mysqli_query($db, $sql_command);

while($id_rows = mysqli_fetch_assoc($myresult))
{
	$id = $id_rows['darea'];
	echo "<option value=$id>".$id."</option>";
}

?>
</select>
<br><br>
<button>SHOW</button>
</form>

<?php
include "listdoctors.php";
?>
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
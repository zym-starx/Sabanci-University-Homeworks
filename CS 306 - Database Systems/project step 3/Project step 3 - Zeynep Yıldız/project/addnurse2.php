<?php

include "config.php";

if (isset($_POST['name'])){

	$name = $_POST['name'];
	$area = $_POST['area'];

	echo $name . ":	" . $area . "<br>";

	$sql_statement = "INSERT INTO nurse(nname, area) 
	VALUES ('$name','$area')";

	$result = mysqli_query($db, $sql_statement);
	echo "Result is: " . $result;

	header("Location: addnurse.php");
}

else
{
	echo "the form is not set";
}

?>
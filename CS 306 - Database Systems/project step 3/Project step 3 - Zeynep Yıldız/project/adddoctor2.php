<?php

include "config.php";

if (isset($_POST['name'])){

	$name = $_POST['name'];
	$area = $_POST['area'];

	echo $name . ":	" . $age . "<br>";

	$sql_statement = "INSERT INTO doctor(dname, darea) 
	VALUES ('$name','$area')";

	$result = mysqli_query($db, $sql_statement);
	echo "Result is: " . $result;

	header("Location: adddoctor.php");
}

else
{
	echo "the form is not set";
}

?>
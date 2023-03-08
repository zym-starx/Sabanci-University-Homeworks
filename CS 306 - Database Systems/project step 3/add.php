<?php

include "config.php";

if (isset($_POST['name'])){

	$name = $_POST['name'];
	$age = $_POST['age'];

	echo $name . ":	" . $age . "<br>";

	$sql_statement = "INSERT INTO Patient(pname, page) 
	VALUES ('$name','$age')";

	$result = mysqli_query($db, $sql_statement);
	echo "Result is: " . $result;

	header("Location: index.php");
}

else
{
	echo "the form is not set";
}

?>
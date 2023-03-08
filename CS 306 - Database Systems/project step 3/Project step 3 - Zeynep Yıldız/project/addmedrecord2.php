<?php

include "config.php";

if (isset($_POST['dis'])){

	$dis = $_POST['dis'];
	$med = $_POST['med'];

	echo $dis . ":	" . $med . "<br>";

	$sql_statement = "INSERT INTO medical_record(disease, pres_med) 
	VALUES ('$dis','$med')";

	$result = mysqli_query($db, $sql_statement);
	echo "Result is: " . $result;

	header("Location: addmedrecord.php");
}

else
{
	echo "the form is not set";
}

?>
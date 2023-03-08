<!DOCTYPE html>
<html>
<head>
	<title>Add Patient</title>
	<style>
		input[type=text], select {
		width: 50%;
		padding: 12px 20px;
		margin: 8px 0;
		display: inline-block;
		border: 1px solid #ccc;
		border-radius: 4px;
		box-sizing: border-box;
		}

		input[type=submit] {
		width: 50%;
		background-color: #4CAF50;
		color: black;
		padding: 14px 20px;
		margin: 8px 0;
		border: none;
		border-radius: 4px;
		cursor: pointer;
		}

		input[type=submit]:hover {
		background-color: #45a049;
		}

		div {
		border-radius: 5px;
		background-color: #f2f2f2;
		padding: 20px;
		}
	</style>
</head>

<body>
<div align="left">
<b>Add Patient<b>
<br> <br>

<?php
include "patients.php";
?>
<br><br>
Please enter the information of the patient:
<br>
<form action="add.php" method ="POST"><br>
	<input type="text" name="name" placeholder="Type patient's name"><br><br>
	<input type="integer" name="age" placeholder="Type patient's age"><br><br>
	<button>Submit</button>
	<br><br>
</form>
</div>

<div align="right">
<form action="index.php">
        <button class = "gfg" type="submit">
            Index page
        </button>
</form>
</div>


</body>
</html>

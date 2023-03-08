<?php

$db = mysqli_connect('localhost', 'root', '', 'cs306project');

if($db->connect_errno > 0){
	die('unable to connect to database [' . $db->connect_error . ']');
}

?>
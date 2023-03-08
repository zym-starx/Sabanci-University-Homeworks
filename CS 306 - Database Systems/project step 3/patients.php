<!DOCTYPE html>
<html> 
<head>
    <title>Patients</title> 
    
    <style>
    table {
        font-family: arial, sans-serif;
        border-collapse: collapse;
        width: 70%;
    }

    td, th {
        border: 1px solid #dddddd;
        text-align: left;
        padding: 8px;
    }

    tr:nth-child(even) {
        background-color: #dddddd;
    }
    </style>
  </head>

  <body> 
    <h2>Patients</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Age</th>
        </tr>


<?php

include "config.php";

$sql_statement = "SELECT * FROM Patient";

$result = mysqli_query($db, $sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $myid = $row['pid'];
    $myname = $row['pname'];
    $age = $row['page'];

    echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $myname . "</th>" . "<th>" . $age . "</th>" . "</tr" . "<br>";
    //echo $mysender . "<br>" . $message . "<br><br>";
}

?>

</table>
    
</body>
</html>
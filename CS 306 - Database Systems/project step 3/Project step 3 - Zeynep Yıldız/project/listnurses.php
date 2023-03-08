<!DOCTYPE html>
<html> 
<head>
    <title>Nurses</title> 
    
    <style>
    table {
        font-family: arial, sans-serif;
        border-collapse: collapse;
        width: 100%;
    }

    td, th {
        border: 1px solid #dddddd;
        text-align: left;
        padding: 8px;
    }

    tr:nth-child(even) {
        background-color: #636363;
    }
    </style>
  </head>

  <body> 
    <h2>Nurses</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Area</th>
        </tr>


<?php

include "config.php";

$sql_statement = "SELECT * FROM Nurse";

$result = mysqli_query($db, $sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $n_id = $row['nid'];
    $n_name = $row['nname'];
    $n_area = $row['area'];

    echo "<tr>" . "<th>" . $n_id . "</th>" . "<th>" . $n_name . "</th>" . "<th>" . $n_area . "</th>" . "</tr" . "<br>";
    //echo $mysender . "<br>" . $message . "<br><br>";
}

?>

</table>
    
</body>
</html>
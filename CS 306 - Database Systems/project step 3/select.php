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
if(isset($_POST['ages']))
{
    $selection_id = $_POST['ages'];
    $sql_statement = "SELECT * FROM patient WHERE page = $selection_id";
    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['pid'];
        $myname = $row['pname'];
        $myage = $row['page'];

        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $myname . "</th>" . "<th>" . $myage . "</th>" . "</tr>";
    }

    //header("Location: index.php");
}

else
{
    echo "The form is not set";
}

?>
<div align="right">
<form action="index.php">
        <button class = "gfg" type="submit">
            Index page
        </button>
</form>
</div>

</table>
    
</body>
</html>
<!DOCTYPE html>
<html> 
<head>
    <title>Viewing Selected Nurses</title> 
    <link rel="stylesheet" href="style.css">
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
if(isset($_POST['areas']))
{
    $selection_id = $_POST['areas'];
    $sql_statement = "SELECT nid, nname, area FROM nurse WHERE area = '$selection_id'";
    $result = mysqli_query($db, $sql_statement);
    if ($result) {
        while($row = mysqli_fetch_assoc($result))
        {
            $nurse_id = $row['nid'];
            $nurse_name = $row['nname'];
            $nurse_area = $row['area'];

            echo "<tr>" . "<th>" . $nurse_id . "</th>" . "<th>" . $nurse_name . "</th>" . "<th>" . $nurse_area . "</th>" . "</tr>";
        }
    } 
    else {
        echo ("Could not insert data : ");
    }

    

    //header("Location: index.php");
}

else
{
    echo "The form is not set";
}

?>

<br><br><br>
<div align="left">
<form action="nurse.php">
        <button class = "gfg" type="submit">
            Nurse main page
        </button>
</form>
</div>

</table>
    
</body>
</html>
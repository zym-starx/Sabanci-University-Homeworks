<!DOCTYPE html>
<html> 
<head>
    <link rel="stylesheet" href="style.css">
    <title>Doctor</title> 
   
  </head>

  <body> 
    <h2>Doctor</h2>

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
    $sql_statement = "SELECT md_id, dname, darea FROM doctor WHERE darea = '$selection_id'";
    $result = mysqli_query($db, $sql_statement);    

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['md_id'];
        $myname = $row['dname'];
        $myarea = $row['darea'];

        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $myname . "</th>" . "<th>" . $myarea . "</th>" . "</tr>";
    }

    //header("Location: index.php");
}
else
{
    echo "The form is not set";
}

?>

<br><br><br>
<div align="right">
<form action="doctor.php">
        <button class = "gfg" type="submit">
            Doctors main page
        </button>
</form>
</div>

</table>
    
</body>
</html>
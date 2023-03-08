<!DOCTYPE html>
<html> 
<head>
    <title>Doctors</title> 
    
  <body> 
    <h2>Doctors</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Area</th>
        </tr>


<?php

include "config.php";

$sql_statement = "SELECT * FROM doctor";

$result = mysqli_query($db, $sql_statement);

while($row = mysqli_fetch_assoc($result))
{
    $myid = $row['md_id'];
    $myname = $row['dname'];
    $area = $row['darea'];

    echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $myname . "</th>" . "<th>" . $area . "</th>" . "</tr" . "<br>";
    //echo $mysender . "<br>" . $message . "<br><br>";
}

?>

</table>
    
</body>
</html>
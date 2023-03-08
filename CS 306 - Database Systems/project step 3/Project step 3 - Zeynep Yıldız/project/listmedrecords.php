<!DOCTYPE html>
<html> 
<head>
    <title>Medical Records</title> 
    <link rel="stylesheet" href="style.css">
    </head>

  <body> 
    <h2>Medical Records</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Disease</th>
            <th>Medicine</th>
        </tr>


<?php

include "config.php";

    global $patientid;
	$sql_statement = "SELECT  M.disease, M.pres_med
    FROM  Medical_record M, has H
    WHERE  $patientid = H.pid AND M.med_id = H.med_id";

    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['med_id'];
        $dis = $row['disease'];
        $med = $row['pres_med'];

        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $dis . "</th>" . "<th>" . $med . "</th>" . "</tr" . "<br>";
        //echo $mysender . "<br>" . $message . "<br><br>";
    }
	echo "Result is: " . $result;

?>

</table>
    
</body>
</html>
<!DOCTYPE html>
<html> 
<head>
    <title>Selected Patient</title> 
    <link rel="stylesheet" href="style.css">
  </head>

  <body> 
    <h2>Doctors</h2>

    <table>
        <tr>
            <th>Patient ID</th>
            <th>Patient Name</th>
            <th>Doctor ID</th>
            <th>Doctor Name</th>
        </tr>


<?php

include "config.php";
if(isset($_POST['ids']))
{
    $selection_id = $_POST['ids'];
    $sql_statement = "SELECT P.pid, P.pname, D.dname, D.md_id FROM patient P, doctor D, goes_to G WHERE P.pid = '$selection_id' AND P.pid = G.pid AND D.md_id = G.md_id";
    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $pid = $row['pid'];
        $pname = $row['pname'];
        $md_id = $row['md_id'];
        $md_name = $row['dname'];

        echo "<tr>" . "<th>" . $pid . "</th>" . "<th>" . $pname . "</th>" . "<th>" . $md_id . "</th>" .  "<th>" . $md_name . "</th>" . "</tr>";
    }

    //header("Location: index.php");
?>
</table>
<br><br><br>

<h2>Medical Records</h2>

    <table>
        <tr>
            <th>Patient ID</th>
            <th>Disease</th>
            <th>Prescribed Medicine</th>
        </tr>

<?php
    $sql_statement = "SELECT H.pid, M.disease, M.pres_med
    FROM  Medical_record M, has H
    WHERE  '$selection_id' = H.pid AND M.med_id = H.med_id";

    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['pid'];
        $dis = $row['disease'];
        $med = $row['pres_med'];

        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $dis . "</th>" . "<th>" . $med . "</th>" . "</tr" . "<br>";
        //echo $mysender . "<br>" . $message . "<br><br>";
    }
?>
</table>
<br><br><br>

<h2>Nurses</h2>

    <table>
        <tr>
            <th>Patient ID</th>
            <th>Nurse ID</th>
            <th>Nurse Name</th>
            <th>Nurse Area</th>
        </tr>

<?php
    $sql_statement = "SELECT T.pid, N.nname, N.nid, N.area
    FROM  Nurse N, takecare_of T
    WHERE  '$selection_id' = T.pid AND N.nid = T.nid";

    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['pid'];
        $nid = $row['nid'];
        $nname = $row['nname'];
        $area = $row['area'];

        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $nid . "</th>" . "<th>" . $nname . "</th>" . "<th>" . $area . "</th>" . "</tr" . "<br>";
        //echo $mysender . "<br>" . $message . "<br><br>";
    }

}

else
{
    echo "The form is not set";
}

?>
</table>

<br><br><br><br>
<div align="left">
<form action="patient.php">
        <button class = "gfg" type="submit">
            Patient main page
        </button>
</form>
</div>


    
</body>
</html>
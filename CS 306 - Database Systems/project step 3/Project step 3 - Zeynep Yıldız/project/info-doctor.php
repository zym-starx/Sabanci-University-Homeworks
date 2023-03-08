<!DOCTYPE html>
<html> 
<head>
    <title>Selected Doctor</title> 
    <link rel="stylesheet" href="style.css">
  </head>

  <body> 
    <h2>Patients</h2>

    <table>
        <tr>
            <th>Doctor ID</th>
            <th>Doctor Name</th>
            <th>Patient ID</th>
            <th>Patient Name</th>
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

        echo "<tr>" . "<th>" . $md_id . "</th>" . "<th>" . $md_name . "</th>" . "<th>" . $pid . "</th>" .  "<th>" . $pname . "</th>" . "</tr>";
    }

    //header("Location: index.php");
?>
</table>
<br><br><br>

<h2>Nurses</h2>

    <table>
        <tr>
            <th>Doctor ID</th>
            <th>Nurse ID</th>
            <th>Nurse Name</th>
            <th>Nurse Area</th>
        </tr>

<?php
    $sql_statement = "SELECT W.md_id, N.nid, N.nname, N.area
    FROM  Nurse N, works_with W
    WHERE  '$selection_id' = W.md_id AND N.nid = W.nid";

    $result = mysqli_query($db, $sql_statement);

    while($row = mysqli_fetch_assoc($result))
    {
        $myid = $row['md_id'];
        $nname = $row['nname'];
        $nid = $row['nid'];
        $narea = $row['area'];
        
        echo "<tr>" . "<th>" . $myid . "</th>" . "<th>" . $nname . "</th>" . "<th>" . $nid . "</th>"  ."<th>" . $narea . "</th>". "</tr" . "<br>";
        //echo $mysender . "<br>" . $message . "<br><br>";
    }
?>
</table>
<br><br><br>

<?php
}
else
{
    echo "The form is not set";
}
?>

<br><br><br><br>
<div align="left">
<form action="doctor.php">
        <button class = "gfg" type="submit">
            Doctor main page
        </button>
</form>
</div>


    
</body>
</html>